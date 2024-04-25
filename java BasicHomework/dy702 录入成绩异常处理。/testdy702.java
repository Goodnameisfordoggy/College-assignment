/*
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2024-04-25 15:24:34
 * @FilePath: \java BasicHomework\dy702 录入成绩异常处理。\test1.java
 * @Description: 
编写一个应用程序，要求输入一个成绩，当输入的成绩不在[0,100]之间时，则抛出异常信息，否则，则显示输入的成绩。
具体要求：
（1）编写一个异常类ScoreException，确定异常信息。
（2）编写一个Teacher类，创建一个check（）方法用来检测是否需要抛出异常。

测试用例1：
输入：-5
输出：please input 0-100
测试用例2：
输入：88
输出：The score is:88
 请注意，main()函数与给定函数必须按如下所示编写：
public class test {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        Teacher t = new Teacher();
        try {
            t.check(in.nextInt());
        } catch (ScoreException e) {
            System.out.println(e.getMessage());
        }
    }
}
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
import java.util.Scanner;

class ScoreException extends Exception {
    public ScoreException() {
        super("please input 0-100");
    }
}

class Teacher {
    public void check(int score) throws ScoreException {
        if (score < 0 || score > 100) {
            throw new ScoreException();
        } else {
            System.out.println("The score is:" + score);
        }
    }
}

public class testdy702 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        Teacher t = new Teacher();
        try {
            System.out.println("请输入成绩：");
            t.check(in.nextInt());
        } catch (ScoreException e) {
            System.out.println(e.getMessage());
        }
        in.close();
    }
}
