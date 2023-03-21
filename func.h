#pragma once
//本头文件用于定义和实现函数
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include"init_golbalvar.h"
#include"struct.h"
#include<io.h>
#include<conio.h>
#define red  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED); //红色
#define nop SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);   //原色
#define blue SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);			//蓝色
#define green SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);  //绿色
#define white SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);  //白色
#define pink SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |FOREGROUND_BLUE);//粉色
#define ching SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN |FOREGROUND_BLUE);  //青色
int getdamage(Monster monster,Player player) ;//受到伤害计算
int damage(Monster monster,Player player); //对怪物造成的伤害计算
void gamehelp();//游戏帮助
void menu();
int kill(Player *player);
void setplayername(Player*);
void printmap(Map);
int win(Map map);
void printBoard(Player);
void move(Player *,Map *);
void levelup(Player* player);
int vs(Player* player,Monster monster);
void printmonster(Monster monster);
int win(Map map) {
	if (map.ceng == 3) {
		printf("恭喜你已经通关\t\n未完待续\t\n");
		printf("游戏即将退出\n");
		return 1;
	} else return 0;
}
void levelup(Player* player) {
	if (player->exp >= 100) {
		printf("你升级了");
		player->attack+=10;
		player->defensive+=5;
		player->hplimit+=20;
		player->hp = player->hplimit;
		player->exp =player->exp-100;
		player->leavl += 1;
	}
}
int damage(Monster monster,Player player) {
	int flag;
	int attack;
	flag = player.attack+player.rattack - monster.defensive;
	if (flag > 0) {
		attack = flag;
	} else attack = player.rattack;
	return attack;
}
int getdamage(Monster monster,Player player) {
	int flag;
	int getattack;
	flag = monster.attack+monster.rattack - player.defensive;
	if (flag > 0) {
		getattack = flag;
	} else getattack = monster.rattack;
	return getattack;
}
int kill(Player *player) {
	if (player->hp <= 0) {
		printf("玩家死亡游戏结束");
		system("pause");
		return 1;
	} else return 0;
}
void printmonster(Monster monster) {
	printf ("----------------------------------------------------------------\n");
	printf ("怪物名::%s\n" , monster.monstername );
	printf ("当前血量:%d\n" , monster.hp );
	printf ("攻击力:%d\n" , monster.attack );
	printf ("防御力:%d\n" , monster.defensive) ;
	printf ("固定伤害:%d\n" , monster.rattack );
	printf ("可获取的经验:%d\n" , monster.getexp) ;
	printf ("----------------------------------------------------------------\n") ;
}

int vs(Player* player,Monster monster) {

	printf("--------是否与%s对战(y/n)---------",monster.monstername);
	printmonster(monster);
	char tmp=_getch();
	switch (tmp) {
		case 'Y':
		case 'y':
			while (monster.hp >= 0) {
				player->hp -= getdamage(monster,*player);
				printf("你受到了伤害:%d",getdamage(monster,*player));
				monster.hp -= damage(monster,*player);
				printf("你对%s造成了%d伤害\n",monster.monstername, damage(monster,*player));
				if (kill(player)) {
					printf("你被%s杀死了\n",monster.monstername);
					exit(1);
				}
			}
			player->exp += monster.getexp;
			levelup(player);
			system("pause");
			return 1;
			break;
		case 'n':
		case 'N':
			return 0;
			break;
		default:
			vs(player,monster);
			break;
	}
}
void printBoard(Player p) {
	white {
		printf("----------------------------------------------------------------\n");
		printf("玩家名:");
		puts(p.playername);
		printf("当前所在层数:%d\n",p.ceng);
		printf("当前血量:%d\n",p.hp);
		printf("当前经验:%d\n",p.exp);
		printf("当前攻击力:%d\n",p.attack);
		printf("当前防御力:%d\n",p.defensive);
		printf("固定伤害:%d\n",p.rattack);
		printf("当前等级:%d\n",p.leavl);
		printf("当前持有钥匙:%d\n",p.key);
		printf("当前坐标:(%d,%d)\n",p.x,p.y);
		printf("----------------------------------------------------------------\n") ;
		printf("按t键打开游戏帮助\n");
	}
}
void printmap(Map map) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			switch (map.map1[map.ceng-1][i][j]) {
				case 0:
					red;
					printf("#");//地图边界
					break;
				case 1:
					red;
					printf("*");//墙壁
					break;
				case 2:
					red;
					printf("%%");//蜘蛛低级怪
					break;
				case 3:
					red;
					printf("&");//骷髅中级怪
					break;
				case 4:
					red;
					printf("~");//蝙蝠高级怪
					break;
				case 5:
					ching;
					printf("!");//钥匙
					break;
				case 6:
					pink;
					printf("D");//锁上的门
					break;
				case 7:
					white;
					printf("B");//魔王
					break;
				case 8:
					green;
					printf("+");//回血
					break;
				case 9:
					nop;
					printf("/");//上楼梯
					break;
				case 10:
					printf(" ");//通道
					break;
				case 11:
					nop;
					printf("\\");//下楼梯
					break;
				case 12:
					printf("o");//角色位置
					break;
			}
		}
		printf("\n");
	}
}
void setplayername(Player *player) {
	printf("请输入你的用户名\n");
	gets(player->playername);
}
void gamehelp() {
	white {
		printf("-------------------------------------这是一个游戏帮助------------------------------------\n");
		printf("-----------------------------------------------------------------------------------------\n");
		printf("输入w a s d并进行回车来进行移动\n");
		printf("输入数字0进行游戏存档\n");
		printf("下面是玩法介绍\n");
		printf("%(蜘蛛)(level:1)  &(骷髅)(level:2)  ~(蝙蝠)(level 3)  B(魔王)(level 4)\n");
		printf("+(回血包)回满血  !(钥匙)  D(锁上的门)  *(墙壁)  #(地图边界)  o(主角)\n");
		printf("                 升级将会回满血                             \n");
		printf("作者能力有限颜色随机变化，请见谅\n");
		printf("-----------------------------------------------------------------------------------------\n");
	}
}
void menu() {
	white {
		printf("欢迎来到魔塔     制作人:123456dfg \n");
		printf("           请输入数字来进行操作     \n");
		printf("  1.新建存档        2.读取存档        \n");
	}
	char select;
	scanf("%c",&select) ;
	switch(select) {
		case '1':
			break;
		case '2':
			break;
		default:
			menu();
			break;
	}
}
void move(Player *player,Map *map) {
	printmap(*map);
	char dir=_getch();
	int px = player->x, py = player->y, tr = map->row, tl = map->column, ceng = 1;
	switch (dir) {
		case 'w':
		case'W':
			map->row -= 1;
			player->y += 1;
			break;
		case 's':
		case'S':
			map->row += 1;
			player->y -= 1;
			break;
		case 'a':
		case'A':
			map->column -= 1;
			player->x -= 1;
			break;
		case 'd':
		case'D':
			map->column += 1;
			player->x += 1;
			break;
		case '0':
			//save(*map, *player);
			break;
		case 27:
			exit(1);
			break;
		case't':
		case'T':
			gamehelp();
			break;
	}
	if (map->map1[map->ceng - 1][map->row][map->column] == tongdao) {//前方是通道
		map->map1[map->ceng - 1][tr][tl] = tongdao;
		map->map1[map->ceng - 1][map->row][map->column] = juese;
	} else if (map->map1[map->ceng - 1][map->row][map->column] == qiangbi || map->map1[map->ceng - 1][map->row][map->column] == bianjie) { //前方是墙壁或者边界
		printf("无法越过边界和障碍\n");
		player->y = py;
		player->x = px;
		map->row = tr;
		map->column = tl;
	} else if (map->map1[map->ceng - 1][map->row][map->column] == key) { //前方是钥匙
		map->map1[map->ceng - 1][map->row][map->column] = juese;
		map->map1[map->ceng - 1][tr][tl] = tongdao;
		printf("获得一条钥匙\n");
		player->key += 1;
		Sleep(1000);
	} else if (map->map1[map->ceng - 1][map->row][map->column] == heal) { //前方是血包
		printf("生命值已经回复\n");
		map->map1[map->ceng - 1][map->row][map->column] = juese;
		map->map1[map->ceng - 1][tr][tl] = tongdao;
		player->hp = player->hplimit;
	} else if (map->map1[map->ceng - 1][map->row][map->column] == door) { //前方是锁住的门
		player->y = py;
		player->x = px;
		if (player->key > 0) {//如果有钥匙
			printf("是否使用一把钥匙开门\n");
			char tmp;
			scanf("%c",&tmp);
			switch (tmp) {
				case 'y':
					map->map1[map->ceng - 1][map->row][map->column] = tongdao;
					map->row = tr;
					map->column = tl;
					player->key -= 1;
					break;
				case 'n':
					break;
			}
		} else { //如果没有钥匙
			printf("先去找一把钥匙吧\n");
			player->y = py;
			player->x = px;
			map->row = tr;
			map->column = tl;
		}
	} else if (map->map1[map->ceng - 1][map->row][map->column] == zhizhu) { //前方是蜘蛛
		if (vs(player,monster[0])) {//如果战胜
			map->map1[map->ceng - 1][map->row][map->column] = juese;
			map->map1[map->ceng - 1][tr][tl] = tongdao;
		} else { //如果选择不挑战
			player->y = py;
			player->x = px;
			map->row = tr;
			map->column = tl;
		}
	} else if (map->map1[map->ceng - 1][map->row][map->column] == kulou) { //前方是骷髅
		if (vs(player,monster[1])) {
			map->map1[map->ceng - 1][map->row][map->column] = juese;
			map->map1[map->ceng - 1][tr][tl] = tongdao;
		} else {
			player->y = py;
			player->x = px;
			map->row = tr;
			map->column = tl;
		}
	} else if (map->map1[map->ceng - 1][map->row][map->column] == bianfu) { //前方是蝙蝠
		if (vs(player,monster[2])) {
			map->map1[map->ceng - 1][map->row][map->column] = juese;
			map->map1[map->ceng - 1][tr][tl] = tongdao;
		} else {
			player->y = py;
			player->x = px;
			map->row = tr;
			map->column = tl;
		}
	} else if (map->map1[map->ceng - 1][map->row][map->column] == boss) { //前方是boss
		if (vs(player,monster[3])) {
			map->map1[map->ceng - 1][map->row][map->column] = juese;
			map->map1[map->ceng - 1][tr][tl] = tongdao;
		} else {
			player->y = py;
			player->x = px;
			map->row = tr;
			map->column = tl;
		}
	} else if (map->map1[map->ceng - 1][map->row][map->column] == up) { //上楼
		map->map1[map->ceng - 1][tr][tl] = tongdao;
		map->ceng += 1;
		player->x = 0;
		player->y = 0;
		map->row =11 ;
		map->column =1;
		map->map1[map->ceng - 1][map->row][map->column] = juese;
	} else if (map->map1[map->ceng - 1][map->row][map->column] == down) { //下楼
		map->map1[map->ceng - 1][tr][tl] = tongdao;
		map->ceng -= 1;
		player->x = 10;
		player->y = 8;
		map->row =4 ;
		map->column = 10;
		map->map1[map->ceng - 1][map->row][map->column] = juese;
	}
	if (win(*map)) {
		system("pause");
		exit(1);
	}
}
