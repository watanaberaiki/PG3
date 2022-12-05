#include <stdio.h>
#include<stdlib.h>
//一般的な賃金形態の計算
int TimeMoney(int time, int money) {
	return time* money;
}

//再帰的な賃金形態の計算
//時間が一定数以下になるまで呼び出す
int RecursionTimeMoney(int time,int money) {
	time--;
	
	if (time<1) {
		return money;
	}

	return RecursionTimeMoney(time,money * 2 - 50);
}

int main() {
	int time = 100;				//時間
	int money = 1072;			//一般的な賃金形態
	int recursionMoney = 100;	//再帰的な賃金形態
	int memoryRecursionMoney = 0;	//再帰的な賃金形態の合計


	//一般的な賃金形態と再帰的な賃金形態の比較
	for (int i = 1; i < time; i++)
	{
		printf("%d時間働いた場合\n", i);
		printf("一般的な賃金体態:%d\n", TimeMoney(i, money));
		printf("再起的な賃金体態:%d\n\n", memoryRecursionMoney+=RecursionTimeMoney(i, recursionMoney));
		if (TimeMoney(i, money) < memoryRecursionMoney)
		{
			break;
		}
	}

	system("pause");

	return 0;
}