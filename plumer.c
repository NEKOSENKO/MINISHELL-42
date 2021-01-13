#include "shell.h"

void	buf_free(char *buffer)
{
	ft_putstr("USSR : Allocation Error!");
	free(buffer);
	exit(1);
}