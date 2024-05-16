/*
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2024-05-16 16:23:06
 * @FilePath: \java BasicHomework\????\??? ??????\ViewsTest.java
 * @Description: 
 * 
 * 				*		????????????????
 * 				*		????????????????
 * 				*		????????????????
 * 				*		????????????????
 * 				*		????????????????
 * 				*		????????????????
 * 				*		????????????????
 * 				*		????????????????    
 * Copyright (c) 2024 by HDJ, All Rights Reserved. 
 */
import javax.swing.*;
import java.awt.event.*;
import java.awt.*;
import javax.swing.border.EmptyBorder;

class Views extends JFrame {
    private JPanel contentPane;
    private JTextField textField, textField_1, textField_2;	
    private JLabel lblNewLabel, lblNewLabe2;	

    Views() {
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setBounds(100, 100, 450, 300);
        contentPane = new JPanel();
        contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
        setContentPane(contentPane);
        contentPane.setLayout(null);		

        textField = new JTextField();
        textField.setBounds(102, 10, 66, 21);
        contentPane.add(textField);
        textField.setColumns(10);		

        lblNewLabel = new JLabel("+");
        lblNewLabel.setBounds(173, 13, 15, 20);
        contentPane.add(lblNewLabel);		

        textField_1 = new JTextField();
        textField_1.setBounds(184, 10, 66, 21);
        contentPane.add(textField_1);
        textField_1.setColumns(10);		

        lblNewLabe2 = new JLabel("=");
        lblNewLabe2.setBounds(255, 13, 15, 20);
        contentPane.add(lblNewLabe2);		

        textField_2 = new JTextField();
        textField_2.setBounds(266, 10, 66, 21);
        contentPane.add(textField_2);
        textField_2.setColumns(10);		

        JButton btnNewButton = new JButton("¼ÆËã");
        btnNewButton.setBounds(168, 83, 93, 23);
        contentPane.add(btnNewButton);

        // ÎªbtnNewButtonÌí¼Ó¼àÌýÆ÷ addActionListener
        btnNewButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String s1 = textField.getText().trim();
                String s2 = textField_1.getText().trim();
                int num1 = Integer.parseInt(s1);
                int num2 = Integer.parseInt(s2);
                int sum = num1 + num2;
                textField_2.setText(String.valueOf(sum));
            }
        });
    }
}

public class ViewsTest {
    public static void main(String[] args) {
        Views frame = new Views();
        frame.setVisible(true);
    }
}
