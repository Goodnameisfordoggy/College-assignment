/*
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2024-05-26 17:48:55
 * @FilePath: \java BasicHomework\上机实验\实验九 使用JDBC进行数据库操作\JDBC综合应用-实现简单界面与数据库的交互\src\view\Register.java
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

        JLabel lblNewLabel = new JLabel("注册新用户");
        lblNewLabel.setBounds(177, 28, 120, 20);
        lblNewLabel.setFont(new Font("", Font.BOLD, 18));
        contentPane.add(lblNewLabel);

        JLabel lblNewLabel_1 = new JLabel("用户名");
        lblNewLabel_1.setBounds(135, 77, 82, 15);
        contentPane.add(lblNewLabel_1);

        textField = new JTextField();
        textField.setBounds(193, 74, 120, 21);
        contentPane.add(textField);
        textField.setColumns(10);

        JLabel lblNewLabel_2 = new JLabel("密码");
        lblNewLabel_2.setBounds(145, 108, 54, 15);
        contentPane.add(lblNewLabel_2);

        psdTextField = new JPasswordField();
        psdTextField.setBounds(193, 105, 120, 21);
        contentPane.add(psdTextField);
        psdTextField.setColumns(10);

        JLabel lblNewLabel_3 = new JLabel("确认密码");
        lblNewLabel_3.setBounds(129, 145, 54, 15);
        contentPane.add(lblNewLabel_3);

        psdTextField02 = new JPasswordField();
        psdTextField02.setBounds(193, 142, 120, 21);
        contentPane.add(psdTextField02);
        psdTextField02.setColumns(10);

        JButton btnNewButton = new JButton("确定");
        btnNewButton.setBounds(124, 183, 93, 23);
        contentPane.add(btnNewButton);

        JButton btnNewButton_1 = new JButton("取消");
        btnNewButton_1.setBounds(242, 183, 93, 23);
        contentPane.add(btnNewButton_1);

        // 为“确定”按钮添加事件监听器
		btnNewButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				// 获取用户名和两次输入的密码
				String userName = textField.getText();
				String userPwd = new String(psdTextField.getPassword());
				String userPwdConfirm = new String(psdTextField02.getPassword());

				// 检查是否所有字段均已填
				if (userName.isEmpty() || userPwd.isEmpty() || userPwdConfirm.isEmpty()) {
					JOptionPane.showMessageDialog(null, "所有字段均为必填");
					return; // 如果有未填字段，显示提示信息并返回
				}

				// 检查两次密码输入是否一致
				if (!userPwd.equals(userPwdConfirm)) {
					JOptionPane.showMessageDialog(null, "两次密码输入不一致");
					return; // 如果密码不一致，显示提示信息并返回
				}

				// 尝试获取数据库连接，并执行数据库操作
				try (Connection con = DbUtil.getConnection()) {
					UserDao userDao = new UserDao();
					// 检查用户名是否已存在
					if (userDao.userCheck(con, userName)) {
						JOptionPane.showMessageDialog(null, "用户名已存在");
						return; // 如果用户名已存在，显示提示信息并返回
					}
					// 创建新的User对象
					User user = new User(userName, userPwd);
					// 将新用户添加到数据库
					userDao.userAdd(con, user);
					// 显示注册成功的提示信息
					JOptionPane.showMessageDialog(null, "注册成功");
					// 关闭当前注册窗口
					dispose();
				} catch (SQLException ex) {
					ex.printStackTrace();
				}
			}
		});

		// 为“取消”按钮添加事件监听器
		btnNewButton_1.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				// 清空所有输入字段
				textField.setText("");
				psdTextField.setText("");
				psdTextField02.setText("");
			}
		});


        setVisible(true);
    }
}

