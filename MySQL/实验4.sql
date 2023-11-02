-- locahost查询

/*1.请用T-SQL语句创建数据库JXGL2*/
CREATE DATABASE JXGL2;
/*2.请用T-SQL语句创建数据表student，course和test*/
USE JXGL2;
CREATE TABLE Student (
    SNO CHAR(9) NOT NULL PRIMARY KEY,
    SNAME VARCHAR(10) NOT NULL,
    SEX CHAR(2),
    AGE SMALLINT,
    CGNO CHAR(5)
);

/*3.*/
CREATE TABLE Course (
    CNO CHAR(6) NOT NULL PRIMARY KEY,
    CNAME VARCHAR(20) NOT NULL,
    CREDIT SMALLINT,
    WHOURS SMALLINT
);
CREATE TABLE Test (
    SNO CHAR(9) NOT NULL,
    CNO CHAR(10) NOT NULL,
    GRADE SMALLINT,
		PRIMARY KEY (SNO, CNO)
);

/*4.请用T-SQL语句插入表数据*/
INSERT INTO student (SNO, SNAME, AGE, SEX, CGNO) VALUES ('200515001', '赵菁菁', 23, '女', 'CS');
INSERT INTO student (SNO, SNAME, AGE, SEX, CGNO) VALUES ('200515002', '李勇', 22, '男', 'CS');
INSERT INTO student (SNO, SNAME, AGE, SEX, CGNO) VALUES ('200515004', '张衡', 18, '男', 'IS');
INSERT INTO student (SNO, SNAME, AGE, SEX, CGNO) VALUES ('200515005', '张向东', 20, '男', 'IS');
INSERT INTO student (SNO, SNAME, AGE, SEX, CGNO) VALUES ('200515006', '张向丽', 20, '女', 'IS');
INSERT INTO student (SNO, SNAME, AGE, SEX, CGNO) VALUES ('200515007', '王芳', 20, '女', 'CS');
INSERT INTO student (SNO, SNAME, AGE, SEX, CGNO) VALUES ('200515008', '王民生', 25, '男', 'MA');
INSERT INTO student (SNO, SNAME, AGE, SEX, CGNO) VALUES ('200515009', '王小民', 18, '女', 'MA');
INSERT INTO student (SNO, SNAME, AGE, SEX, CGNO) VALUES ('200515010', '李晨', 22, '女', 'MA');
INSERT INTO student (SNO, SNAME, AGE, SEX, CGNO) VALUES ('200515011', '张毅', 20, '男', 'WM');
INSERT INTO student (SNO, SNAME, AGE, SEX, CGNO) VALUES ('200515012', '杨磊', 20, '女', 'EN');
INSERT INTO student (SNO, SNAME, AGE, SEX, CGNO) VALUES ('200515013', '李晨', 19, '女', 'MA');
INSERT INTO student (SNO, SNAME, AGE, SEX, CGNO) VALUES ('200515014', '张丰毅', 22, '男', 'CS');
INSERT INTO student (SNO, SNAME, AGE, SEX, CGNO) VALUES ('200515015', '李蕾', 21, '女', 'EN');
INSERT INTO student (SNO, SNAME, AGE, SEX, CGNO) VALUES ('200515016', '刘社', 21, '男', 'CM');
INSERT INTO student (SNO, SNAME, AGE, SEX, CGNO) VALUES ('200515017', '刘星耀', 18, '男', 'CM');
INSERT INTO student (SNO, SNAME, AGE, SEX, CGNO) VALUES ('200515018', '李贵', 19, '男', 'EN');
INSERT INTO student (SNO, SNAME, AGE, SEX, CGNO) VALUES ('200515019', '林自许', 20, '男', 'WM');
INSERT INTO student (SNO, SNAME, AGE, SEX, CGNO) VALUES ('200515020', '马翔', 21, '男', NULL);
INSERT INTO student (SNO, SNAME, AGE, SEX, CGNO) VALUES ('200515021', '刘峰', 25, '男', 'CS');
INSERT INTO student (SNO, SNAME, AGE, SEX, CGNO) VALUES ('200515022', '牛站强', 22, '男', NULL);
INSERT INTO student (SNO, SNAME, AGE, SEX, CGNO) VALUES ('200515023', '李婷婷', 18, '女', NULL);
INSERT INTO student (SNO, SNAME, AGE, SEX, CGNO) VALUES ('200515024', '严丽', 20, '女', NULL);
INSERT INTO student (SNO, SNAME, AGE, SEX, CGNO) VALUES ('200515025', '朱小鸥', 30, '女', 'WM');

INSERT INTO `course` VALUES ('1', '数据库', 4, 6);
INSERT INTO `course` VALUES ('10', '人工智能', 2, 2);
INSERT INTO `course` VALUES ('2', '数学', 2, 6);
INSERT INTO `course` VALUES ('3', '信息系统', 4, 4);
INSERT INTO `course` VALUES ('4', '操作系统', 3, 5);
INSERT INTO `course` VALUES ('5', '数据结构', 4, 6);
INSERT INTO `course` VALUES ('6', '数据处理', 2, 4);
INSERT INTO `course` VALUES ('7', 'PASCAL语言', 4, 2);
INSERT INTO `course` VALUES ('8', '大学英语', 4, 4);
INSERT INTO `course` VALUES ('9', '计算机网络', 4, 4);

INSERT INTO `test` VALUES ('200515001', '1', 75);
INSERT INTO `test` VALUES ('200515001', '4', 62);
INSERT INTO `test` VALUES ('200515001', '5', 58);
INSERT INTO `test` VALUES ('200515001', '7', 70);
INSERT INTO `test` VALUES ('200515002', '1', 85);
INSERT INTO `test` VALUES ('200515002', '3', 53);
INSERT INTO `test` VALUES ('200515002', '4', 85);
INSERT INTO `test` VALUES ('200515003', '1', 86);
INSERT INTO `test` VALUES ('200515004', '1', 74);
INSERT INTO `test` VALUES ('200515004', '2', 46);
INSERT INTO `test` VALUES ('200515005', '1', 58);
INSERT INTO `test` VALUES ('200515005', '10', 65);
INSERT INTO `test` VALUES ('200515005', '2', 89);
INSERT INTO `test` VALUES ('200515006', '1', 84);
INSERT INTO `test` VALUES ('200515006', '2', 65);
INSERT INTO `test` VALUES ('200515008', '2', 72);
INSERT INTO `test` VALUES ('200515009', '2', 76);
INSERT INTO `test` VALUES ('200515010', '2', 96);
INSERT INTO `test` VALUES ('200515010', '8', 86);
INSERT INTO `test` VALUES ('200515011', '8', 62);
INSERT INTO `test` VALUES ('200515015', '8', 0);
INSERT INTO `test` VALUES ('200515016', '8', 99);
INSERT INTO `test` VALUES ('200515017', '8', 99);
INSERT INTO `test` VALUES ('200515018', '8', 58);
INSERT INTO `test` VALUES ('200515021', '6', 58);
INSERT INTO `test` VALUES ('200515021', '9', 54);
INSERT INTO `test` VALUES ('200515029', '7', 20);

/*5.请用至少2种方法定义JXGL数据库中student表的主键sno*/
-- 方法1见2.
-- 方法2
ALTER TABLE student
ADD PRIMARY KEY (sno);

/*6.将数据库JXGL的表course的cno字段定义为主键，约束名称为cno_pk*/

-- 删除原有主键(QwQ:布吉岛原来有没有同名约束,又不想写查询的懒方法)
ALTER TABLE course
DROP PRIMARY KEY;

-- 定义主键约束
ALTER TABLE course
ADD CONSTRAINT cno_pk PRIMARY KEY (cno);

/*7.为表course中的字段cname添加唯一值约束*/
ALTER TABLE course
ADD CONSTRAINT unique_cname UNIQUE (cname);

/*8.将数据库JXGL的表test的sno及cno字段组合定义为主键，约束名称为test_pk*/

-- 删除原有主键(QwQ:布吉岛原来有没有同名约束,又不想写查询的懒方法)
ALTER TABLE test
DROP PRIMARY KEY;

-- 定义主键约束
ALTER TABLE test
ADD CONSTRAINT test_pk PRIMARY KEY (sno, cno);

/*9.对于数据表test的sno、cno字段定义为外码，使之与表student的主码sno及表course的主码cno对应，实现如下参照完整性*/

-- 1)	删除student表中记录的同时删除test表中与该记录sno字段值相同的记录；
ALTER TABLE test
ADD CONSTRAINT fk_test_sno_delete
FOREIGN KEY (sno) REFERENCES student(sno)
ON DELETE CASCADE;
-- 2)	修改student表某记录的sno时，若test表中与该字段值对应的有若干条记录，则拒绝修改；
ALTER TABLE test
ADD CONSTRAINT fk_test_sno_change
FOREIGN KEY (sno) REFERENCES student(sno)
ON UPDATE RESTRICT;
-- 3)	修改course表cno字段值时，该字段在test表中的对应值也应修改
ALTER TABLE test
ADD CONSTRAINT fk_test_cno_change
FOREIGN KEY (cno) REFERENCES course(cno)
ON UPDATE CASCADE;
-- 4)	删除course表一条记录时，若该字段在在test表中存在，则删除该字段对应的记录；
ALTER TABLE test
ADD CONSTRAINT fk_test_cno_delete
FOREIGN KEY (cno) REFERENCES course(cno)
ON DELETE CASCADE;
-- 5)	向test表添加记录时，如果该记录的sno字段的值在student中不存在，则拒绝插入；
ALTER TABLE test
ADD CONSTRAINT fk_test_sno_insert
FOREIGN KEY (sno) REFERENCES student(sno);
ON UPDATE NO ACTION;

/*10.定义check约束，要求学生成绩在0-100之*/
ALTER TABLE test
ADD CONSTRAINT chk_test_grade CHECK (grade BETWEEN 0 AND 100);

/*11.定义JXGL数据库中student表中学生年龄值在16-25范围内*/
ALTER TABLE student
ADD CONSTRAINT chk_student_age CHECK (age BETWEEN 16 AND 25);-- 若数据表中含有不符合约束的数据,则无法创建约束.

-- QwQ:检查是否有有年龄不在16到25的记录
SELECT *FROM student WHERE age NOT BETWEEN 16 AND 25;

/*12.修改JXGL数据库中student表中学生姓名长度在2-8字符之间*/
ALTER TABLE student
ADD CONSTRAINT chk_student_name_length CHECK (LENGTH(sname) BETWEEN 2 AND 8);-- 若数据表中含有不符合约束的数据,则无法创建约束.

-- QwQ:检查是否有长度不在2到8之间的记录
SELECT * FROM student WHERE LENGTH(sname) NOT BETWEEN 2 AND 8;

/*13.定义JXGL数据库中student表中学生性别列中只能输入“男”或“女”*/
ALTER TABLE student
ADD CONSTRAINT chk_student_sex CHECK (sex IN ('男', '女'));

/*14.定义JXGL数据库student表中学生年龄值默认值为20*/
ALTER TABLE student
ALTER COLUMN age SET DEFAULT 20;

/*15.修改student表学生的年龄值约束可以为15-30范围内*/

-- 删除原有的名为chk_student_age的约束
ALTER TABLE student
DROP CONSTRAINT IF EXISTS chk_student_age;

-- 创建新的CHECK约束
ALTER TABLE student
ADD CONSTRAINT chk_student_age CHECK (age BETWEEN 15 AND 30);

/*16.删除上述唯一值约束、外键约束及check约束*/

-- (1)删除唯一值约束
ALTER TABLE course
DROP CONSTRAINT unique_cname;

-- (2)删除外键约束
ALTER TABLE test
DROP CONSTRAINT fk_test_sno_change;

ALTER TABLE test
DROP CONSTRAINT fk_test_sno_delete;

ALTER TABLE test
DROP CONSTRAINT fk_test_sno_insert;

ALTER TABLE test
DROP CONSTRAINT fk_test_cno_change;

ALTER TABLE test
DROP CONSTRAINT fk_test_cno_delete;
/*
QwQ:可以合成一句,但一般情况不会同时操作很多个外键,所以通常分开写.
e.g.
ALTER TABLE test
DROP CONSTRAINT fk_test_sno_change,
DROP CONSTRAINT fk_test_sno_delete,
DROP CONSTRAINT fk_test_sno_insert;
*/

-- (3)删除check约束
-- 删除性别约束
ALTER TABLE student
DROP CONSTRAINT chk_student_sex;

-- 删除年龄约束
ALTER TABLE student
DROP CONSTRAINT chk_student_age;

-- 删除姓名长度约束
ALTER TABLE student
DROP CONSTRAINT chk_student_name_length;
-- 删除成绩约束
ALTER TABLE test
DROP CONSTRAINT chk_test_grade;

