#include "shell.h"

node_t	*new_node(enum node_type_e type)
{
	node_t *node;
	node = malloc(sizeof(node_t));

	if(!node)
		return NULL;
	memset(node, 0, sizeof(node_t)); //re use ft_memset
	node->type = type;
	return node;
}

void	add_child_node(node_t *parent, node_t *child)
{
	node_t *sibling;
	
	if(!parent || !child)
		return;
	if(!parent->fist_child)
		parent->fist_child = child;
	else
	{
		sibling = parent->fist_child;
		while(sibling->next_sibling)
			sibling = sibling->next_sibling;
		sibling->next_sibling = child;
		child->fist_child = sibling;
	}
	parent->children++;
	
}

void	set_node_val_str(node_t *node, char *val)
{
	char	*val2;
	
	node->val_type = VAL_STR;
	if(!val)
		node->val.str = NULL;
	else
	{
		val2 = malloc(ft_strlen(val) + 1);
		if(!val2)
			node->val.str = NULL;
		else
		{
			strcpy(val2, val); // re use ft_strcpy
			node->val.str = val2;
		}
	}
}

node_t	*parse_simple_command(token_t *tok)
{
	node_t		*cmd;
	source_t	*src;
	node_t		*word;
	
	if (!tok)
		return NULL;
	cmd = new_node(NODE_COMMAND);
	if(!cmd)
	{
		free_token(tok);
		return NULL;
	}
	src = tok->src;
	while ((tok = tokenize(src) != &eof_token))
	{
		if(tok->text[0] == '\n')
		{
			free_token(tok);
			break;
		}
		word = new_node(NODE_VAR);
		if(!word)
		{
			free_node_tree(cmd);
			free_token(tok);
			return NULL;
		}
		set_node_val_str(word, tok->text);
		add_child_node(cmd, word);
		free_token(tok);
	}
	return cmd;
}