/*
 Navicat Premium Data Transfer

 Source Server         : localhost
 Source Server Type    : MySQL
 Source Server Version : 80034 (8.0.34)
 Source Host           : localhost:3306
 Source Schema         : jxgl

 Target Server Type    : MySQL
 Target Server Version : 80034 (8.0.34)
 File Encoding         : 65001

 Date: 06/11/2023 11:12:05
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for course
-- ----------------------------
DROP TABLE IF EXISTS `course`;
CREATE TABLE `course`  (
  `CNO` char(6) CHARACTER SET utf8mb3 COLLATE utf8mb3_general_ci NOT NULL,
  `CNAME` varchar(20) CHARACTER SET utf8mb3 COLLATE utf8mb3_general_ci NOT NULL,
  `CREDIT` smallint NULL DEFAULT NULL,
  `WHOURS` smallint NULL DEFAULT NULL,
  PRIMARY KEY (`CNO`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8mb3 COLLATE = utf8mb3_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of course
-- ----------------------------
INSERT INTO `course` VALUES ('1', '数据库', 4, 6);
INSERT INTO `course` VALUES ('10', '人工智能', 2, 2);
INSERT INTO `course` VALUES ('2', '数学', 2, 6);
INSERT INTO `course` VALUES ('3', '信息系统', 4, 4);
INSERT INTO `course` VALUES ('4', '操作系统', 3, 5);
INSERT INTO `course` VALUES ('5', '数据结构', 4, 6);
INSERT INTO `course` VALUES ('6', '数据处理', 3, 4);
INSERT INTO `course` VALUES ('7', 'PASCAL语言', 4, 2);
INSERT INTO `course` VALUES ('8', '大学英语', 4, 4);
INSERT INTO `course` VALUES ('9', '计算机网络', 4, 4);

-- ----------------------------
-- Table structure for student
-- ----------------------------
DROP TABLE IF EXISTS `student`;
CREATE TABLE `student`  (
  `SNO` char(9) CHARACTER SET utf8mb3 COLLATE utf8mb3_general_ci NOT NULL,
  `SNAME` varchar(10) CHARACTER SET utf8mb3 COLLATE utf8mb3_general_ci NOT NULL,
  `AGE` smallint NULL DEFAULT NULL,
  `SEX` char(2) CHARACTER SET utf8mb3 COLLATE utf8mb3_general_ci NULL DEFAULT NULL,
  `CGNO` char(5) CHARACTER SET utf8mb3 COLLATE utf8mb3_general_ci NULL DEFAULT NULL,
  UNIQUE INDEX `un_s`(`SNAME` ASC) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8mb3 COLLATE = utf8mb3_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of student
-- ----------------------------
INSERT INTO `student` VALUES ('200515021', '刘峰', 25, '男', 'CS');
INSERT INTO `student` VALUES ('200515017', '刘星耀', 18, '男', 'CM');
INSERT INTO `student` VALUES ('200515016', '刘社', 21, '男', 'CM');
INSERT INTO `student` VALUES ('220210102', '张三丰', 19, '男', 'CS');
INSERT INTO `student` VALUES ('200515014', '张丰毅', 22, '男', 'CS');
INSERT INTO `student` VALUES ('200515005', '张向东', 20, '男', 'IS');
INSERT INTO `student` VALUES ('200515006', '张向丽', 20, '女', 'IS');
INSERT INTO `student` VALUES ('222030012', '张张', NULL, NULL, NULL);
INSERT INTO `student` VALUES ('200515011', '张毅', 20, '男', 'WM');
INSERT INTO `student` VALUES ('200515004', '张衡', 18, '男', 'IS');
INSERT INTO `student` VALUES ('200515025', '朱小鸥', 30, '女', 'WM');
INSERT INTO `student` VALUES ('200515002', '李咏', 22, '男', 'CS');
INSERT INTO `student` VALUES ('200515013', '李晨', 19, '女', 'MA');
INSERT INTO `student` VALUES ('200515015', '李蕾', 21, '女', 'EN');
INSERT INTO `student` VALUES ('200515018', '李贵', 19, '男', 'EN');
INSERT INTO `student` VALUES ('200515012', '杨磊', 20, '女', 'EN');
INSERT INTO `student` VALUES ('200515026', '杨磊2', 22, '男', NULL);
INSERT INTO `student` VALUES ('200515019', '林自许', 20, '男', 'WM');
INSERT INTO `student` VALUES ('200515010', '王丹丹', 20, '女', 'MA');
INSERT INTO `student` VALUES ('200515001', '王婧婧', 25, '女', 'IS');
INSERT INTO `student` VALUES ('200515009', '王小民', 18, '女', 'MA');
INSERT INTO `student` VALUES ('200515008', '王民生', 25, '男', 'MA');
INSERT INTO `student` VALUES ('200515007', '王芳', 20, '女', 'CS');

-- ----------------------------
-- Table structure for test
-- ----------------------------
DROP TABLE IF EXISTS `test`;
CREATE TABLE `test`  (
  `SNO` char(9) CHARACTER SET utf8mb3 COLLATE utf8mb3_general_ci NOT NULL,
  `CNO` char(10) CHARACTER SET utf8mb3 COLLATE utf8mb3_general_ci NOT NULL,
  `GRADE` smallint NULL DEFAULT NULL,
  PRIMARY KEY (`SNO`, `CNO`) USING BTREE,
  CONSTRAINT `ck_grade` CHECK ((`grade` >= 0) and (`grade` <= 100))
) ENGINE = InnoDB CHARACTER SET = utf8mb3 COLLATE = utf8mb3_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of test
-- ----------------------------
INSERT INTO `test` VALUES ('200515001', '1', 80);
INSERT INTO `test` VALUES ('200515001', '4', 62);
INSERT INTO `test` VALUES ('200515001', '5', 58);
INSERT INTO `test` VALUES ('200515001', '7', 70);
INSERT INTO `test` VALUES ('200515002', '1', 90);
INSERT INTO `test` VALUES ('200515002', '3', 53);
INSERT INTO `test` VALUES ('200515002', '4', 85);
INSERT INTO `test` VALUES ('200515003', '1', 91);
INSERT INTO `test` VALUES ('200515004', '1', 79);
INSERT INTO `test` VALUES ('200515004', '2', 46);
INSERT INTO `test` VALUES ('200515005', '1', 63);
INSERT INTO `test` VALUES ('200515005', '10', 65);
INSERT INTO `test` VALUES ('200515005', '2', 89);
INSERT INTO `test` VALUES ('200515006', '1', 89);
INSERT INTO `test` VALUES ('200515006', '2', 65);
INSERT INTO `test` VALUES ('200515008', '2', 72);
INSERT INTO `test` VALUES ('200515009', '2', 76);
INSERT INTO `test` VALUES ('200515010', '2', 96);
INSERT INTO `test` VALUES ('200515010', '8', 91);
INSERT INTO `test` VALUES ('200515011', '8', 67);
INSERT INTO `test` VALUES ('200515015', '8', 5);
INSERT INTO `test` VALUES ('200515016', '8', 94);
INSERT INTO `test` VALUES ('200515017', '8', 94);
INSERT INTO `test` VALUES ('200515018', '8', 63);
INSERT INTO `test` VALUES ('200515021', '6', 58);
INSERT INTO `test` VALUES ('200515021', '9', 54);
INSERT INTO `test` VALUES ('200515029', '7', 20);

-- ----------------------------
-- Table structure for 女学生
-- ----------------------------
DROP TABLE IF EXISTS `女学生`;
CREATE TABLE `女学生`  (
  `学号` char(9) CHARACTER SET utf8mb3 COLLATE utf8mb3_general_ci NOT NULL,
  `姓名` char(10) CHARACTER SET utf8mb3 COLLATE utf8mb3_general_ci NULL DEFAULT NULL,
  `年龄` smallint NULL DEFAULT NULL
) ENGINE = InnoDB CHARACTER SET = utf8mb3 COLLATE = utf8mb3_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of 女学生
-- ----------------------------
INSERT INTO `女学生` VALUES ('200515006', '张向丽', 20);
INSERT INTO `女学生` VALUES ('200515025', '朱小鸥', 30);
INSERT INTO `女学生` VALUES ('200515013', '李晨', 19);
INSERT INTO `女学生` VALUES ('200515015', '李蕾', 21);
INSERT INTO `女学生` VALUES ('200515012', '杨磊', 20);
INSERT INTO `女学生` VALUES ('200515010', '王丹丹', 20);
INSERT INTO `女学生` VALUES ('200515001', '王婧婧', 25);
INSERT INTO `女学生` VALUES ('200515009', '王小民', 18);
INSERT INTO `女学生` VALUES ('200515007', '王芳', 20);

SET FOREIGN_KEY_CHECKS = 1;
