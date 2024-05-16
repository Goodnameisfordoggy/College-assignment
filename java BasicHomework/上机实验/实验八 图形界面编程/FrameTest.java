/*
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2024-05-16 16:32:33
 * @FilePath: \java BasicHomework\�ϻ�ʵ��\ʵ��� ͼ�ν�����\FrameTest.java
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

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

class LoginFrame extends JFrame {
    private JTextField textField;
    private JPasswordField passwordField;
    private JLabel label, usernameLabel, passwordLabel;
    private JPanel jp;

    public LoginFrame() {
        // �̳и���Ĺ��췽��
        super();
        // ���ô������
        setTitle("��¼����");
        // ���ô������ʾλ�ü���С
        setBounds(100, 100, 300, 260);
        // ����Ϊ�������κβ��ֹ�����
        setLayout(null);
        // �������
        jp = new JPanel();
        // �������λ�ü���С
        jp.setBounds(0, 0, 260, 240);
        // ������������
        jp.setLayout(null);
        Container contentPane = this.getContentPane();
        contentPane.add(jp);
        // ������ʾ����ҵ���¹���ϵͳ����ǩ������������
        label = new JLabel("��ҵ���¹���ϵͳ");
        jp.add(label);
        // ���á���ҵ���¹���ϵͳ����ǩ�����弰��ɫ
        label.setForeground(new Color(255, 0, 0));
        label.setFont(new Font("", Font.BOLD, 18));
        // ��ʾλ�ü���С
        label.setBounds(50, 30, 170, 40);
        // �������������ӡ��û�������ǩ
        usernameLabel = new JLabel("�û�����");
        jp.add(usernameLabel);
        // ���á��û�������ǩ����ʾλ�ü���С
        usernameLabel.setBounds(50, 80, 60, 15);
        // �������������ӡ��û����������ı���
        textField = new JTextField();
        jp.add(textField);
        // ���á��û������ı������ʾλ�ü���С
        textField.setBounds(100, 80, 120, 20);
        // �������û�������ǩ
        passwordLabel = new JLabel("�� �룺");
        // ���á��� �롱��ǩ����ʾλ�ü���С
        passwordLabel.setBounds(50, 110, 60, 15);
        // �������ӡ��� �롱��ǩ
        jp.add(passwordLabel);
        // �������������ӡ����롱�����ı���
        passwordField = new JPasswordField();
        // ���á��� �롱��������ʾλ�ü���С
        passwordField.setBounds(100, 110, 120, 20);
        jp.add(passwordField);
        // ��������¼����ť
        JButton landButton = new JButton("��¼");
        // ���á���¼����ť����ʾλ�ü���С
        landButton.setBounds(60, 150, 70, 25);
        jp.add(landButton);
        // ��ӡ���¼����ť�������������������¼�
        landButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String username = textField.getText();
                String password = new String(passwordField.getPassword());
                if (username.equals("admin") && password.equals("123456")) {
                    MainFrame mainFrame = new MainFrame();
                    mainFrame.setVisible(true);
                    dispose(); // �رյ�¼����
                } else {
                    JOptionPane.showMessageDialog(null, "�û������������");
                }
            }
        });
        // �������˳�����ť
        JButton exitButton = new JButton("�˳�");
        // ���á��˳�����ť����ʾλ�ü���С
        exitButton.setBounds(140, 150, 70, 25);
        jp.add(exitButton);
        // ��ӡ��˳�����ť�������������������¼�
        exitButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                System.exit(0);
            }
        });
    }
}

// �����ڴ���
class MainFrame extends JFrame {
    public MainFrame() {
        super(); // �̳и���Ĺ��췽��
        setTitle("������");
        setBounds(200, 200, 400, 300); // ���ô������ʾλ�ü���С
        getContentPane().setLayout(null); // ����Ϊ�������κβ��ֹ�����
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        final JLabel label = new JLabel();
        label.setForeground(new Color(255, 0, 0));
        label.setFont(new Font("", Font.BOLD, 18));
        label.setText("��ӭ����������");
        label.setBounds(100, 100, 180, 50); // ���á���ҵ���¹���ϵͳ����ǩ����ʾλ�ü���С
        getContentPane().add(label);
    }
}

// ������
public class FrameTest {
    public static void main(String args[]) {
        // ������¼����
        LoginFrame frame = new LoginFrame();
        // ���ô���ɼ�
        frame.setVisible(true);
    }
}
