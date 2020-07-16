#include <stdio.h>

int main()
{
	printf("\nc = |%c|", 'c');
	printf("\nc = |%3c|", 'c');
	printf("\nc = |%-3c|", 'c');
	printf("\nc = |%-*c|", 3,'c');
	return 0;
}
