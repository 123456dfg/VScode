#pragma once
#include "func.h"
#define N 13
//本头文件用于存储游戏相关角色类型的结构体
typedef struct {
	int map1[2][N][N];
	int column;
	int row;
	int ceng;
} Map;
typedef struct {
	int attack ;//怪物伤害
	int defensive ;//怪物防御
	int hp ;
	int rattack ;
	int exp ;
	int leavl ;
	int key ;
	int x ;
	int y ;
	int hplimit ;
	char playername[20];
	int ceng;
} Player;

typedef struct {
	char monstername[10];
	int attack;
	int rattack;
	int hp;
	int defensive;
	int getexp;
} Monster;


