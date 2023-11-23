-- (1)在food表上创建名为Pfood_price_count的存储过程。其中存储过程Pfood_price_count有3个参数。输入参数为price_info1和price_info2，输出参数为count。存储过程的满足：查询food表中食品单价高于price_info1且低于price_info2的食品种数，然后由count参数来输出，并且计算满足条件的单价的总和。
DELIMITER //

CREATE PROCEDURE Pfood_price_count(IN price_info1 FLOAT, IN price_info2 FLOAT, OUT count INT)
BEGIN
    SELECT COUNT(*), SUM(Price)
    INTO count, @sum
    FROM Food
    WHERE Price > price_info1 AND Price < price_info2;
END //

DELIMITER ;


-- (2)使用CALL语句来调用存储过程。查询价格在2至18之间的食品种数。
CALL Pfood_price_count(2, 18, @count);

-- (3)使用SELECT语句查看结果。
-- 其中，count是存储过程的输出结果：sum是存储过程中的变量，sum中的值满足条件的单价的总和。
SELECT @count AS FoodCount, @sum AS sumPrice;

-- (4)使用DROP语句删除存储过程Pfood_price_count。
DROP PROCEDURE IF EXISTS Pfood_price_count;

-- (5)使用存储函数来实现（1）的要求。 -- QwQ:Mysql中UDF(用户自定义函数)只能返回一个值
DELIMITER //

CREATE FUNCTION Ffood_price_count(price_info1 FLOAT, price_info2 FLOAT) RETURNS INT DETERMINISTIC
BEGIN
    DECLARE count_result INT;

    -- 查询满足条件的食品数量
    SELECT COUNT(*)
    INTO count_result
    FROM Food
    WHERE Price > price_info1 AND Price < price_info2;

    RETURN count_result;
END //

DELIMITER ;


-- (6)调用存储函数。
SELECT Ffood_price_count(2, 18) AS FoodCount;

-- (7)删除存储函数。
DROP FUNCTION IF EXISTS Ffood_price_count;

