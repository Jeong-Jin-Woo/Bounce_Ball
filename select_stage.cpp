//select_stage.cpp
#define _CRT_SECURE_NO_WARNINGS
#include"BounceBall.h"


void select() {
	static int called = 1;
	unsigned char ch;
	screen = 0;
	while (initUI) {
		system("mode con:cols=24 lines=9");
		//�ʱ�ȭ��
		gotoxy(8, 3);
		textcolor(0, 15);
		printf("��");

		gotoxy(10, 3);
		textcolor(0, 15);
		printf("Start");

		gotoxy(10, 4);
		textcolor(15, 0);
		printf("Exit");

		initUI -= 1;
	}

	if (_kbhit() == 1 && screen == 0) {  // Ű���尡 ������ ������
		ch = _getch(); // key ���� �д´�
		//
		// ESC ������ ���α׷� ����
		if (ch == ESC)exit(0);
		if (ch == ENTER) {
			if (called == 1) {
				system("cls");
				initUI += 1;
				while (TRUE)
					stage_select();
			}
			else {
				system("cls");
				exit(0);
			}
		}

		//
		if (ch == SPECIAL1 || ch == SPECIAL2) { // ���� Ư��Ű

			// ���� ��� UP key�� ��� 0xe0 0x48 �ΰ��� ���ڰ� ���´�.
			ch = _getch();
			// Player1�� ����Ű�� �����δ�.
			switch (ch) {
			case UP:
				system("cls");
				called = 1;

				gotoxy(8, called - 1 + 3);
				textcolor(0, 15);
				printf("��");
				gotoxy(10, called - 1 + 3);
				textcolor(0, 15);
				printf("Start");

				gotoxy(10, called + 3);
				textcolor(15, 0);
				printf("Exit");

				break;

			case DOWN:
				system("cls");
				called = 2;

				gotoxy(8, called - 1 + 3);
				textcolor(0, 15);
				printf("��");
				gotoxy(10, called - 1 + 3);
				textcolor(0, 15);
				printf("Exit");

				gotoxy(10, called - 2 + 3);
				textcolor(15, 0);
				printf("Start");

				break;
			default:// Ư��Ű ������ ����Ű�� �ƴ� ���
				break;
			}

		}
	}
}