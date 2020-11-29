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