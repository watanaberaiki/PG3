#include "Circle.h"
#include <stdio.h>

void Circle::size()
{
	area = r * r * 3.14;
}

void Circle::draw()
{
	printf("�~�̖ʐ�%f\n", area);
}
