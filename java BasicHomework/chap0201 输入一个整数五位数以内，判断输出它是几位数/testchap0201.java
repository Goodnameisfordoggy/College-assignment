
/*
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2024-04-11 22:12:35
 * @FilePath: \java BasicHomework\chap0201 ����һ��������λ�����ڣ��ж�������Ǽ�λ��\test.java
 * @Description: ��Ŀ���ݣ�
��
����:1234�����:4digits
����:123456�����:error
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

public class testchap0201 {
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