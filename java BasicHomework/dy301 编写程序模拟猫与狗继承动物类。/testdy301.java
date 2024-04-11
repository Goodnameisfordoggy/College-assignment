
/*
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2024-04-11 22:51:53
 * @FilePath: \java BasicHomework\dy301 ��д����ģ��è�빷�̳ж����ࡣ\test.java
 * @Description: ��������4���ࣺAnimal��Dog��Cat������test��
����Ҫ�����£�
��1��Animal��������£�
---------------------------------------------------------------------------------------
class Animal {
    protected String name;
    public void showName() {
        System.out.print(name + ",");
    }
    public void cry() {
        System.out.print("Different animals make different sounds");
    }
}
---------------------------------------------------------------------------------------
��2����дһ��Animal������Dog������public void swimming()��������д�����
public void cry()������
��3����дһ��Animal������Cat������public void climbUpTree()��������д�����
public void cry()������
��4������test��main�����Ѹ�����ͨ��������Ӧ�����֣��ֱ�Ҫ�������Ϣ��

�����������£�
�����please input a name for the dog
���룺Alpha
�����please input a name for the cat
���룺Tom
�����
Alpha,wang...wang,can swimming.
Tom,miao...miao,can climb the tree.
---------------------------------------------------------------------------------------
 ��ע�⣬main()����������������밴������ʾ��д��
public class test {
    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        System.out.println("please input a name for the dog");
        Dog dog = new Dog(in.nextLine());
        System.out.println("please input a name for the cat");
        Cat cat = new Cat(in.nextLine());
        dog.showName();
        dog.cry();
        dog.swimming();
        cat.showName();
        cat.cry();
        cat.climbUpTree();
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

class Animal {
    protected String name;

    public Animal(String name) {
        this.name = name;
    }

    public void showName() {
        System.out.print(name + ",");
    }

    public void cry() {
        System.out.print("Different animals make different sounds");
    }
}

class Dog extends Animal {
    public Dog(String name) {
        super(name);
    }

    @Override
    public void cry() {
        System.out.print("wang...wang");
    }

    public void swimming() {
        System.out.println(",can swimming.");
    }
}

class Cat extends Animal {
    public Cat(String name) {
        super(name);
    }

    @Override
    public void cry() {
        System.out.print("miao...miao");
    }

    public void climbUpTree() {
        System.out.println(",can climb the tree.");
    }
}

public class testdy301 {
    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        System.out.println("please input a name for the dog");
        Dog dog = new Dog(in.nextLine());
        System.out.println("please input a name for the cat");
        Cat cat = new Cat(in.nextLine());
        dog.showName();
        dog.cry();
        dog.swimming();
        System.out.println();
        cat.showName();
        cat.cry();
        cat.climbUpTree();
        in.close();
    }
}
