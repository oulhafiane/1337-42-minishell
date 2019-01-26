/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoulhafi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 01:27:30 by zoulhafi          #+#    #+#             */
/*   Updated: 2019/01/23 13:25:13 by zoulhafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

void	minishell(t_list *lst, t_list **env)
{
	char	*cmd;
	char	**cmds;
	t_list	*bltin;

	while (ft_printf("$> ") > 0 && get_next_line(0, &cmd) == 1)
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
