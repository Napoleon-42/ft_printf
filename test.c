#include <stdio.h>

int main()
{
	int a;

	printf("\n p = |%p|", &a);
    printf("\n p = |%20p|", &a);
    printf("\n p = |%020p|", &a);
    printf("\n p = |%-20p|", &a);

	return 0;
}
