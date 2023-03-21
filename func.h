#pragma once
//��ͷ�ļ����ڶ����ʵ�ֺ���
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include"init_golbalvar.h"
#include"struct.h"
#include<io.h>
#include<conio.h>
#define red  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED); //��ɫ
#define nop SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);   //ԭɫ
#define blue SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);			//��ɫ
#define green SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);  //��ɫ
#define white SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);  //��ɫ
#define pink SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |FOREGROUND_BLUE);//��ɫ
#define ching SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN |FOREGROUND_BLUE);  //��ɫ
int getdamage(Monster monster,Player player) ;//�ܵ��˺�����
int damage(Monster monster,Player player); //�Թ�����ɵ��˺�����
void gamehelp();//��Ϸ����
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
		printf("��ϲ���Ѿ�ͨ��\t\nδ�����\t\n");
		printf("��Ϸ�����˳�\n");
		return 1;
	} else return 0;
}
void levelup(Player* player) {
	if (player->exp >= 100) {
		printf("��������");
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
		printf("���������Ϸ����");
		system("pause");
		return 1;
	} else return 0;
}
void printmonster(Monster monster) {
	printf ("----------------------------------------------------------------\n");
	printf ("������::%s\n" , monster.monstername );
	printf ("��ǰѪ��:%d\n" , monster.hp );
	printf ("������:%d\n" , monster.attack );
	printf ("������:%d\n" , monster.defensive) ;
	printf ("�̶��˺�:%d\n" , monster.rattack );
	printf ("�ɻ�ȡ�ľ���:%d\n" , monster.getexp) ;
	printf ("----------------------------------------------------------------\n") ;
}

int vs(Player* player,Monster monster) {

	printf("--------�Ƿ���%s��ս(y/n)---------",monster.monstername);
	printmonster(monster);
	char tmp=_getch();
	switch (tmp) {
		case 'Y':
		case 'y':
			while (monster.hp >= 0) {
				player->hp -= getdamage(monster,*player);
				printf("���ܵ����˺�:%d",getdamage(monster,*player));
				monster.hp -= damage(monster,*player);
				printf("���%s�����%d�˺�\n",monster.monstername, damage(monster,*player));
				if (kill(player)) {
					printf("�㱻%sɱ����\n",monster.monstername);
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
		printf("�����:");
		puts(p.playername);
		printf("��ǰ���ڲ���:%d\n",p.ceng);
		printf("��ǰѪ��:%d\n",p.hp);
		printf("��ǰ����:%d\n",p.exp);
		printf("��ǰ������:%d\n",p.attack);
		printf("��ǰ������:%d\n",p.defensive);
		printf("�̶��˺�:%d\n",p.rattack);
		printf("��ǰ�ȼ�:%d\n",p.leavl);
		printf("��ǰ����Կ��:%d\n",p.key);
		printf("��ǰ����:(%d,%d)\n",p.x,p.y);
		printf("----------------------------------------------------------------\n") ;
		printf("��t������Ϸ����\n");
	}
}
void printmap(Map map) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			switch (map.map1[map.ceng-1][i][j]) {
				case 0:
					red;
					printf("#");//��ͼ�߽�
					break;
				case 1:
					red;
					printf("*");//ǽ��
					break;
				case 2:
					red;
					printf("%%");//֩��ͼ���
					break;
				case 3:
					red;
					printf("&");//�����м���
					break;
				case 4:
					red;
					printf("~");//����߼���
					break;
				case 5:
					ching;
					printf("!");//Կ��
					break;
				case 6:
					pink;
					printf("D");//���ϵ���
					break;
				case 7:
					white;
					printf("B");//ħ��
					break;
				case 8:
					green;
					printf("+");//��Ѫ
					break;
				case 9:
					nop;
					printf("/");//��¥��
					break;
				case 10:
					printf(" ");//ͨ��
					break;
				case 11:
					nop;
					printf("\\");//��¥��
					break;
				case 12:
					printf("o");//��ɫλ��
					break;
			}
		}
		printf("\n");
	}
}
void setplayername(Player *player) {
	printf("����������û���\n");
	gets(player->playername);
}
void gamehelp() {
	white {
		printf("-------------------------------------����һ����Ϸ����------------------------------------\n");
		printf("-----------------------------------------------------------------------------------------\n");
		printf("����w a s d�����лس��������ƶ�\n");
		printf("��������0������Ϸ�浵\n");
		printf("�������淨����\n");
		printf("%(֩��)(level:1)  &(����)(level:2)  ~(����)(level 3)  B(ħ��)(level 4)\n");
		printf("+(��Ѫ��)����Ѫ  !(Կ��)  D(���ϵ���)  *(ǽ��)  #(��ͼ�߽�)  o(����)\n");
		printf("                 �����������Ѫ                             \n");
		printf("��������������ɫ����仯�������\n");
		printf("-----------------------------------------------------------------------------------------\n");
	}
}
void menu() {
	white {
		printf("��ӭ����ħ��     ������:123456dfg \n");
		printf("           ���������������в���     \n");
		printf("  1.�½��浵        2.��ȡ�浵        \n");
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
	if (map->map1[map->ceng - 1][map->row][map->column] == tongdao) {//ǰ����ͨ��
		map->map1[map->ceng - 1][tr][tl] = tongdao;
		map->map1[map->ceng - 1][map->row][map->column] = juese;
	} else if (map->map1[map->ceng - 1][map->row][map->column] == qiangbi || map->map1[map->ceng - 1][map->row][map->column] == bianjie) { //ǰ����ǽ�ڻ��߽߱�
		printf("�޷�Խ���߽���ϰ�\n");
		player->y = py;
		player->x = px;
		map->row = tr;
		map->column = tl;
	} else if (map->map1[map->ceng - 1][map->row][map->column] == key) { //ǰ����Կ��
		map->map1[map->ceng - 1][map->row][map->column] = juese;
		map->map1[map->ceng - 1][tr][tl] = tongdao;
		printf("���һ��Կ��\n");
		player->key += 1;
		Sleep(1000);
	} else if (map->map1[map->ceng - 1][map->row][map->column] == heal) { //ǰ����Ѫ��
		printf("����ֵ�Ѿ��ظ�\n");
		map->map1[map->ceng - 1][map->row][map->column] = juese;
		map->map1[map->ceng - 1][tr][tl] = tongdao;
		player->hp = player->hplimit;
	} else if (map->map1[map->ceng - 1][map->row][map->column] == door) { //ǰ������ס����
		player->y = py;
		player->x = px;
		if (player->key > 0) {//�����Կ��
			printf("�Ƿ�ʹ��һ��Կ�׿���\n");
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
		} else { //���û��Կ��
			printf("��ȥ��һ��Կ�װ�\n");
			player->y = py;
			player->x = px;
			map->row = tr;
			map->column = tl;
		}
	} else if (map->map1[map->ceng - 1][map->row][map->column] == zhizhu) { //ǰ����֩��
		if (vs(player,monster[0])) {//���սʤ
			map->map1[map->ceng - 1][map->row][map->column] = juese;
			map->map1[map->ceng - 1][tr][tl] = tongdao;
		} else { //���ѡ����ս
			player->y = py;
			player->x = px;
			map->row = tr;
			map->column = tl;
		}
	} else if (map->map1[map->ceng - 1][map->row][map->column] == kulou) { //ǰ��������
		if (vs(player,monster[1])) {
			map->map1[map->ceng - 1][map->row][map->column] = juese;
			map->map1[map->ceng - 1][tr][tl] = tongdao;
		} else {
			player->y = py;
			player->x = px;
			map->row = tr;
			map->column = tl;
		}
	} else if (map->map1[map->ceng - 1][map->row][map->column] == bianfu) { //ǰ��������
		if (vs(player,monster[2])) {
			map->map1[map->ceng - 1][map->row][map->column] = juese;
			map->map1[map->ceng - 1][tr][tl] = tongdao;
		} else {
			player->y = py;
			player->x = px;
			map->row = tr;
			map->column = tl;
		}
	} else if (map->map1[map->ceng - 1][map->row][map->column] == boss) { //ǰ����boss
		if (vs(player,monster[3])) {
			map->map1[map->ceng - 1][map->row][map->column] = juese;
			map->map1[map->ceng - 1][tr][tl] = tongdao;
		} else {
			player->y = py;
			player->x = px;
			map->row = tr;
			map->column = tl;
		}
	} else if (map->map1[map->ceng - 1][map->row][map->column] == up) { //��¥
		map->map1[map->ceng - 1][tr][tl] = tongdao;
		map->ceng += 1;
		player->x = 0;
		player->y = 0;
		map->row =11 ;
		map->column =1;
		map->map1[map->ceng - 1][map->row][map->column] = juese;
	} else if (map->map1[map->ceng - 1][map->row][map->column] == down) { //��¥
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
