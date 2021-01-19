#include "shell.h"

int 	senko_getchar(void)
{
	char	buf[1];
    int		n; 
	
	n = read(0, buf, 1);

    if(n < 1)
        return (-1);

    return (buf[0]);
}

void    unget_char(source_t *src)
{
    if (src->curpos < 0)
        return;
    src->curpos--;
}

char    next_char(source_t *src)
{
    char c1;

    c1 = 0;
    if(!src || !src->buffer)
    {
        errno = ENODATA;
        return ERRCHAR;
    }
    if(src->curpos == INIT_SRC_POS)
        src->curpos = -1;
    else
        c1 = src->buffer[src->curpos];
    if(++src->curpos >= src->bufsize)
        return EOF;
    printf("  ~ NEXT CHAR FUNC %c\n", src->buffer[src->curpos]) ;
    return src->buffer[src->curpos];
}

char    peek_char(source_t *src)
{
    long pos;

    if(!src || !src->buffer)
    {
        errno = ENODATA;
        return ERRCHAR;
    }
    pos = src->curpos;
    if (pos == INIT_SRC_POS)
        pos++;
    pos++;
    if(pos >= src->bufsize)
        return EOF;
    return src->buffer[pos];
}

void    skip_white_spaces(source_t *src)
{
    char c;
    if(!src || !src->buffer)
        return;
    while(((c = peek_char(src)) != EOF) && (c == ' ' || c == '\t'))
        next_char(src);
        //printf("  ~ SKIPED %c\n", c) ;
}