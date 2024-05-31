/*
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2024-05-26 17:21:14
 * @FilePath: \java BasicHomework\�ϻ�ʵ��\ʵ��� ʹ��JDBC�������ݿ����\JDBC�ۺ�Ӧ��-ʵ�ּ򵥽��������ݿ�Ľ���\src\util\DbUtil.java
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
package util;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

// ���ݿ⹤���࣬���ڻ�ȡ���ݿ����Ӻ͹ر�����
public class DbUtil {
    private static final String URL = "jdbc:mysql://localhost:3306/hbgc";   // ���ݿ�����URL
    private static final String USER = "root";    // �û���
    private static final String PASSWORD = "root";   // ����
    
    // ��ȡ���ݿ����ӵľ�̬����
    public static Connection getConnection() throws SQLException {
        // ʹ��DriverManager��ȡ���ݿ����ӣ�������
        return DriverManager.getConnection(URL, USER, PASSWORD);
    }
    
    // �ر����ݿ����ӵľ�̬����
    public static void closeConnection(Connection connection) {
        // ������Ӳ�Ϊnull����ر�����
        if (connection != null) {
            try {
                connection.close();
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
    }
}
