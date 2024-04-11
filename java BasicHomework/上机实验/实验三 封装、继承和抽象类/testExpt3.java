/*
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2024-04-11 23:13:47
 * @FilePath: \java BasicHomework\上机实验\实验三 封装、继承和抽象类\testExpt3.java
 * @Description: 
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
class Employee {
    /* 员工 */
    protected String name; // 员工姓名
    protected int birthMonth; // 生日月份

    public Employee(String name, int birthMonth) {
        this.name = name; 
        this.birthMonth = birthMonth; 
    }

    public double getSalary(int month) {
        double salary = 0;
        // 如果该月员工过生日，公司额外奖励100元。
        if (month == birthMonth) {
            salary += 100;
        }
        return salary;
    }
}

class SalariedEmployee extends Employee {
    /* 拿固定工资的员工 */
    private double monthlySalary; // 每月固定工资

    public SalariedEmployee(String name, int birthMonth, double monthlySalary) {
        super(name, birthMonth);
        this.monthlySalary = monthlySalary;
    }

    @Override
    public double getSalary(int month) {
        return monthlySalary + super.getSalary(month);
    }
}

class HourlyEmployee extends Employee {
    /* 按小时拿工资的员工 */
    private double hoursWorked; // 每月工时
    private double hourlyRate; // 每小时工资

    public HourlyEmployee(String name, int birthMonth, double hoursWorked, double hourlyRate) {
        super(name, birthMonth);
        this.hoursWorked = hoursWorked;
        this.hourlyRate = hourlyRate;
    }

    @Override
    public double getSalary(int month) {
        double salary = 0;
        if (hoursWorked > 160) {
            // 每月工作超出160小时的部分按照1.5倍工资发放。
            salary += (hoursWorked - 160) * 1.5 * hourlyRate;
        }
        return salary + (hoursWorked * hourlyRate) + super.getSalary(month);
    }
}

class SalesEmployee extends Employee {
    /* 销售人员 */
    protected double sales; // 销售额
    protected double commissionRate; // 提成率

    public SalesEmployee(String name, int birthMonth, double sales, double commissionRate) {
        super(name, birthMonth);
        this.sales = sales;
        this.commissionRate = commissionRate;
    }

    @Override
    public double getSalary(int month) {
        // 工资由月销售额和提成率决定 
        return sales * commissionRate + super.getSalary(month);
    }
}

class BasePlusSalesEmployee extends SalesEmployee {
    /* 有固定底薪的销售人员 */
    private double baseSalary;

    public BasePlusSalesEmployee(String name, int birthMonth, double sales, double commissionRate, double baseSalary) {
        super(name, birthMonth, sales, commissionRate);
        this.baseSalary = baseSalary; // 固定底薪
    }

    @Override
    public double getSalary(int month) {
        // 工资由底薪加上销售提成部分。 
        return baseSalary + super.getSalary(month);
    }
}

public class testExpt3 {
    public static void main(String[] args) {
        SalariedEmployee salariedEmployee = new SalariedEmployee("Alice", 5, 2000);
        HourlyEmployee hourlyEmployee = new HourlyEmployee("John", 8, 180, 10);
        SalesEmployee salesEmployee = new SalesEmployee("Bob", 3, 5000, 0.05);
        BasePlusSalesEmployee basePlusSalesEmployee = new BasePlusSalesEmployee("Carol", 7, 8000, 0.03, 1500);

        System.out.println(salariedEmployee.name + " Salary (Salaried Employee): " + salariedEmployee.getSalary(5));
        System.out.println(hourlyEmployee.name + " Salary (Hourly Employee): " + hourlyEmployee.getSalary(8));
        System.out.println(salesEmployee.name + " Salary (Sales Employee): " + salesEmployee.getSalary(3));
        System.out.println(basePlusSalesEmployee.name + " Salary (Base Plus Sales Employee): " + basePlusSalesEmployee.getSalary(7));
    }
}
