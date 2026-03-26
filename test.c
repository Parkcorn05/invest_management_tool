#include <stdio.h>
#include <conio.h>
#include <Windows.h>

typedef double rate; typedef char string; typedef int date;
/* double -> rate : 백분율(%)용 타입문 | char -> string : 문자열용 타입문 | int -> date : 날짜용 타입문 */

/* 자료 구조 */

typedef struct data_{
    string stockName[30]; //종목 이름
    double curPrice; //현재가
    double valuation; //평가금액
    double holding; //보유량
    rate weight; //비중
    double profit; //수익
    rate profitRate; //수익률
    string type[5]; //통화 (USA KRW JPY)
} data;

typedef struct addr_{
    struct addr_ *children[10]; //자식(10개까지 가능)
    int childNum; //자식 개수
    data *data; //데이터
    char level; //계층
} addr;

typedef struct head_{
    addr *root;
    date date;
} head, tree;

/* 함수 선언문 */

void gotoxy(int x, int y);
void textcolor(int colorNum);
void text(int x, int y, int colorNum, char *message);

void mainScreen(void);

/* 메인 함수 */

int main(void) {
    text(1, 1, 7, "1.종목관리\t2.포폴관리\t3.가상매매\t4.일지작성");
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

void text(int x, int y, int colorNum, char *message){
    gotoxy(x, y);
    textcolor(colorNum);
    printf("%s", message);
    return;
}

void textcolor(int colorNum) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorNum);
}