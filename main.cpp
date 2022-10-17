#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<windows.h>

typedef void (*PFunc)(int*,int*);

//コールバック関数
void Callback(int* second,int* predict) {
	printf("結果\n");
}

//何秒か待って関数を呼ぶ
void SetTimeout(PFunc p, int second, int predict) {
	//待つ
	Sleep(second * 1000);
	
	//呼び出し
	p(&second,&predict);
}

//結果判定
void Result(int *second,int* predict) {
	//ランダム
	int ramdom = rand() % 6 + 1;
	
	//奇数の場合
	if (*predict ==1 ) {
		if (ramdom % 2 == 1) {
			printf("正解です!\n%dが抽選で選ばれました",ramdom);
		}
		else {
			printf("不正解です\n%dが抽選で選ばれました", ramdom);
		}
	}

	//偶数の場合
	else if (*predict == 2) {
		if (ramdom % 2  == 0) {
			printf("正解です!\n%dが抽選で選ばれました", ramdom);
		}
		else {
			printf("不正解です\n%dが抽選で選ばれました", ramdom);
		}
	}
	//違う値が入力された場合
	else {
		printf("不適切な値が入力されました");
	}
}

int main() {

	//ランダム用
	srand((unsigned int)time(NULL));
	int ramdom = rand() % 6 + 1;


	//奇数か偶数か入力
	int predict = 0;
	printf("奇数だと思うなら1を、偶数だと思うなら２を入力してください。");
	scanf_s("%d", &predict);

	//関数ポインタ
	PFunc p;
	
	//少し待つ
	p = Callback;
	SetTimeout(p, 3, predict);
	
	//結果出力
	p = Result;
	SetTimeout(p, 0, predict);

	return 0;
}