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

char *read_line()
{
	int		buff_size;
	int		pos;
	char 	*buffer;
	int		c;

	buff_size	= 1024;
	pos			= 0;
	*buffer		= malloc(sizeof(char) * buff_size);

	if (!buffer)
	{
		ft_putstr("Allocation Error");
		free(buffer);
		exit(1);
	}

	while (1)
	{
		c = getchar(); //this must be edited for later, function not allowed
		if (c == -1 || c == '\n')
		{
			buffer[pos] = '\0';
			return buffer;
		}
		else 
			buffer[pos] = c;
		pos++;

		if (pos >= buff_size)
		{
			buff_size += 1024;
			*buffer	= malloc(sizeof(char) * buff_size);
			if (!buffer)
			{
				ft_putstr("Allocation Error");
				free(buffer);
				exit(1);
			}
		}
	}

}

char	**spilt_line(char *line)
{
	int		buffsize;
	int		pos;
	char 	**tokens;
	char	*token;

	buffsize = 1024;
	pos = 0;
	**tokens = malloc(sizeof(char *) * buffsize);

	if (!tokens)
	{
		ft_putstr("Allocation Error");
		free(tokens);
		exit(1);
	}
	//to do :
	/*
		tokenise to token ! use split ?
		loop if token, and fill them to **tokens 
		....
	*/

}

void minishell_loop()
{
	char	*line;
	char	**args;
	int status;

	status = 1;
	while (status)
	{
		ft_putstr("Senko~> ");
		line = read_line(); //read
		args = spilt_line(line); //split
		//exec
		//free
	}
}

int main (int argc, char **argv)
{
	minishell_loop();
	return (0);
}