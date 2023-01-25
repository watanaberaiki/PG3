#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<windows.h>
#include<functional>
#include"SceneManager.h"


int main() {
	//�C���X�^���X�擾
	SceneManager* sceneManager = SceneManager::GetInstance();
	
	int nextSceneNo = 1;

	while (true) {
		//�҂�
		Sleep(2 * 1000);
		//�\��
		if (sceneManager->sceneNo % 4 == 0) {
			printf("sceneNo:%d--Title\n", sceneManager->sceneNo % 4);
		}else if (sceneManager->sceneNo % 4 == 1) {
			printf("sceneNo:%d--NewGame\n", sceneManager->sceneNo % 4);
		}
		else if(sceneManager->sceneNo % 4 == 2) {
			printf("sceneNo:%d--GamePlay\n", sceneManager->sceneNo % 4);
		}
		else if(sceneManager->sceneNo % 4 == 3) {
			printf("sceneNo:%d--GameClear\n", sceneManager->sceneNo % 4);
		}
		//�V�[���`�F���W
		sceneManager->ChangeScene(nextSceneNo);
		nextSceneNo++;
	}

	system("pause");
	return 0;
}