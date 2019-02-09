/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoulhafi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 01:27:30 by zoulhafi          #+#    #+#             */
/*   Updated: 2019/01/26 17:39:29 by zoulhafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	The Fork Function
**	it creates a copy (child process) of the current process (parent process)
**	man fork -> for more info.
**	after that there will be two processes one is parent and the other is child
**	the child executes the cmds with the environment given on the parameters
**	the parent waits the child to finish
*/

void	forkit(char *full_path, char **cmds, t_list **env)
{
	int		status;
	pid_t	father;
	char	**env_tab;

	env_tab = env_to_tab(*env);
	father = fork();
	if (father > 0)
	{
		wait(&status);
		ft_free_strtab(env_tab);
	}
	else if (father == 0)
		execve(full_path, cmds, env_tab);
}

/*
**	the command given need to be executed without searching in $PATH
**	because it's have with it the path like : /bin/ls
**	the function check if it's exist and it's permission to execute is OK
**	then sends it to forkit function 
**	otherwise, it prints an error msg.
*/

void	exec_local(char **cmds, t_list **env)
{
	if (access(*cmds, F_OK) == 0)
	{
		if (access(*cmds, X_OK) == 0)
			forkit(*cmds, cmds, env);
		else
			ft_printf_fd(2, "%s: Permission denied.\n", *cmds);
	}
	else
		ft_printf_fd(2, "%s: Command not found.\n", *cmds);
}

/*
**	the command given to be search in all paths stored in environment variable $PATH
**	then if it's exist it checks it's permission to execute
**	then sends it to forkit function
**	otherwise, it prints an error msg.
*/

void	exec_cmd(char **cmds, char **path, t_list **env)
{
	char	*full_path;
	char	*error;
	char	**head_path;

	error = NULL;
	head_path = path;
	if (*cmds != NULL)
	{
		while (*path)
		{
			full_path = ft_strjoin_pre(*path, "/", *cmds);
			if (access(full_path, F_OK) == 0 && access(full_path, X_OK) == 0)
			{
				forkit(full_path, cmds, env);
				free_exec_cmd(error, full_path, head_path);
				return ;
			}
			else if (error != NULL && access(full_path, F_OK) == 0)
				error = ft_strjoin(full_path, ": Permission denied.\n");
			path++;
			free(full_path);
		}
		print_error(error, *cmds);
	}
	ft_free_strtab(head_path);
}

/*
**	The loop function of minishell
**	it prints the minishell msg : My_Minishell $>
**	and reads from the input standard the command
**	and check it which type is it : exit, builtins, Cmd with path, Cmd Without Path
**	and sends the list of agruments to appropriate function.
**	
**	Notes : (libft functions)
**	get_next_line  : reads a line from the standard input.
**	ft_strsplit_ws : splits a line to a multiple words by whitespace delimiters
**			 returns a char** and last pointer is NULL.
**	free_strtab    : frees all strings (char**) returned by ft_strsplit_ws. 
*/

void	minishell(t_list *lst, t_list **env)
{
	char	*cmd;
	char	**cmds;
	t_list	*bltin;

	while (ft_printf("\033[32;1mMy_Minishell $>\033[0m ") > 0 && get_next_line(0, &cmd) == 1)
	{
		if (fix_line(&cmd, *env) == 1)
		{
			cmds = ft_strsplit_ws(cmd);
			if (ft_strcmp(*cmds, "exit") == 0)
			{
				ft_free_strtab(cmds);
				free(cmd);
				break ;
			}
			else if ((bltin = ft_lstsearch(lst, *cmds, &check_builtin)) != NULL)
				((t_builtin*)bltin->content)->f(cmds + 1, env);
			else if (ft_strchr(*cmds, '/') != NULL)
				exec_local(cmds, env);
			else
				exec_cmd(cmds, get_path(*env), env);
			ft_free_strtab(cmds);
		}
		free(cmd);
	}
}

/*
**	The Main Function of Minishell
**	it initiates the builtins and environment lists,
**	after calls the loop function of minishell,
**	after frees all memory allocated on the heap
*/

int		main(int ac, char **av, char **ev)
{
	t_list		*env;
	t_list		*lst;

	(void)ac;
	(void)av;
	lst = NULL;
	env = NULL;
	init_env(&env, ev);
	init_builtin(&lst);
	minishell(lst, &env);
	free_gnl(0);
	free_env(env);
	free_builtin(lst);
	return (0);
}
