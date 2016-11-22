
#include "libft/includes/libft.h"

char		*ft_ctoa(char c)
{
	char	*str;

	str = ft_strnew(1);
	if (!str)
		return (NULL);
	str[0] = c;
	return (str);
}

