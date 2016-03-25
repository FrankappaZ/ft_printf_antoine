
#include <stdlib.h>
#include <stdio.h>
#include "ft_printf.h"
#include <stdarg.h>
#include <string.h> 
static void foo(char **str, int nbrarg, ...)
{
	va_list ap;
	int d;

	va_start(ap, nbrarg);
	while (nbrarg > 0)
	{
		
		*str = strdup(va_arg(ap, char*));	
		nbrarg--;
	}
	va_end(ap);
}

int main(int a, char **b)
{
	int i = atoi(b[2]);
	char toto[30] = "Salut";

	char *test;
	test = ft_itoh(i);
//	foo(&test, 1, b[1]);
	printf("%d\n", 12.34, 56.78, 90.12, 42);
	printf("%u ey !\n", 45000000000000);
	printf("1234567890");
	return (0);
}
