/*
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2024-04-11 22:48:59
 * @FilePath: \java BasicHomework\0504 StringBuffer��ʹ�ã��ж�һ���ַ����Ƿ�Գƣ�\test.java
 * @Description: ��Ŀ���ݣ�
��ʾ����ת�ķ���   public StringBuffer reverse()
��������1��
input string:
abcdedcba
�����
symmetry

��������2��
input string:
abdcfhejl
�����
asymmetric
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
