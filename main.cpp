#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<windows.h>

typedef void (*newType)(int *second);

//コールバック関数
void callback(int *second) {
	printf("%d秒待ちます\n", *second);
}

void setTimeout(newType wait,int second) {
	Sleep(second*1000);

	wait(&second);
}

int main() {
	//関数ポインタ
	newType wait;
	//ランダム用
	srand((unsigned int)time(NULL));

	//奇数か偶数か入力
	int num = 0;
	printf("奇数を入力したら奇数が出力され、偶数が入力されたら偶数が出力されます。");
	scanf_s("%d", &num);

	//少し待つ
	wait = callback;
	setTimeout(wait, 5);
	//出力
	if (num % 2 == 0) {
		printf("偶数:%d", (rand() % 100+1) * 2);
	}
	else if (num%2==1) {
		printf("奇数:%d", (rand() % 100+1) * 2 + 1);
	}
	else {

	}

	return 0;
}