#include "ft_printf.h"

int		free_ptf(t_pf *ptf)
{
	if (ptf)
	{
		if (ptf->len)
			free(ptf->len);
		if (ptf->value)
			free(ptf->value);
		free(ptf);
		ptf = NULL;
	}
	return (-1);
}
