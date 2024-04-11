/*
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2024-04-11 15:37:12
 * @FilePath: \java BasicHomework\dy501 接口练习--CanFly\test.java
 * @Description: 
（1）定义一个接口CanFly，描述会飞的方法public void fly(); 
（2）分别定义类飞机和鸟，实现CanFly接口。
（3）定义一个测试类，测试飞机和鸟。测试类中定义一个makeFly()方法，让会飞的事物飞起来。然后在main方法中创建飞机对象和鸟对象，并在main方法中调用makeFly()方法，让飞机和鸟起飞。（该测试类已在题目中给出）

运行结果：
plane can fly
bird can fly

 请注意，main()函数与给定函数必须按如下所示编写：
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

public class test {
    void makeFly(CanFly cf) {
        cf.fly();
    }

    public static void main(String[] args) {
        Test t = new Test();
        t.makeFly(new Plane());
        t.makeFly(new Bird());
    }
}
