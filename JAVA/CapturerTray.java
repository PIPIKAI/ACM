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
		if (SystemTray.isSupported()) { // 判断是否支持系统托盘
				/*// 获取图片所在的URL
		         URL url = CapturerTray.class.getResource("aa.png");
		         // 实例化图像对象
		         ImageIcon icon = new ImageIcon(url);
		         // 获得Image对象
		         Image image = icon.getImage();
		         // 创建托盘图标
		         */
		         
		         ImageIcon icon = new ImageIcon("tp.png"); //图标用 16×16 的图片
		       //打包请用注释的代码，img 文件与 CapturerTray.class 文件在一个目录中
		       //URL imgURL = getClass().getResource("capture.jpg");
		       Image image = icon.getImage(); // 获得 Image 对象
		       
		         TrayIcon trayIcon = new TrayIcon(image);
		         PopupMenu popupMenu = new PopupMenu(); // 创建弹出菜单
				capture = new MenuItem("截图"); // 创建菜单项
				exit = new MenuItem("退出");
				fcapture= new MenuItem("截图快捷键 Alt+Z");
				fexit = new MenuItem("退出快捷键 Alt+Q");
				popupMenu.add(fcapture); 
				popupMenu.add(fexit); 
				popupMenu.add(capture); // 为弹出菜单添加菜单项
				popupMenu.add(exit); // 为弹出菜单添加菜单项
				trayIcon.setPopupMenu(popupMenu); // 为托盘图标加弹出菜弹
				trayIcon.setToolTip("屏幕截图工具"); // 添加工具提示文本
				//显示托盘
				SystemTray systemTray = SystemTray.getSystemTray(); // 获得系统托盘对象
				try {
				systemTray.add(trayIcon); // 为系统托盘添加图标
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
		//快捷键监听
		
		//退出菜单项事件监听
		exit.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
			// TODO Auto-generated method stub
			System.exit(0);
		}
		});
		//截图菜单项事件监听
		capture.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				try {
				//捕获屏幕图像，传递给 ImageCapture 处理
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