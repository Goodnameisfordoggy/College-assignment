/*
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2024-04-11 22:28:59
 * @FilePath: \java BasicHomework\�ַ�����ϰ\StringExample.java
 * @Description: 
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

class StringExample {   
    public static void main(String args[]) {
        String s1 = new String("you are a student"), s2 = new String("how are you");
        
        if(s1.equals(s2)) { //�ж�s1��s2�Ƿ���ͬ
            System.out.println("s1��s2��ͬ");
        } else {
            System.out.println("s1��s2����ͬ"); 
        }

        String s3 = new String("22030219851022024");
        if(s3.startsWith("220302")) { //�ж�s3��ǰ׺�Ƿ��ǡ�220302����
            System.out.println("����ʡ�����֤");
        }

        String s4 = new String("��"), s5 = new String("��");
        if(s4.compareTo(s5) > 0) { //���ֵ���Ƚ�s4�Ƿ����s5
            System.out.println("���ֵ���s4����s5");
        } else {
            System.out.println("���ֵ���s4С��s5");
        }

        int position = 0;
        String path = "c:\\java\\jsp\\A.java";
        position = path.lastIndexOf("\\"); //��ȡpath��������Ŀ¼�ָ����ŵ�λ��
        System.out.println("c:\\java\\jsp\\A.java��������\\��λ��:" + position);

        String fileName = path.substring(position + 1); //��ȡpath�С�A.java�����ַ�����
        System.out.println("c:\\java\\jsp\\A.java�к��е��ļ���:" + fileName);

        String s6 = new String("100"), s7 = new String("123.678");
        int n1 = Integer.parseInt(s6); //��s6ת����int������
        double n2 = Double.parseDouble(s7); //��s7ת����double�����ݡ�

        double m = n1 + n2;
        System.out.println(m);
        String s8 = String.valueOf(m);  //String����valuOf(int n)������mת��Ϊ�ַ�������
        position = s8.indexOf(".");
        String temp = s8.substring(position + 1);
        System.out.println("����" + m + "��" + temp.length() + "λС��");

        String s9 = new String("ABCDEF");
        char a[] = s9.toCharArray(); //��s8��ŵ�����a�С�
        for(int i = a.length - 1; i >= 0; i--) {
            System.out.print(" " + a[i]);
        }
    }
}
