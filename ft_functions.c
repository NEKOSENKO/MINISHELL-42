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

void	ft_putstr(char const *s)
{
	if (!s)
		return ;
	write(0, s, ft_strlen(s));
}

int		ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s)
{
	int		i;
	int		len;
	char	*p;

	i = 0;
	len = ft_strlen(s);
	p = malloc(len + 1);
	while (s[i])
	{
		p[i] = s[i];
		i++;
	}
	p[i] = 0;
	return (p);
}

char	*ft_strchr(char *s, char c)
{
	int i;

	i = 0;
	while (s[i++])
		if (s[i] == c)
		{
			return (s + i);
		}
	return (0);
}

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int i;

	i = -1;
	while ((size_t)++i < n)
		if (((unsigned char)s1[i] - (unsigned char)s2[i]) != 0
				|| s1[i] == 0 || s2[i] == 0)
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}
