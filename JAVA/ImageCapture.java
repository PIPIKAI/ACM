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
private String saveDir;     //���ͼƬ��·��
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
	ok = new JButton("ȷ��");
	cancel = new JButton("ȡ��");
	save = new JButton("����");
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
	//�����������
	label.addMouseListener(new MouseAdapter(){
		//��������Ҽ����ͷ���Դ
			public void mouseClicked(MouseEvent e) {
				if (e.getButton() == MouseEvent.BUTTON3) {
				dispose(); //�ͷ���Դ
				}
			}
			//������������ȡѡ�����Ͻ�����
			public void mousePressed(MouseEvent e) {
				x1 = e.getX();
				y1 = e.getY();
				
			}
			//�ͷ���������ȡѡ�����½�����
			public void mouseReleased(MouseEvent e) {
				if (isDrag) {
				isDrag=false;
				x2 = e.getX();
				y2 = e.getY();
				//���Ƴ��ֹ�������λ��
				if(y2>=screenSize.height-60) {
					toolPanel.setLocation(Math.max(x2-200,x1-200), y1);//����ײ���ʾ�����ˣ�����ʾ�����Ͻ�
				}
				else {
					toolPanel.setLocation(Math.max(x2-200,x1-200), y2);//��ʾ�����½�
				}
				toolPanel.setVisible(true);
				}
			}
	});
	//�������ƶ�������
	label.addMouseMotionListener(new MouseMotionAdapter() {
		public void mouseDragged(MouseEvent e) {
				if(!isDrag){
				isDrag = true;
				}
				//�϶����̵�����ѡȡ��ʵ��
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
		//ȡ����ť�¼���ȡ��ѡ����
			cancel.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent e){
			dispose();
			}
			});
		//ȷ����ť�¼�������ѡ��ͼ��
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
		//���水ť�¼�������ѡ��ͼ��Ϊ�ļ���
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
		//��ȡ��Ļ�ĳߴ�
		screenSize = Toolkit.getDefaultToolkit().getScreenSize();
		Rectangle d = new Rectangle(0, 0,screenSize.width, screenSize.height);
		//��ȡ������Ļ��ͼ��
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
        //�ĸ�����
        g.setColor(Color.BLUE);
        g.fillRect(x1 - 2, y1 - 2, 4 , 4 );
        g.fillRect(x2 - 2, y1 - 2, 4,  4);
        g.fillRect(x1 - 2, y2 - 2, 4, 4);
        g.fillRect(x2 - 2, y2 - 2, 4, 4);
        //�ĸ��е�
        g.fillRect( (x1 + x2) / 2 - 2, y1 - 2, 4, 4);
        g.fillRect( (x1 + x2) / 2 - 2, y2 - 2, 4, 4);
        g.fillRect(x1 - 2, (y1+y2) / 2 - 2, 4, 4);
        g.fillRect(x2 - 2, (y1+y2) / 2 - 2, 4, 4);
        g.drawRect(Math.min(x1,x2),Math.min(y1,y2),Math.abs(x2-x1),Math.abs(y2-y1));
        //��ʾ��ͼ�ı߿�Ĵ�С
        Color color2= new Color(0,0,0, 0.7F);
        g.setColor(color2);
        int x = Math.min(x1, x2) - 5, y = Math.min(y1, y2) - 28;
        y = y < -5 ? 2 : y;
        g.fillRect(x, y, 70, 20);
        g.setColor(Color.white);
        g.drawString(Math.abs(x2 - x1) + " x " + Math.abs(y2 - y1), x + 5, y + 18);
    }
	public void saveImage(BufferedImage image){
		// ��ͬѧ�ǲ�������
		JFileChooser chooser = new JFileChooser();// �����ļ�ѡ����
        int option = chooser.showSaveDialog(this);// ���ļ�����Ի���
        if (option == JFileChooser.APPROVE_OPTION) {// �����ļ��������
            File file = chooser.getSelectedFile();// ��ȡ�û�ѡ����ļ�
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
