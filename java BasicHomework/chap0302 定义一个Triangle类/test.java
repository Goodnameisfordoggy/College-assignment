/*
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2024-03-21 15:51:33
 * @FilePath: \java\test.java
 * @Description: 1������һ��Triangle�࣬�����ж���һ�����ι��췽��������һ���ж��Ƿ��ܹ��������εķ���������һ�����ܳ��ķ���������һ��������ķ�����
��2������һ��������test���������������������������ܳ���������������Error
���磺
���룺3 4 5     �����12.0 
                     6.0
���룺4 2 2     �����Error
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
