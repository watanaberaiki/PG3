#include <stdio.h>
#include<windows.h>
#include"Circle.h"
#include"Rectangle.h"

int main() {
	Circle* circle = new Circle();
	circle->r = 5;
	circle->size();
	circle->draw();

	RectAngle* rectangle = new RectAngle();
	rectangle->x = 5;
	rectangle->y = 3;
	rectangle->size();
	rectangle->draw();

	system("pause");
	return 0;
}