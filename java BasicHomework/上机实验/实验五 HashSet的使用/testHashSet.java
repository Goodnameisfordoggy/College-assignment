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
        Worker worker = (Worker) obj; // Worker 的姓名相等则视为对象相等
        return name.equals(worker.name);
    }
}

public class testHashSet {
    public static void main(String[] args) {
        // 创建HashSet来储存Worker对象
        HashSet<Worker> workers = new HashSet<>();

        // 在集合中增加三个工人
        workers.add(new Worker("zhangsan", 18, 4000));
        workers.add(new Worker("lisi", 25, 4500));
        workers.add(new Worker("wangwu", 22, 4200));

        // 利用 Iterator()方法完成遍历集合并输出集合中对象
        System.out.println("print1:");
        Iterator<Worker> iterator = workers.iterator();
        while (iterator.hasNext()) {
            Worker worker = iterator.next();
            System.out.println(worker.getName() + "," + worker.getAge() + "," + worker.getSalary());
        }

        // 重复添加“wangwu”对象，使用foreach()方法遍历集合并输出。
        workers.add(new Worker("wangwu", 22, 4200));
        System.out.println("print-add:");
        for (Worker worker : workers) {
            System.out.println(worker.getName() + "," + worker.getAge() + "," + worker.getSalary());
        }

        // 删除“zhangsan”的信息，并使用foreach()方法遍历集合并输出。
        workers.remove(new Worker("zhangsan", 18, 4000));
        System.out.println("print-del:");
        for (Worker worker : workers) {
            System.out.println(worker.getName() + "," + worker.getAge() + "," + worker.getSalary());
        }
    }
}
