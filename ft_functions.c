# include "s_header.h"

void	ft_putstr(char const *s)
{
	if (!s)
		return ;
	write(0, s, ft_strlen(s));
}

int ft_strlen(const char *s)
{
	int i = 0;
	while(s[i])
	{
		i++;
	}
	return (i);
}

char *ft_strdup(char *s)
{
	int i = 0;
	int len = ft_strlen(s);
	char *p = malloc (len + 1);

	while (s[i])
	{
		p[i] = s[i];
		i++;
	}
	p[i] = 0;
	return (p);
}

char *ft_strchr(char *s, char c)
{
	int i = 0;
	while (s[i++])
		if (s[i] == c)
		{
			return (s + i);
		}
	return (0);
}

