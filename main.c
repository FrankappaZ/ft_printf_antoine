
#include <stdlib.h>
#include <stdio.h>
#include "ft_printf.h"
#include <stdarg.h>
#include <string.h> 
#include "libft/includes/libft.h"

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
	short nbr = 42;
	test = ft_lltoabase((u64)nbr, 2, 0);
//	foo(&test, 1, b[1]);
	ft_putstr(test);
	printf("\n\n%lu\n", sizeof(nbr));
	return (0);
}
