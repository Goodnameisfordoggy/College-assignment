/*
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2024-04-25 15:24:45
 * @FilePath: \java BasicHomework\dy701 编写程序，判断输入的数是否超出1000，超出则输出异常信息，否则，正常输出该数。\test.java
 * @Description:
编写程序，判断输入的数是否超出1000，超出则输出异常信息，否则，正常输出该数。
具体要求：
（1）编写一个异常类MyException，用来设置超出1000时的异常信息为“数字x超出了1000。”
（2）再编写一个类Student，该类有一个产生异常的方法speak（int m）。要求参数m的值大于1000时，方法抛出一个MyExcepiton对象，否则正常输出m。
（3）最后编写主类test，在主方法中创建Student对象，让该对象调用speak（）方法判断一个通过键盘输入的数字是否超出1000。

测试用例如下：
（测试1）
输出：please input a number:
输入： 900
输出：the number is:900
（测试2）
输出：please input a number:
输入：1200
输出：The number 1200 is greater than 1000
 请注意，main()函数与给定函数必须按如下所示编写：

public class test {
    public static void main(String[] args) {
        Student stu=new Student();
        System.out.println("please input a number:");
        Scanner sca = new Scanner (System.in);
        try {
            stu.speak(sca.nextInt());
        } catch (MyException e) {
            // TODO Auto-generated catch block
            System.out.println(e.message);
        }
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

class MyException extends Exception {
    String message;

    public MyException(String message) {
        this.message = message;
    }
}

class Student {
    public void speak(int m) throws MyException {
        if (m > 1000) {
            throw new MyException("The number " + m + " is greater than 1000");
        } else {
            System.out.println("the number is:" + m);
        }
    }
}

public class testdy701 {
    public static void main(String[] args) {
        Student stu = new Student();
        System.out.println("please input a number:");
        Scanner sca = new Scanner(System.in);
        try {
            stu.speak(sca.nextInt());
        } catch (MyException e) {
            System.out.println(e.message);
        }
        sca.close();
    }
}
