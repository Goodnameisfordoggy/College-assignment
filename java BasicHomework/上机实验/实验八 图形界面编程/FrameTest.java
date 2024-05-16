/*
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2024-05-16 16:32:33
 * @FilePath: \java BasicHomework\上机实验\实验八 图形界面编程\FrameTest.java
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
        // 继承父类的构造方法
        super();
        // 设置窗体标题
        setTitle("登录窗口");
        // 设置窗体的显示位置及大小
        setBounds(100, 100, 300, 260);
        // 设置为不采用任何布局管理器
        setLayout(null);
        // 创建面板
        jp = new JPanel();
        // 设置面板位置及大小
        jp.setBounds(0, 0, 260, 240);
        // 窗体中添加面板
        jp.setLayout(null);
        Container contentPane = this.getContentPane();
        contentPane.add(jp);
        // 创建显示“企业人事管理系统”标签，并添加至面板
        label = new JLabel("企业人事管理系统");
        jp.add(label);
        // 设置“企业人事管理系统”标签的字体及颜色
        label.setForeground(new Color(255, 0, 0));
        label.setFont(new Font("", Font.BOLD, 18));
        // 显示位置及大小
        label.setBounds(50, 30, 170, 40);
        // 创建并向面板添加“用户名”标签
        usernameLabel = new JLabel("用户名：");
        jp.add(usernameLabel);
        // 设置“用户名”标签的显示位置及大小
        usernameLabel.setBounds(50, 80, 60, 15);
        // 创建并向面板添加“用户名”输入文本框
        textField = new JTextField();
        jp.add(textField);
        // 设置“用户名”文本框的显示位置及大小
        textField.setBounds(100, 80, 120, 20);
        // 创建“用户名”标签
        passwordLabel = new JLabel("密 码：");
        // 设置“密 码”标签的显示位置及大小
        passwordLabel.setBounds(50, 110, 60, 15);
        // 向面板添加“密 码”标签
        jp.add(passwordLabel);
        // 创建并向面板添加“密码”输入文本框
        passwordField = new JPasswordField();
        // 设置“密 码”密码框的显示位置及大小
        passwordField.setBounds(100, 110, 120, 20);
        jp.add(passwordField);
        // 创建“登录”按钮
        JButton landButton = new JButton("登录");
        // 设置“登录”按钮的显示位置及大小
        landButton.setBounds(60, 150, 70, 25);
        jp.add(landButton);
        // 添加“登录”按钮单击监听器，处理单击事件
        landButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String username = textField.getText();
                String password = new String(passwordField.getPassword());
                if (username.equals("admin") && password.equals("123456")) {
                    MainFrame mainFrame = new MainFrame();
                    mainFrame.setVisible(true);
                    dispose(); // 关闭登录窗体
                } else {
                    JOptionPane.showMessageDialog(null, "用户名或密码错误");
                }
            }
        });
        // 创建“退出”按钮
        JButton exitButton = new JButton("退出");
        // 设置“退出”按钮的显示位置及大小
        exitButton.setBounds(140, 150, 70, 25);
        jp.add(exitButton);
        // 添加“退出”按钮单击监听器，处理单击事件
        exitButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                System.exit(0);
            }
        });
    }
}

// 主窗口窗体
class MainFrame extends JFrame {
    public MainFrame() {
        super(); // 继承父类的构造方法
        setTitle("主窗口");
        setBounds(200, 200, 400, 300); // 设置窗体的显示位置及大小
        getContentPane().setLayout(null); // 设置为不采用任何布局管理器
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        final JLabel label = new JLabel();
        label.setForeground(new Color(255, 0, 0));
        label.setFont(new Font("", Font.BOLD, 18));
        label.setText("欢迎进入主窗口");
        label.setBounds(100, 100, 180, 50); // 设置“企业人事管理系统”标签的显示位置及大小
        getContentPane().add(label);
    }
}

// 测试类
public class FrameTest {
    public static void main(String args[]) {
        // 创建登录窗体
        LoginFrame frame = new LoginFrame();
        // 设置窗体可见
        frame.setVisible(true);
    }
}
