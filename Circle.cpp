#include "Circle.h"
#include <stdio.h>

void Circle::size()
{
	area = r * r * 3.14;
}

void Circle::draw()
{
	printf("â~ÇÃñ êœ%f\n", area);
}
