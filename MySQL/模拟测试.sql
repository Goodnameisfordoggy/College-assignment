-- 1、在student表中插入你的个人信息。
INSERT INTO stud (sno, sname, ssex, sbirth, zno, sclass)
VALUES ('228212118', '霍东君', '男', '2004-02-23', '1201', '计算机2221');

-- 2、根据提供数据为自己选两门课。
INSERT INTO sc (sno, cno, grade)
VALUES ('228212118', '11110140', NULL);

INSERT INTO sc (sno, cno, grade)
VALUES ('228212118', '11110470', NULL);

-- 3、删除自己的一门选课信息。
DELETE FROM sc
WHERE sno = '228212118' AND cno = '11110140';

-- 4、更新王琴雪为王雪琴。
UPDATE stud
SET sname = '王雪琴' WHERE sname = '王琴雪';

-- 5、查询每门课程的选课人数，查询结果要求提供姓名，课程名和选课门数并按照姓名排序。
SELECT s.sname, c.cname, COUNT(sc.sno) AS '选课人数'
FROM sc
JOIN stud s ON sc.sno = s.sno
JOIN course c ON sc.cno = c.cno
GROUP BY s.sno, c.cno
ORDER BY s.sname;

-- 6、查询欧阳贝贝的选课情况，查询结果显示：姓名，课程名和分数。
SELECT s.sname, c.cname, sc.grade
FROM sc sc
JOIN stud s ON sc.sno = s.sno
JOIN course c ON sc.cno = c.cno
WHERE s.sname = '欧阳贝贝';

-- 7、查询选课人数前三的课程号和选课人数。
SELECT cno, COUNT(sno) AS '选课人数'
FROM sc
GROUP BY cno
ORDER BY COUNT(sno) DESC
LIMIT 3;

-- 8、查询姓王的同学信息。
SELECT *
FROM stud
WHERE sname LIKE '王%';

-- 9、查询没有成绩的课程号和学号。
SELECT sno, cno
FROM sc
WHERE grade IS NULL;

-- 10、使用集合查询列出1407系的学生以及性别为女的学生名单；
SELECT *
FROM stud
WHERE zno = '1407'

UNION

SELECT *
FROM stud
WHERE ssex = '女';

-- 11、创建视图，查询所有学生的姓名，选课门数，平均成绩并按照姓名升序排序。
CREATE VIEW Student_v AS
SELECT s.sname, COUNT(sc.cno) AS '选课门数', AVG(sc.grade) AS '平均成绩'
FROM stud s
LEFT JOIN sc sc ON s.sno = sc.sno
GROUP BY s.sname
ORDER BY s.sname ASC;

SELECT *
FROM Student_v
ORDER BY sname ASC;


