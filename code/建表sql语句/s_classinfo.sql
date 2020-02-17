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

 Date: 07/07/2019 15:27:20
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for s_classinfo
-- ----------------------------
DROP TABLE IF EXISTS `s_classinfo`;
CREATE TABLE `s_classinfo`  (
  `S_number` int(11) NOT NULL,
  `S_grade` int(11) NULL DEFAULT NULL,
  `T_number` int(11) NOT NULL,
  `Class_number` int(11) NOT NULL,
  PRIMARY KEY (`S_number`, `T_number`, `Class_number`) USING BTREE,
  INDEX `FK_S_classInfo_CourseTable`(`Class_number`, `T_number`) USING BTREE,
  CONSTRAINT `FK_S_classInfo_CourseTable` FOREIGN KEY (`Class_number`, `T_number`) REFERENCES `coursetable` (`Class_number`, `T_number`) ON DELETE RESTRICT ON UPDATE RESTRICT,
  CONSTRAINT `FK_S_classInfo_SBasicInformation` FOREIGN KEY (`S_number`) REFERENCES `sbasicinformation` (`S_number`) ON DELETE RESTRICT ON UPDATE RESTRICT
) ENGINE = InnoDB CHARACTER SET = utf8mb4 COLLATE = utf8mb4_0900_ai_ci ROW_FORMAT = Dynamic;

SET FOREIGN_KEY_CHECKS = 1;
