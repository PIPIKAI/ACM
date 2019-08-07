package jieping;
import java.awt.*;
import java.awt.datatransfer.DataFlavor;
import java.awt.datatransfer.Transferable;
import java.awt.datatransfer.UnsupportedFlavorException;
import java.awt.event.*;
import java.awt.image.*;
import java.io.*;
import javax.imageio.ImageIO;
import javax.swing.*;
@SuppressWarnings("serial")
public class ImageCapture extends JWindow{
private Dimension screenSize;
private BufferedImage screenimage;
private BufferedImage capturedimage = null;
JLabel label;
JPanel toolPanel;
JButton ok;
JButton cancel;
JButton save;
private int x1 = 0;
private int y1 = 0;
private int x2 = 0;
private int y2 = 0;
private boolean isDrag = false;
private String saveDir;     //存放图片的路径
public ImageCapture(){
	init();
	addCaptureListener();
	showWindow();
}
public void init(){
	captureDesktop();
	JLayeredPane layeredPane = new JLayeredPane();
	label = new JLabel();
	ImageIcon icon = new ImageIcon(screenimage);
	label.setBounds(0,0,screenSize.width,screenSize.height);
	label.setIcon(icon);
	setCursor(new Cursor(Cursor.CROSSHAIR_CURSOR));
	toolPanel = new JPanel();
	toolPanel.setLayout(new GridLayout(1,3));
	ok = new JButton("确定");
	cancel = new JButton("取消");
	save = new JButton("保存");
	toolPanel.add(save);
	toolPanel.add(cancel);
	toolPanel.add(ok);
	toolPanel.setBounds(0, 0, 200, 30);
	
	toolPanel.setVisible(false);
	layeredPane.add(label,new Integer(0));
	layeredPane.add(toolPanel,new Integer(1));
	add(layeredPane);
}
void addCaptureListener(){
	//添加鼠标监听器
	label.addMouseListener(new MouseAdapter(){
		//按下鼠标右键，释放资源
			public void mouseClicked(MouseEvent e) {
				if (e.getButton() == MouseEvent.BUTTON3) {
				dispose(); //释放资源
				}
			}
			//按下鼠标键，获取选框左上角坐标
			public void mousePressed(MouseEvent e) {
				x1 = e.getX();
				y1 = e.getY();
				
			}
			//释放鼠标键，获取选框右下角坐标
			public void mouseReleased(MouseEvent e) {
				if (isDrag) {
				isDrag=false;
				x2 = e.getX();
				y2 = e.getY();
				//控制出现工具栏的位置
				if(y2>=screenSize.height-60) {
					toolPanel.setLocation(Math.max(x2-200,x1-200), y1);//如果底部显示不下了，就显示在左上角
				}
				else {
					toolPanel.setLocation(Math.max(x2-200,x1-200), y2);//显示在右下角
				}
				toolPanel.setVisible(true);
				}
			}
	});
	//添加鼠标移动监听器
	label.addMouseMotionListener(new MouseMotionAdapter() {
		public void mouseDragged(MouseEvent e) {
				if(!isDrag){
				isDrag = true;
				}
				//拖动过程的虚线选取框实现
				capturedimage = new
				BufferedImage(screenimage.getWidth(),screenimage.getHeight(),screenimage.getType());
				Graphics g = capturedimage.getGraphics();
				g.drawImage(screenimage,0,0,screenimage.getWidth(),screenimage.getHeight(),null);
				int x=e.getX();
				int y=e.getY();
				drawLines(g,x,y);
				label.setIcon(new ImageIcon(capturedimage));
			}
		});
		//取消按钮事件（取消选区）
			cancel.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent e){
			dispose();
			}
			});
		//确定按钮事件（剪贴选区图像）
			ok.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent e){
			dispose();
			if (capturedimage!=null){
			BufferedImage subimg =
			screenimage.getSubimage(Math.min(x1,x2),Math.min(y1,y2),Math.abs(x2-x1),Math.abs(y2-y1));
			setImageClipboard(subimg);
			}
			}
			});
		//保存按钮事件（保存选区图像为文件）
		save.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent e){
			dispose();
			if (capturedimage!=null){
			BufferedImage subimg =
			screenimage.getSubimage(Math.min(x1,x2),Math.min(y1,y2),Math.abs(x2-x1),Math.abs(y2-y1));
			saveImage(subimg);
			}
		}
		});
}
	void showWindow(){
		setSize(screenimage.getWidth(),screenimage.getHeight());
		setVisible(true);
		setAlwaysOnTop(true);
	}
	public void captureDesktop(){
		//获取屏幕的尺寸
		screenSize = Toolkit.getDefaultToolkit().getScreenSize();
		Rectangle d = new Rectangle(0, 0,screenSize.width, screenSize.height);
		//截取整个屏幕的图像
		Robot robot;
		try {
			Thread.sleep(250);
			robot = new Robot();
			screenimage = robot.createScreenCapture(d);
			} 
		catch (Exception e) {
			e.printStackTrace();
			}
	}
	public void drawLines(Graphics g,int x2,int y2) {
		Color color1= new Color(0,0,0, 0.3F);
        g.setColor(color1);
        for (int i = 0; i < screenSize.height; i ++) {
            if (i >= Math.min(y1, y2) && i <= Math.max(y1,y2)) {
                g.drawLine(0, i, Math.min(x1,x2), i);
                g.drawLine(Math.max(x1,x2), i,screenSize.width, i);
            }
            else {
            	g.drawLine(0, i, screenSize.width, i);
            }
        }
        //四个顶点
        g.setColor(Color.BLUE);
        g.fillRect(x1 - 2, y1 - 2, 4 , 4 );
        g.fillRect(x2 - 2, y1 - 2, 4,  4);
        g.fillRect(x1 - 2, y2 - 2, 4, 4);
        g.fillRect(x2 - 2, y2 - 2, 4, 4);
        //四个中点
        g.fillRect( (x1 + x2) / 2 - 2, y1 - 2, 4, 4);
        g.fillRect( (x1 + x2) / 2 - 2, y2 - 2, 4, 4);
        g.fillRect(x1 - 2, (y1+y2) / 2 - 2, 4, 4);
        g.fillRect(x2 - 2, (y1+y2) / 2 - 2, 4, 4);
        g.drawRect(Math.min(x1,x2),Math.min(y1,y2),Math.abs(x2-x1),Math.abs(y2-y1));
        //显示截图的边框的大小
        Color color2= new Color(0,0,0, 0.7F);
        g.setColor(color2);
        int x = Math.min(x1, x2) - 5, y = Math.min(y1, y2) - 28;
        y = y < -5 ? 2 : y;
        g.fillRect(x, y, 70, 20);
        g.setColor(Color.white);
        g.drawString(Math.abs(x2 - x1) + " x " + Math.abs(y2 - y1), x + 5, y + 18);
    }
	public void saveImage(BufferedImage image){
		// 请同学们补充完善
		JFileChooser chooser = new JFileChooser();// 创建文件选择器
        int option = chooser.showSaveDialog(this);// 打开文件保存对话框
        if (option == JFileChooser.APPROVE_OPTION) {// 处理文件保存操作
            File file = chooser.getSelectedFile();// 获取用户选择的文件
            try {
                ImageIO.write(image, "", file);
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
	}
	public void setImageClipboard(Image image) {
		ImageSelection imgSel = new ImageSelection(image);
		Toolkit.getDefaultToolkit().getSystemClipboard().setContents(imgSel, null);
	}
}
	class ImageSelection implements Transferable {
	private Image image;
	public ImageSelection(Image image) {
	this.image = image;
	}
	@Override
	public DataFlavor[] getTransferDataFlavors() {
	// TODO Auto-generated method stub
	return new DataFlavor[]{DataFlavor.imageFlavor};
	}
	@Override
	public boolean isDataFlavorSupported(DataFlavor flavor) {
	// TODO Auto-generated method stub
	return DataFlavor.imageFlavor.equals(flavor);
	}
	@Override
	public Object getTransferData(DataFlavor flavor) throws UnsupportedFlavorException,
	IOException {
	// TODO Auto-generated method stub
	if (!DataFlavor.imageFlavor.equals(flavor)) {
	throw new UnsupportedFlavorException(flavor);
	}
	return image;
	}
	}
