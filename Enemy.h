#pragma once
class Enemy
{
public://メンバ関数
	//近接
	void Attack();
	//射撃
	void Shot();
	//離脱
	void Leave();
	//更新
	void Update();

public://メンバ変数
	int phase = 0;

private://メンバ関数ポインタ
	static void(Enemy::* Phase[])();

};

