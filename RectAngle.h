#pragma once
#include "IShape.h"
class RectAngle :public IShape
{
public:
	float x=0;
	float y=0;
	float area = 0;

public:
	//�v�Z
	void size() override;
	//�\��
	void draw() override;
};

