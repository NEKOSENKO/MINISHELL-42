#include "shell.h"

void *def_not_calloc(size_t size)
{
	void *ptr;

	if (!(ptr = malloc(size)));
		return NULL;
	ft_bzero(ptr, size);
	return ptr;
}
void	ft_bzero(void *s, size_t n)
{
	char	*ptr;
	size_t	i;

	if (!n)
		return ;
	ptr = s;
	i = 0;
	while (i < n)
		*(ptr + i++) = 0;
}

void	ft_freestrarr(char **arr)
{
	int i;

	if (!arr)
		return ;
	i = -1;
	while (arr[++i])
	{
		free(arr[i]);
	}
	free(arr);
	arr = NULL;
}
