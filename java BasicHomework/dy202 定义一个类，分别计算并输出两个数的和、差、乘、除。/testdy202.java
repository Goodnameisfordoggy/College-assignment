/*
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2024-04-11 22:33:52
 * @FilePath: \java BasicHomework\dy202 ����һ���࣬�ֱ���㲢����������ĺ͡���ˡ�����\test.java
 * @Description: 1������һ��compute�࣬�������x��y������̬���������幹�췽����ʼ���������������ٶ���4���������ֱ������������ĺ͡���ˡ�������������
��2����main�����У��û�Ӧ�������������������������������Ӧ�����㡣����֪�������£�

 ��ע�⣬main()����������������밴������ʾ��д��
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