#include <stdio.h>

int main()
{
	int a;
/*
	printf("\ni = |%i|", -2147483648);
    printf("\ni = |%0 15i|",  -2147483648);
    printf("\ni = |%0 -12i|", -2147483648);
    printf("\ni = |%0 -15.13i|", -2147483648);
    printf("\ni = |% -15.13i|", -2147483648);
    printf("\ni = |% 15.13i|", -2147483648);
    printf("\ni = |%015.13i|", -2147483648);
    printf("\ni = |%0*.9i|\n", 15, -2147483648);
*/
/*

    printf("\nu = |%0+15u|",  (unsigned int)4294967295);
    printf("\nu = |%0+-12u|", (unsigned int)4294967295);
    printf("\nu = |%0 -15.13u|", (unsigned int)4294967295);
    printf("\nu = |%+-15.13u|", (unsigned int)4294967295);
    printf("\nu = |%+15.13u|", (unsigned int)4294967295);
    printf("\nu = |%015.13u|", (unsigned int)4294967295);
    printf("\nu = |%0 *.9u|\n", 15, (unsigned int)4294967295);
*/ 
	printf("\ni = |%0x|", (unsigned int)4294967295);
    printf("\ni = |%0#18x|", (unsigned int)4294967295);
    printf("\ni = |%0-#12x|", (unsigned int)4294967295);
    printf("\ni = |%-#18.13x|", (unsigned int)4294967295);
    printf("\ni = |%#-18.13x|", (unsigned int)4294967295);
    printf("\ni = |% #18.13x|", (unsigned int)4294967295);
    printf("\ni = |%#18.13x|", (unsigned int)4294967295);
    printf("\ni = |%#*.9x|\n", 15, (unsigned int)4294967295);


	return 0;
}
