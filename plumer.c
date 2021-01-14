#include "shell.h"

void	buf_free(char *buffer)
{
	ft_putstr("USSR : Allocation Error!");
	free(buffer);
	exit(1);
}

void	free_token(token_t	*tok)
{
	if(tok->text)
		free(tok->text);
	free(tok);
}

void	free_node_tree(node_t *node)
{
	node_t *child;
	node_t *next;
	
	if(!node)
		return;
	child = node->fist_child;
	while(child)
	{
		next = child->next_sibling;
		free_node_tree(child);
		child = next;
	}
	if(node->val_type == VAL_STR)
	{
		if(node->val.str)
			free(node->val.str);
	}
	free(node);
}