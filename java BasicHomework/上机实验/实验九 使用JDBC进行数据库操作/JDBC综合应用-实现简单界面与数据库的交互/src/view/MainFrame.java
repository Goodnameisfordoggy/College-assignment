/*
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2024-05-26 17:57:45
 * @FilePath: \java BasicHomework\�ϻ�ʵ��\ʵ��� ʹ��JDBC�������ݿ����\JDBC�ۺ�Ӧ��-ʵ�ּ򵥽��������ݿ�Ľ���\src\view\MainFrame.java
 * @Description: 
 * 
 * 				*		д��¥��д�ּ䣬д�ּ������Ա��
 * 				*		������Աд�������ó��򻻾�Ǯ��
 * 				*		����ֻ���������������������ߣ�
 * 				*		��������ո��գ����������긴�ꡣ
 * 				*		��Ը�������Լ䣬��Ը�Ϲ��ϰ�ǰ��
 * 				*		���۱������Ȥ���������г���Ա��
 * 				*		����Ц��߯��񲣬��Ц�Լ���̫����
 * 				*		��������Ư���ã��ĸ���ó���Ա��    
 * Copyright (c) 2024 by HDJ, All Rights Reserved. 
 */
package view;

import javax.swing.JFrame;
import javax.swing.JLabel;
import java.awt.Color;
import java.awt.Font;

public class MainFrame extends JFrame {
	public MainFrame() {
		super(); // �̳и���Ĺ��췽��
		setTitle("������");
		setBounds(100, 100, 260, 210); // ���ô������ʾλ�ü���С
		getContentPane().setLayout(null); // ����Ϊ�������κβ��ֹ�����
		setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
		final JLabel label = new JLabel();
		label.setForeground(new Color(255, 0, 0));
		label.setFont(new Font("", Font.BOLD, 18));
		label.setText("��ӭ����������");
		label.setBounds(39, 28, 170, 36); 
		getContentPane().add(label);
	}
}