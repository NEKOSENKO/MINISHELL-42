#include "shell.h"

char 	*g_tok_buf = NULL; //* to current tok buf
int		g_tok_bufsize = 0;
int		g_tok_bufindex = -1;

/* special token to indicate end of input */
struct token_s eof_token =
{
	.text_len = 0,
};

void	add_to_buf(char c)
{
	char *tmp;

	g_tok_buf[g_tok_bufindex++] = c;
	if (g_tok_bufindex >= g_tok_bufsize)
	{
		tmp = realloc(g_tok_buf, g_tok_bufsize * 2); //re use realloc to senko_realloc
		if (!tmp)
		{
			errno = ENOMEM;
			return;
		}
		g_tok_buf = tmp;
		g_tok_bufsize *= 2;
	}
}

token_t	*create_token(char *str)
{
	token_t	*tok;
	char	*nstr;

	tok = malloc(sizeof(token_t));
	if (!tok)
		return NULL;
	memset(tok, 0, sizeof(token_t)); // re use ft_memset
	tok->text_len = ft_strlen(str);
	nstr = malloc(tok->text_len + 1);
	if (!nstr)
	{
		free(tok);
		return NULL;
	}
	strcpy(nstr, str); //re use ft_strcpy
	tok->text = nstr;
	return tok;
}

token_t	*tokenize(source_t *src)
{
	char nc;
	token_t *tok;

	if (!src || !src->buffer || !src->bufsize)
	{
		errno = ENODATA;
		return &eof_token;
	}
	if(!g_tok_buf)
	{
		g_tok_bufsize = 1024;
		g_tok_buf = malloc(g_tok_bufsize);
		if (!g_tok_buf)
		{
			errno = ENOMEM;
			return &eof_token;
		}
	}
	g_tok_bufindex = 0;
	g_tok_buf[0] = '\0';
	nc = next_char(src);
	if(nc == ERRCHAR || nc == EOF)
		return &eof_token;
	check_dilms(nc, src);
	if (g_tok_bufindex == 0)
		return &eof_token;
	if(g_tok_bufindex >= g_tok_bufsize)
		g_tok_bufindex--;
	g_tok_buf[g_tok_bufindex] = '\0';
	tok = create_token(g_tok_buf);
	if(!tok)
	{
		ft_putstr("Error : failed to Alloacate Buffer");
		return &eof_token;
	}
	tok->src = src;
	return tok;
}

void	check_dilms(char nc, source_t *src)
{
	int endloop;

	endloop = 0;
	while ((nc = next_char(src)) != EOF)
	{
		if(nc == '\t' || nc == ' ')
		{
			if(g_tok_bufindex > 0)
				endloop = 1;
			break;
		}
		if(nc == '\n')
		{
			if (g_tok_bufindex > 0)
				unget_char(src);
			else
				add_to_buf(nc);
			endloop = 1;
			break;
		}
		else
		{
			add_to_buf(nc);
			break;
		}
		
		if(endloop)
			break;
	}
}