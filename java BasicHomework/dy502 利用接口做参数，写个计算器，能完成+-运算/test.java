/*
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2024-04-11 15:36:17
 * @FilePath: \java BasicHomework\dy502 利用接口做参数，写个计算器，能完成+-运算\test.java
 * @Description: 
1、定义一个接口Compute含有一个方法int computer(int n,int m);
2、设计两个类分别实现此接口，完成+-运算（即：n+m，n-m）
3、设计一个类UseCompute，含有方法：public void useCom(Compute com, int one, int two)
此方法要求能够：
（1）用传递过来的对象调用computer方法完成运算
（2）输出运算的结果
4、设计一个测试类，键盘输入两个整数，调用UseCompute中的方法useCom来完成+-运算，并输出相应结果。

测试用例：
输入：
5
4
输出：
5+4=9
5-4=1
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

interface Compute {
    int computer(int n, int m);
}

class Add implements Compute {
    @Override
    public int computer(int n, int m) {
        return n + m;
    }
}

class Subtract implements Compute {
    @Override
    public int computer(int n, int m) {
        return n - m;
    }
}

class UseCompute {
    public void useCom(Compute com, int one, int two) {
        int result = com.computer(one, two);
        System.out.println(one + (com instanceof Add ? "+" : "-") + two + "=" + result);
    }
}

public class test {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int num1 = scanner.nextInt();
        int num2 = scanner.nextInt();
        scanner.close();

        UseCompute useCompute = new UseCompute();
        useCompute.useCom(new Add(), num1, num2); 
        useCompute.useCom(new Subtract(), num1, num2); 
    }
}
