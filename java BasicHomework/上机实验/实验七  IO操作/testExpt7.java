/*
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2024-05-11 17:21:10
 * @FilePath: \java BasicHomework\上机实验\实验七  IO操作\testExpt7.java
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
import java.io.BufferedWriter;
import java.io.FileOutputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.File;
import java.io.FileWriter;
import java.io.OutputStreamWriter;
import java.util.Random;

public class testExpt7 {
    public static void main(String[] args) {
        // 如果文件d:\test.txt不存在，以该名创建一个文件，如果该文件存在，将100个随机生成的整数写入文件，整数之间用空格分隔。
        createAndWriteToFile("d:\\test.txt", 0, 1000);

        // 将text.txt内容复制到d:\text2.txt中。
        copyFile("d:\\test.txt", "d:\\test2.txt");

        // 将e:\filedemo下所有文件名写入d:\text3.txt文件中，要求使用字符缓冲输出流。
        listFilesInDirectory("e:\\filedemo", "d:\\test3.txt");
    }

    /* 
    * 如果指定路径下文件不存在，以该名创建一个文件，如果该文件存在，将100个随机生成的整数写入文件，整数之间用空格分隔。
    * @param filePath 指定文件路径
    * @param rangeStart 随机数生成起点
    * @param rangeEnd 随机数生成终点
    */
    private static void createAndWriteToFile(String filePath, int rangeStart, int rangeEnd) {
        
        try (FileOutputStream fos = new FileOutputStream(filePath);
                BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(fos))) {

            File file = new File(filePath);
            if (!file.exists()) {
                file.createNewFile();
            }
            // 生成随机数
            Random random = new Random();
            for (int i = 0; i < 100; i++) {
                int num = rangeStart + random.nextInt(rangeEnd - rangeStart + 1);
                writer.write(Integer.toString(num));
                writer.write(" "); // 两个数之间用空格隔开
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    
    /*
    * 复制文件全部内容到另一个文件
    * @param sourcePath 源文件路径
    * @param destinationPath 目标文件路径
    */
    private static void copyFile(String sourcePath, String destinationPath) {

        try (FileInputStream fis = new FileInputStream(sourcePath);
                FileOutputStream fos = new FileOutputStream(destinationPath)) {

            byte[] buffer = new byte[1024];
            int bytesRead;
            while ((bytesRead = fis.read(buffer)) != -1) {
                fos.write(buffer, 0, bytesRead);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    
    /*
    * 将指定目录下所有文件名写入指定文件中，使用字符缓冲输出流。
    * @param directoryPath 目录路径
    * @param destinationPath 目标文件路径
    */
    private static void listFilesInDirectory(String directoryPath, String destinationPath) {
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(destinationPath))) {
            File directory = new File(directoryPath);
            if (directory.isDirectory()) {
                File[] files = directory.listFiles(); // 获取文件列表
                if (files != null) {
                    for (File file : files) {
                        writer.write(file.getName());
                        writer.newLine();
                    }
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
