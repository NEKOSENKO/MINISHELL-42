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

int main(int ac, char **av, char **ev)
{
	char *line;
	char **coms;
	int ret;

	(void)ac;
	(void)av;

	while (1) //Read-Eval-Print-L
	{
		ft_putstr("\033[1;3;4;33;41m Union_of_Senko_Shell_Republicans \033[0m$> ");
		//read_line
		line = read_line();
		//parse_line (lexical scanning)
		
		//execute
		//freeehe
		free(line);
	}
	return (0);
}