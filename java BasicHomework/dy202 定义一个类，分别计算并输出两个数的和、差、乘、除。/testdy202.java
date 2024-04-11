/*
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2024-04-11 22:33:52
 * @FilePath: \java BasicHomework\dy202 定义一个类，分别计算并输出两个数的和、差、乘、除。\test.java
 * @Description: 1）定义一个compute类，该类具有x和y两个静态变量，定义构造方法初始化这两个变量；再定义4个方法，分别求这两个数的和、差、乘、处结果并输出。
（2）在main方法中，用户应能输入两个数，根据数入的数进行相应的运算。（已知代码如下）

 请注意，main()函数与给定函数必须按如下所示编写：
public class test {
    public static void main(String[] args) {
        System.out.println("Please enter two numbers:");
        Scanner in = new Scanner(System.in);
        Compute data = new Compute(in.nextInt(), in.nextInt()); 
        data.add();
        data.sub();
        data.Multiplication();
        data.division();
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

class Compute {
    private static int x;
    private static int y;

    public Compute(int x, int y) {
        Compute.x = x;
        Compute.y = y;
    }

    public void add() {
        int result = x + y;
        System.out.println("x+y=" + result);
    }

    public void sub() {
        int result = x - y;
        System.out.println("x-y=" + result);
    }

    public void Multiplication() {
        int result = x * y;
        System.out.println("x*y=" + result);
    }

    public void division() {
        if (y != 0) {
            int result = (int) x / y;
            System.out.println("x/y=" + result);
        } else {
            System.out.println("Division by zero is undefined.");
        }
    }
}

public class testdy202 {
    public static void main(String[] args) {
        System.out.println("Please enter two numbers:");
        Scanner in = new Scanner(System.in);
        Compute data = new Compute(in.nextInt(), in.nextInt()); 
        data.add();
        data.sub();
        data.Multiplication();
        data.division();
        in.close();
    }
}