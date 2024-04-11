/*
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2024-04-11 22:48:22
 * @FilePath: \java BasicHomework\0503 中国特色社会主义的体制中有这样的现象：地方省政府要坚持党的领导和按照国务院的指示进行安全生产。编写一个Java应用程序描述上述的体制现象。\test.java
 * @Description: 题目内容：
（1）定义一个“党中央”接口：CentralPartyCommittee，?6?8该接口中有个“坚持党的领导”方法：void partyLeader()。
（2）定义一个“国务院”抽象类：StateCouncil，?6?8该抽象类中有个“安全生产”的抽象方法： void?6?8safetyInProduction()。
（3）定义一个“省政府”类：Province，?6?8该类有一个成员变量name，该类继承StateCouncil类并实现CentralPartyCommittee接口；
重写partyLeader()方法和safetyInProduction()方法?6?8。定义show方法，输出省份名称。
（4）定义一个主类Test，在主类的main方法中创建Province类的对象，测试Province类的功能。
注意：定义接口时不要加public

输出：
Hebei Province---
The people of our provinces must adhere to the leadership of the Party.
The people of our provinces must carry out safe production in accordance with the instructions of the State Council.
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
interface CentralPartyCommittee {
    void partyLeader();
}


abstract class StateCouncil {
    abstract void safetyInProduction();
}

class Province extends StateCouncil implements CentralPartyCommittee {
    String name; 

    Province(String name) {
        this.name = name;
    }

    @Override
    public void partyLeader() {
        System.out.println("The people of our provinces must adhere to the leadership of the Party.");
    }

    @Override
    void safetyInProduction() {
        System.out.println("The people of our provinces must carry out safe production in accordance with the instructions of the State Council.");
    }

    void show() {
        System.out.println(name + " Province---");
    }
}

public class test0503 {
    public static void main(String[] args) {
        Province hebei = new Province("Hebei");
        hebei.show(); 
        hebei.partyLeader(); 
        hebei.safetyInProduction(); 
    }
}
