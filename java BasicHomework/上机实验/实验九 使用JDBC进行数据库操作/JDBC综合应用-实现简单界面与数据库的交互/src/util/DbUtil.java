/*
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2024-05-26 17:21:14
 * @FilePath: \java BasicHomework\上机实验\实验九 使用JDBC进行数据库操作\JDBC综合应用-实现简单界面与数据库的交互\src\util\DbUtil.java
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
package util;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

// 数据库工具类，用于获取数据库连接和关闭连接
public class DbUtil {
    private static final String URL = "jdbc:mysql://localhost:3306/hbgc";   // 数据库连接URL
    private static final String USER = "root";    // 用户名
    private static final String PASSWORD = "root";   // 密码
    
    // 获取数据库连接的静态方法
    public static Connection getConnection() throws SQLException {
        // 使用DriverManager获取数据库连接，并返回
        return DriverManager.getConnection(URL, USER, PASSWORD);
    }
    
    // 关闭数据库连接的静态方法
    public static void closeConnection(Connection connection) {
        // 如果连接不为null，则关闭连接
        if (connection != null) {
            try {
                connection.close();
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
    }
}
