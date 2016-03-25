
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

static char	*strjoin(char *signe, char *str)
{
	char	*result;
	int		i;

	i = ft_strlen(str) + ft_strlen(signe);
	result = ft_strnew(i);
	if (!result)
		return (NULL);

}

static char	*valtostr(unsigned long value, unsigned int base)
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
		str[len] = (value % base) > 9 ?
			(value % base) - 10 + 'a' : (value % base) + '0';
		value = value / base;
	}
	return (str);
}

char	*ft_converteur()
{
	char	*result;

	

	return (result);
}
