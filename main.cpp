#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<windows.h>
#include<functional>

int main() {

	//�����_��
	srand((unsigned int)time(NULL));
	int ramdom = rand() % 6 + 1;

	//����
	int second = 3;


	//�������������
	int predict = 0;
	printf("����Ǝv���Ȃ�1���A�������Ǝv���Ȃ�Q����͂��Ă��������B");
	scanf_s("%d", &predict);

	//���Ԃ�u��
	std::function<void(int, int)>SetTimeout = [](int second, int ramdom) {Sleep(second * 1000); };

	//���ʔ���Əo��
	std::function<void(int)>Result = [=](int ramdom) {
		
		//��̏ꍇ
		if (predict == 1) {
			if (ramdom % 2 == 1) {
				printf("�����ł�!\n%d�����I�őI�΂�܂���", ramdom);
			}
			else {
				printf("�s�����ł�\n%d�����I�őI�΂�܂���", ramdom);
			}
		}

		//�����̏ꍇ
		else if (predict == 2) {
			if (ramdom % 2 == 0) {
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
		return 0;
	};

	//���Ԃ�u���Ăяo��
	SetTimeout(second, ramdom);

	//���ʔ���
	Result(ramdom);

	return 0;
}