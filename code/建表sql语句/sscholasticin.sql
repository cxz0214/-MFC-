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

 Date: 07/07/2019 15:20:14
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for sscholasticin
-- ----------------------------
DROP TABLE IF EXISTS `sscholasticin`;
CREATE TABLE `sscholasticin`  (
  `S_number` int(11) NOT NULL,
  `S_class` int(6) NULL DEFAULT 0,
  `S_serial` smallint(6) NULL DEFAULT 0,
  `S_department` varchar(50) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL,
  `S_major` varchar(50) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL,
  `S_gpa` float(3, 2) NULL DEFAULT 0.00,
  PRIMARY KEY (`S_number`) USING BTREE,
  CONSTRAINT `FK_SScholasticIn_SBasicInformation` FOREIGN KEY (`S_number`) REFERENCES `sbasicinformation` (`S_number`) ON DELETE RESTRICT ON UPDATE RESTRICT
) ENGINE = InnoDB CHARACTER SET = utf8mb4 COLLATE = utf8mb4_0900_ai_ci ROW_FORMAT = Dynamic;

SET FOREIGN_KEY_CHECKS = 1;
