#include <stdio.h>
//��ʓI�Ȓ����`�Ԃ̌v�Z
int TimeMoney(int time, int money) {
	return time* money;
}

//�ċA�I�Ȓ����`�Ԃ̌v�Z
//���Ԃ���萔�ȉ��ɂȂ�܂ŌĂяo��
int Recursion(int time,int money) {
	time--;
	
	if (time<1) {
		return money;
	}

	return Recursion(time,money * 2 - 50);
}

int main() {
	int time = 100;				//����
	int money = 1072;			//��ʓI�Ȓ����`��
	int recursionMoney = 100;	//�ċA�I�Ȓ����`��


	//��ʓI�Ȓ����`�ԂƍċA�I�Ȓ����`�Ԃ̔�r
	for (int i = 1; i < time; i++)
	{
		printf("%d���ԓ������ꍇ\n", i);
		printf("��ʓI�Ȓ����̑�:%d\n", TimeMoney(i, money));
		printf("�ċN�I�Ȓ����̑�:%d\n\n", Recursion(i, recursionMoney));
		if (TimeMoney(i, money) < Recursion(i, recursionMoney))
		{
			break;
		}
	}

	return 0;
}