#include "shell.h"
/* this is here for norm shit 
void shell_loop(void)
{

}*/

char *read_line(void)
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

int	parse_and_exec(source_t *src)
{
	token_t *tok;
	node_t	*com;

	skip_white_spaces(src);
	tok = tokenize(src);
	if (tok == &eof_token)
		return 1;
	while (tok && tok != &eof_token)
	{
		com = parse_simple_command(tok);
		printf("  ~ N children : [%d]\n",com->children);
		printf("  ~ parsed : [%s]\n",com->fist_child->val.str);
		if(!com)
			break;
		//exec
		//free_node_tree(com);
		tok = tokenize(src);
	}
	return 1;
}

int main(int ac, char **av, char **ev)
{
//	char *line;
	char *com;
//	int ret;
	source_t src;

	(void)ac;
	(void)av;
	(void)ev;

	while (1) //Read-Eval-Print-L
	{
		ft_putstr("\033[1;3;4;33;41m Union_of_Senko_Shell_Republicans \033[0m$> ");
		com = read_line();
		src.buffer = com;
		src.bufsize = ft_strlen(com);
		src.curpos = INIT_SRC_POS;
		printf("  ~ initial buffer : > %s\n", src.buffer);
		parse_and_exec(&src);
	}
	return (0);
}