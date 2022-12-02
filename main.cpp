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
	//それぞれの操作
	int operationNum[3] = { 0,0,0 };
	//番号受付
	int iterator[2] = { 0,0 };
	//値代入用
	int inputValue;
	//操作用
	CELL* insertCell[2];
	int keepval;

	//初期からある
	CELL head;
	CELL cell1;
	head.next = &cell1;
	head.prev = nullptr;

	cell1.val = 10;
	cell1.next = nullptr;
	cell1.prev = &head;

	while (1) {


		if (operationNum[0] == 0 && head.next != nullptr) {
			printf("要素の操作\n");
			printf("1.要素の表示\n");
			printf("2.要素の挿入\n");
			printf("3.要素の編集\n");
			printf("4.要素の削除\n");
			printf("5.要素の並び替え(オプション)\n");
			printf("\n----------------------------\n");
			printf("操作を選択して下さい\n");
			scanf_s("%d", &operationNum[0]);
		}
		//要素がないとき
		else if (operationNum[0] == 0 && head.next == nullptr) {
			printf("要素の操作\n");
			printf("1.要素の表示\n");
			printf("2.要素の挿入\n");
			printf("\n----------------------------\n");
			printf("操作を選択して下さい\n");
			scanf_s("%d", &operationNum[0]);
		}

		//要素の表示
		else if (operationNum[0] == 1) {
			if (operationNum[1] == 0) {
				printf("----------------------------\n");
				printf("1.要素の一覧表示\n");
				printf("2.順番を指定して要素を表示\n");
				printf("9.要素操作に戻る\n");
				printf("\n----------------------------\n");
				printf("操作を選択して下さい\n");
				scanf_s("%d", &operationNum[1]);
			}
			else if (operationNum[1] == 1) {
				if (operationNum[2] == 0) {
					printf("----------------------------\n");
					Index(&head);
					printf("----------------------------\n");
					printf("1.要素の表示に戻る\n");
					printf("2.要素の操作に戻る\n");
					printf("\n----------------------------\n");
					printf("操作を選択して下さい\n");
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
					printf("指定した番号の要素の表示\n");
					printf("表示したい要素の番号を入力してください\n");
					scanf_s("%d", &iterator[0]);
					printf("----------------------------\n");
					insertCell[0] = getInsertCellAddress(&head, iterator[0]);//表示したいセルのアドレス
					printf("%d:%d\n", iterator[0], insertCell[0]->val);
					printf("----------------------------\n");

					printf("1.要素の表示に戻る\n");
					printf("2.要素の操作に戻る\n");
					printf("\n----------------------------\n");
					printf("操作を選択して下さい\n");
					scanf_s("%d", &operationNum[2]);
				}
				//要素の表示に戻る
				else if (operationNum[2] == 1) {
					operationNum[1] = 0;
					operationNum[2] = 0;
				}
				//要素の操作に戻る
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

		//要素の挿入
		else if (operationNum[0] == 2) {
			printf("----------------------------\n");
			printf("リスト要素の挿入\n");
			printf("要素を追加する場所を入力してください。最後尾に追加する場合は0を入力してください。\n");
			scanf_s("%d", &iterator[0]);
			printf("----------------------------\n");
			printf("追加する要素の値を入力してください。\n");
			scanf_s("%d", &inputValue);

			if (iterator[0] != 0) {
				insertCell[0] = getInsertCellAddress(&head, iterator[0]);//挿入したいセルのアドレス
				//もし要素を追加する場所が高すぎたりした場合
				if (insertCell[0] == nullptr) {
					CELL* endCell = &head;
					iterator[0] = 0;
					while (endCell->next != nullptr) {
						endCell = endCell->next;
						iterator[0]++;
					}
					insertCell[0] = getInsertCellAddress(&head, iterator[0]);//挿入したいセルのアドレス
				}

				Create(insertCell[0], inputValue);
				printf("要素%dが%dに追加されました。\n", inputValue, iterator[0]);
				printf("----------------------------\n");
			}
			else {
				CELL* endCell = &head;
				iterator[0] = 0;
				while (endCell->next != nullptr) {
					endCell = endCell->next;
					iterator[0]++;
				}
				insertCell[0] = getInsertCellAddress(&head, iterator[0]);//挿入したいセルのアドレス
				Create(insertCell[0], inputValue);
				printf("要素%dが最後尾に追加されました。\n", inputValue);
				printf("----------------------------\n");
			}

			operationNum[0] = 0;
			operationNum[1] = 0;
			operationNum[2] = 0;

		}
		//要素の編集
		else if (operationNum[0] == 3 && head.next != nullptr) {
			printf("----------------------------\n");
			printf("要素の編集\n");
			printf("編集したい要素の番号を指定してください。\n");
			scanf_s("%d", &iterator[0]);
			insertCell[0] = getInsertCellAddress(&head, iterator[0]);//挿入したいセルのアドレス
			printf("----------------------------\n");

			if (insertCell != nullptr) {
				printf("%d番目の要素の変更する値を入力してください。\n", iterator[0]);
				scanf_s("%d", &inputValue);
				Edit(insertCell[0], inputValue);
			}
			else {
				printf("%d番目の要素が見つかりませんでした。\n", iterator[0]);
			}
			printf("----------------------------\n");
			operationNum[0] = 0;
			operationNum[1] = 0;
			operationNum[2] = 0;

		}
		//要素がないとき
		else if (operationNum[0] == 3 && head.next == nullptr) {
			operationNum[0] = 0;
			operationNum[1] = 0;
			operationNum[2] = 0;
		}

		//要素の削除
		else if (operationNum[0] == 4 && head.next != nullptr) {
			printf("----------------------------\n");
			printf("要素の削除\n");
			printf("編集したい要素の番号を指定してください。\n");
			scanf_s("%d", &iterator[0]);
			printf("----------------------------\n");
			insertCell[0] = getInsertCellAddress(&head, iterator[0]);//削除したいセルのアドレス
			if (insertCell != nullptr) {
				Delete(insertCell[0], iterator[0]);
				printf("----------------------------\n");
			}
			else {
				printf("%d番目の要素が見つかりませんでした。", iterator[0]);
				printf("----------------------------\n");
			}
			operationNum[0] = 0;
			operationNum[1] = 0;
			operationNum[2] = 0;

		}
		//要素がないとき
		else if (operationNum[0] == 4 && head.next == nullptr) {
			operationNum[0] = 0;
			operationNum[1] = 0;
			operationNum[2] = 0;
		}

		//要素の並び替え
		else if (operationNum[0] == 5 && head.next != nullptr) {
			printf("----------------------------\n");
			printf("要素の並び替え\n");
			printf("1つ目の並び替えたい要素の番号を指定してください。\n");
			scanf_s("%d", &iterator[0]);
			printf("2つ目の並び替えたい要素の番号を指定してください。\n");
			scanf_s("%d", &iterator[1]);
			printf("----------------------------\n");
			insertCell[0] = getInsertCellAddress(&head, iterator[0]);//挿入したいセルのアドレス
			insertCell[1] = getInsertCellAddress(&head, iterator[1]);//挿入したいセルのアドレス
			if (insertCell[0] != nullptr) {
				if (insertCell[1] != nullptr) {
					//保存する
					keepval = insertCell[0]->val;
					//編集で並び変える
					Edit(insertCell[0], insertCell[1]->val);
					Edit(insertCell[1], keepval);
				}
				else {
					printf("%d番目には要素がありません\n",iterator[1]);
					printf("----------------------------\n");
				}
			}
			else {
				printf("%d番目には要素がありません\n", iterator[0]);
				printf("----------------------------\n");
			}
			operationNum[0] = 0;
			operationNum[1] = 0;
			operationNum[2] = 0;

		}
		//要素がないとき
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
	//新規にセルを作成
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
	printf("\n要素数:%d\n", no - 1);
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
	printf("%d番目の要素%dが削除されました\n", iterator, currentCell->val);
	currentCell = nullptr;
}