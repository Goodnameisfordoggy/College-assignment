/*
Navicat MySQL Data Transfer

Source Server         : localhost
Source Server Version : 50725
Source Host           : localhost:3306
Source Database       : job

Target Server Type    : MYSQL
Target Server Version : 50725
File Encoding         : 65001

Date: 2023-04-06 14:25:06
*/

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for food
-- ----------------------------
DROP TABLE IF EXISTS `food`;
CREATE TABLE `food` (
  `foodid` int(4) NOT NULL AUTO_INCREMENT,
  `name` varchar(20) NOT NULL,
  `company` varchar(30) NOT NULL,
  `price` float NOT NULL,
  `product_time` year(4) DEFAULT NULL,
  `validity_time` int(4) DEFAULT NULL,
  `address` varchar(50) DEFAULT NULL,
  PRIMARY KEY (`foodid`),
  UNIQUE KEY `foodid` (`foodid`)
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of food
-- ----------------------------
INSERT INTO `food` VALUES ('1', 'QQ饼干', 'QQ饼干厂', '2.5', '2021', '3', '北京');
INSERT INTO `food` VALUES ('2', 'MN牛奶', 'MN牛奶厂', '3.5', '2020', '1', '河北');
INSERT INTO `food` VALUES ('3', 'EE果冻', 'EE果冻厂', '1.5', '2020', '2', '北京');
INSERT INTO `food` VALUES ('4', 'FF咖啡', 'FF咖啡厂', '20', '2020', '5', '天津');
INSERT INTO `food` VALUES ('5', 'GG奶糖', 'GG奶糖', '14', '2021', '3', '广东');

-- ----------------------------
-- Table structure for food_copy
-- ----------------------------
DROP TABLE IF EXISTS `food_copy`;
CREATE TABLE `food_copy` (
  `foodid` int(4) NOT NULL AUTO_INCREMENT,
  `name` varchar(20) NOT NULL,
  `company` varchar(30) NOT NULL,
  `price` float NOT NULL,
  `product_time` year(4) DEFAULT NULL,
  `validity_time` int(4) DEFAULT NULL,
  `address` varchar(50) DEFAULT NULL,
  PRIMARY KEY (`foodid`),
  UNIQUE KEY `foodid` (`foodid`)
) ENGINE=InnoDB AUTO_INCREMENT=11 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of food_copy
-- ----------------------------
INSERT INTO `food_copy` VALUES ('1', 'QQ饼干', 'QQ饼干厂', '2.5', '2021', '3', '北京');
INSERT INTO `food_copy` VALUES ('2', 'MN牛奶', 'MN牛奶厂', '3.5', '2020', '1', '河北');
INSERT INTO `food_copy` VALUES ('3', 'EE果冻', 'EE果冻厂', '1.5', '2020', '2', '北京');
INSERT INTO `food_copy` VALUES ('4', 'FF咖啡', 'FF咖啡厂', '20', '2020', '5', '天津');
INSERT INTO `food_copy` VALUES ('5', 'GG奶糖', 'GG奶糖', '14', '2021', '3', '广东');
INSERT INTO `food_copy` VALUES ('6', 'QQ饼干', 'QQ饼干厂', '2.5', '2021', '3', '北京');
INSERT INTO `food_copy` VALUES ('7', 'MN牛奶', 'MN牛奶厂', '3.5', '2020', '1', '河北');
INSERT INTO `food_copy` VALUES ('8', 'EE果冻', 'EE果冻厂', '1.5', '2020', '2', '北京');
INSERT INTO `food_copy` VALUES ('9', 'FF咖啡', 'FF咖啡厂', '20', '2020', '5', '天津');
INSERT INTO `food_copy` VALUES ('10', 'GG奶糖', 'GG奶糖', '14', '2021', '3', '广东');

-- ----------------------------
-- Table structure for information
-- ----------------------------
DROP TABLE IF EXISTS `information`;
CREATE TABLE `information` (
  `id` int(4) NOT NULL AUTO_INCREMENT,
  `name` varchar(20) NOT NULL,
  `sex` varchar(4) NOT NULL,
  `birthday` date DEFAULT NULL,
  `address` varchar(50) DEFAULT NULL,
  `tel` varchar(20) DEFAULT NULL,
  `pic` blob,
  PRIMARY KEY (`id`),
  UNIQUE KEY `id` (`id`),
  UNIQUE KEY `index_id` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of information
-- ----------------------------

-- ----------------------------
-- Table structure for operate
-- ----------------------------
DROP TABLE IF EXISTS `operate`;
CREATE TABLE `operate` (
  `op_id` int(10) NOT NULL AUTO_INCREMENT,
  `op_name` varchar(20) NOT NULL,
  `op_tiem` time NOT NULL,
  PRIMARY KEY (`op_id`),
  UNIQUE KEY `op_id` (`op_id`)
) ENGINE=InnoDB AUTO_INCREMENT=17 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of operate
-- ----------------------------
INSERT INTO `operate` VALUES ('1', 'Insert product', '18:26:43');
INSERT INTO `operate` VALUES ('3', 'update product', '18:28:47');
INSERT INTO `operate` VALUES ('4', 'delete product', '18:28:56');
INSERT INTO `operate` VALUES ('5', 'Insert product', '18:29:33');
INSERT INTO `operate` VALUES ('6', 'Insert product', '09:43:22');
INSERT INTO `operate` VALUES ('7', 'update product', '09:43:53');
INSERT INTO `operate` VALUES ('10', 'Insert product', '14:24:07');
INSERT INTO `operate` VALUES ('11', 'update product', '14:24:47');
INSERT INTO `operate` VALUES ('12', 'delete product', '14:24:56');
INSERT INTO `operate` VALUES ('13', 'Insert product', '14:38:54');
INSERT INTO `operate` VALUES ('14', 'Insert product', '14:37:38');
INSERT INTO `operate` VALUES ('15', 'update product', '14:38:35');
INSERT INTO `operate` VALUES ('16', 'delete product', '14:38:57');

-- ----------------------------
-- Table structure for product
-- ----------------------------
DROP TABLE IF EXISTS `product`;
CREATE TABLE `product` (
  `id` int(10) NOT NULL,
  `name` varchar(20) NOT NULL,
  `function` varchar(50) DEFAULT NULL,
  `company` varchar(20) NOT NULL,
  `address` varchar(50) DEFAULT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `id` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of product
-- ----------------------------
INSERT INTO `product` VALUES ('2', 'abc', '治疗感冒', '北京abc制药厂', '北京市昌平区');
INSERT INTO `product` VALUES ('3', 'abc', '治疗感冒', '北京abc制药厂', '北京市昌平区');
INSERT INTO `product` VALUES ('5', 'abc', '治疗感冒', '北京abc制药厂', '北京市昌平区');

-- ----------------------------
-- Table structure for userlogin
-- ----------------------------
DROP TABLE IF EXISTS `userlogin`;
CREATE TABLE `userlogin` (
  `id` int(4) NOT NULL AUTO_INCREMENT,
  `name` varchar(20) NOT NULL,
  `password` varchar(20) NOT NULL,
  `info` text,
  PRIMARY KEY (`id`),
  UNIQUE KEY `id` (`id`),
  KEY `index_name` (`name`(10))
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of userlogin
-- ----------------------------

-- ----------------------------
-- Table structure for work_info
-- ----------------------------
DROP TABLE IF EXISTS `work_info`;
CREATE TABLE `work_info` (
  `id` int(4) NOT NULL,
  `name` varchar(20) NOT NULL,
  `sex` varchar(4) NOT NULL,
  `age` int(11) DEFAULT NULL,
  `address` varchar(50) DEFAULT NULL,
  `tel` varchar(20) DEFAULT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `id` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of work_info
-- ----------------------------
INSERT INTO `work_info` VALUES ('2', '李广', '男', '21', '北京市昌平区', '2345678');
INSERT INTO `work_info` VALUES ('3', '王丹', '女', '18', '湖南省永州市', '3456789');
INSERT INTO `work_info` VALUES ('4', '赵一枚', '女', '24', '浙江宁波市', '4567890');
INSERT INTO `work_info` VALUES ('11', '张明明', '男', '19', '北京市朝阳区', '1234567');

-- ----------------------------
-- View structure for info_view
-- ----------------------------
DROP VIEW IF EXISTS `info_view`;
CREATE ALGORITHM=UNDEFINED DEFINER=`root`@`localhost` SQL SECURITY DEFINER VIEW `info_view` AS select `work_info`.`id` AS `id`,`work_info`.`name` AS `name`,`work_info`.`sex` AS `sex`,`work_info`.`address` AS `address` from `work_info` where (`work_info`.`age` < 20) ;

-- ----------------------------
-- Procedure structure for pfood_price_count
-- ----------------------------
DROP PROCEDURE IF EXISTS `pfood_price_count`;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `pfood_price_count`(in price_info1 FLOAT,price_info2 FLOAT,out count INT)
begin
select count(*) into count FROM food
where price BETWEEN price_info1 AND price_info2;
end
;;
DELIMITER ;

-- ----------------------------
-- Procedure structure for pfood_price_count_sum
-- ----------------------------
DROP PROCEDURE IF EXISTS `pfood_price_count_sum`;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `pfood_price_count_sum`(in price_info1 FLOAT,price_info2 FLOAT,out count INT,sum FLOAT)
begin
select count(*) into count FROM food
where price BETWEEN price_info1 AND price_info2;
select SUM(price) INTO sum FROM food
where price BETWEEN price_info1 AND price_info2;
end
;;
DELIMITER ;

-- ----------------------------
-- Procedure structure for pfood_price_sum
-- ----------------------------
DROP PROCEDURE IF EXISTS `pfood_price_sum`;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `pfood_price_sum`(in price_info1 FLOAT,price_info2 FLOAT,out sum FLOAT)
begin
select SUM(price) INTO sum FROM food
where price BETWEEN price_info1 AND price_info2;
end
;;
DELIMITER ;

-- ----------------------------
-- Function structure for ffood_price_count
-- ----------------------------
DROP FUNCTION IF EXISTS `ffood_price_count`;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` FUNCTION `ffood_price_count`(price1 float,price2 float) RETURNS int(11)
    READS SQL DATA
begin
declare count INT;
select count(*) into count FROM food
where price BETWEEN price1 AND price2;
RETURN count;
end
;;
DELIMITER ;

-- ----------------------------
-- Function structure for ffood_price_sum
-- ----------------------------
DROP FUNCTION IF EXISTS `ffood_price_sum`;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` FUNCTION `ffood_price_sum`(price1 float,price2 float) RETURNS float
    NO SQL
begin
declare sum float;
select SUM(price) INTO sum FROM food
where price BETWEEN price1 AND price2;
return sum;
end
;;
DELIMITER ;
DROP TRIGGER IF EXISTS `tproduct_bf_insert`;
DELIMITER ;;
CREATE TRIGGER `tproduct_bf_insert` BEFORE INSERT ON `product` FOR EACH ROW BEGIN
INSERT INTO operate  VALUES (NULL,'Insert product',NOW());
END
;;
DELIMITER ;
DROP TRIGGER IF EXISTS `tproduct_af_update`;
DELIMITER ;;
CREATE TRIGGER `tproduct_af_update` AFTER UPDATE ON `product` FOR EACH ROW BEGIN
INSERT INTO operate  VALUES (NULL,'update product',NOW());
END
;;
DELIMITER ;
DROP TRIGGER IF EXISTS `tproduct_af_del`;
DELIMITER ;;
CREATE TRIGGER `tproduct_af_del` AFTER DELETE ON `product` FOR EACH ROW BEGIN
INSERT INTO operate  VALUES (NULL,'delete product',NOW());
END
;;
DELIMITER ;
