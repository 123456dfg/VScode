#pragma once
#include "func.h"
#define N 13
//��ͷ�ļ����ڴ洢��Ϸ��ؽ�ɫ���͵Ľṹ��
typedef struct {
	int map1[2][N][N];
	int column;
	int row;
	int ceng;
} Map;
typedef struct {
	int attack ;//�����˺�
	int defensive ;//�������
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


