#pragma once
#include "IShape.h"
class Circle : public IShape
{
public:
	float r=0;

	float area;

public:
	//�v�Z
	void size() override;
	//�\��
	void draw() override;
};

