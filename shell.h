#ifndef __SHELL_H
#define __SHELL_H

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>

/* -- Parse Defs -- */
#define W_DELIM "\t \r \n \a"
#define EOF             (-1)
#define ERRCHAR         ( 0)
#define INIT_SRC_POS    (-2)

typedef struct 	source_s
{   
	char *buffer;       /* the input text */
	long bufsize;       /* size of the input text */ 
	long  curpos;       /* absolute char position in source */
}				source_t;

/* -- Scanner --*/
typedef struct  token_s
{
	struct source_s *src;       /* source of input */
	int    text_len;            /* length of token text */
	char   *text;               /* token text */
}               token_t;

/* the special EOF token, which indicates the end of input */
extern	token_t eof_token;
token_t *tokenize(struct source_s *src);
void	free_token(struct token_s *tok);
/*----------------*/


/* -- Parse Functs --*/
char	next_char(source_t *src);
void	unget_char(source_t *src);
char	peek_char(source_t *src);
void	skip_white_spaces(source_t *src);
char	*read_line(void);
/*-------------------*/



/* uwu SENKO__FT_LIB uwu*/
/* -- Free -- */
void	buf_free(char *buffer);

/*-- Lib Functions --*/
int 	senko_getchar(void);
void	ft_putstr(char const *s);
int		ft_strlen(const char *s);
char	*ft_strdup(char *s);
char	*ft_strchr(char *s, char c);
char	*ft_strjoin(char *s1, char *s2);
/*----------------------*/

/* USSR Communists all rights reserved */
#endif