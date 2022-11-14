#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<windows.h>
#include<functional>

int main() {

	//ランダム
	srand((unsigned int)time(NULL));
	int ramdom = rand() % 6 + 1;

	//時間
	int second = 3;


	//奇数か偶数か入力
	int predict = 0;
	printf("奇数だと思うなら1を、偶数だと思うなら２を入力してください。");
	scanf_s("%d", &predict);

	//時間を置く
	std::function<void(int, int)>SetTimeout = [](int second, int ramdom) {Sleep(second * 1000); };

	//結果判定と出力
	std::function<void(int)>Result = [=](int ramdom) {
		
		//奇数の場合
		if (predict == 1) {
			if (ramdom % 2 == 1) {
				printf("正解です!\n%dが抽選で選ばれました", ramdom);
			}
			else {
				printf("不正解です\n%dが抽選で選ばれました", ramdom);
			}
		}

		//偶数の場合
		else if (predict == 2) {
			if (ramdom % 2 == 0) {
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
		return 0;
	};

	//時間を置く呼び出し
	SetTimeout(second, ramdom);

	//結果判定
	Result(ramdom);

	return 0;
}