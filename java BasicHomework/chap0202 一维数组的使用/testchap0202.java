
/*
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2024-04-11 22:49:56
 * @FilePath: \java BasicHomework\chap0202 һά�����ʹ��\test.java
 * @Description: ����һ��ʵ�������������ѧ���ɼ�����ʾ�û�ȷ���ɼ��ĸ��������ݸ����������顣
 * ��ʾ�û�����ÿ���ɼ���Ϊ������Ԫ�ظ�ֵ��ѯ���û�Ҫ���ҵڼ���ͬѧ�ĳɼ�����ʾ��Ӧ�Ĳ�ѯ�����
 * �������������Χ�������Ӧ��ʾ��

���������� ��ע����������У�
input n:
3
input1score:70
input2score:80
input3score:90
input number:
2
80

����������
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