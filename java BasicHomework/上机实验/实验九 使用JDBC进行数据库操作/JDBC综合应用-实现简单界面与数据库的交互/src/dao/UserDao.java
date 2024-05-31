/*
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2024-05-31 22:03:05
 * @FilePath: \java BasicHomework\上机实验\实验九 使用JDBC进行数据库操作\JDBC综合应用-实现简单界面与数据库的交互\src\dao\UserDao.java
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
package dao;

import model.User;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

/**
 * UserDao类提供对用户信息进行操作的方法，包括检查用户是否存在、添加用户和选择用户。
 */
public class UserDao {

    /**
     * 检查用户名是否已存在于数据库中。
     *
     * @param con 数据库连接对象
     * @param userName 要检查的用户名
     * @return 如果用户名存在返回true，否则返回false
     * @throws SQLException 如果SQL查询过程中发生错误
     */
    public boolean userCheck(Connection con, String userName) throws SQLException {
        // SQL查询语句，检查用户名是否存在
        String sql = "SELECT * FROM user_table WHERE userName=?";
        // 使用try-with-resources语句自动关闭PreparedStatement和ResultSet
        try (PreparedStatement pstmt = con.prepareStatement(sql)) {
            // 设置查询语句中的参数
            pstmt.setString(1, userName);
            // 执行查询并返回结果集
            try (ResultSet rs = pstmt.executeQuery()) {
                // 如果结果集中有数据，说明用户名已存在
                return rs.next();
            }
        }
    }

    /**
     * 添加新用户到数据库中。
     *
     * @param con 数据库连接对象
     * @param user 要添加的用户对象
     * @throws SQLException 如果SQL插入过程中发生错误
     */
    public void userAdd(Connection con, User user) throws SQLException {
        // SQL插入语句，将用户名和用户密码插入到数据库
        String sql = "INSERT INTO user_table(userName, userPsw) VALUES(?, ?)";
        // 使用try-with-resources语句自动关闭PreparedStatement
        try (PreparedStatement pstmt = con.prepareStatement(sql)) {
            // 设置插入语句中的参数
            pstmt.setString(1, user.getUserName());
            pstmt.setString(2, user.getUserPwd());
            // 执行插入操作
            pstmt.executeUpdate();
        }
    }

    /**
     * 从数据库中选择用户信息，用于用户登录验证。
     *
     * @param con 数据库连接对象
     * @param user 包含用户名和密码的用户对象
     * @return 如果用户名和密码匹配，返回对应的用户对象；否则返回null
     * @throws SQLException 如果SQL查询过程中发生错误
     */
    public User userSelect(Connection con, User user) throws SQLException {
        // SQL查询语句，选择用户名和密码匹配的用户
        String sql = "SELECT * FROM user_table WHERE userName=? AND userPsw=?";
        // 使用try-with-resources语句自动关闭PreparedStatement和ResultSet
        try (PreparedStatement pstmt = con.prepareStatement(sql)) {
            // 设置查询语句中的参数
            pstmt.setString(1, user.getUserName());
            pstmt.setString(2, user.getUserPwd());
            // 执行查询并返回结果集
            try (ResultSet rs = pstmt.executeQuery()) {
                // 如果结果集中有数据，说明用户名和密码匹配
                if (rs.next()) {
                    // 返回匹配的用户对象
                    return new User(rs.getString("userName"), rs.getString("userPsw"));
                } else {
                    // 如果没有匹配的数据，返回null
                    return null;
                }
            }
        }
    }
}
