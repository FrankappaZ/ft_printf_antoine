
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
	u64 nbtest = ULL_MAX;

	
	test = ft_lltoabase(INT_MIN, 16, 1);
//	foo(&test, 1, b[1]);
	printf("INT MAX : %d\nINT MIN : %d\nbinary : %s\n", INT_MAX, INT_MIN, test);
	return (0);
}
