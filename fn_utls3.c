#include "shell.h"

char 	*g_tok_buf = NULL;
int		g_tok_bufsize = 0;
int		g_tok_bufindex = -1;

/* special token to indicate end of input */
struct token_s eof_token =
{
	.text_len = 0,
};

void	add_to_buf(char c)
{
	
}