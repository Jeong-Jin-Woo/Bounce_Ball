//BounceBall.h
#ifndef BOUNCEBALL_H
#define BOUNCEBALL_H

#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>
#include <cmath>

// 색상 정의
#define BLACK	0
#define BLUE1	1
#define GREEN1	2
#define CYAN1	3
#define RED1	4
#define MAGENTA1 5
#define YELLOW1	6
#define GRAY1	7
#define GRAY2	8
#define BLUE2	9
#define GREEN2	10
#define CYAN2	11
#define RED2	12
#define MAGENTA2 13
#define YELLOW2	14
#define WHITE	15

#define STAR1 'O' // player1 표시
#define STAR2 'X' // player2 표시
#define BLANK '.' // ' ' 로하면 흔적이 지워진다 

#define ESC 0x1b //  ESC 누르면 종료
#define ENTER 0xd

#define SPECIAL1 0xe0 // 특수키는 0xe0 + key 값으로 구성된다.
#define SPECIAL2 0x00 // keypad 경우 0x00 + key 로 구성된다.

#define UP  0x48 // Up key는 0xe0 + 0x48 두개의 값이 들어온다.
#define DOWN 0x50
#define LEFT 0x4b
#define RIGHT 0x4d

#define UP2		'w'
#define DOWN2	's'
#define LEFT2	'a'
#define RIGHT2	'd'

#define WIDTH 80
#define HEIGHT 24

#define MAP_X_MAX 96
#define MAP_Y_MAX 32

#define FALSE 0
#define TRUE 1

void gotoxy(int x, int y);
void removeCursor();
void textcolor(int fg_color, int bg_color);
int main();
void SetConsole();
void ControlBall(int num);
void FillMap(char str[], char str_s, int max_value);
void EditMap(int x, int y, char str);
void DrawSprite(int x, int y, int size_x, int size_y, char spr[]);
void select();
void stage_select();

int check(int num);

void ControlUI_1();
void SetUI_1();
void SetStar_1();
void start_1();

void start_2();
void ControlUI_2();
void SetUI_2();

void start_3();
void start_4();

//clear시
int clearUI(int n);

static int screen = 0;
static int initUI = 1;
static char mapData[MAP_X_MAX * MAP_Y_MAX];

#endif