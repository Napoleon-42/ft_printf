#include <stdio.h>
#include "printf.h"

int main()
{
	int a;

static unsigned int		mx_u = 235;
static char				mx_c = 'G';
static char			   *mx_s = "Hello, World!";
static int				mx_i = 42;

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
/*	printf("\ni = |%0x|", (unsigned int)4294967295);
    printf("\ni = |%0#18x|", (unsigned int)4294967295);
    printf("\ni = |%0-#12x|", (unsigned int)4294967295);
    printf("\ni = |%-#18.13x|", (unsigned int)4294967295);
    printf("\ni = |%#-18.13x|", (unsigned int)4294967295);
    printf("\ni = |% #18.13x|", (unsigned int)4294967295);
    printf("\ni = |%#18.13x|", (unsigned int)4294967295);
    printf("\ni = |%#*.9x|\n", 15, (unsigned int)4294967295);*/
/*
	   printf("\nf = |%f|", __FLT_MIN__);
	   printf("\nf = |%0 15f|", __FLT_MIN__);
	   printf("\nf = |% -12f|", __FLT_MIN__);
	   printf("\nf = |% -15.13f|", __FLT_MIN__);
	   printf("\nf = |% 15.13f|", __FLT_MIN__);
	   printf("\nf = |%015.13f|", __FLT_MIN__);
	   printf("\nf = |%0*.9f|\n", 15, __FLT_MIN__);
*/
	printf("%05");

//	ft_printf("%03.3u", 6983);
//	printf("\ntrue one- (%x    %c    %X    %s    %u    %p ",
//			mx_u, mx_c, mx_u, mx_s, mx_u, &mx_i);
//	ft_printf("\n\t\t-  %x    %c    %X    %s    %u    %p  ",
//		mx_u, mx_c, mx_u, mx_s, mx_u, &mx_i);


	return 0;
}
