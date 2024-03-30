/*
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2024-03-29 11:47:57
 * @FilePath: \java BasicHomeworkd:\LocalUsers\vscode\java\project\test.java
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
class Employee {
    protected String name;
    protected int birthMonth;

    public Employee(String name, int birthMonth) {
        this.name = name; // Ա������
        this.birthMonth = birthMonth; // �����·�
    }

    public double getSalary(int month) {
        double salary = 0;
        // �������Ա�������գ���˾���⽱��100Ԫ��
        if (month == birthMonth) {
            salary += 100;
        }
        return salary;
    }
}

class SalariedEmployee extends Employee {
    // �ù̶����ʵ�Ա�� 
    private double monthlySalary; // ÿ�¹̶�����

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
    /* ��Сʱ�ù��ʵ�Ա�� */
    private double hoursWorked; // ÿ�¹�ʱ
    private double hourlyRate; // ÿСʱ����

    public HourlyEmployee(String name, int birthMonth, double hoursWorked, double hourlyRate) {
        super(name, birthMonth);
        this.hoursWorked = hoursWorked;
        this.hourlyRate = hourlyRate;
    }

    @Override
    public double getSalary(int month) {
        double salary = 0;
        if (hoursWorked > 160) {
            // ÿ�¹�������160Сʱ�Ĳ��ְ���1.5�����ʷ��š�
            salary += (hoursWorked - 160) * 1.5 * hourlyRate;
        }
        return salary + (hoursWorked * hourlyRate) + super.getSalary(month);
    }
}

class SalesEmployee extends Employee {
    /* ������Ա */
    protected double sales; // ���۶�
    protected double commissionRate; // �����

    public SalesEmployee(String name, int birthMonth, double sales, double commissionRate) {
        super(name, birthMonth);
        this.sales = sales;
        this.commissionRate = commissionRate;
    }

    @Override
    public double getSalary(int month) {
        // �����������۶������ʾ��� 
        return sales * commissionRate + super.getSalary(month);
    }
}

class BasePlusSalesEmployee extends SalesEmployee {
    /* �й̶���н��������Ա */
    private double baseSalary;

    public BasePlusSalesEmployee(String name, int birthMonth, double sales, double commissionRate, double baseSalary) {
        super(name, birthMonth, sales, commissionRate);
        this.baseSalary = baseSalary; // �̶���н
    }

    @Override
    public double getSalary(int month) {
        // �����ɵ�н����������ɲ��֡� 
        return baseSalary + super.getSalary(month);
    }
}

public class test {
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
