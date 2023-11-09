-- 以数据库原理实验4数据库中数据为基础，请使用T-SQL 语句实现以下操作：

-- 1.	列出所有不姓刘的所有学生；
SELECT *
FROM student
WHERE sname NOT LIKE '刘%';

-- 2.	列出姓“沈”且全名为3个汉字的学生；
SELECT *
FROM student
WHERE sname LIKE '张__';

-- 3.	显示在1985年以后出生的学生的基本信息；
SELECT *
FROM student
WHERE age < 2023 - 1985;

-- 4.	按照“性别、学号、姓名、年龄、院系”的顺序列出学生信息；
SELECT sex, sno, sname, age, cgno
FROM student;

-- 5.	查询出课程名含有“数据”字串的所有课程基本信息；
SELECT *
FROM course
WHERE cname LIKE '%数据%'

-- 6.	显示学号第三位是1的学生的学号、姓名、性别、年龄及院系；
SELECT sno, sname, sex, age, cgno
FROM student
WHERE sno LIKE '__1%';

-- 7.	列出选修了‘1’课程的学生，按成绩的降序排列；
SELECT *
FROM student
JOIN test ON student.sno = test.sno
WHERE test.cno = '1'
ORDER BY test.grade DESC;

-- 8.	列出同时选修“1”号课程和“2”号课程的所有学生的学号；
SELECT student.sno
FROM student
JOIN test ON student.sno = test.sno
WHERE test.cno IN ('1', '2')
GROUP BY student.sno
HAVING count(DISTINCT test.cno) = 2;

-- 9.	列出年龄超过平均值的所有学生名单，按年龄的降序显示；
SELECT *
FROM student
WHERE age > (SELECT AVG(age) FROM student)
ORDER BY age DESC;

-- 10.	按照院系降序显示所有学生的 “院系，学号、姓名、性别、年龄”等信息；
SELECT cgno, sno, sname, sex, age
FROM student
ORDER BY cgno DESC;

-- 11.	显示所有院系（要求不能重复，不包括空值）；
SELECT DISTINCT cgno
FROM student
WHERE cgno IS NOT NULL;

-- 12.	按照课程号、成绩降序显示课程成绩在70-80之间的学生的学号、课程号及成绩；
SELECT student.sno, cno, grade
FROM student
JOIN test on student.sno =test.sno
WHERE grade BETWEEN 70 AND 80
ORDER BY cno DESC, grade DESC;

-- 13.	显示学生信息表中的学生总人数及平均年龄，在结果集中列标题分别指定为“学生总人数，平均年龄”；
SELECT count(*) AS "学生总人数", AVG(age) AS "平均年龄"
FROM student;

-- 14.	显示选修的课程数大于3的各个学生的 选修课程数；
SELECT student.sno, count(test.cno) AS "选修课程数"
FROM student
LEFT JOIN test ON student.sno = test.sno
GROUP BY student.sno
HAVING count(test.cno) > 3;

-- 15.	按课程号降序显示选修各个课程的总人数、最高成绩、最低成绩及平均成绩；
SELECT test.cno,
       count(DISTINCT test.sno) AS "总人数",
       MAX(test.grade) AS "最高成绩",
       MIN(test.grade) AS "最低成绩",
       AVG(test.grade) AS "平均成绩"
FROM test
GROUP BY test.cno
ORDER BY test.cno DESC;

-- 16.	显示平均成绩大于“200515001”学生平均成绩的各个学生的学号、平均成绩；
SELECT student.sno, AVG(test.grade) AS "平均成绩"
FROM student
JOIN test ON student.sno = test.sno
GROUP BY student.sno
HAVING AVG(test.grade) > (SELECT AVG(test.grade) FROM test WHERE sno = '200515001');

-- 17.	显示选修各个课程的及格的人数、及格比率；
SELECT test.cno,
       count(CASE WHEN test.grade >= 60 THEN 1 END) AS "及格人数",
       count(*) AS "总人数",
       count(CASE WHEN test.grade >= 60 THEN 1 END) / count(*) * 100 + '%' AS "及格比率"
FROM test
GROUP BY test.cno;

-- 18.	显示选修课程数最多的学号及选修课程数最少的学号；
-- 最多
SELECT student.sno,
       count(DISTINCT test.cno) AS "选修课程数"
FROM student
LEFT JOIN test ON student.sno = test.sno
GROUP BY student.sno
ORDER BY 选修课程数 DESC -- 此处的关键字不能加双引号,否则无效
LIMIT 1;
-- 最少
SELECT student.sno,
       count(DISTINCT test.cno) AS "选修课程数"
FROM student
LEFT JOIN test ON student.sno = test.sno
GROUP BY student.sno
ORDER BY 选修课程数; -- 此处的关键字不能加双引号,否则无效

-- 19.	显示各个院系男女生人数，其中在结果集中列标题分别指定为“院系名称、男生人数、女生人数”；
SELECT cgno AS "院系名称",
			 count(CASE WHEN sex = '男' THEN 1 END) AS "男生人数",
			 count(CASE WHEN sex = '女' THEN 1 END) AS "女生人数"
FROM student
GROUP BY cgno;

-- 20.	列出有二门以上课程（含两门）不及格的学生的学号及该学生的平均成绩；
SELECT student.sno, AVG(test.grade)
FROM student
LEFT JOIN test ON student.sno = test.sno
GROUP BY student.sno
HAVING count(CASE WHEN test.grade < 60 THEN 1 END) >= 2;
