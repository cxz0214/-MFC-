/*
 Navicat Premium Data Transfer

 Source Server         : mysql_learn
 Source Server Type    : MySQL
 Source Server Version : 80016
 Source Host           : localhost:3306
 Source Schema         : mysql_learn

 Target Server Type    : MySQL
 Target Server Version : 80016
 File Encoding         : 65001

 Date: 07/07/2019 15:25:50
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for coursetable
-- ----------------------------
DROP TABLE IF EXISTS `coursetable`;
CREATE TABLE `coursetable`  (
  `Class_number` int(11) NOT NULL,
  `T_number` int(11) NOT NULL,
  `Class_name` varchar(50) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  `Class_count` int(11) NOT NULL,
  `SetDepartment` varchar(50) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  `Credit` float(2, 1) NOT NULL,
  PRIMARY KEY (`Class_number`, `T_number`) USING BTREE,
  INDEX `FK_CourseTable_TeacherInfo`(`T_number`) USING BTREE,
  CONSTRAINT `FK_CourseTable_TeacherInfo` FOREIGN KEY (`T_number`) REFERENCES `teacherinfo` (`T_number`) ON DELETE RESTRICT ON UPDATE RESTRICT
) ENGINE = InnoDB CHARACTER SET = utf8mb4 COLLATE = utf8mb4_0900_ai_ci ROW_FORMAT = Dynamic;

SET FOREIGN_KEY_CHECKS = 1;
