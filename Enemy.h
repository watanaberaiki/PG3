#pragma once
class Enemy
{
public://�����o�֐�
	//�ߐ�
	void Attack();
	//�ˌ�
	void Shot();
	//���E
	void Leave();
	//�X�V
	void Update();

public://�����o�ϐ�
	int phase = 0;

private://�����o�֐��|�C���^
	static void(Enemy::* Phase[])();

};

