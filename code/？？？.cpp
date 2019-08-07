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
public class ImageCapture extends JWindow {
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
    private int rgbs = 0;
    private boolean isDrag = false;
    private Robot robot;
    private int frameX = 0;//�Ŵ󾵵�Xλ��
    private int frameY = 0;//�Ŵ󾵵�Yλ��
    private int frameSize = 30;//ʵ�ʽ�ȡ��СΪ61����
    private int multiple  = 2;//�Ŵ���
    private int framebigSize = 70 * multiple; //�Ŵ󾵴�С
    @SuppressWarnings("unused")
    private String saveDir;     //���ͼƬ��·��
    public ImageCapture() {
        init();
        addCaptureListener();
        showWindow();
    }
    public void init() {
        captureDesktop();
        JLayeredPane layeredPane = new JLayeredPane();
        label = new JLabel();
        ImageIcon icon = new ImageIcon(screenimage);
        label.setBounds(0, 0, screenSize.width, screenSize.height);
        label.setIcon(icon);
        setCursor(new Cursor(Cursor.CROSSHAIR_CURSOR));
        toolPanel = new JPanel();
        toolPanel.setLayout(new GridLayout(1, 3));
        ok = new JButton("ȷ��");
        cancel = new JButton("ȡ��");
        save = new JButton("����");
        toolPanel.add(save);
        toolPanel.add(cancel);
        toolPanel.add(ok);
        toolPanel.setBounds(0, 0, 200, 30);
        toolPanel.setVisible(false);
        layeredPane.add(label, new Integer(0));
        layeredPane.add(toolPanel, new Integer(1));
        add(layeredPane);
    }
    void addCaptureListener() {
        //�����������
        label.addMouseListener(new MouseAdapter() {
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
                    isDrag = false;
                    x2 = e.getX();
                    y2 = e.getY();
                    //���Ƴ��ֹ�������λ��
                    if(y2 >= screenSize.height - 60) {
                        toolPanel.setLocation(Math.max(x2 - 200, x1 - 200), y1); //����ײ���ʾ�����ˣ�����ʾ�����Ͻ�
                    } else {
                        toolPanel.setLocation(Math.max(x2 - 200, x1 - 200), y2); //��ʾ�����½�
                    }
                    toolPanel.setVisible(true);
                }
            }
        });
        //�������ƶ�������
        label.addMouseMotionListener(new MouseMotionAdapter() {
            public void mouseDragged(MouseEvent e) {
                super.mouseDragged(e);
                if(!isDrag) {
                    isDrag = true;
                }
                if(capturedimage == null) {
                    capturedimage = new BufferedImage(screenimage.getWidth(), screenimage.getHeight(), screenimage.getType());
                }
                Graphics g = capturedimage.getGraphics();
                g.drawImage(screenimage, 0, 0, screenimage.getWidth(), screenimage.getHeight(), null);
                int x = e.getX();
                int y = e.getY();
                drawGamer( g, capturedimage, x, y);
                drawLines(g, x, y);
                label.setIcon(new ImageIcon(capturedimage));
            }
        });
        //ȡ����ť�¼���ȡ��ѡ����
        cancel.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                dispose();
            }
        });
        //ȷ����ť�¼�������ѡ��ͼ��
        ok.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                dispose();
                if (capturedimage != null) {
                    BufferedImage subimg =
                        screenimage.getSubimage(Math.min(x1, x2), Math.min(y1, y2), Math.abs(x2 - x1), Math.abs(y2 - y1));
                    setImageClipboard(subimg);
                }
            }
        });
        //���水ť�¼�������ѡ��ͼ��Ϊ�ļ���
        save.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                dispose();
                if (capturedimage != null) {
                    BufferedImage subimg =
                        screenimage.getSubimage(Math.min(x1, x2), Math.min(y1, y2), Math.abs(x2 - x1), Math.abs(y2 - y1));
                    saveImage(subimg);
                }
            }
        });
    }
    void showWindow() {
        setSize(screenimage.getWidth(), screenimage.getHeight());
        setVisible(true);
        setAlwaysOnTop(true);
    }
    public void captureDesktop() {
        //��ȡ��Ļ�ĳߴ�
        screenSize = Toolkit.getDefaultToolkit().getScreenSize();
        Rectangle d = new Rectangle(0, 0, screenSize.width, screenSize.height);
        //��ȡ������Ļ��ͼ��
        try {
            Thread.sleep(250);
            robot = new Robot();
            screenimage = robot.createScreenCapture(d);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    //�Ŵ�
    public void drawGamer(Graphics g, Image  imageCache, int x2, int y2) {
        Color c = g.getColor();// ��ȡԭɫ
        //����λ��x,y
        int x, y;
        if(Math.max(x1, x2) + 145 + 50 >= screenSize.width) {
            x = Math.min(x1, x2) - 50 - 10;
        } else {
            x = Math.max(x1, x2) + 10;
        }
        if(Math.max(y1, y2) + 45 + 40 + 140 >= screenSize.height) {
            y = Math.min(y1, y2) - 40 - 10 - 140;
        } else {
            y = Math.max(y1, y2) + 10;
        }
        frameX = x;
        frameY = y;
        g.drawImage(imageCache, frameX, frameY, frameX + framebigSize, frameY + framebigSize, x2 - frameSize, y2 - frameSize, x2 + frameSize, y2 + frameSize, null);
        g.setColor(Color.blue);
        //����ʮ�ּ�
        Graphics2D g2d = (Graphics2D) g;
        g2d.setStroke(new BasicStroke(multiple));//�����߿�Ϊ2.0
        g.drawLine(frameX, frameY + (framebigSize >> 1), frameX + framebigSize, frameY + (framebigSize >> 1));
        g.drawLine(frameX + (framebigSize >> 1), frameY, frameX + (framebigSize >> 1), frameY + framebigSize);
        g.setColor(c);// ��ԭɫ
    }
    public void drawLines(Graphics g, int x2, int y2) {
        Color c = g.getColor();// ��ȡԭɫ
        Color color1 = new Color(0, 0, 0, 0.3F);
        int sx = Math.min(x1, x2), sy = Math.min(y1, y2), lx = Math.max(x1, x2), ly = Math.max(y1, y2);
        g.setColor(color1);
        /*for (int i = 0; i < screenSize.height; i ++) {
            if (i >= Math.min(y1, y2) && i <= Math.max(y1,y2)) {
                g.drawLine(0, i, Math.min(x1,x2), i);
                g.drawLine(Math.max(x1,x2), i,screenSize.width, i);
            }
            else {
            	g.drawLine(0, i, screenSize.width, i);����̫����!!
            }
        }*/
        g.fillRect(0, 0, screenSize.width, sy); // up
        g.fillRect(0, ly, screenSize.width, screenSize.height - ly); // down
        g.fillRect(0, sy, sx, ly - sy); // left
        g.fillRect(lx, sy, screenSize.width - lx, ly - sy); // right
        //��ʾ��ͼ�ı߿�Ĵ�С
        //��
        //��ʾ��굱ǰ�� RGBֵ
        Color color2 = new Color(0, 0, 0, 0.7F);
        g.setColor(color2);
        rgbs = GetRGB(x2, y2);
        int x, y;
        if(Math.max(x1, x2) + 140 + 5 >= screenSize.width) {
            x = Math.min(x1, x2) - 50 - 10;
        } else {
            x = Math.max(x1, x2) + 10;
        }
        if(Math.max(y1, y2) + 45 + 40 + 140 >= screenSize.height) {
            y = Math.min(y1, y2) - 10 - 40;
        } else {
            y = Math.max(y1, y2) + 140;
        }
        int r = (rgbs >> 16) & 0xff ;
        int gg = (rgbs >> 8) & 0xff ;
        Math.abs(x2 - x1 + 1);
        int b = (rgbs) & 0xff ;
        g.fillRect(x, y, 140, 40);
        g.setColor(Color.WHITE);
        Font fsib30 = new Font("����", Font.BOLD, 16);
        g.setFont(fsib30);
        g.drawString( "�ֱ��ʣ�" + Math.abs(x2 - x1 + 1) + "x" + Math.abs(y2 - y1 + 1), x, y + 15);
        g.drawString("RGB:(" + r + "," + gg + "," + b + ")", x, y + 30);
        //�ĸ�����
        g.setColor(Color.BLUE);
        g.fillRect(x1 - 2, y1 - 2, 4, 4 );
        g.fillRect(x2 - 2, y1 - 2, 4,  4);
        g.fillRect(x1 - 2, y2 - 2, 4, 4);
        g.fillRect(x2 - 2, y2 - 2, 4, 4);
        //�ĸ��е�
        g.fillRect( (x1 + x2) / 2 - 2, y1 - 2, 4, 4);
        g.fillRect( (x1 + x2) / 2 - 2, y2 - 2, 4, 4);
        g.fillRect(x1 - 2, (y1 + y2) / 2 - 2, 4, 4);
        g.fillRect(x2 - 2, (y1 + y2) / 2 - 2, 4, 4);
        g.drawRect(Math.min(x1, x2), Math.min(y1, y2), Math.abs(x2 - x1), Math.abs(y2 - y1));
        g.setColor(c);// ��ԭɫ
    }
    public int GetRGB(int x2, int y2) {
        Toolkit tk = Toolkit.getDefaultToolkit(); // ��ȡȱʡ���߰�
        Dimension di = tk.getScreenSize(); //��Ļ�ߴ���
        Rectangle rec = new Rectangle(0, 0, di.width, di.height);
        BufferedImage bi = robot.createScreenCapture(rec);
        int pixelColor = bi.getRGB(x2, y2);//����Զ����������ֵ
        // pixelColor��ֵΪ��������ʵ���ó���������ɫ���ֵ����ʵ����ɫֵ��
        return 16777216 + pixelColor;
    }
    public void saveImage(BufferedImage image) {
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
        return new DataFlavor[] {DataFlavor.imageFlavor};
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
