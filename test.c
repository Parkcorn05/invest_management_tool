#include <stdio.h>
#include <conio.h>
#include <Windows.h>

void gotoxy(int x, int y);

/* 메인 함수 */

int main(void) {
    gotoxy(1, 1);
    printf("goto test");
    getch();
    return 0;
}

/*함수 구현 내용*/

void gotoxy(int x, int y) {
    COORD Pos;
    Pos.X = x;
    Pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Pos);
}