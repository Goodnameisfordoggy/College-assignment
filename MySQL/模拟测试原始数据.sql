/*
Navicat MySQL Data Transfer

Source Server         : root
Source Server Version : 50717
Source Host           : localhost:3306
Source Database       : jxgl

Target Server Type    : MYSQL
Target Server Version : 50717
File Encoding         : 65001

Date: 2023-12-07 10:18:30
*/

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for course
-- ----------------------------
DROP TABLE IF EXISTS `course`;
CREATE TABLE `course` (
  `cno` varchar(8) NOT NULL,
  `cname` varchar(50) NOT NULL,
  `ccredit` int(11) NOT NULL,
  `cdept` varchar(20) NOT NULL,
  PRIMARY KEY (`cno`) USING BTREE
) ENGINE=InnoDB DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC;

-- ----------------------------
-- Records of course
-- ----------------------------
INSERT INTO `course` VALUES ('11110140', '大数据管理', '3', '人工智能学院');
INSERT INTO `course` VALUES ('11110470', '数据分析与可视化', '3', '人工智能学院');
INSERT INTO `course` VALUES ('11110930', '电子商务', '2', '人工智能学院');
INSERT INTO `course` VALUES ('11111260', '客户关系管理', '2', '人工智能学院');
INSERT INTO `course` VALUES ('11140260', '新媒体运营', '2', '信息学院');
INSERT INTO `course` VALUES ('18110140', 'Python程序设计', '3', '信息学院');
INSERT INTO `course` VALUES ('18111850', '数据库原理', '3', '大数据学院');
INSERT INTO `course` VALUES ('18112820', '网站设计与开发', '2', '信息学院');
INSERT INTO `course` VALUES ('18130320', 'Internet技术及应用', '2', '信息学院');
INSERT INTO `course` VALUES ('18132220', '数据库技术及应用', '2', '大数据学院');
INSERT INTO `course` VALUES ('18132370', 'Java程序设计', '2', '信息学院');
INSERT INTO `course` VALUES ('18132600', '数据库原理与应用A', '3', '大数据学院');
INSERT INTO `course` VALUES ('58130060', 'Python程序设计', '3', '信息学院');
INSERT INTO `course` VALUES ('58130540', '大数据技术及应用', '3', '大数据学院');

-- ----------------------------
-- Table structure for sc
-- ----------------------------
DROP TABLE IF EXISTS `sc`;
CREATE TABLE `sc` (
  `sno` char(20) NOT NULL,
  `cno` varchar(20) NOT NULL,
  `grade` float DEFAULT NULL,
  PRIMARY KEY (`sno`,`cno`) USING BTREE,
  KEY `cno` (`cno`) USING BTREE,
  KEY `in_sno` (`sno`) USING BTREE,
  CONSTRAINT `frk_sc_c` FOREIGN KEY (`cno`) REFERENCES `course` (`cno`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC;

-- ----------------------------
-- Records of sc
-- ----------------------------
INSERT INTO `sc` VALUES ('202011855228', '18132220', '96');
INSERT INTO `sc` VALUES ('202011855321', '11110470', '69');
INSERT INTO `sc` VALUES ('202012855223', '18130320', '60');
INSERT INTO `sc` VALUES ('202012855223', '58130540', '77');
INSERT INTO `sc` VALUES ('202014070116', '11110930', '65');
INSERT INTO `sc` VALUES ('202014070116', '18130320', '90');
INSERT INTO `sc` VALUES ('202014855302', '11110140', '90');
INSERT INTO `sc` VALUES ('202014855328', '18130320', '96');
INSERT INTO `sc` VALUES ('202014855328', '58130540', '85');
INSERT INTO `sc` VALUES ('202014855406', '11110470', '86');
INSERT INTO `sc` VALUES ('202014855406', '18110140', '75');
INSERT INTO `sc` VALUES ('202014855406', '18132220', '84');
INSERT INTO `sc` VALUES ('202018855232', '18110140', '87');
INSERT INTO `sc` VALUES ('202018855232', '58130540', '91');

-- ----------------------------
-- Table structure for specialty
-- ----------------------------
DROP TABLE IF EXISTS `specialty`;
CREATE TABLE `specialty` (
  `zno` char(4) COLLATE utf8_bin NOT NULL COMMENT '专业号',
  `zname` varchar(50) COLLATE utf8_bin DEFAULT NULL COMMENT '专业名',
  PRIMARY KEY (`zno`) USING BTREE
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_bin ROW_FORMAT=DYNAMIC COMMENT='专业表';

-- ----------------------------
-- Records of specialty
-- ----------------------------
INSERT INTO `specialty` VALUES ('1102', '数据科学与大数据技术');
INSERT INTO `specialty` VALUES ('1103', '人工智能');
INSERT INTO `specialty` VALUES ('1201', '计算机科学与技术');
INSERT INTO `specialty` VALUES ('1214', '区块链工程');
INSERT INTO `specialty` VALUES ('1407', '健康服务与管理 ');
INSERT INTO `specialty` VALUES ('1409', '智能医学工程');
INSERT INTO `specialty` VALUES ('1601', '供应链管理 ');
INSERT INTO `specialty` VALUES ('1805', '智能感知工程');
INSERT INTO `specialty` VALUES ('1807', '智能装备与系统');

-- ----------------------------
-- Table structure for stud
-- ----------------------------
DROP TABLE IF EXISTS `stud`;
CREATE TABLE `stud` (
  `sno` char(20) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL COMMENT '学号',
  `sname` varchar(20) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL COMMENT '姓名',
  `ssex` enum('男','女') NOT NULL DEFAULT '男' COMMENT '性别',
  `sbirth` date NOT NULL COMMENT '出生日期',
  `zno` char(4) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL COMMENT '专业号',
  `sclass` varchar(10) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL COMMENT '班级',
  PRIMARY KEY (`sno`) USING BTREE,
  KEY `zno` (`zno`) USING BTREE,
  CONSTRAINT `zno` FOREIGN KEY (`zno`) REFERENCES `specialty` (`zno`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC;

-- ----------------------------
-- Records of stud
-- ----------------------------
INSERT INTO `stud` VALUES ('202011070338', '孙一凯', '男', '2000-10-11', '1102', '大数据2001');
INSERT INTO `stud` VALUES ('202011855228', '唐晓', '女', '2002-11-05', '1102', '大数据2001');
INSERT INTO `stud` VALUES ('202011855321', '蓝梅', '女', '2002-07-02', '1102', '大数据2001');
INSERT INTO `stud` VALUES ('202011855426', '余小梅', '女', '2002-06-18', '1102', '大数据2001');
INSERT INTO `stud` VALUES ('202012040137', '郑熙婷', '女', '2003-05-23', '1214', '区块链2001');
INSERT INTO `stud` VALUES ('202012855223', '徐美利', '女', '2000-09-07', '1214', '区块链2001');
INSERT INTO `stud` VALUES ('202014070116', '欧阳贝贝', '女', '2002-01-08', '1407', '健管2001');
INSERT INTO `stud` VALUES ('202014320425', '曹平', '女', '2002-12-14', '1407', '健管2001');
INSERT INTO `stud` VALUES ('202014855302', '李壮', '男', '2003-01-17', '1409', '智能医学2001');
INSERT INTO `stud` VALUES ('202014855308', '马琦', '男', '2003-06-14', '1409', '智能医学2001');
INSERT INTO `stud` VALUES ('202014855328', '刘梅红', '女', '2000-06-12', '1407', '健管2001');
INSERT INTO `stud` VALUES ('202014855406', '王松', '男', '2003-10-06', '1409', '智能医学2001');
INSERT INTO `stud` VALUES ('202016855305', '聂鹏飞', '男', '2002-08-25', '1601', '供应链2001');
INSERT INTO `stud` VALUES ('202016855313', '郭爽', '女', '2001-02-14', '1601', '供应链2001');
INSERT INTO `stud` VALUES ('202018855212', '李冬旭', '男', '2003-06-08', '1805', '智能感知2001');
INSERT INTO `stud` VALUES ('202018855232', '王琴雪', '女', '2002-07-20', '1805', '智能感知2001');
