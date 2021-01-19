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
/* -- Parsers --*/
enum node_type_e
{
	NODE_COMMAND,
	NODE_VAR, /*Word*/
};

enum val_type_e
{
	VAL_SINT = 1, /*S int*/
	VAL_UINT,
	VAL_SLLONG,
	VAL_ULLONG,
	VAL_FLOAT,
	VAL_DOUBLE,
	VAL_CHR,
	VAL_STR,
};

union symval_u
{
	long               sint;
    unsigned long      uint;
    long long          sllong;
    unsigned long long ullong;
    double             sfloat;
    long double        ldouble;
    char               chr;
    char              *str;
};
typedef struct 			node_s
{
	enum node_type_e	type;
	enum val_type_e 	val_type;
	union symval_u 		val;
	int					children;
	struct node_s 		*fist_child;
	struct node_s 		*next_sibling;
}						node_t;


node_t	*parse_simple_command(token_t *tok);
node_t	*new_node(enum node_type_e type);
void	add_child_node(node_t *parent, node_t *child);
void	set_node_val_str(node_t *node, char *val);

/* the special EOF token, which indicates the end of input */
extern	token_t eof_token;
token_t *tokenize(struct source_s *src);
void	free_token(struct token_s *tok);

/* -- Token Functs --*/
token_t	*create_token(char *str);
void	add_to_buf(char c);
void	check_dilms(char nc, source_t *src);


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
void	free_token(token_t	*tok);
void	free_node_tree(node_t *node);

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