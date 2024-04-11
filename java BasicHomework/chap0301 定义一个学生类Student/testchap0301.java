/*
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2024-04-11 22:50:31
 * @FilePath: \java BasicHomework\chap0301 定义一个学生类Student\test.java
 * @Description: 1)定义一个学生类Student，该类具有属性：name、age、score；添加无参及带参构造方法；
 * 编写show()方法输出3项成员变量的值；
2)编写一个测试类test，在main()方法中，使用无参构造方法创建对象student1，对三个成员分别赋值；
使用带参构造方法创建并初始化对象student2，调用show()方法输出对象student1，student2各成员变量的值。
输出：
Peter,25,85.0
Marry,22,95.0
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
