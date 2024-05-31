/*
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2024-05-31 22:03:05
 * @FilePath: \java BasicHomework\�ϻ�ʵ��\ʵ��� ʹ��JDBC�������ݿ����\JDBC�ۺ�Ӧ��-ʵ�ּ򵥽��������ݿ�Ľ���\src\dao\UserDao.java
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
package dao;

import model.User;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

/**
 * UserDao���ṩ���û���Ϣ���в����ķ�������������û��Ƿ���ڡ�����û���ѡ���û���
 */
public class UserDao {

    /**
     * ����û����Ƿ��Ѵ��������ݿ��С�
     *
     * @param con ���ݿ����Ӷ���
     * @param userName Ҫ�����û���
     * @return ����û������ڷ���true�����򷵻�false
     * @throws SQLException ���SQL��ѯ�����з�������
     */
    public boolean userCheck(Connection con, String userName) throws SQLException {
        // SQL��ѯ��䣬����û����Ƿ����
        String sql = "SELECT * FROM user_table WHERE userName=?";
        // ʹ��try-with-resources����Զ��ر�PreparedStatement��ResultSet
        try (PreparedStatement pstmt = con.prepareStatement(sql)) {
            // ���ò�ѯ����еĲ���
            pstmt.setString(1, userName);
            // ִ�в�ѯ�����ؽ����
            try (ResultSet rs = pstmt.executeQuery()) {
                // ���������������ݣ�˵���û����Ѵ���
                return rs.next();
            }
        }
    }

    /**
     * ������û������ݿ��С�
     *
     * @param con ���ݿ����Ӷ���
     * @param user Ҫ��ӵ��û�����
     * @throws SQLException ���SQL��������з�������
     */
    public void userAdd(Connection con, User user) throws SQLException {
        // SQL������䣬���û������û�������뵽���ݿ�
        String sql = "INSERT INTO user_table(userName, userPsw) VALUES(?, ?)";
        // ʹ��try-with-resources����Զ��ر�PreparedStatement
        try (PreparedStatement pstmt = con.prepareStatement(sql)) {
            // ���ò�������еĲ���
            pstmt.setString(1, user.getUserName());
            pstmt.setString(2, user.getUserPwd());
            // ִ�в������
            pstmt.executeUpdate();
        }
    }

    /**
     * �����ݿ���ѡ���û���Ϣ�������û���¼��֤��
     *
     * @param con ���ݿ����Ӷ���
     * @param user �����û�����������û�����
     * @return ����û���������ƥ�䣬���ض�Ӧ���û����󣻷��򷵻�null
     * @throws SQLException ���SQL��ѯ�����з�������
     */
    public User userSelect(Connection con, User user) throws SQLException {
        // SQL��ѯ��䣬ѡ���û���������ƥ����û�
        String sql = "SELECT * FROM user_table WHERE userName=? AND userPsw=?";
        // ʹ��try-with-resources����Զ��ر�PreparedStatement��ResultSet
        try (PreparedStatement pstmt = con.prepareStatement(sql)) {
            // ���ò�ѯ����еĲ���
            pstmt.setString(1, user.getUserName());
            pstmt.setString(2, user.getUserPwd());
            // ִ�в�ѯ�����ؽ����
            try (ResultSet rs = pstmt.executeQuery()) {
                // ���������������ݣ�˵���û���������ƥ��
                if (rs.next()) {
                    // ����ƥ����û�����
                    return new User(rs.getString("userName"), rs.getString("userPsw"));
                } else {
                    // ���û��ƥ������ݣ�����null
                    return null;
                }
            }
        }
    }
}
