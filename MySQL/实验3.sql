
UPDATE student SET sname='李咏' WHERE sname='李勇' AND cgno='CS';
UPDATE course SET credit=3 WHERE cname='数据处理';
UPDATE test SET grade=grade+5 WHERE cno=1;
UPDATE test SET grade=grade+5 WHERE cno=8;
UPDATE student SET sname='王丹丹', ssex='女', sage=20, cgno='MA' WHERE sno='200515010';
UPDATE student SET sname='王婧婧', cgno='IS' WHERE sno='200515005';
DELETE FROM student WHERE cgno IS NULL;
DELETE FROM student WHERE sage>25 AND ssex='男';
DELETE FROM course WHERE credit<1;
