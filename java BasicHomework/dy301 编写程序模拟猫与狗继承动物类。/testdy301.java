
/*
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2024-04-11 22:51:53
 * @FilePath: \java BasicHomework\dy301 编写程序模拟猫与狗继承动物类。\test.java
 * @Description: 程序中有4个类：Animal、Dog、Cat和主类test。
具体要求如下：
（1）Animal类代码如下：
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
（2）编写一个Animal的子类Dog，新增public void swimming()方法；重写父类的
public void cry()方法。
（3）编写一个Animal的子类Cat，新增public void climbUpTree()方法；重写父类的
public void cry()方法。
（4）主类test的main函数已给出，通过输入相应的名字，分别按要求输出信息。

测试用例如下：
输出：please input a name for the dog
输入：Alpha
输出：please input a name for the cat
输入：Tom
输出：
Alpha,wang...wang,can swimming.
Tom,miao...miao,can climb the tree.
---------------------------------------------------------------------------------------
 请注意，main()函数与给定函数必须按如下所示编写：
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
 * 				*		写字楼里写字间，写字间里程序员；
 * 				*		程序人员写程序，又拿程序换酒钱。
 * 				*		酒醒只在网上坐，酒醉还来网下眠；
 * 				*		酒醉酒醒日复日，网上网下年复年。
 * 				*		但愿老死电脑间，不愿鞠躬老板前；
 * 				*		奔驰宝马贵者趣，公交自行程序员。
 * 				*		别人笑我忒疯癫，我笑自己命太贱；
 * 				*		不见满街漂亮妹，哪个归得程序员？    
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
