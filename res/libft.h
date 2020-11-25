/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrija <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 10:30:00 by mbrija            #+#    #+#             */
/*   Updated: 2019/10/10 10:30:05 by mbrija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include "../s_header.h"


size_t				ft_strlen(const char *str);

int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strdup(const char *s);

char				*ft_strnstr(const char *haystack, const char *needle, size_t len);

char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putnbr(int n);

char				*ft_strtrim(char const *s1, char const	*set);

char				*ft_strjoin(char const *s1, char const *s2);

int					get_next_line(char **line);
char				**ft_split(char const *s, char c);
char				*ft_substr(char const *s, unsigned int start, size_t len);


#endif
