/*
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2024-04-11 22:52:34
 * @FilePath: \java BasicHomework\dy501 �ӿ���ϰ--CanFly\testdy501.java
 * @Description: 
��1������һ���ӿ�CanFly��������ɵķ���public void fly(); 
��2���ֱ�����ɻ�����ʵ��CanFly�ӿڡ�
��3������һ�������࣬���Էɻ����񡣲������ж���һ��makeFly()�������û�ɵ������������Ȼ����main�����д����ɻ����������󣬲���main�����е���makeFly()�������÷ɻ�������ɡ����ò�����������Ŀ�и�����

���н����
plane can fly
bird can fly

 ��ע�⣬main()����������������밴������ʾ��д��
public class test {
    void makeFly(CanFly cf) {
        cf.fly();
    }
    public static void main(String[] args) {
        test t = new test();
        t.makeFly(new Plane());
        t.makeFly(new Bird());
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
interface CanFly {
    void fly();
}

class Plane implements CanFly {
    @Override
    public void fly() {
        System.out.println("plane can fly");
    }
}

class Bird implements CanFly {
    @Override
    public void fly() {
        System.out.println("bird can fly");
    }
}

public class testdy501 {
    void makeFly(CanFly cf) {
        cf.fly();
    }
    public static void main(String[] args) {
        testdy501 t = new testdy501();
        t.makeFly(new Plane());
        t.makeFly(new Bird());
    }
}