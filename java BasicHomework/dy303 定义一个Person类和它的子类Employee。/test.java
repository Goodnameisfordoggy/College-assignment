
/*
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2024-03-28 15:44:33
 * @FilePath: \java\java BasicHomework\dy303 定义一个Person类和它的子类Employee。\test.java
 * @Description: 具体要求：
（1）Person类有属性（name、address、telphone、email），然后定义一个方法showMessage()用于输出人员的信息。
（2）Employee类有属性（offic、salary、Date），也定义了一个方法showMessage()用于输出雇员的信息。
（3）定义一个test类用来进行对象创建并输出相应信息，在其main()方法中分别为基于父类和子类创建两个对象，
并分别为父类和子类的成员变量赋值（相应信息均由键盘输入），然后分别调用父类和子类的showMessage()方法来输出信息。
Please input personnel information(name,address,telphone,email):
Please enter employee information(offic,salary,Date):
name:xiaoli
address:china
telephone:123456789
email:123@qq.com
office:A-11
Date:20190130
salary:2500.0
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

class Person {
    protected String name;
    protected String address;
    protected String telephone;
    protected String email;

    public Person(String name, String address, String telephone, String email) {
        this.name = name;
        this.address = address;
        this.telephone = telephone;
        this.email = email;
    }

    public void showMessage() {
        System.out.println("name:" + name);
        System.out.println("address:" + address);
        System.out.println("telephone:" + telephone);
        System.out.println("email:" + email);
    }
}

class Employee extends Person {
    private String office;
    private double salary;
    private String date;

    public Employee(String name, String address, String telephone, String email, String office, double salary,
            String date) {
        super(name, address, telephone, email);
        this.office = office;
        this.salary = salary;
        this.date = date;
    }

    @Override
    public void showMessage() {
        System.out.println("office:" + office);
        System.out.println("Date:" + date);
        System.out.println("salary:" + salary);
    }
}

public class test {
    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        System.out.println("Please input personnel information(name,address,telphone,email):");
        String name = in.next();
        String address = in.next();
        String telephone = in.next();
        String email = in.next();

        System.out.println("Please enter employee information(offic,salary,Date):");
        String office = in.next();
        double salary = in.nextDouble();
        String date = in.next();

        Person person = new Person(name, address, telephone, email);
        Employee employee = new Employee(name, address, telephone, email, office, salary, date);
        person.showMessage();
        employee.showMessage();
        in.close();
    }
}
