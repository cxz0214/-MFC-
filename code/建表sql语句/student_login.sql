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

 Date: 07/07/2019 15:12:25
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for student_login
-- ----------------------------
DROP TABLE IF EXISTS `student_login`;
CREATE TABLE `student_login`  (
  `S_number` int(11) NOT NULL,
  `S_password` varchar(50) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  PRIMARY KEY (`S_number`) USING BTREE,
  CONSTRAINT `FK_Student_login_SBasicInformation` FOREIGN KEY (`S_number`) REFERENCES `sbasicinformation` (`S_number`) ON DELETE RESTRICT ON UPDATE RESTRICT
) ENGINE = InnoDB CHARACTER SET = utf8mb4 COLLATE = utf8mb4_0900_ai_ci ROW_FORMAT = Dynamic;

SET FOREIGN_KEY_CHECKS = 1;
