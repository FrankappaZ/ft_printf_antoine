#include "ft_printf.h"

int	check_type(char *str, int *i, t_pf *ptf)
{
	if (str[*i] == 's' || str[*i] == 'S')
		ptf->type = str[*i];
	else if (str[*i] == 'o' || str[*i] == 'O')
		ptf->type = str[*i];
	else if (str[*i] == 'u' || str[*i] == 'U')
		ptf->type = str[*i];
	else if (str[*i] == 'x' || str[*i] == 'X')
		ptf->type = str[*i];
	else if (str[*i] == 'c' || str[*i] == 'C' || str[*i] == '%')
		ptf->type = str[*i];
	else if (str[*i] == 'd' || str[*i] == 'D' || str[*i] == 'i')
		ptf->type = str[*i];
	else
		return (-1);
	return (0);
}

int	get_type(char *str, int *i, t_pf *ptf)
{
	if (str[*i] == 's' || str[*i] == 'S')
		ptf->type = str[*i];
	else if (str[*i] == 'p' || str[*i] == 'n')
		ptf->type = str[*i];
	else if (str[*i] == 'o' || str[*i] == 'O')
		ptf->type = str[*i];
	else if (str[*i] == 'u' || str[*i] == 'U')
		ptf->type = str[*i];
	else if (str[*i] == 'e' || str[*i] == 'E')
		ptf->type = str[*i];
	else if (str[*i] == 'f' || str[*i] == 'F')
		ptf->type = str[*i];
	else if (str[*i] == 'g' || str[*i] == 'G')
		ptf->type = str[*i];
	else if (str[*i] == 'a' || str[*i] == 'A')
		ptf->type = str[*i];
	else if (str[*i] == 'x' || str[*i] == 'X')
		ptf->type = str[*i];
	else if (str[*i] == 'c' || str[*i] == 'C' || str[*i] == '%')
		ptf->type = str[*i];
	else if (str[*i] == 'd' || str[*i] == 'D' || str[*i] == 'i')
		ptf->type = str[*i];
	else
		return (-1);
	return (0);
}
