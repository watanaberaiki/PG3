#include "RectAngle.h"
#include <stdio.h>
void RectAngle::size()
{
	area = x * y;
}

void RectAngle::draw()
{
	printf("‹éŒ`‚Ì–ÊÏ%f\n", area);
}
