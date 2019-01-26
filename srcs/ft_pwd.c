/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoulhafi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 15:52:28 by zoulhafi          #+#    #+#             */
/*   Updated: 2019/01/22 17:48:31 by zoulhafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_pwd(char **args, t_list **lst)
{
	t_list		*cpy;
	t_env		*env;
	char		**path;
	char		**args_to_exec;

	(void)args;
	cpy = *lst;
	while (cpy)
	{
		env = (t_env*)cpy->content;
		if (ft_strcmp(env->name, "PWD") == 0)
		{
			ft_printf("%s\n", env->value);
			return ;
		}
		cpy = cpy->next;
	}
	path = ft_strsplit(get_env_value("PATH", *lst), ':');
	args_to_exec = ft_strsplit("pwd", ' ');
	exec_cmd(args_to_exec, path, lst);
	ft_free_strtab(args_to_exec);
}
