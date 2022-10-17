#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<windows.h>

typedef void (*PFunc)(int*,int*);

//�R�[���o�b�N�֐�
void Callback(int* second,int* predict) {
	printf("����\n");
}

//���b���҂��Ċ֐����Ă�
void SetTimeout(PFunc p, int second, int predict) {
	//�҂�
	Sleep(second * 1000);
	
	//�Ăяo��
	p(&second,&predict);
}

//���ʔ���
void Result(int *second,int* predict) {
	//�����_��
	int ramdom = rand() % 6 + 1;
	
	//��̏ꍇ
	if (*predict ==1 ) {
		if (ramdom % 2 == 1) {
			printf("�����ł�!\n%d�����I�őI�΂�܂���",ramdom);
		}
		else {
			printf("�s�����ł�\n%d�����I�őI�΂�܂���", ramdom);
		}
	}

	//�����̏ꍇ
	else if (*predict == 2) {
		if (ramdom % 2  == 0) {
			printf("�����ł�!\n%d�����I�őI�΂�܂���", ramdom);
		}
		else {
			printf("�s�����ł�\n%d�����I�őI�΂�܂���", ramdom);
		}
	}
	//�Ⴄ�l�����͂��ꂽ�ꍇ
	else {
		printf("�s�K�؂Ȓl�����͂���܂���");
	}
}

int main() {

	//�����_���p
	srand((unsigned int)time(NULL));
	int ramdom = rand() % 6 + 1;


	//�������������
	int predict = 0;
	printf("����Ǝv���Ȃ�1���A�������Ǝv���Ȃ�Q����͂��Ă��������B");
	scanf_s("%d", &predict);

	//�֐��|�C���^
	PFunc p;
	
	//�����҂�
	p = Callback;
	SetTimeout(p, 3, predict);
	
	//���ʏo��
	p = Result;
	SetTimeout(p, 0, predict);

	return 0;
}