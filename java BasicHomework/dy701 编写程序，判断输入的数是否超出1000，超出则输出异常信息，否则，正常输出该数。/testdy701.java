/*
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2024-04-25 15:24:45
 * @FilePath: \java BasicHomework\dy701 ��д�����ж���������Ƿ񳬳�1000������������쳣��Ϣ�������������������\test.java
 * @Description:
��д�����ж���������Ƿ񳬳�1000������������쳣��Ϣ�������������������
����Ҫ��
��1����дһ���쳣��MyException���������ó���1000ʱ���쳣��ϢΪ������x������1000����
��2���ٱ�дһ����Student��������һ�������쳣�ķ���speak��int m����Ҫ�����m��ֵ����1000ʱ�������׳�һ��MyExcepiton���󣬷����������m��
��3������д����test�����������д���Student�����øö������speak���������ж�һ��ͨ����������������Ƿ񳬳�1000��

�����������£�
������1��
�����please input a number:
���룺 900
�����the number is:900
������2��
�����please input a number:
���룺1200
�����The number 1200 is greater than 1000
 ��ע�⣬main()����������������밴������ʾ��д��

public class test {
    public static void main(String[] args) {
        Student stu=new Student();
        System.out.println("please input a number:");
        Scanner sca = new Scanner (System.in);
        try {
            stu.speak(sca.nextInt());
        } catch (MyException e) {
            // TODO Auto-generated catch block
            System.out.println(e.message);
        }
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

class MyException extends Exception {
    String message;

    public MyException(String message) {
        this.message = message;
    }
}

class Student {
    public void speak(int m) throws MyException {
        if (m > 1000) {
            throw new MyException("The number " + m + " is greater than 1000");
        } else {
            System.out.println("the number is:" + m);
        }
    }
}

public class testdy701 {
    public static void main(String[] args) {
        Student stu = new Student();
        System.out.println("please input a number:");
        Scanner sca = new Scanner(System.in);
        try {
            stu.speak(sca.nextInt());
        } catch (MyException e) {
            System.out.println(e.message);
        }
        sca.close();
    }
}
