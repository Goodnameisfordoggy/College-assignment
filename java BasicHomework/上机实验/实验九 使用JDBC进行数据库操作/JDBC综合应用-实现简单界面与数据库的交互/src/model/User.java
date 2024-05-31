/*
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2024-05-26 17:11:10
 * @FilePath: \java BasicHomework\上机实验\实验九 使用JDBC进行数据库操作\JDBC综合应用-实现简单界面与数据库的交互\src\model\User.java
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
package model;

/**
 * User类表示一个用户对象，包含用户名和密码。
 */
public class User {
    // 用户名
    private String userName;
    // 用户密码
    private String userPwd;

    /**
     * 构造方法，初始化用户名和密码。
     *
     * @param userName 用户名
     * @param userPwd 用户密码
     */
    public User(String userName, String userPwd) {
        this.userName = userName;
        this.userPwd = userPwd;
    }

    /**
     * 获取用户名。
     *
     * @return 用户名
     */
    public String getUserName() {
        return userName;
    }

    /**
     * 设置用户名。
     *
     * @param userName 新的用户名
     */
    public void setUserName(String userName) {
        this.userName = userName;
    }

    /**
     * 获取用户密码。
     *
     * @return 用户密码
     */
    public String getUserPwd() {
        return userPwd;
    }

    /**
     * 设置用户密码。
     *
     * @param userPwd 新的用户密码
     */
    public void setUserPwd(String userPwd) {
        this.userPwd = userPwd;
    }
}
