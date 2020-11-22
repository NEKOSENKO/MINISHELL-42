/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrija <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 12:24:11 by mbrija            #+#    #+#             */
/*   Updated: 2020/11/22 12:24:21 by mbrija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "s_header.h"

void minishell_loop()
{
	char	*line;
	char	**args;
	int status;

	status = 1;
	while (status)
	{
		ft_putstr("Senko~> ");
		//read
		//split
		//exec
		//free
	}
}

int main (int argc, char **argv)
{
	minishell_loop();
	return (0);
}