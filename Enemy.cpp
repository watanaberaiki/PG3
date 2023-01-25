#include "Enemy.h"
#include <stdio.h>
void Enemy::Attack() {
	printf("“G‚ª‹ßÚUŒ‚‚µ‚Ä‚­‚é\n");
}

void Enemy::Shot() {
	printf("“G‚ªŽËŒ‚‚ÌUŒ‚‚ð‚µ‚Ä‚­‚é\n");
}

void Enemy::Leave() {
	printf("“G‚ª—£’E‚µ‚Ä‚é\n");
}

void Enemy::Update() {
	(this->*Enemy::Phase[static_cast<size_t>(phase)])();
}

void(Enemy::* Enemy::Phase[])() = {
	&Enemy::Attack,
	&Enemy::Shot,
	&Enemy::Leave
};