#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<windows.h>

typedef void (*newType)(int *second);

//�R�[���o�b�N�֐�
void callback(int *second) {
	printf("%d�b�҂��܂�\n", *second);
}

void setTimeout(newType wait,int second) {
	Sleep(second*1000);

	wait(&second);
}

int main() {
	//�֐��|�C���^
	newType wait;
	//�����_���p
	srand((unsigned int)time(NULL));

	//�������������
	int num = 0;
	printf("�����͂��������o�͂���A���������͂��ꂽ��������o�͂���܂��B");
	scanf_s("%d", &num);

	//�����҂�
	wait = callback;
	setTimeout(wait, 5);
	//�o��
	if (num % 2 == 0) {
		printf("����:%d", (rand() % 100+1) * 2);
	}
	else if (num%2==1) {
		printf("�:%d", (rand() % 100+1) * 2 + 1);
	}
	else {

	}

	return 0;
}