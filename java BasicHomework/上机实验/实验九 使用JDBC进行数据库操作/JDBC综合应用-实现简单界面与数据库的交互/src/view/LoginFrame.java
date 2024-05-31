/*
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2024-05-26 17:41:40
 * @FilePath: \java BasicHomework\上机实验\实验九 使用JDBC进行数据库操作\JDBC综合应用-实现简单界面与数据库的交互\src\view\LoginFrame.java
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
        frame.setVisible(true); // 设置窗体可见，默认为不可见
    }

    public LoginFrame() {
        super(); // 继承父类的构造方法
        setTitle("登录窗口");
        setBounds(100, 100, 260, 210); // 设置窗体的显示位置及大小
        getContentPane().setLayout(null); // 设置为不采用任何布局管理器
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        final JLabel label = new JLabel();
        label.setBorder(new TitledBorder(null, "", TitledBorder.DEFAULT_JUSTIFICATION,
                TitledBorder.DEFAULT_POSITION, null, null));
        label.setForeground(new Color(255, 0, 0));
        label.setFont(new Font("", Font.BOLD, 18));
        label.setText("企业人事管理系统");
        label.setBounds(39, 28, 170, 36); // 设置“企业人事管理系统”标签的显示位置及大小
        getContentPane().add(label);

        final JLabel usernameLabel = new JLabel();
        usernameLabel.setText("用户名：");
        usernameLabel.setBounds(38, 83, 60, 15); // 设置“用户名”标签的显示位置及大小
        getContentPane().add(usernameLabel);

        textField = new JTextField();
        textField.setBounds(89, 80, 120, 21); // 设置“用户名”文本框的显示位置及大小
        getContentPane().add(textField);

        final JLabel passwordLabel = new JLabel();
        passwordLabel.setText("密  码：");
        passwordLabel.setBounds(39, 107, 60, 15); // 设置“密 码”标签的显示位置及大小
        getContentPane().add(passwordLabel);

        passwordField = new JPasswordField();
        passwordField.setBounds(89, 104, 120, 21); // 设置“密 码”密码框的显示位置及大小
        getContentPane().add(passwordField);

        final JButton RegisterButton = new JButton();
        RegisterButton.setText("注册");
        RegisterButton.setBounds(141, 131, 68, 23); // 设置“注册”按钮的显示位置及大小
        getContentPane().add(RegisterButton);

        final JButton landButton = new JButton();
        landButton.setText("登录");
        landButton.setBounds(67, 131, 68, 23); // 设置“登录”按钮的显示位置及大小
        getContentPane().add(landButton);

        landButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                // 获取用户名和密码输入框中的值
                String userName = textField.getText();
                String userPwd = new String(passwordField.getPassword());
        
                // 检查用户名或密码是否为空
                if (userName.isEmpty() || userPwd.isEmpty()) {
                    JOptionPane.showMessageDialog(null, "用户名或密码不能为空");
                    return; // 如果为空，则显示提示信息并返回
                }
        
                // 创建一个新的用户对象，使用输入的用户名和密码
                User user = new User(userName, userPwd);
        
                // 使用try-with-resources语句，确保数据库连接在使用后关闭
                try (Connection con = DbUtil.getConnection()) {
                    // 创建UserDao对象，用于操作数据库
                    UserDao userDao = new UserDao();
        
                    // 检查用户是否存在并且密码匹配
                    User currentUser = userDao.userSelect(con, user);
                    if (currentUser != null) {
                        // 如果用户存在并且密码匹配，则显示主窗口
                        new MainFrame().setVisible(true);
                        // 关闭当前登录窗口
                        dispose();
                    } else {
                        // 如果用户不存在或者密码不匹配，则显示错误信息
                        JOptionPane.showMessageDialog(null, "用户名或密码错误");
                    }
                } catch (SQLException ex) {
                    // 如果发生SQL异常，打印堆栈跟踪信息
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

