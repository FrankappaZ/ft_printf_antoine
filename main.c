
#include <stdlib.h>
#include <stdio.h>
#include "ft_printf.h"
#include <stdarg.h>
#include <string.h> 
#include "libft/includes/libft.h"
#include "ft_linit.h"

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
	unsigned long nbtest = UL32_MAX;

	
	test = ft_lltoabase(UL32_MAX, 16, 1);
//	foo(&test, 1, b[1]);
	printf("INT MAX : %lu\nINT MIN : %lu\nbinary : %s\n", UL32_MAX, 4294967295UL, test);
//	ft_printf("%iurge %3 %% %% \n %s %s %%");
	return (0);
}
