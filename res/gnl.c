# include "libft.h"


int ft_strlen(char *s)
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

char *ft_strjoin(char *s1, char *s2)
{
	int i = 0;
	int j = 0;
	int len1 = ft_strlen(s1);
	int len2 = ft_strlen(s2);

	char *p = malloc (len1 + len2 + 1);
	while (i < len1 + len2)
	{
		if (i < len1)
			p[i] = s1[i];
		else
			p[i] = s2[j++];
		i++;
	}
	p[i] = 0;
	return (p);
}


int get_next_line(char **line)
{
	static char *rest;
	char temp [10000];
	char *p;
	char *pfree;
	int ret;


	if (!line)
		return (-1);
	*line = ft_strdup("");
	if (rest)
	{
		if ((p = ft_strchr(rest, '\n')))
		{
			*p = 0;
			pfree = *line;
			*line = ft_strdup(rest);
			free(pfree);
			pfree = rest;
			rest = ft_strdup(p + 1);
			free(pfree);
			return (1);
		}
		pfree = *line;
		*line = ft_strdup(rest);
		free(pfree);
		free(rest);
		rest = NULL;
	}


	while ((ret = read(0,&temp, 1000)))
	{
		temp[ret] = 0;
		if ((p = ft_strchr(temp, '\n')))
		{
			*p = 0;
			pfree = *line;
			*line = ft_strjoin(*line, temp);
			free(pfree);
			rest = ft_strdup(p + 1);
			return (1);
		}
		pfree = *line;
		*line = ft_strjoin(*line, temp);
		free(pfree);
	}
	return (0);
}

/*
int main()
{
    int ret = 0;
    char *line = NULL;
    while ((ret = get_next_line(&line)) > 0)
    {
        printf("%s\n",line);
        free(line);
    }
    printf("%s",line);
    free(line);
    // system("leaks a.out");
}
*/