#include <stdio.h>
#include<stdlib.h>
//��ʓI�Ȓ����`�Ԃ̌v�Z
int TimeMoney(int time, int money) {
	return time* money;
}

//�ċA�I�Ȓ����`�Ԃ̌v�Z
//���Ԃ���萔�ȉ��ɂȂ�܂ŌĂяo��
int RecursionTimeMoney(int time,int money) {
	time--;
	
	if (time<1) {
		return money;
	}

	return RecursionTimeMoney(time,money * 2 - 50);
}

int main() {
	int time = 100;				//����
	int money = 1072;			//��ʓI�Ȓ����`��
	int recursionMoney = 100;	//�ċA�I�Ȓ����`��
	int memoryRecursionMoney = 0;	//�ċA�I�Ȓ����`�Ԃ̍��v


	//��ʓI�Ȓ����`�ԂƍċA�I�Ȓ����`�Ԃ̔�r
	for (int i = 1; i < time; i++)
	{
		printf("%d���ԓ������ꍇ\n", i);
		printf("��ʓI�Ȓ����̑�:%d\n", TimeMoney(i, money));
		printf("�ċN�I�Ȓ����̑�:%d\n\n", memoryRecursionMoney+=RecursionTimeMoney(i, recursionMoney));
		if (TimeMoney(i, money) < memoryRecursionMoney)
		{
			break;
		}
	}

	system("pause");

	return 0;
}