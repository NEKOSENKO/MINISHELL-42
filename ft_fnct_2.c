#include "shell.h"


static char *ft_strjoin(char *s1, char *s2)
{
	int i;
	int j;
	int len1;
	int len2;

	i = 0;
	j = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	char *p = malloc (len1 + len2 + 1);
	while (i < len1 + len2)
	{
		if (i < len1)
			p[i] = s1[i];
		else
			p[i] = s2[j++];
		i++;
	}
	p[i] = 0;
	return (p);
}

int 	senko_getchar()
{
	char buf[1];
    int n = read(0, buf, 1);

    if(n < 1)
        return -1;

    return buf[0];
}


char	*senko_tok(char *s, char *delm)
{
	char	*w;
	int		i;
	int		j;
	int 	k;

	w = malloc(sizeof(char*) * 1024);
	i = 0;
	k = 0;
	if (!s || !delm || s[i] == '\0')
		return NULL;
	while (s[i] != '\0')
	{
		j = 0;
		while (delm[j] != '\0')
		{
			if (s[i] != delm[j])
				w[k] = s[i];
			else
			{
				w[i] = 0;
				return w;
				i++;
				
			}
			j++;
		}
		i++;
		k++;
		
	}
	return w;
}

void	ft_lstadd_back(t_command **alst, t_command *new)
{
	t_command	*last;

	if (!new)
		return ;
	last = *alst;
	new->next = NULL;
	if ((*alst) == NULL)
		(*alst) = new;
	else
	{
		while (last->next != NULL)
			last = last->next;
		last->next = new;
	}
}

void	ft_lstclear(t_command **lst, void (*del)(void *))
{
	t_command	*next_node;
	t_command	*current;

	if (lst && del)
	{
		next_node = (*lst);
		current = (*lst);
		while (next_node != NULL)
		{
			current = next_node;
			next_node = next_node->next;
			(*del)(current->node);
			free(current);
		}
		*lst = NULL;
	}
}

t_command	*ft_lstnew(void *content)
{
	t_command	*head;

	head = (t_command*)malloc(sizeof(t_command));
	if (head == 0)
		return (NULL);
	head->node = content;
	head->next = NULL;
	return (head);
}