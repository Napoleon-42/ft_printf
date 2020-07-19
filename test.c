#include <stdio.h>

int main()
{
	int a;

	printf("\ni = |%i|", -2147483648);
    printf("\ni = |%0 15i|",  -2147483648);
    printf("\ni = |%0 -12i|", -2147483648);
    printf("\ni = |%0 -15.13i|", -2147483648);
    printf("\ni = |% -15.13i|", -2147483648);
    printf("\ni = |% 15.13i|", -2147483648);
    printf("\ni = |%015.13i|", -2147483648);
    printf("\ni = |%0*.9i|\n", 15, -2147483648);



	return 0;
}
