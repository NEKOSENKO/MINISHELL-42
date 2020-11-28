/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_header.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrija <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 12:23:59 by mbrija            #+#    #+#             */
/*   Updated: 2020/11/22 12:24:04 by mbrija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_HEADER_H
# define S_HEADER_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <errno.h>

# define SH_TOK_DELIM "\t \r \n \a"


//prototypes 
void	ft_putstr(char const *s);

int		ft_strlen(const char *s);

char	*ft_strdup(char *s);

char	*ft_strchr(char *s, char c);

void	free_buf(char *buffer);

char	*read_line();

char	**spilt_line(char *line);

void	minishell_loop();

#endif
