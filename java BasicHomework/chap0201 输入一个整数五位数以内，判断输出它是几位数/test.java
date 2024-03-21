
/*
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2024-03-16 17:27:17
 * @FilePath: \java\test.java
 * @Description: 题目内容：
如
输入:1234，输出:4digits
输入:123456，输出:error
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

public class test {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int num = scanner.nextInt();
        int i = 0;
        while (num > 0) {
            num = num / 10;
            i++;
        }
        if (i <= 5)
            System.out.println(i + "digits");
        else
            System.out.println("error");
        ;

        scanner.close();
    }
}   