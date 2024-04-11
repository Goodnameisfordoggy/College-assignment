
/*
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2024-04-11 22:49:56
 * @FilePath: \java BasicHomework\chap0202 一维数组的使用\test.java
 * @Description: 定义一个实型数组用来存放学生成绩，提示用户确定成绩的个数，根据个数创建数组。
 * 提示用户输入每个成绩，为各数组元素赋值。询问用户要查找第几个同学的成绩，显示相应的查询结果，
 * 如果超出个数范围则进行相应提示。

测试用例： （注意输出带换行）
input n:
3
input1score:70
input2score:80
input3score:90
input number:
2
80

测试用例：
input n:
2
input1score:90
input2score:80
input number:
5
error
 * 
 * 
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

public class testchap0202 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("input n:");
        int[] score = new int[100];
        int i = scanner.nextInt();
        for (int j = 0; j < i; j++) {
            System.out.println("input" + (j + 1) + "score:");
            score[j] = scanner.nextInt();
        }
        System.out.println("input number:");
        int k = scanner.nextInt();
        if (k < i)
            System.out.println(score[k - 1]);
        else
            System.out.println("error");

            scanner.close();
    }
}