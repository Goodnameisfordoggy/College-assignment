/*
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2024-04-11 22:48:59
 * @FilePath: \java BasicHomework\0504 StringBuffer的使用，判断一个字符串是否对称？\test.java
 * @Description: 题目内容：
提示：反转的方法   public StringBuffer reverse()
测试用例1：
input string:
abcdedcba
输出：
symmetry

测试用例2：
input string:
abdcfhejl
输出：
asymmetric
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

public class test0504 {

    public static String checkSymmetry(String str) {
        String reversed = new StringBuffer(str).reverse().toString();
        if (str.equals(reversed)) {
            return "symmetry"; 
        } else {
            return "asymmetric"; 
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("input string:");
        String inputString = scanner.nextLine();
        scanner.close();

        String result = checkSymmetry(inputString);
        System.out.println(result);
    }
}
