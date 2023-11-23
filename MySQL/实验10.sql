-- 1．在product表上分别创建BEFOREINSERT、AFTERUPDATE和AFTERDELETE这3个触发器，触发器的名称分别为Tproduct_bf_insert、Tproduct_af_update和Tproduct_af_del。执行语句部分都是向operate表插入操作方法和操作时间。

-- （1）创建Tproduct_bf_insert触发器SQL代码。.
DELIMITER //

CREATE TRIGGER Tproduct_bf_insert
BEFORE INSERT ON product
FOR EACH ROW
BEGIN
    INSERT INTO operate (op_name, op_time)
    VALUES ('INSERT', NOW());
END //

DELIMITER ;

-- （2）创建Tproduct_af_update触发器的SQL代码。
DELIMITER //

CREATE TRIGGER Tproduct_af_update
AFTER UPDATE ON product
FOR EACH ROW
BEGIN
    INSERT INTO operate (op_name, op_time)
    VALUES ('UPDATE', NOW());
END //

DELIMITER ;

-- （3）创建Tproduct_af_del触发器的SQL代码。
DELIMITER //

CREATE TRIGGER Tproduct_af_del
AFTER DELETE ON product
FOR EACH ROW
BEGIN
    INSERT INTO operate (op_name, op_time)
    VALUES ('DELETE', NOW());
END //

DELIMITER ;

-- 2．对product表分别执行INSERT、UPDATE和DELETE操作，分别查看operate表。
-- （1）对product表中插入一条记录：1,'abc','治疗感冒','北京abc制药厂','北京市昌平区'。
-- 原始数据中operate表里的op_time不存在,拼错了改过来就好了.
INSERT INTO product (id, name,  `function`, company, address) 
VALUES (1, 'abc', '治疗感冒', '北京abc制药厂', '北京市昌平区');

-- （2）更新记录，将产品编号为1的厂商住址：改为“北京市海淀区”。
UPDATE product SET address = '北京市海淀区' WHERE id = 1;

-- （3）删除产品编号为1的记录。
DELETE FROM product WHERE id = 1;

-- 3．删除Tproduct_bf_update触发器。
DROP TRIGGER IF EXISTS Tproduct_af_update;