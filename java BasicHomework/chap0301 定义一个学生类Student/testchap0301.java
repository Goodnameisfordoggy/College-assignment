/*
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2024-04-11 22:50:31
 * @FilePath: \java BasicHomework\chap0301 ����һ��ѧ����Student\test.java
 * @Description: 1)����һ��ѧ����Student������������ԣ�name��age��score������޲μ����ι��췽����
 * ��дshow()�������3���Ա������ֵ��
2)��дһ��������test����main()�����У�ʹ���޲ι��췽����������student1����������Ա�ֱ�ֵ��
ʹ�ô��ι��췽����������ʼ������student2������show()�����������student1��student2����Ա������ֵ��
�����
Peter,25,85.0
Marry,22,95.0
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
class Student {
    protected String name;
    protected int age;
    protected double score;

    public Student() {
    }

    public Student(String name, int age, double score) {
        this.name = name;
        this.age = age;
        this.score = score;
    }
    

    public void show() {
        System.out.println(name + "," + age + "," + score);
    }
}

public class testchap0301 {
    public static void main(String[] args) {
        Student student1 = new Student();
        student1.name = "Peter";
        student1.age = 25;
        student1.score = 85.0;

        Student student2 = new Student("Marry", 22, 95.0);

        student1.show();
        student2.show();
    }
}
