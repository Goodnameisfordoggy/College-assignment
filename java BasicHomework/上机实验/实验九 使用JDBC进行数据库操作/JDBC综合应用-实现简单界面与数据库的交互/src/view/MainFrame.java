/*
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2024-05-26 17:57:45
 * @FilePath: \java BasicHomework\上机实验\实验九 使用JDBC进行数据库操作\JDBC综合应用-实现简单界面与数据库的交互\src\view\MainFrame.java
 * @Description: 
 * 
 * 				*		写字楼里写字间，写字间里程序员；
 * 				*		程序人员写程序，又拿程序换酒钱。
 * 				*		酒醒只在网上坐，酒醉还来网下眠；
 * 				*		酒醉酒醒日复日，网上网下年复年。
 * 				*		但愿老死电脑间，不愿鞠躬老板前；
 * 				*		奔驰宝马贵者趣，公交自行程序员。
 * 				*		别人笑我忒疯癫，我笑自己命太贱；
 * 				*		不见满街漂亮妹，哪个归得程序员？    
 * Copyright (c) 2024 by HDJ, All Rights Reserved. 
 */
package view;

import javax.swing.JFrame;
import javax.swing.JLabel;
import java.awt.Color;
import java.awt.Font;

public class MainFrame extends JFrame {
	public MainFrame() {
		super(); // 继承父类的构造方法
		setTitle("主窗口");
		setBounds(100, 100, 260, 210); // 设置窗体的显示位置及大小
		getContentPane().setLayout(null); // 设置为不采用任何布局管理器
		setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
		final JLabel label = new JLabel();
		label.setForeground(new Color(255, 0, 0));
		label.setFont(new Font("", Font.BOLD, 18));
		label.setText("欢迎进入主窗口");
		label.setBounds(39, 28, 170, 36); 
		getContentPane().add(label);
	}
}