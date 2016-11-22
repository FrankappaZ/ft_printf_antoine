#include "libft/includes/libft.h"

void	upstr(char **str)
{
	size_t	i;

	i = 0;
	while (str[0][i])
	{
		if (str[0][i] > 96 && str[0][i] < 123)
			str[0][i] -= 32;
		i++;
	}
}
