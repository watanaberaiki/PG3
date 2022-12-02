#include <stdio.h>
#include <stdlib.h>

typedef struct cell
{
	int val;
	struct cell* prev;
	struct cell* next;
}CELL;

void Create(CELL* currentCell, int val);
void Index(CELL* endCell);
void Edit(CELL* currentCell, int val);
void Delete(CELL* currentCell, int iterator);

CELL* getInsertCellAddress(CELL* endCELL, int iterator);

int main() {
	//���ꂼ��̑���
	int operationNum[3] = { 0,0,0 };
	//�ԍ���t
	int iterator[2] = { 0,0 };
	//�l����p
	int inputValue;
	//����p
	CELL* insertCell[2];
	int keepval;

	//�������炠��
	CELL head;
	CELL cell1;
	head.next = &cell1;
	head.prev = nullptr;

	cell1.val = 10;
	cell1.next = nullptr;
	cell1.prev = &head;

	while (1) {


		if (operationNum[0] == 0 && head.next != nullptr) {
			printf("�v�f�̑���\n");
			printf("1.�v�f�̕\��\n");
			printf("2.�v�f�̑}��\n");
			printf("3.�v�f�̕ҏW\n");
			printf("4.�v�f�̍폜\n");
			printf("5.�v�f�̕��ёւ�(�I�v�V����)\n");
			printf("\n----------------------------\n");
			printf("�����I�����ĉ�����\n");
			scanf_s("%d", &operationNum[0]);
		}
		//�v�f���Ȃ��Ƃ�
		else if (operationNum[0] == 0 && head.next == nullptr) {
			printf("�v�f�̑���\n");
			printf("1.�v�f�̕\��\n");
			printf("2.�v�f�̑}��\n");
			printf("\n----------------------------\n");
			printf("�����I�����ĉ�����\n");
			scanf_s("%d", &operationNum[0]);
		}

		//�v�f�̕\��
		else if (operationNum[0] == 1) {
			if (operationNum[1] == 0) {
				printf("----------------------------\n");
				printf("1.�v�f�̈ꗗ�\��\n");
				printf("2.���Ԃ��w�肵�ėv�f��\��\n");
				printf("9.�v�f����ɖ߂�\n");
				printf("\n----------------------------\n");
				printf("�����I�����ĉ�����\n");
				scanf_s("%d", &operationNum[1]);
			}
			else if (operationNum[1] == 1) {
				if (operationNum[2] == 0) {
					printf("----------------------------\n");
					Index(&head);
					printf("----------------------------\n");
					printf("1.�v�f�̕\���ɖ߂�\n");
					printf("2.�v�f�̑���ɖ߂�\n");
					printf("\n----------------------------\n");
					printf("�����I�����ĉ�����\n");
					scanf_s("%d", &operationNum[2]);
				}
				else if (operationNum[2] == 1) {
					operationNum[1] = 0;
					operationNum[2] = 0;
				}
				else if (operationNum[2] == 2) {
					operationNum[0] = 0;
					operationNum[1] = 0;
					operationNum[2] = 0;
				}
			}
			else if (operationNum[1] == 2) {
				if (operationNum[2] == 0) {
					printf("----------------------------\n");
					printf("�w�肵���ԍ��̗v�f�̕\��\n");
					printf("�\���������v�f�̔ԍ�����͂��Ă�������\n");
					scanf_s("%d", &iterator[0]);
					printf("----------------------------\n");
					insertCell[0] = getInsertCellAddress(&head, iterator[0]);//�\���������Z���̃A�h���X
					printf("%d:%d\n", iterator[0], insertCell[0]->val);
					printf("----------------------------\n");

					printf("1.�v�f�̕\���ɖ߂�\n");
					printf("2.�v�f�̑���ɖ߂�\n");
					printf("\n----------------------------\n");
					printf("�����I�����ĉ�����\n");
					scanf_s("%d", &operationNum[2]);
				}
				//�v�f�̕\���ɖ߂�
				else if (operationNum[2] == 1) {
					operationNum[1] = 0;
					operationNum[2] = 0;
				}
				//�v�f�̑���ɖ߂�
				else if (operationNum[2] == 2) {
					operationNum[0] = 0;
					operationNum[1] = 0;
					operationNum[2] = 0;
				}
			}
			else if (operationNum[1] == 9) {
				operationNum[0] = 0;
				operationNum[1] = 0;
				operationNum[2] = 0;
			}
		}

		//�v�f�̑}��
		else if (operationNum[0] == 2) {
			printf("----------------------------\n");
			printf("���X�g�v�f�̑}��\n");
			printf("�v�f��ǉ�����ꏊ����͂��Ă��������B�Ō���ɒǉ�����ꍇ��0����͂��Ă��������B\n");
			scanf_s("%d", &iterator[0]);
			printf("----------------------------\n");
			printf("�ǉ�����v�f�̒l����͂��Ă��������B\n");
			scanf_s("%d", &inputValue);

			if (iterator[0] != 0) {
				insertCell[0] = getInsertCellAddress(&head, iterator[0]);//�}���������Z���̃A�h���X
				//�����v�f��ǉ�����ꏊ�����������肵���ꍇ
				if (insertCell[0] == nullptr) {
					CELL* endCell = &head;
					iterator[0] = 0;
					while (endCell->next != nullptr) {
						endCell = endCell->next;
						iterator[0]++;
					}
					insertCell[0] = getInsertCellAddress(&head, iterator[0]);//�}���������Z���̃A�h���X
				}

				Create(insertCell[0], inputValue);
				printf("�v�f%d��%d�ɒǉ�����܂����B\n", inputValue, iterator[0]);
				printf("----------------------------\n");
			}
			else {
				CELL* endCell = &head;
				iterator[0] = 0;
				while (endCell->next != nullptr) {
					endCell = endCell->next;
					iterator[0]++;
				}
				insertCell[0] = getInsertCellAddress(&head, iterator[0]);//�}���������Z���̃A�h���X
				Create(insertCell[0], inputValue);
				printf("�v�f%d���Ō���ɒǉ�����܂����B\n", inputValue);
				printf("----------------------------\n");
			}

			operationNum[0] = 0;
			operationNum[1] = 0;
			operationNum[2] = 0;

		}
		//�v�f�̕ҏW
		else if (operationNum[0] == 3 && head.next != nullptr) {
			printf("----------------------------\n");
			printf("�v�f�̕ҏW\n");
			printf("�ҏW�������v�f�̔ԍ����w�肵�Ă��������B\n");
			scanf_s("%d", &iterator[0]);
			insertCell[0] = getInsertCellAddress(&head, iterator[0]);//�}���������Z���̃A�h���X
			printf("----------------------------\n");

			if (insertCell != nullptr) {
				printf("%d�Ԗڂ̗v�f�̕ύX����l����͂��Ă��������B\n", iterator[0]);
				scanf_s("%d", &inputValue);
				Edit(insertCell[0], inputValue);
			}
			else {
				printf("%d�Ԗڂ̗v�f��������܂���ł����B\n", iterator[0]);
			}
			printf("----------------------------\n");
			operationNum[0] = 0;
			operationNum[1] = 0;
			operationNum[2] = 0;

		}
		//�v�f���Ȃ��Ƃ�
		else if (operationNum[0] == 3 && head.next == nullptr) {
			operationNum[0] = 0;
			operationNum[1] = 0;
			operationNum[2] = 0;
		}

		//�v�f�̍폜
		else if (operationNum[0] == 4 && head.next != nullptr) {
			printf("----------------------------\n");
			printf("�v�f�̍폜\n");
			printf("�ҏW�������v�f�̔ԍ����w�肵�Ă��������B\n");
			scanf_s("%d", &iterator[0]);
			printf("----------------------------\n");
			insertCell[0] = getInsertCellAddress(&head, iterator[0]);//�폜�������Z���̃A�h���X
			if (insertCell != nullptr) {
				Delete(insertCell[0], iterator[0]);
				printf("----------------------------\n");
			}
			else {
				printf("%d�Ԗڂ̗v�f��������܂���ł����B", iterator[0]);
				printf("----------------------------\n");
			}
			operationNum[0] = 0;
			operationNum[1] = 0;
			operationNum[2] = 0;

		}
		//�v�f���Ȃ��Ƃ�
		else if (operationNum[0] == 4 && head.next == nullptr) {
			operationNum[0] = 0;
			operationNum[1] = 0;
			operationNum[2] = 0;
		}

		//�v�f�̕��ёւ�
		else if (operationNum[0] == 5 && head.next != nullptr) {
			printf("----------------------------\n");
			printf("�v�f�̕��ёւ�\n");
			printf("1�ڂ̕��ёւ������v�f�̔ԍ����w�肵�Ă��������B\n");
			scanf_s("%d", &iterator[0]);
			printf("2�ڂ̕��ёւ������v�f�̔ԍ����w�肵�Ă��������B\n");
			scanf_s("%d", &iterator[1]);
			printf("----------------------------\n");
			insertCell[0] = getInsertCellAddress(&head, iterator[0]);//�}���������Z���̃A�h���X
			insertCell[1] = getInsertCellAddress(&head, iterator[1]);//�}���������Z���̃A�h���X
			if (insertCell[0] != nullptr) {
				if (insertCell[1] != nullptr) {
					//�ۑ�����
					keepval = insertCell[0]->val;
					//�ҏW�ŕ��ѕς���
					Edit(insertCell[0], insertCell[1]->val);
					Edit(insertCell[1], keepval);
				}
				else {
					printf("%d�Ԗڂɂ͗v�f������܂���\n",iterator[1]);
					printf("----------------------------\n");
				}
			}
			else {
				printf("%d�Ԗڂɂ͗v�f������܂���\n", iterator[0]);
				printf("----------------------------\n");
			}
			operationNum[0] = 0;
			operationNum[1] = 0;
			operationNum[2] = 0;

		}
		//�v�f���Ȃ��Ƃ�
		else if (operationNum[0] == 5 && head.next == nullptr) {
			operationNum[0] = 0;
			operationNum[1] = 0;
			operationNum[2] = 0;
		}
	}
}


CELL* getInsertCellAddress(CELL* endCELL, int iterator) {
	for (int i = 0; i < iterator; i++) {
		if (endCELL->next) {
			endCELL = endCELL->next;
		}
		else {
			endCELL = nullptr;
			break;
		}
	}
	return endCELL;
}

void Create(CELL* currentCell, int val) {
	//�V�K�ɃZ�����쐬
	CELL* newCell;
	newCell = (CELL*)malloc(sizeof(CELL));
	newCell->val = val;
	newCell->prev = currentCell;
	newCell->next = currentCell->next;

	if (currentCell->next) {
		CELL* nextCell = currentCell->next;
		nextCell->prev = newCell;
	}

	currentCell->next = newCell;
}

void Index(CELL* endCell) {
	int no = 1;
	while (endCell->next != nullptr) {
		endCell = endCell->next;
		printf("\n%d:", no);
		printf("%d\n", endCell->val);
		no++;
	}
	printf("\n�v�f��:%d\n", no - 1);
}

void Edit(CELL* currentCell, int val) {
	currentCell->val = val;
}

void Delete(CELL* currentCell, int iterator) {
	if (currentCell->prev != nullptr) {
		currentCell->prev->next = currentCell->next;
	}
	if (currentCell->next != nullptr) {
		currentCell->next->prev = currentCell->prev;
	}
	printf("%d�Ԗڂ̗v�f%d���폜����܂���\n", iterator, currentCell->val);
	currentCell = nullptr;
}