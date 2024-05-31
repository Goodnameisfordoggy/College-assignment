/*
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2024-05-26 17:11:10
 * @FilePath: \java BasicHomework\�ϻ�ʵ��\ʵ��� ʹ��JDBC�������ݿ����\JDBC�ۺ�Ӧ��-ʵ�ּ򵥽��������ݿ�Ľ���\src\model\User.java
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
package model;

/**
 * User���ʾһ���û����󣬰����û��������롣
 */
public class User {
    // �û���
    private String userName;
    // �û�����
    private String userPwd;

    /**
     * ���췽������ʼ���û��������롣
     *
     * @param userName �û���
     * @param userPwd �û�����
     */
    public User(String userName, String userPwd) {
        this.userName = userName;
        this.userPwd = userPwd;
    }

    /**
     * ��ȡ�û�����
     *
     * @return �û���
     */
    public String getUserName() {
        return userName;
    }

    /**
     * �����û�����
     *
     * @param userName �µ��û���
     */
    public void setUserName(String userName) {
        this.userName = userName;
    }

    /**
     * ��ȡ�û����롣
     *
     * @return �û�����
     */
    public String getUserPwd() {
        return userPwd;
    }

    /**
     * �����û����롣
     *
     * @param userPwd �µ��û�����
     */
    public void setUserPwd(String userPwd) {
        this.userPwd = userPwd;
    }
}
