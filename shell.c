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
		if (c == EOF || c == '\n')
		{
			buffer[pos] = '\0';
			return buffer;
		}
		else 
			buffer[pos] = c;
			//printf("%c", buffer[pos]);
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

char	**spilt_line(char *line)
{
	int		buffsize;
	int		pos;
	char 	**tokens;
	char	*token;

	buffsize = 1024;
	pos = 0;
	tokens = malloc(sizeof(char *) * buffsize);

	if (!tokens)
	{
		ft_putstr("Allocation Error");
		free(tokens);
		exit(1);
	}
		/*to do :
		
			tokenise to token[] ! use split ?
			loop if token, and fill -> **tokens 
			....
		*/
	token = senko_tok(line, SH_TOK_DELIM); //ft_split doesn't work here, so i made a better one .
	while (token != NULL)
	{
		tokens[pos] = token;
		pos++;
		if (pos >= buffsize)
		{
			buffsize += 1024;
			tokens = malloc(sizeof(char *) * buffsize);
			if (!tokens)
			{
				ft_putstr("Allocation Error");
				free(tokens);
				exit(1);
			}
		}
		token = senko_tok(NULL, SH_TOK_DELIM); // .................... !	
	}
	tokens[pos] = NULL;
	return tokens;

} 

int	shell_exec(char **args)
{
	int i;

	i = 0;
	if (args[0] == NULL)
		return 1;
	while (i < num_builtin_coms())
	{
		if (ft_strcmp(args[0], builtin_str[i] == 0))
			return (*builtin_func[i](args));
	}
	return (shell_launch(args));
}

int	shell_launch(char **args)
{
	
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
		status = shell_exec(args); //execution

		free(line);
		free(args); //free
	}
}

int main (int argc, char **argv)
{
	minishell_loop();
	return (0);
}