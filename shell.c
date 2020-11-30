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


void free_buf(char *buffer)
{
	ft_putstr("Allocation Error");
	free(buffer);
	exit(1);
}

int 	senko_getchar()
{
	char buf[1];
    int n = read(0, buf, 1);

    if(n < 1)
        return -1;

    return buf[0];
}

char *read_line()
{
	int		buff_size;
	int		pos;
	char 	*buffer;
	int		c;

	buff_size	= 1024;
	pos			= 0;
	buffer		= malloc(sizeof(char) * buff_size);

	if (!buffer)
		free_buf(buffer);
		
	while (1)
	{
		c = senko_getchar();
		//this must be edited for later, function not allowed

		if (c == EOF || c == '\n')
		{
			buffer[pos] = '\0';
			return buffer;
		}
		else 
			buffer[pos] = c;
			printf("%c", buffer[pos]);
		pos++;

		if (pos >= buff_size)
		{
			buff_size += 1024;
			buffer	= malloc(sizeof(char) * buff_size);
			if (!buffer)
				free_buf(buffer);
		}
	}
	return buffer;
}
/*
char	**spilt_line(char *line)
{
	int		buffsize;
	int		pos;
	char 	**tokens;
	char	*token;

	buffsize = 1024;
	pos = 0;
	*tokens = malloc(sizeof(char *) * buffsize);

	if (!tokens)
	{
		ft_putstr("Allocation Error");
		free(tokens);
		exit(1);
	}
	//to do :
	
		tokenise to token[] ! use split ?
		loop if token, and fill -> **tokens 
		....
	

} 
*/

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
		//args = spilt_line(line); //split
		//exec
		//free
	}
}

int main (int argc, char **argv)
{
	minishell_loop();
	return (0);
}