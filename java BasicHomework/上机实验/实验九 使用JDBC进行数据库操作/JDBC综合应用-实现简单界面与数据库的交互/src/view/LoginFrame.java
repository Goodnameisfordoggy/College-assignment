/*
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2024-05-26 17:41:40
 * @FilePath: \java BasicHomework\�ϻ�ʵ��\ʵ��� ʹ��JDBC�������ݿ����\JDBC�ۺ�Ӧ��-ʵ�ּ򵥽��������ݿ�Ľ���\src\view\LoginFrame.java
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

import javax.swing.*;
import javax.swing.border.TitledBorder;
import java.awt.Color;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.Connection;
import java.sql.SQLException;
import util.DbUtil;
import model.User;
import dao.UserDao;

public class LoginFrame extends JFrame {
    private JTextField textField;
    private JPasswordField passwordField;

    public static void main(String[] args) {
        LoginFrame frame = new LoginFrame();
        frame.setVisible(true); // ���ô���ɼ���Ĭ��Ϊ���ɼ�
    }

    public LoginFrame() {
        super(); // �̳и���Ĺ��췽��
        setTitle("��¼����");
        setBounds(100, 100, 260, 210); // ���ô������ʾλ�ü���С
        getContentPane().setLayout(null); // ����Ϊ�������κβ��ֹ�����
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        final JLabel label = new JLabel();
        label.setBorder(new TitledBorder(null, "", TitledBorder.DEFAULT_JUSTIFICATION,
                TitledBorder.DEFAULT_POSITION, null, null));
        label.setForeground(new Color(255, 0, 0));
        label.setFont(new Font("", Font.BOLD, 18));
        label.setText("��ҵ���¹���ϵͳ");
        label.setBounds(39, 28, 170, 36); // ���á���ҵ���¹���ϵͳ����ǩ����ʾλ�ü���С
        getContentPane().add(label);

        final JLabel usernameLabel = new JLabel();
        usernameLabel.setText("�û�����");
        usernameLabel.setBounds(38, 83, 60, 15); // ���á��û�������ǩ����ʾλ�ü���С
        getContentPane().add(usernameLabel);

        textField = new JTextField();
        textField.setBounds(89, 80, 120, 21); // ���á��û������ı������ʾλ�ü���С
        getContentPane().add(textField);

        final JLabel passwordLabel = new JLabel();
        passwordLabel.setText("��  �룺");
        passwordLabel.setBounds(39, 107, 60, 15); // ���á��� �롱��ǩ����ʾλ�ü���С
        getContentPane().add(passwordLabel);

        passwordField = new JPasswordField();
        passwordField.setBounds(89, 104, 120, 21); // ���á��� �롱��������ʾλ�ü���С
        getContentPane().add(passwordField);

        final JButton RegisterButton = new JButton();
        RegisterButton.setText("ע��");
        RegisterButton.setBounds(141, 131, 68, 23); // ���á�ע�ᡱ��ť����ʾλ�ü���С
        getContentPane().add(RegisterButton);

        final JButton landButton = new JButton();
        landButton.setText("��¼");
        landButton.setBounds(67, 131, 68, 23); // ���á���¼����ť����ʾλ�ü���С
        getContentPane().add(landButton);

        landButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                // ��ȡ�û���������������е�ֵ
                String userName = textField.getText();
                String userPwd = new String(passwordField.getPassword());
        
                // ����û����������Ƿ�Ϊ��
                if (userName.isEmpty() || userPwd.isEmpty()) {
                    JOptionPane.showMessageDialog(null, "�û��������벻��Ϊ��");
                    return; // ���Ϊ�գ�����ʾ��ʾ��Ϣ������
                }
        
                // ����һ���µ��û�����ʹ��������û���������
                User user = new User(userName, userPwd);
        
                // ʹ��try-with-resources��䣬ȷ�����ݿ�������ʹ�ú�ر�
                try (Connection con = DbUtil.getConnection()) {
                    // ����UserDao�������ڲ������ݿ�
                    UserDao userDao = new UserDao();
        
                    // ����û��Ƿ���ڲ�������ƥ��
                    User currentUser = userDao.userSelect(con, user);
                    if (currentUser != null) {
                        // ����û����ڲ�������ƥ�䣬����ʾ������
                        new MainFrame().setVisible(true);
                        // �رյ�ǰ��¼����
                        dispose();
                    } else {
                        // ����û������ڻ������벻ƥ�䣬����ʾ������Ϣ
                        JOptionPane.showMessageDialog(null, "�û������������");
                    }
                } catch (SQLException ex) {
                    // �������SQL�쳣����ӡ��ջ������Ϣ
                    ex.printStackTrace();
                }
            }
        });
        

        RegisterButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                new Register().setVisible(true);
                dispose();
            }
        });

        setVisible(true);
    }
}

