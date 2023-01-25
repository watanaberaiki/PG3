#pragma once
class SceneManager final
{
private:
	//�R���X�g���N�^��private�ɂ���
	SceneManager();
	//�f�X�g���N�^��private�ɂ���
	~SceneManager();
public:
	//�R�s�[�R���X�g���N�^�𖳌��ɂ���
	SceneManager(const SceneManager& obj) = delete;
	//������Z�q�𖳌��ɂ���
	SceneManager& operator=(const SceneManager& obj) = delete;
	//�C���X�^���X
	static SceneManager* GetInstance();
	//�V�[���`�F���W
	void ChangeScene(int sceneNo);

public:
	int sceneNo = 0;
};

