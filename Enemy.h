#pragma once
class Enemy
{
public:
	static int enemyCount;

	Enemy() { enemyCount++; }
	~Enemy(){ enemyCount=0; }
};

