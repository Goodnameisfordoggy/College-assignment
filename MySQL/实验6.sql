-- 1.	查询以‘数’开头的课程的详细情况；
SELECT *
FROM course
WHERE cname LIKE '数%';

-- 2.	查询名字中第2个字为‘向’的学生姓名和学号及选修的课程号、课程名；
SELECT student.sno, student.sname, test.cno , course.cname
FROM student
JOIN test ON student.sno = test.sno
JOIN course ON test.cno = course.cno
WHERE SUBSTRING(student.sname, 2, 1) = '向';

-- 3.	列出选修了‘数学’或者‘大学英语’的学生学号、姓名、所在院系、选修课程号及成绩；
SELECT student.sno, student.sname, student.cgno, test.cno, test.grade
FROM student
JOIN test ON student.sno = test.sno
JOIN course ON test.cno = course.cno
WHERE course.cname IN ('数学', '大学英语');

-- 4.	查询缺少成绩的所有学生的详细情况；
SELECT *
FROM student
WHERE sno NOT IN (SELECT DISTINCT sno FROM test);

-- 5.	查询与‘王芳’年龄不同的所有学生的信息；
SELECT *
FROM student
WHERE age != (SELECT age FROM student WHERE sname = '王芳');

-- 6.	查询所选课程的平均成绩大于‘王婧婧’的平均成绩的学生学号、姓名及平均成绩；
SELECT student.sno, student.sname, AVG(test.grade) AS 平均成绩
FROM student
JOIN test ON student.sno = test.sno
GROUP BY student.sno, student.sname
HAVING 平均成绩 > (SELECT AVG(test.grade) FROM student JOIN test ON student.sno = test.sno WHERE student.sname = '王婧婧');

-- 7.按照“学号，姓名，所在院系，已修学分”的顺序列出学生学分的获得情况。其中已修学分为考试已经及格的课程学分之和；
SELECT student.sno, student.sname, student.cgno, SUM(course.credit) AS 已修学分
FROM student
JOIN test ON student.sno = test.sno
JOIN course ON test.cno = course.cno
WHERE test.grade >= 60
GROUP BY student.sno, student.sname, student.cgno
ORDER BY student.sno;

-- 8.	列出只选修一门课程的学生的学号、姓名、院系及成绩；
SELECT student.sno, student.sname, student.cgno, MAX(test.grade) AS grade
FROM student
JOIN test ON student.sno = test.sno
GROUP BY student.sno, student.sname, student.cgno
HAVING COUNT(test.cno) = 1;

-- 9.	查找选修了至少一门和‘王婧婧’选修课程一样的学生的学号、姓名及课程号；
SELECT DISTINCT s1.sno, s1.sname, t1.cno
FROM student s1
JOIN test t1 ON s1.sno = t1.sno
WHERE t1.cno IN (SELECT t2.cno
                 FROM student s2
                 JOIN test t2 ON s2.sno = t2.sno
                 WHERE s2.sname = '王婧婧');

-- 10.	只选修“数据库”和“数据结构”两门课程的学生的基本信息；
SELECT s.sno, s.sname, s.cgno
FROM student s
JOIN test t ON s.sno = t.sno
WHERE t.cno IN ('1', '5')
GROUP BY s.sno, s.sname, s.cgno
HAVING COUNT(DISTINCT t.cno) = 2;

-- 11.	至少选修“数据库”或“数据结构”课程的学生的基本信息；
SELECT s.sno, s.sname, s.cgno
FROM student s
JOIN test t ON s.sno = t.sno
WHERE t.cno IN ('1', '5')
GROUP BY s.sno, s.sname, s.cgno;

-- 12.	列出所有课程被选修的详细情况，包括课程号、课程名、学号、姓名及成绩；
select c.cno, c.cname, s.sno, s.sname, t.grade
from course c
join test t on c.cno = t.cno
join student s on t.sno = s.sno;

-- 13.	查询只被一名学生选修的课程的课程号、课程名；
SELECT test.cno, course.cname
FROM test
JOIN course ON test.cno = course.cno
GROUP BY test.cno, course.cname
HAVING COUNT(DISTINCT test.sno) = 1;

-- 14.	检索所学课程包含学生‘张向东’所学课程的学生学号、姓名；
SELECT DISTINCT s.sno, s.sname
FROM student s
JOIN test t ON s.sno = t.sno
WHERE t.cno IN (
    SELECT t2.cno
    FROM test t2
    JOIN student s2 ON t2.sno = s2.sno
    WHERE s2.sname = '张向东'
);

-- 15.	使用嵌套查询列出选修了“数据结构”课程的学生学号和姓名；
SELECT sno, sname
FROM student
WHERE sno IN (
    SELECT sno
    FROM test
    WHERE cno = '5'  -- 数据结构的课程号
);

-- 16.	使用嵌套查询查询其它系中年龄小于CS系的某个学生的学生姓名、年龄和院系；
SELECT sname, age, cgno
FROM student
WHERE cgno != 'CS' AND age < (SELECT MAX(age) FROM student WHERE cgno = 'CS');

-- 17.	使用ANY、ALL 查询，列出其他院系中比CS系所有学生年龄小的学生；
SELECT sname, age, cgno
FROM student
WHERE age < ALL (SELECT age FROM student WHERE cgno = 'CS')
  AND cgno != 'CS';

-- 18.	分别使用连接查询和嵌套查询，列出与‘王婧婧’在一个院系的学生的信息；
-- 使用连接查询
SELECT s2.sno, s2.sname, s2.cgno
FROM student s1
JOIN student s2 ON s1.cgno = s2.cgno
WHERE s1.sname = '王婧婧';

-- 使用嵌套查询
SELECT sno, sname, cgno
FROM student
WHERE cgno = (SELECT cgno FROM student WHERE sname = '王婧婧');

-- 19.	使用集合查询列出CS系的学生以及性别为女的学生名单；?
SELECT sno, sname, sex
FROM student
WHERE cgno = 'CS'
INTERSECT
SELECT sno, sname, sex
FROM student
WHERE sex = '女';

-- 20.	使用集合查询列出CS系的学生与年龄不大于19岁的学生的交集、差集；
-- 交集
SELECT sno, sname, age, cgno
FROM student
WHERE cgno = 'CS'
INTERSECT
SELECT sno, sname, age, cgno
FROM student
WHERE age <= 19;

-- 差集
SELECT sno, sname, age, cgno
FROM student
WHERE cgno = 'CS'
EXCEPT
SELECT sno, sname, age, cgno
FROM student
WHERE age <= 19;

-- 21.	使用集合查询列出选修课程1的学生集合与选修课程2的学生集合的交集；
SELECT test.sno, sname
FROM test
JOIN student ON test.sno =student.sno
WHERE cno = '1'
INTERSECT
SELECT test.sno, sname
FROM test
JOIN student ON test.sno =student.sno
WHERE cno = '2';

