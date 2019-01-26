/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoulhafi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 11:26:41 by zoulhafi          #+#    #+#             */
/*   Updated: 2019/01/12 00:17:27 by zoulhafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_builtin(t_list **lst, char *cmd, void (*f)())
{
	t_builtin	*elem;

	elem = (t_builtin*)malloc(sizeof(t_builtin));
	elem->cmd = (char*)malloc(sizeof(char) * (ft_strlen(cmd) + 1));
	ft_strcpy(elem->cmd, cmd);
	elem->f = f;
	ft_lstadd(lst, ft_lstnew(elem, 0));
}

void	init_builtin(t_list **lst)
{
	add_builtin(lst, "echo", &ft_echo);
	add_builtin(lst, "cd", &ft_cd);
	add_builtin(lst, "env", &ft_env);
	add_builtin(lst, "pwd", &ft_pwd);
	add_builtin(lst, "setenv", &ft_setenv);
	add_builtin(lst, "unsetenv", &ft_unsetenv);
}

int		check_builtin(t_list *elem, void *obj)
{
	if (ft_strcmp(((t_builtin*)elem->content)->cmd, (char*)obj) == 0)
		return (1);
	else
		return (0);
}

void	free_builtin(t_list *lst)
{
	t_list		*previous;

	while (lst)
	{
		free(((t_builtin*)lst->content)->cmd);
		free((t_builtin*)lst->content);
		previous = lst;
		lst = lst->next;
		free(previous);
	}
}
