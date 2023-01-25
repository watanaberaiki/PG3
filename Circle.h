#pragma once
#include "IShape.h"
class Circle : public IShape
{
public:
	float r=0;

	float area;

public:
	//ŒvŽZ
	void size() override;
	//•\Ž¦
	void draw() override;
};

