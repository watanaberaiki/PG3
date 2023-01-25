#include "Enemy.h"
#include <stdio.h>
void Enemy::Attack() {
	printf("�G���ߐڍU�����Ă���\n");
}

void Enemy::Shot() {
	printf("�G���ˌ��̍U�������Ă���\n");
}

void Enemy::Leave() {
	printf("�G�����E���Ă�\n");
}

void Enemy::Update() {
	(this->*Enemy::Phase[static_cast<size_t>(phase)])();
}

void(Enemy::* Enemy::Phase[])() = {
	&Enemy::Attack,
	&Enemy::Shot,
	&Enemy::Leave
};