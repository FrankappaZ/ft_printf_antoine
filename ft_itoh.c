
#include "ft_printf.h"
#include "libft/includes/libft.h"

static int	lenght(unsigned int value)
{
	int i;

	i = 0;
	if (value == 0)
	i++;
	while (value != 0)
	{
		value /= 16;
		i++;
	}
	return (i);
}

char	*ft_itoh(unsigned int value)
{
	int len;
	char *str;

	len = lenght(value);
	str = ft_strnew(len + 1);
	if (!str)
		return (NULL);
	while (len > 0)
	{
		len --;
		str[len] = (value % 16) > 9 ?
			(value % 16) - 10 + 'a' : (value % 16) + '0';
		value = value / 16;
	}
	return (str);
}
