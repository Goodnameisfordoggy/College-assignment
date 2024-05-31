/*
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2024-05-26 17:48:55
 * @FilePath: \java BasicHomework\�ϻ�ʵ��\ʵ��� ʹ��JDBC�������ݿ����\JDBC�ۺ�Ӧ��-ʵ�ּ򵥽��������ݿ�Ľ���\src\view\Register.java
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
import javax.swing.border.EmptyBorder;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.Connection;
import java.sql.SQLException;
import util.DbUtil;
import model.User;
import dao.UserDao;

public class Register extends JFrame {
    private JPanel contentPane;
    private JTextField textField;
    private JPasswordField psdTextField;
    private JPasswordField psdTextField02;

    public Register() {
        setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        setBounds(100, 100, 450, 300);
        contentPane = new JPanel();
        contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
        setContentPane(contentPane);
        contentPane.setLayout(null);

        JLabel lblNewLabel = new JLabel("ע�����û�");
        lblNewLabel.setBounds(177, 28, 120, 20);
        lblNewLabel.setFont(new Font("", Font.BOLD, 18));
        contentPane.add(lblNewLabel);

        JLabel lblNewLabel_1 = new JLabel("�û���");
        lblNewLabel_1.setBounds(135, 77, 82, 15);
        contentPane.add(lblNewLabel_1);

        textField = new JTextField();
        textField.setBounds(193, 74, 120, 21);
        contentPane.add(textField);
        textField.setColumns(10);

        JLabel lblNewLabel_2 = new JLabel("����");
        lblNewLabel_2.setBounds(145, 108, 54, 15);
        contentPane.add(lblNewLabel_2);

        psdTextField = new JPasswordField();
        psdTextField.setBounds(193, 105, 120, 21);
        contentPane.add(psdTextField);
        psdTextField.setColumns(10);

        JLabel lblNewLabel_3 = new JLabel("ȷ������");
        lblNewLabel_3.setBounds(129, 145, 54, 15);
        contentPane.add(lblNewLabel_3);

        psdTextField02 = new JPasswordField();
        psdTextField02.setBounds(193, 142, 120, 21);
        contentPane.add(psdTextField02);
        psdTextField02.setColumns(10);

        JButton btnNewButton = new JButton("ȷ��");
        btnNewButton.setBounds(124, 183, 93, 23);
        contentPane.add(btnNewButton);

        JButton btnNewButton_1 = new JButton("ȡ��");
        btnNewButton_1.setBounds(242, 183, 93, 23);
        contentPane.add(btnNewButton_1);

        // Ϊ��ȷ������ť����¼�������
		btnNewButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				// ��ȡ�û������������������
				String userName = textField.getText();
				String userPwd = new String(psdTextField.getPassword());
				String userPwdConfirm = new String(psdTextField02.getPassword());

				// ����Ƿ������ֶξ�����
				if (userName.isEmpty() || userPwd.isEmpty() || userPwdConfirm.isEmpty()) {
					JOptionPane.showMessageDialog(null, "�����ֶξ�Ϊ����");
					return; // �����δ���ֶΣ���ʾ��ʾ��Ϣ������
				}

				// ����������������Ƿ�һ��
				if (!userPwd.equals(userPwdConfirm)) {
					JOptionPane.showMessageDialog(null, "�����������벻һ��");
					return; // ������벻һ�£���ʾ��ʾ��Ϣ������
				}

				// ���Ի�ȡ���ݿ����ӣ���ִ�����ݿ����
				try (Connection con = DbUtil.getConnection()) {
					UserDao userDao = new UserDao();
					// ����û����Ƿ��Ѵ���
					if (userDao.userCheck(con, userName)) {
						JOptionPane.showMessageDialog(null, "�û����Ѵ���");
						return; // ����û����Ѵ��ڣ���ʾ��ʾ��Ϣ������
					}
					// �����µ�User����
					User user = new User(userName, userPwd);
					// �����û���ӵ����ݿ�
					userDao.userAdd(con, user);
					// ��ʾע��ɹ�����ʾ��Ϣ
					JOptionPane.showMessageDialog(null, "ע��ɹ�");
					// �رյ�ǰע�ᴰ��
					dispose();
				} catch (SQLException ex) {
					ex.printStackTrace();
				}
			}
		});

		// Ϊ��ȡ������ť����¼�������
		btnNewButton_1.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				// ������������ֶ�
				textField.setText("");
				psdTextField.setText("");
				psdTextField02.setText("");
			}
		});


        setVisible(true);
    }
}

