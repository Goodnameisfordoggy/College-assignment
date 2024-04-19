import java.util.HashSet;
import java.util.Iterator;

class Worker {
    private String name;
    private int age;
    private int salary;

    public Worker(String name, int age, int salary) {
        this.name = name;
        this.age = age;
        this.salary = salary;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public int getSalary() {
        return salary;
    }

    public void setSalary(int salary) {
        this.salary = salary;
    }

    // @Override
    // public int hashCode() {
    //     return name.hashCode();
    // }

    @Override
    public boolean equals(Object obj) {
        if (this == obj)
            return true;
        if (obj == null || getClass() != obj.getClass())
            return false;
        Worker worker = (Worker) obj; // Worker �������������Ϊ�������
        return name.equals(worker.name);
    }
}

public class testHashSet {
    public static void main(String[] args) {
        // ����HashSet������Worker����
        HashSet<Worker> workers = new HashSet<>();

        // �ڼ�����������������
        workers.add(new Worker("zhangsan", 18, 4000));
        workers.add(new Worker("lisi", 25, 4500));
        workers.add(new Worker("wangwu", 22, 4200));

        // ���� Iterator()������ɱ������ϲ���������ж���
        System.out.println("print1:");
        Iterator<Worker> iterator = workers.iterator();
        while (iterator.hasNext()) {
            Worker worker = iterator.next();
            System.out.println(worker.getName() + "," + worker.getAge() + "," + worker.getSalary());
        }

        // �ظ���ӡ�wangwu������ʹ��foreach()�����������ϲ������
        workers.add(new Worker("wangwu", 22, 4200));
        System.out.println("print-add:");
        for (Worker worker : workers) {
            System.out.println(worker.getName() + "," + worker.getAge() + "," + worker.getSalary());
        }

        // ɾ����zhangsan������Ϣ����ʹ��foreach()�����������ϲ������
        workers.remove(new Worker("zhangsan", 18, 4000));
        System.out.println("print-del:");
        for (Worker worker : workers) {
            System.out.println(worker.getName() + "," + worker.getAge() + "," + worker.getSalary());
        }
    }
}
