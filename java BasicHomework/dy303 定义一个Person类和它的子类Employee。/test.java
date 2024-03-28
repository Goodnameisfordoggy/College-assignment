
/*
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2024-03-28 15:44:33
 * @FilePath: \java\java BasicHomework\dy303 ����һ��Person�����������Employee��\test.java
 * @Description: ����Ҫ��
��1��Person�������ԣ�name��address��telphone��email����Ȼ����һ������showMessage()���������Ա����Ϣ��
��2��Employee�������ԣ�offic��salary��Date����Ҳ������һ������showMessage()���������Ա����Ϣ��
��3������һ��test���������ж��󴴽��������Ӧ��Ϣ������main()�����зֱ�Ϊ���ڸ�������ഴ����������
���ֱ�Ϊ���������ĳ�Ա������ֵ����Ӧ��Ϣ���ɼ������룩��Ȼ��ֱ���ø���������showMessage()�����������Ϣ��
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
