/*
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2024-03-21 15:51:33
 * @FilePath: \java\test.java
 * @Description: 1）定义一个Triangle类，在类中定义一个带参构造方法，定义一个判断是否能构成三角形的方法，定义一个求周长的方法，定义一个求面积的方法。
（2）定义一个测试类test，创建对象，如果构成三角形输出周长和面积，否则输出Error
例如：
输入：3 4 5     输出：12.0 
                     6.0
输入：4 2 2     输出：Error
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

class Triangle {
    private double side1;
    private double side2;
    private double side3;

    public Triangle(double side1, double side2, double side3) {
        this.side1 = side1;
        this.side2 = side2;
        this.side3 = side3;
    }

    public boolean isTriangle() {
        return side1 + side2 > side3 && side1 + side3 > side2 && side2 + side3 > side1;
    }

    public double calculatePerimeter() {
        return side1 + side2 + side3;
    }

    public double calculateArea() {
        double s = calculatePerimeter() / 2;
        return Math.sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }
}

public class test {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        double side1 = scanner.nextDouble();
        double side2 = scanner.nextDouble();
        double side3 = scanner.nextDouble();

        Triangle triangle = new Triangle(side1, side2, side3);
        if (triangle.isTriangle()) {
            System.out.println(triangle.calculatePerimeter());
            System.out.println(triangle.calculateArea());
        } else {
            System.out.println("Error");
        }

        scanner.close();
    }
}
