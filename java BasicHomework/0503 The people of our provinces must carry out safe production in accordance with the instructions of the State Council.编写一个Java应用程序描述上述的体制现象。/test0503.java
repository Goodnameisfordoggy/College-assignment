/*
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2024-04-11 22:48:22
 * @FilePath: \java BasicHomework\0503 �й���ɫ�������������������������󣺵ط�ʡ����Ҫ��ֵ����쵼�Ͱ��չ���Ժ��ָʾ���а�ȫ��������дһ��JavaӦ�ó���������������������\test.java
 * @Description: ��Ŀ���ݣ�
��1������һ���������롱�ӿڣ�CentralPartyCommittee��?6?8�ýӿ����и�����ֵ����쵼��������void partyLeader()��
��2������һ��������Ժ�������ࣺStateCouncil��?6?8�ó��������и�����ȫ�������ĳ��󷽷��� void?6?8safetyInProduction()��
��3������һ����ʡ�������ࣺProvince��?6?8������һ����Ա����name������̳�StateCouncil�ಢʵ��CentralPartyCommittee�ӿڣ�
��дpartyLeader()������safetyInProduction()����?6?8������show���������ʡ�����ơ�
��4������һ������Test���������main�����д���Province��Ķ��󣬲���Province��Ĺ��ܡ�
ע�⣺����ӿ�ʱ��Ҫ��public

�����
Hebei Province---
The people of our provinces must adhere to the leadership of the Party.
The people of our provinces must carry out safe production in accordance with the instructions of the State Council.
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
