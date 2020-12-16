/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrija <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 11:20:27 by mbrija            #+#    #+#             */
/*   Updated: 2020/11/29 11:20:31 by mbrija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_header.h"

static char *ft_strjoin(char *s1, char *s2)
{
	int i;
	int j;
	int len1;
	int len2;

	i = 0;
	j = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
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

int 	senko_getchar()
{
	char buf[1];
    int n = read(0, buf, 1);

    if(n < 1)
        return -1;

    return buf[0];
}

char	*senko_tok(char *s, char *delm)
{
	char	*w;
	int		i;
	int		j;
	int 	k;

	w = malloc(sizeof(char*) * 1024);
	i = 0;
	k = 0;
	if (!s || !delm || s[i] == '\0')
		return NULL;
	while (s[i] != '\0')
	{
		j = 0;
		while (delm[j] != '\0')
		{
			if (s[i] != delm[j])
				w[k] = s[i];
			else
			{
				w[i] = 0;
				return w;
				i++;
				
			}
			j++;
		}
		i++;
		k++;
		
	}
	return w;
}

int num_builtin_coms()
{
	return sizeof(builtin_str) / sizeof(char *);
}

int ft_strcmp(const char *s1, const char *s2)
{
	int i;

	i = -1;
	while (++i < ft_strlen(s1))
		if (((unsigned char)s1[i] - (unsigned char)s2[i]) != 0
				|| s1[i] == 0 || s2[i] == 0)
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}