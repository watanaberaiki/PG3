#include "RectAngle.h"
#include <stdio.h>
void RectAngle::size()
{
	area = x * y;
}

void RectAngle::draw()
{
	printf("��`�̖ʐ�%f\n", area);
}
