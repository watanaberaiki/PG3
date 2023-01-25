#include "Enemy.h"
#include <stdio.h>
void Enemy::Attack() {
	printf("敵が近接攻撃してくる\n");
}

void Enemy::Shot() {
	printf("敵が射撃の攻撃をしてくる\n");
}

void Enemy::Leave() {
	printf("敵が離脱してる\n");
}

void Enemy::Update() {
	(this->*Enemy::Phase[static_cast<size_t>(phase)])();
}

void(Enemy::* Enemy::Phase[])() = {
	&Enemy::Attack,
	&Enemy::Shot,
	&Enemy::Leave
};