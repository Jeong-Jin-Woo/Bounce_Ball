//main.cpp
#define _CRT_SECURE_NO_WARNINGS
#include"BounceBall.h"

typedef struct _Map {
	int num; //�������� 1~4
	//�� ������
	char ss_wall[3];
	char sm_wall[5];
	char sl_wall[10];
	char ms_wall[20];
	char mm_wall[30];
	char ml_wall[40];
	char ls_wall[50];
	char lm_wall[60];
	char ll_wall[70];
	char bottom_wall[MAP_X_MAX];
	char half_wall[MAP_X_MAX / 2];
	//�� ����
	int star[10][2];
	//Ŭ���� ����
	bool clear = false;
}Map;

typedef struct _Ball {
	short x, y;
	short size_x, size_y;
	char sprite[2];
	bool direction;
	float t_jump;
	short leg_m;
	unsigned int t_leg;
	short last_ball_x; //ó�� ball��ġ ���
	short last_ball_y; //ó�� ball��ġ ���
}Ball;

Ball ball;
Map map[4];

//wchar_t mapData[MAP_X_MAX * MAP_Y_MAX];
char wall[MAP_X_MAX];
char wall2[MAP_X_MAX / 2];
char wall3[MAP_X_MAX / 3];

int check(int n) {
	if (strchr(mapData, '*') == NULL) {
		return 1;
	}
	return 0;
}
int clearUI(int n) {
	gotoxy((MAP_X_MAX) / 2 -5, (MAP_Y_MAX-1) / 2 - 1);
	printf("!!!!!!!!!");
	gotoxy((MAP_X_MAX) / 2 - 5, (MAP_Y_MAX - 1) / 2);
	printf("!!");
	gotoxy((MAP_X_MAX) / 2-3, (MAP_Y_MAX - 1) / 2);
	printf("CLEAR");
	gotoxy((MAP_X_MAX) / 2 + 2, (MAP_Y_MAX - 1) / 2);
	printf("!!");
	gotoxy((MAP_X_MAX) / 2-5, (MAP_Y_MAX - 1) / 2 + 1);
	printf("!!!!!!!!!");
	/*
		textcolor(15, 0);
		gotoxy((MAP_X_MAX) / 2 - 20, (MAP_Y_MAX - 1) / 2 + 3);
		textcolor(0, 15); //��� ��濡 ���� ����
		printf("��");
		gotoxy((MAP_X_MAX) / 2 - 18, (MAP_Y_MAX - 1) / 2 + 3);
		textcolor(0, 15);
		printf("�ڷΰ���");
		gotoxy((MAP_X_MAX) / 2 + 8, (MAP_Y_MAX - 1) / 2 + 3);
		textcolor(15, 0);
		printf("���� ��������");
		textcolor(15, 0);*/
		int sel = 0;
		unsigned char ch1;
		while (TRUE) {
			if (_kbhit() == 1) {  // Ű���尡 ������ ������
				ch1 = _getch(); // key ���� �д´�
				//
				if (ch1 == ENTER) {
					if (sel == 0) {
						system("cls");
						return 0; //���ư���
					}
					else {
						system("cls");
						return 1; //���� ��������
					}
				}
				if (ch1 == SPECIAL1 || ch1 == SPECIAL2) { // ���� Ư��Ű

				// ���� ��� UP key�� ��� 0xe0 0x48 �ΰ��� ���ڰ� ���´�.
					ch1 = _getch();
					// Player1�� ����Ű�� �����δ�.
					switch (ch1) {
					case LEFT:
						sel = 0;
						textcolor(15, 0);
						gotoxy((MAP_X_MAX) / 2 - 20, (MAP_Y_MAX - 1) / 2 + 3);
						textcolor(0, 15);
						printf("��");
						gotoxy((MAP_X_MAX) / 2 - 18, (MAP_Y_MAX - 1) / 2 + 3);
						textcolor(0, 15);
						printf("�ڷΰ���");

						gotoxy((MAP_X_MAX) / 2 + 6, (MAP_Y_MAX - 1) / 2 + 3);
						textcolor(15, 0);
						printf("  ");
						gotoxy((MAP_X_MAX) / 2 + 8, (MAP_Y_MAX - 1) / 2 + 3);
						textcolor(15, 0);
						printf("���� ��������");
						break;
					case RIGHT:
						sel = 1;
						gotoxy((MAP_X_MAX) / 2 - 20, (MAP_Y_MAX - 1) / 2 + 3);
						textcolor(15, 0);
						printf("  ");
						gotoxy((MAP_X_MAX) / 2 - 18, (MAP_Y_MAX - 1) / 2 + 3);
						textcolor(15, 0);
						printf("�ڷΰ���");
						gotoxy((MAP_X_MAX) / 2 + 6, (MAP_Y_MAX - 1) / 2 + 3);
						textcolor(0, 15);
						printf("��");
						gotoxy((MAP_X_MAX) / 2 + 8, (MAP_Y_MAX - 1) / 2 + 3);
						textcolor(0, 15);
						printf("���� ��������");
						textcolor(15, 0);
						break;
					default:
						break;
					}
				}
			}
		}
}
void start_1() {
	screen = 2;
	map[0].num = 1;
	SetConsole();
	SetUI_1();

	ball.x = 5;
	ball.y = MAP_Y_MAX / 2 - 1;
	ball.size_x = 1;
	ball.size_y = 1;
	ball.sprite[0] = 'o';
	ball.sprite[1] = '\0';
	ball.direction = TRUE;
	ball.t_jump = 2;
	ball.last_ball_y = ball.y;
	
	for (int i = 0; i < 10; i++) {
		map[0].star[i][0] = 1;
		map[0].star[i][1] = i + 1315;
	}

	unsigned int system_tick = GetTickCount();
	while (screen == 2) {
		if (system_tick + 30 < GetTickCount()) {
			system_tick = GetTickCount();
			FillMap(mapData, ' ', MAP_X_MAX * MAP_Y_MAX);
			ControlUI_1();
			//mapData[1000] = '*';
			
			for (int i = 0; i < 10; i++) {
				if (!map[0].star[i][0])
					continue;
				mapData[map[0].star[i][1]] = '*';
			}
			//SetStar_1();
			ControlBall(map[0].num - 1);
			printf("%s", mapData);
			if (check(map[0].num)) {
				map[0].clear = true;
				initUI += 1;
				int	n = clearUI(map[0].num - 1);
				if (n == 0) { // ���ư���
					/*
					system("cls");
					//stage_select()ȣ��..
					system("mode con:cols=32 lines=24");
					gotoxy(12, 3);
					textcolor(15, 0);
					printf("�ڷΰ���");
					gotoxy(10, 6);
					textcolor(0, 15); //��� ��濡 ���� ����
					printf("��");
					gotoxy(12, 6);
					textcolor(0, 15);
					printf("��������1");
					textcolor(0, 15);
					map[0].clear ? printf("\tCLEAR") : printf("");
					gotoxy(12, 9);
					textcolor(15, 0);
					printf("��������2");
					map[1].clear ? printf("\tCLEAR") : printf("");

					gotoxy(12, 12);
					textcolor(15, 0);
					printf("��������3");
					map[2].clear ? printf("\tCLEAR") : printf("");
					gotoxy(12, 15);
					textcolor(15, 0);
					printf("��������4");
					map[3].clear ? printf("\tCLEAR") : printf("");
					gotoxy(12, 18);
					textcolor(15, 0);
					printf("����");
					break; //??
					*/
					
					system("cls");
					initUI += 1;
					stage_select();
					break;
				}
				else { // ���� ��������
					system("cls");
					start_2();
					break;
				}
			}
		}
	}

}

void start_2() {
	screen = 3;
	map[1].num = 2;
	SetConsole();
	SetUI_2();

	ball.x = 60;
	ball.y = MAP_Y_MAX - 1;
	ball.size_x = 1;
	ball.size_y = 1;
	ball.sprite[0] = 'o';
	ball.sprite[1] = '\0';
	ball.direction = TRUE;
	ball.t_jump = 2;
	ball.last_ball_y = ball.y;
	ball.last_ball_x = ball.x;

	for (int i = 0; i < 10; i++) {
		map[1].star[i][0] = 1;
	}
	for(int i=0; i<5; i++)
		map[1].star[i][1] = i + 513;
	map[1].star[5][1] = 2972;
	map[1].star[6][1] = 1158;
	map[1].star[7][1] = 1320;
	map[1].star[8][1] = 1820;
	map[1].star[9][1] = 2973;

	unsigned int system_tick = GetTickCount();
	while (screen == 3) {
		if (system_tick + 30 < GetTickCount()) {
			system_tick = GetTickCount();
			FillMap(mapData, ' ', MAP_X_MAX * MAP_Y_MAX);
			ControlUI_2();

			for (int i = 0; i < 10; i++) {
				if (!map[1].star[i][0])
					continue;
				mapData[map[1].star[i][1]] = '*';
			}

			ControlBall(map[1].num - 1);
			printf("%s", mapData);
			if (check(map[1].num)) {
				map[1].clear = true;
				initUI += 1;
				int	n = clearUI(map[1].num - 1);
				if (n == 0) { // ���ư���
					/*
					system("cls");
					//stage_select()ȣ��..
					system("mode con:cols=32 lines=24");
					gotoxy(12, 3);
					textcolor(15, 0);
					printf("�ڷΰ���");
					gotoxy(10, 6);
					textcolor(0, 15); //��� ��濡 ���� ����
					printf("��");
					gotoxy(12, 6);
					textcolor(0, 15);
					printf("��������1");
					textcolor(0, 15);
					map[0].clear ? printf("\tCLEAR") : printf("");
					gotoxy(12, 9);
					textcolor(15, 0);
					printf("��������2");
					map[1].clear ? printf("\tCLEAR") : printf("");

					gotoxy(12, 12);
					textcolor(15, 0);
					printf("��������3");
					map[2].clear ? printf("\tCLEAR") : printf("");
					gotoxy(12, 15);
					textcolor(15, 0);
					printf("��������4");
					map[3].clear ? printf("\tCLEAR") : printf("");
					gotoxy(12, 18);
					textcolor(15, 0);
					printf("����");
					break; //??
					*/

					system("cls");
					initUI += 1;
					stage_select();
					break;
				}
				else { // ���� ��������
					system("cls");
					start_3();
					break;
				}
			}
			/*
			if (check(map[1].num)) {
				map[1].clear = true;
				initUI += 1;
				system("cls");
				break;
			}
*/
		}

	}

}
void start_3() {
	screen = 4;
}
void start_4() {
	screen = 5;
}
//BallControl
void ControlBall(int num) {
	unsigned int tick = GetTickCount();
	bool move = FALSE;
	if (GetAsyncKeyState(37) != 0 && ball.x > 1) { //����
		ball.x -= 1;
		ball.direction = FALSE;
		move = TRUE;
	}
	if (GetAsyncKeyState(39) != 0 && ball.x < MAP_X_MAX - 2) {
		//������
		ball.x += 1;
		ball.direction = TRUE;
		move = TRUE;
	}
	if (ball.y > 0 && (mapData[(ball.y * MAP_X_MAX) + (ball.x - 1)] == '-'
		|| mapData[((ball.y + 1) * MAP_X_MAX) + (ball.x - 1)] == '-'
		)) { //�Ʒ� - �̸� Ƣ���
		ball.t_jump = 0;
		if (mapData[((ball.y + 1) * MAP_X_MAX) + (ball.x - 1)] == '-') //1ĭ ������� ����
			ball.y -= 1;
	}
	if ((mapData[((ball.y - 1) * MAP_X_MAX) + (ball.x - 1)] == '-'
		|| mapData[((ball.y - 2) * MAP_X_MAX) + (ball.x - 1)] == '-'
		|| ball.y <= 0
		)) 
	{
		ball.t_jump = 4;
		if (mapData[((ball.y - 2) * MAP_X_MAX) + (ball.x - 1)] == '-') //1ĭ ������� ����
			ball.y += 1;
	}
	ball.y -= 2;
	if (ball.y < MAP_Y_MAX) {
		if (ball.t_jump < 4)
			ball.t_jump += 0.35;
		//Sleep(60); //�� �ӵ� ������ -> ?�� Ƣ��� ���� ������ ����?
		ball.y += floor(ball.t_jump);
		if (ball.y > MAP_Y_MAX) //�Ʒ��� ����� 21
			ball.y = MAP_Y_MAX;
	}
	else {
		ball.t_jump = 0;
		ball.y = MAP_Y_MAX;
	}
	if (ball.y >= MAP_Y_MAX) {
		ball.y = ball.last_ball_y;
		ball.x = ball.last_ball_x;
		for (int i = 0; i < 10; i++)
			map[num].star[i][0] = 1;
	}
	if (mapData[((ball.y-1) * MAP_X_MAX) + (ball.x - 1)] == '*') {//�� �Ծ�����
		mapData[((ball.y-1) * MAP_X_MAX) + (ball.x - 1)] = 'o'; //�̰��� ���� ��
		//map[0].star[3][1] = 0;
		for (int i = 0; i < 10; i++) {
			if (map[num].star[i][1] == ((ball.y-1) * MAP_X_MAX) + (ball.x - 1))
				map[num].star[i][0] = 0;
		}
		//mapData[((ball.y+1) * MAP_X_MAX) + (ball.x - 1)] = ' '; //�̰��� ���� ��
		//mapData[1000] = ' ';
	}

	DrawSprite(ball.x, ball.y, ball.size_x, ball.size_y, ball.sprite);
}
void SetConsole() {
	system("mode con:cols=96 lines=32");

	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	ConsoleCursor.bVisible = 0;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(hConsole, &ConsoleCursor);

	//COORD Pos = { 0,0 };
	//SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);

}
void SetUI_1() {
	FillMap(map[0].bottom_wall, '-', MAP_X_MAX);
	FillMap(map[0].half_wall, '-', MAP_X_MAX / 2);
	FillMap(map[0].ms_wall, '-', sizeof(map[0].ms_wall));
	//FillMap(map[0].star, '*', sizeof(map[0].star));
}

void ControlUI_1() {
	DrawSprite(1, 22, MAP_X_MAX, 1, map[0].bottom_wall);
	DrawSprite(30, 15, MAP_X_MAX / 2, 1, map[0].half_wall);
	DrawSprite(50, 8, sizeof(map[0].ms_wall), 1, map[0].ms_wall);
}
void SetStar_1() {
	//DrawSprite(68, 14, sizeof(map[0].star), 1, map[0].star);
}
void SetUI_2() {//hard
	FillMap(map[1].half_wall, '-', sizeof(map[1].half_wall));
	FillMap(map[1].ms_wall, '-', sizeof(map[1].ms_wall));
	FillMap(map[1].sm_wall, '-', sizeof(map[1].sm_wall));
	FillMap(map[1].ss_wall, '-', sizeof(map[1].ss_wall));
	FillMap(map[1].ml_wall, '-', sizeof(map[1].ml_wall));
	FillMap(map[1].sm_wall, '-', sizeof(map[1].sm_wall));
}

void ControlUI_2() {//hard
	DrawSprite(55, MAP_Y_MAX, sizeof(map[1].half_wall), 1, map[1].half_wall);
	DrawSprite(70, 26, sizeof(map[1].sm_wall), 1, map[1].sm_wall);
	DrawSprite(80, 20, sizeof(map[1].ms_wall), 1, map[1].ms_wall);
	DrawSprite(73, 15, sizeof(map[1].ss_wall), 1, map[1].ss_wall);
	DrawSprite(20, 18, sizeof(map[1].ml_wall), 1, map[1].ml_wall);
	DrawSprite(7, 14, sizeof(map[1].sm_wall), 1, map[1].sm_wall);
	DrawSprite(19, 7, sizeof(map[1].ms_wall), 1, map[1].ms_wall);
}

void FillMap(char str[], char str_s, int max_value) {
	for (int i = 0; i < max_value; i++)
		str[i] = str_s;
}

void EditMap(int x, int y, char str) {
	if (x > 0 && y > 0 && x - 1 < MAP_X_MAX && y - 1 < MAP_Y_MAX)
		mapData[(y - 1) * MAP_X_MAX + x - 1] = str;
}/*
void EditMap(int x, int y, char str) {
	if (x > 0 && y > 0 && x <= MAP_X_MAX && y <= MAP_Y_MAX)
		mapData[(y - 1) * MAP_X_MAX + x - 1] = str;
}*/

void DrawSprite(int x, int y, int size_x, int size_y, char spr[]) {
	for (int i = 0; i < size_y; i++) {
		for (int n = 0; n < size_x; n++)
			EditMap(x + n, y + i, spr[i * size_x + n]);
	}
}
//BallControl

int main() {
	removeCursor();
	while (1) {
		select();
	}
}

void removeCursor(void) { // Ŀ���� �Ⱥ��̰� �Ѵ�

	CONSOLE_CURSOR_INFO curInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curInfo.bVisible = 0;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}

void gotoxy(int x, int y) //���� ���ϴ� ��ġ�� Ŀ�� �̵�
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);// WIN32API �Լ��Դϴ�. �̰� ���ʿ� �����
}

void textcolor(int fg_color, int bg_color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), fg_color | bg_color << 4);
}

// ȭ�� ������ ���ϴ� �������� �����Ѵ�.
void cls(int bg_color, int text_color)
{
	char cmd[100];
	system("cls");
	sprintf(cmd, "COLOR %x%x", bg_color, text_color);
	system(cmd);

}

void stage_select() {
	while (initUI) {
		system("mode con:cols=32 lines=24");
		//�ʱ�ȭ��
		gotoxy(10, 3);
		textcolor(0, 15); //��� ��濡 ���� ����
		printf("��");
		gotoxy(12, 3);
		textcolor(0, 15);
		printf("�ڷΰ���");
		gotoxy(12, 6);
		textcolor(15, 0);
		printf("��������1");
		map[0].clear ? printf("\tCLEAR") : printf(" ");
		gotoxy(12, 9);
		textcolor(15, 0);
		printf("��������2");
		map[1].clear ? printf("\tCLEAR") : printf(" ");
		gotoxy(12, 12);
		textcolor(15, 0);
		printf("��������3");
		map[2].clear ? printf("\tCLEAR") : printf(" ");
		gotoxy(12, 15);
		textcolor(15, 0);
		printf("��������4");
		map[3].clear ? printf("\tCLEAR") : printf(" ");
		gotoxy(12, 18);
		textcolor(15, 0);
		printf("����");

		initUI -= 1;
	}

	screen = 1;
	static int selected = 0; //0: back, 1:stage_1, 2:stage_2, 3:stage_3, 4:stage_4, 5: exit
	unsigned char ch1;

	if (_kbhit() == 1 && screen == 1) {  // Ű���尡 ������ ������
		ch1 = _getch(); // key ���� �д´�
		//
		// ESC ������ ���α׷� ����
		if (ch1 == ESC)exit(0);
		if (ch1 == ENTER) {
			if (selected == 0) {
				system("cls");
				initUI += 1;
				main();
			}
			else if (selected == 1) {
				system("cls");
				start_1();

			}
			else if (selected == 2) {
				system("cls");
				start_2();
			}
			else if (selected == 3) {
				system("cls");
				start_3();
			}
			else if (selected == 4) {
				system("cls");
				start_4();
			}
			else if (selected == 5) {
				system("cls");
				exit(0);
			}
		}

		//
		if (ch1 == SPECIAL1 || ch1 == SPECIAL2) { // ���� Ư��Ű

			// ���� ��� UP key�� ��� 0xe0 0x48 �ΰ��� ���ڰ� ���´�.
			ch1 = _getch();
			// Player1�� ����Ű�� �����δ�.
			switch (ch1) {
			case UP:
				system("cls");
				//selected-=1;
				selected < 1 ? selected = 0 : selected -= 1;
				gotoxy(10, (selected + 1) * 3);
				textcolor(0, 15); //��� ��濡 ���� ����
				printf("��");

				gotoxy(12, 3);
				(selected + 1) * 3 == 3 ? textcolor(0, 15) : textcolor(15, 0);
				printf("�ڷΰ���");
				textcolor(15, 0);

				gotoxy(12, 6);
				(selected + 1) * 3 == 6 ? textcolor(0, 15) : textcolor(15, 0);
				printf("��������1");
				map[0].clear ? printf("\tCLEAR") : printf(" ");
				textcolor(15, 0);

				gotoxy(12, 9);
				(selected + 1) * 3 == 9 ? textcolor(0, 15) : textcolor(15, 0);
				printf("��������2");
				map[1].clear ? printf("\tCLEAR") : printf(" ");
				textcolor(15, 0);

				gotoxy(12, 12);
				(selected + 1) * 3 == 12 ? textcolor(0, 15) : textcolor(15, 0);
				printf("��������3");
				map[2].clear ? printf("\tCLEAR") : printf(" ");
				textcolor(15, 0);

				gotoxy(12, 15);
				(selected + 1) * 3 == 15 ? textcolor(0, 15) : textcolor(15, 0);
				printf("��������4");
				map[3].clear ? printf("\tCLEAR") : printf(" ");
				textcolor(15, 0);

				gotoxy(12, 18);
				(selected + 1) * 3 == 18 ? textcolor(0, 15) : textcolor(15, 0);
				printf("����");
				break;

			case DOWN:
				system("cls");
				//selected += 1;
				selected > 4 ? selected = 5 : selected += 1;
				gotoxy(10, (selected + 1) * 3);
				textcolor(0, 15); //��� ��濡 ���� ����
				printf("��");

				gotoxy(12, 3);
				(selected + 1) * 3 == 3 ? textcolor(0, 15) : textcolor(15, 0);
				printf("�ڷΰ���");

				gotoxy(12, 6);
				(selected + 1) * 3 == 6 ? textcolor(0, 15) : textcolor(15, 0);
				printf("��������1");
				map[0].clear ? printf("\tCLEAR") : printf(" ");

				gotoxy(12, 9);
				(selected + 1) * 3 == 9 ? textcolor(0, 15) : textcolor(15, 0);
				printf("��������2");
				map[1].clear ? printf("\tCLEAR") : printf(" ");

				gotoxy(12, 12);
				(selected + 1) * 3 == 12 ? textcolor(0, 15) : textcolor(15, 0);
				printf("��������3");
				map[2].clear ? printf("\tCLEAR") : printf(" ");

				gotoxy(12, 15);
				(selected + 1) * 3 == 15 ? textcolor(0, 15) : textcolor(15, 0);
				printf("��������4");
				map[3].clear ? printf("\tCLEAR") : printf(" ");

				gotoxy(12, 18);
				(selected + 1) * 3 == 18 ? textcolor(0, 15) : textcolor(15, 0);
				printf("����");
				break;
			case LEFT:
			case RIGHT:
			default:// Ư��Ű ������ ����Ű�� �ƴ� ���
				break;
			}
			textcolor(15, 0); // ����(��� ���, ���� ����)
		}
	}
}