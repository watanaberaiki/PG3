#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<windows.h>
#include<functional>

int main(int argc, const char*argy[]) {

	//�����_��
	srand((unsigned int)time(NULL));
	int ramdom = rand() % 6 + 1;

	//����
	int second = 3;
	
	
	//�������������
	int predict = 0;
	printf("����Ǝv���Ȃ�1���A�������Ǝv���Ȃ�Q����͂��Ă��������B");
	scanf_s("%d", &predict);

	//�����҂�
	std::function<int(int)>Timeout = [](int second) {Sleep(second * 1000); return 0; };
	Timeout(second);

	//���ʔ���Əo��
	std::function<int(int)>Result = [predict](int ramdom) {
	//��̏ꍇ
		if (predict ==1 ) {
			if (ramdom % 2 == 1) {
				printf("�����ł�!\n%d�����I�őI�΂�܂���",ramdom);
			}
			else {
				printf("�s�����ł�\n%d�����I�őI�΂�܂���", ramdom);
			}
		}
	
		//�����̏ꍇ
		else if (predict == 2) {
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
		return 0;
	};

	//���ʔ���Əo��
	Result(ramdom);
	
	return 0;
}