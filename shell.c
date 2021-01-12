#include "shell.h"

char* read_line()
{
	int buff_size;
	int pos;
	int c;
	char *buffer;

	buff_size = 1024;
	pos = 0;
	buffer = malloc(sizeof(char) * buff_size);

	//protection 

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
		pos++;
		if (pos >= buff_size)
		{
			buff_size += 1024;
			buffer = malloc(sizeof(char) * buff_size);
			//protection
		}
	}

	return buffer;
}


t_command *parse_line(char *line)
{
	int pos = 0;
	t_command *tok;
	char *token;

	token = senko_tok(line, DELIMS);
	tok = ft_lstnew(token);
	while(token != NULL)
	{
		ft_lstadd_back(tok, ft_lstnew(token[pos]));
		pos++;
	}
	return tok;
}

int main(int argc, char **argv, char **env)
{
	char 	*line;
	char	**commands;
	int 	ret;

	initialise_envv(argc, argv, env);

	while(1)
	{     
		ft_putstr("\033[1;3;4;33;41m UNION_of_SENKO_SHELL_REPUBLICANS \033[0m$> ");
		
			// PARSE COMMAND HERE ..

			// LAUNCH IT HERE ..
			//printf("%s\n",g_line);

		//free(g_line);
		//free(args);
	}
	return 0;
}


/* ------------ DRAFTS -------------

char **split_line(char *line)
{
	int buff_size;
	int pos;
	char **tokens;
	char *token;

	buff_size = 1024;
	pos = 0;
	tokens = malloc(sizeof(char *) * buff_size);


	if (!tokens)
	{
		ft_putstr("ERROR");
		free(tokens);
		exit(1);	
	}

	//protection
	token = senko_tok(line, DELIMS);
	while (token != NULL)
	{
		tokens[pos] = token;
		pos++;
		if (pos >= buff_size)
		{
			buff_size += 1024;
			tokens = malloc(sizeof(char *) * buff_size);
				if (!tokens)
				{
					ft_putstr("ERROR");
					free(tokens);
					exit(1);	
				}
		}
		token = senko_tok(NULL, DELIMS);
	}
	
	tokens[pos] = NULL;
	return tokens;
}

t_job *parse_command(char *line)
{
	t_process *root_proc;
	t_process *proc;		
	char *command;
	char *line_cursor;
	char *c;
	char *seg;
	int seg_len;
	int mode;
 
	line = trim_line(line);
	command = ft_strdup(line);
	root_proc = NULL;
	proc = NULL;
	line_cursor = line;
	c = line;
	seg_len = 0;
	mode = FOREGROUND_EXECUTION;

	if (line[ft_strlen(line) - 1] == '&')
	{
		mode = BACKGROUND_EXECUTION;
		line[ft_strlen(line) - 1] = '\0';
	}
	while (1)
	{
		if (*c == '\0' || *c == '|')
			seg = (char *) malloc((seg_len + 1) * sizeof(char));
			strncpy(seg, line_cursor, seg_len);

			t_process *new_proc;
	}
	
	

	return 0;
}
*/