#include <stdio.h>
#include "printf.h"

int main()
{
/*	int a;

static unsigned int		mx_u = 235;
static char				mx_c = 'G';
static char			   *mx_s = "Hello, World!";
static int				mx_i = 42;
*/
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
//      RETURN VALUE TEST STAND //

int     a = -4;
int     b = 0;
char    c = 'a';
int     d = 2147483647;
int     e = -2147483648;
int     f = 42;
int     g = 25;
int     h = 4200;
int     i = 8;
int     j = -12;
int     k = 123456789;
int     l = 0;
int     m = -12345678;
char    *n = "abcdefghijklmnop";
char    *o = "-a";
char    *p = "-12";
char    *q = "0";
char    *r = "%%";
char    *s = "-2147483648";
char    *t = "0x12345678";
char    *u = "-0";
int     abs, bds;
    
    abs = printf("%*.*s", -2, 3, q);
    printf("res = %i", abs);
    printf("\n-----------------------------\n");


    abs = printf("printf - |%*.*s|\n", -2, 3, q);
    
    write(1, "\n\n", 2);
    
    bds = ft_printf("ftprin - |%*.*s|\n", -2, 3, q);

    write(1, "\n -------------------------------- \n", 37);
    printf("True return = %d \nMy return   = %d", abs, bds);


    //ft_printf("%03.3u", 6983);
//	printf("\ntrue one- (%x    %c    %X    %s    %u    %p ",
//			mx_u, mx_c, mx_u, mx_s, mx_u, &mx_i);
//	ft_printf("\n\t\t-  %x    %c    %X    %s    %u    %p  ",
//		mx_u, mx_c, mx_u, mx_s, mx_u, &mx_i);

/* 
    abs = printf("printf - %*.*s, %*.*s, %*.*s, %*.*s, %*.*s, %*.*s, %*.*s, %*.*s|\n", -2, 3, n, -2, 3, o, -2, 3, p, -2, 3, q, -2, 3, r, -2, 3, s, -2, 3, t, -2, 3, u);
    
    write(1, "\n\n", 2);
    
    bds = ft_printf("ftprin - %*.*s, %*.*s, %*.*s, %*.*s, %*.*s, %*.*s, %*.*s, %*.*s|\n", -2, 3, n, -2, 3, o, -2, 3, p, -2, 3, q, -2, 3, r, -2, 3, s, -2, 3, t, -2, 3, u);
*/

	return 0;
}
