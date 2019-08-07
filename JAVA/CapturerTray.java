package jieping;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import com.melloware.jintellitype.HotkeyListener;
import com.melloware.jintellitype.JIntellitype;
import java.net.URL;
public class CapturerTray {
	MenuItem exit;
	MenuItem capture;
	MenuItem fcapture;
	MenuItem fexit;
	public static final int FUNC_KEY_MARK = 1;
	public static final int EXIT_KEY_MARK = 0;
	public static void main(String[] args){
	new CapturerTray();
	}
	public CapturerTray(){
		setTray();
		setKey();
		addListener();
	}
	public void setTray(){
		if (SystemTray.isSupported()) { // �ж��Ƿ�֧��ϵͳ����
				/*// ��ȡͼƬ���ڵ�URL
		         URL url = CapturerTray.class.getResource("aa.png");
		         // ʵ����ͼ�����
		         ImageIcon icon = new ImageIcon(url);
		         // ���Image����
		         Image image = icon.getImage();
		         // ��������ͼ��
		         */
		         
		         ImageIcon icon = new ImageIcon("tp.png"); //ͼ���� 16��16 ��ͼƬ
		       //�������ע�͵Ĵ��룬img �ļ��� CapturerTray.class �ļ���һ��Ŀ¼��
		       //URL imgURL = getClass().getResource("capture.jpg");
		       Image image = icon.getImage(); // ��� Image ����
		       
		         TrayIcon trayIcon = new TrayIcon(image);
		         PopupMenu popupMenu = new PopupMenu(); // ���������˵�
				capture = new MenuItem("��ͼ"); // �����˵���
				exit = new MenuItem("�˳�");
				fcapture= new MenuItem("��ͼ��ݼ� Alt+Z");
				fexit = new MenuItem("�˳���ݼ� Alt+Q");
				popupMenu.add(fcapture); 
				popupMenu.add(fexit); 
				popupMenu.add(capture); // Ϊ�����˵���Ӳ˵���
				popupMenu.add(exit); // Ϊ�����˵���Ӳ˵���
				trayIcon.setPopupMenu(popupMenu); // Ϊ����ͼ��ӵ����˵�
				trayIcon.setToolTip("��Ļ��ͼ����"); // ��ӹ�����ʾ�ı�
				//��ʾ����
				SystemTray systemTray = SystemTray.getSystemTray(); // ���ϵͳ���̶���
				try {
				systemTray.add(trayIcon); // Ϊϵͳ�������ͼ��
				} 
				catch (Exception e) {
				e.printStackTrace();
				}
		}
	}
	public void setKey(){ 	
		JIntellitype.getInstance().registerHotKey(FUNC_KEY_MARK,JIntellitype.MOD_ALT, (int)'Z');  
		JIntellitype.getInstance().registerHotKey(EXIT_KEY_MARK, JIntellitype.MOD_ALT, (int)'Q');  
	}
	
	public void addListener(){
		//��ݼ�����
		
		//�˳��˵����¼�����
		exit.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
			// TODO Auto-generated method stub
			System.exit(0);
		}
		});
		//��ͼ�˵����¼�����
		capture.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				try {
				//������Ļͼ�񣬴��ݸ� ImageCapture ����
				new ImageCapture();
				} catch (Exception e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
				}
			}
		});
		JIntellitype.getInstance().addHotKeyListener(new HotkeyListener() {           
			             @Override
            public void onHotKey(int markCode) {
                 switch (markCode) {  
                 case FUNC_KEY_MARK:  
                	 new ImageCapture();
                     break;  
                 case EXIT_KEY_MARK:  
                   System.exit(0);
                   break;   
                 }                 
             }
         });  
		
	}
}