#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

#define COLOR_YELLOW "\033[1;33m"

#define BACKGROUND_EXECUTION 0
#define FOREGROUND_EXECUTION 1
#define PIPELINE_EXECUTION 2

#define DELIMS "\t \r \n \a | ;"


typedef struct			s_process 
{
    char				*command;
    int 				argc;
    char 				**argv;
    char 				*input_path;
    char 				*output_path;
    pid_t 				pid;
    int 				type;
    int 				status;
    struct s_process	*next;
}						t_process;

typedef struct 			s_command
{
    char				*node;
    struct s_command	*next;
    
}               		t_command;

char **g_env;

static char *ft_strjoin(char *s1, char *s2);

int 	senko_getchar();

void	ft_putstr(char const *s);

int		ft_strlen(const char *s);

char	*ft_strdup(char *s);

char	*ft_strchr(char *s, char c);

int		ft_strncmp(const char *s1, const char *s2, size_t n);

char	*senko_tok(char *s, char *delm);

void	ft_lstadd_back(t_command **alst, t_command *new);

void	ft_lstclear(t_command **lst, void (*del)(void *));

t_command	*ft_lstnew(void *content);

void	initialise_envv(int ac, char **av, char **env);

void *def_not_calloc(size_t size);

void	ft_bzero(void *s, size_t n);

void	ft_freestrarr(char **arr);

#endif