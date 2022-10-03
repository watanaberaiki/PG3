#include <stdio.h>
template<typename Type>

Type Min(Type a, Type b) {
	if (a <= b) {
		return static_cast<Type>(a);
	}
	else if (a>b) {
		return static_cast<Type>(b);
	}

	return 0;
}

template <>
char Min(char a, char b) {
	printf("”šˆÈŠO‚Í‘ã“ü‚Å‚«‚Ü‚¹‚ñ");
	return 0;
}

int main() {
	//int
	printf("%d\n", Min<int>(5,8));
	//float
	printf("%f\n", Min<float>(8.0,5.0));
	//double
	printf("%lf\n", Min<double>(3.0,3.0));
	//char
	printf("%c\n", Min<char>('a','b'));
}