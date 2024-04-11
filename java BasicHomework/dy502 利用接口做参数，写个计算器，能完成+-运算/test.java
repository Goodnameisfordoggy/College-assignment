/*
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2024-04-11 15:36:17
 * @FilePath: \java BasicHomework\dy502 ���ýӿ���������д���������������+-����\test.java
 * @Description: 
1������һ���ӿ�Compute����һ������int computer(int n,int m);
2�����������ֱ�ʵ�ִ˽ӿڣ����+-���㣨����n+m��n-m��
3�����һ����UseCompute�����з�����public void useCom(Compute com, int one, int two)
�˷���Ҫ���ܹ���
��1���ô��ݹ����Ķ������computer�����������
��2���������Ľ��
4�����һ�������࣬����������������������UseCompute�еķ���useCom�����+-���㣬�������Ӧ�����

����������
���룺
5
4
�����
5+4=9
5-4=1
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
