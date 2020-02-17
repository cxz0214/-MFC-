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

 Date: 07/07/2019 15:09:54
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for teacher_login
-- ----------------------------
DROP TABLE IF EXISTS `teacher_login`;
CREATE TABLE `teacher_login`  (
  `T_number` int(11) NOT NULL,
  `T_password` varchar(50) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  PRIMARY KEY (`T_number`) USING BTREE,
  CONSTRAINT `FK_Teacher_login_TeacherInfo` FOREIGN KEY (`T_number`) REFERENCES `teacherinfo` (`T_number`) ON DELETE RESTRICT ON UPDATE RESTRICT
) ENGINE = InnoDB CHARACTER SET = utf8mb4 COLLATE = utf8mb4_0900_ai_ci ROW_FORMAT = Dynamic;

SET FOREIGN_KEY_CHECKS = 1;
