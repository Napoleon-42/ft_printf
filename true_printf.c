#include <stdio.h>

int main()
{
	char c = 'c';
	printf("\t\033[0;33m printf(\"{char}\", \'c\') =>\033[0;31m|%c|", c);
	return (0);
}