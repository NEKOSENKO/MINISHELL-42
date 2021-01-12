#include "shell.h"

void	exit_shell()
{

	write(1, "\n", 1);
	exit(0);
}

static int env_len(char **env)
{
	int i;
	int	cnt;

	i = -1;
	cnt = 0;
	while(env[++i])
		cnt++;
	return cnt;
}

void	initialise_envv(int ac, char **av, char **env)
{
	int i;
	(void)ac;
	(void)av;

	g_env = (char **)def_not_calloc(sizeof(char *) * (env_len(env) + 1));
	i = -1;
	while (env[++i])
	{
		if(!(g_env[i] = ft_strdup(env[i])))
			exit_shell();
	}
	
}
