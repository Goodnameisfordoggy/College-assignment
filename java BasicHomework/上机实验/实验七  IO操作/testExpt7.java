/*
 * @Author: HDJ
 * @StartDate: please fill in
 * @LastEditTime: 2024-05-09 16:02:18
 * @FilePath: \java BasicHomework\�ϻ�ʵ��\ʵ����  IO����\testEx.java
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
        // ����ļ�d:\test.txt�����ڣ��Ը�������һ���ļ���������ļ����ڣ���100��������ɵ�����д���ļ�������֮���ÿո�ָ���
        createAndWriteToFile("d:\\test.txt", 0, 1000);

        // ��text.txt���ݸ��Ƶ�d:\text2.txt�С�
        copyFile("d:\\test.txt", "d:\\test2.txt");

        // ��e:\filedemo�������ļ���д��d:\text3.txt�ļ��У�Ҫ��ʹ���ַ������������
        listFilesInDirectory("e:\\filedemo", "d:\\test3.txt");
    }

    private static void createAndWriteToFile(String filePath, int rangeStart, int rangeEnd) {
        /* 
         * ���ָ��·�����ļ������ڣ��Ը�������һ���ļ���������ļ����ڣ���100��������ɵ�����д���ļ�������֮���ÿո�ָ���
         * @param filePath ָ���ļ�·��
         * @param rangeStart ������������
         * @param rangeEnd ����������յ�
         */
        try (FileOutputStream fos = new FileOutputStream(filePath);
             BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(fos))) {

            File file = new File(filePath);
            if (!file.exists()) {
                file.createNewFile();
            }
            // ���������
            Random random = new Random();
            for (int i = 0; i < 100; i++) {
                int num = rangeStart + random.nextInt(rangeEnd - rangeStart + 1);
                writer.write(Integer.toString(num));
                writer.write(" ");  // ������֮���ÿո����
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private static void copyFile(String sourcePath, String destinationPath) {
        /*
         * �����ļ�ȫ�����ݵ���һ���ļ�
         * @param sourcePath Դ�ļ�·��
         * @param destinationPath Ŀ���ļ�·��
         */
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

    private static void listFilesInDirectory(String directoryPath, String destinationPath) {
        /*
         * ��ָ��Ŀ¼�������ļ���д��ָ���ļ��У�ʹ���ַ������������
         * @param directoryPath Ŀ¼·��
         * @param destinationPath Ŀ���ļ�·��
         */
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(destinationPath))) {
            File directory = new File(directoryPath);
            if (directory.isDirectory()) {
                File[] files = directory.listFiles(); // ��ȡ�ļ��б�
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
