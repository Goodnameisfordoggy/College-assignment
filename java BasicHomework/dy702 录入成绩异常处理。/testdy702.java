/*
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2024-04-25 15:24:34
 * @FilePath: \java BasicHomework\dy702 ¼��ɼ��쳣����\test1.java
 * @Description: 
��дһ��Ӧ�ó���Ҫ������һ���ɼ���������ĳɼ�����[0,100]֮��ʱ�����׳��쳣��Ϣ����������ʾ����ĳɼ���
����Ҫ��
��1����дһ���쳣��ScoreException��ȷ���쳣��Ϣ��
��2����дһ��Teacher�࣬����һ��check����������������Ƿ���Ҫ�׳��쳣��

��������1��
���룺-5
�����please input 0-100
��������2��
���룺88
�����The score is:88
 ��ע�⣬main()����������������밴������ʾ��д��
public class test {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        Teacher t = new Teacher();
        try {
            t.check(in.nextInt());
        } catch (ScoreException e) {
            System.out.println(e.getMessage());
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

class ScoreException extends Exception {
    public ScoreException() {
        super("please input 0-100");
    }
}

class Teacher {
    public void check(int score) throws ScoreException {
        if (score < 0 || score > 100) {
            throw new ScoreException();
        } else {
            System.out.println("The score is:" + score);
        }
    }
}

public class testdy702 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        Teacher t = new Teacher();
        try {
            System.out.println("������ɼ���");
            t.check(in.nextInt());
        } catch (ScoreException e) {
            System.out.println(e.getMessage());
        }
        in.close();
    }
}
