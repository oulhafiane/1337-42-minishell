/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoulhafi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 14:07:31 by zoulhafi          #+#    #+#             */
/*   Updated: 2019/01/22 17:48:54 by zoulhafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**get_path(t_list *env)
{
	t_env	*tmp;

	while (env)
	{
		tmp = (t_env*)env->content;
		if (ft_strcmp(tmp->name, "PATH") == 0)
			return (ft_strsplit(tmp->value, ':'));
		env = env->next;
	}
	return (ft_strsplit("", ';'));
}

void	add_env(t_list **lst, char *name, char *value, int end)
{
	t_env	*elem;

	elem = (t_env*)malloc(sizeof(t_env));
	elem->name = ft_strdup(name);
	elem->value = ft_strdup(value);
	if (end == 0)
		ft_lstadd(lst, ft_lstnew(elem, 0));
	else
		ft_lstadd_end(lst, ft_lstnew(elem, 0));
}

void	init_env(t_list **lst, char **env)
{
	char	**cpy_env;
	char	**tmp;

	cpy_env = env;
	while (*cpy_env)
	{
		tmp = ft_strsplit(*cpy_env, '=');
		add_env(lst, tmp[0], tmp[1], 0);
		ft_free_strtab(tmp);
		cpy_env++;
	}
}

char	**env_to_tab(t_list *lst)
{
	char	**env;
	t_env	*tmp;
	int		i;

	env = (char**)malloc(sizeof(char*) * (ft_lstlen(lst) + 1));
	i = 0;
	while (lst)
	{
		tmp = (t_env*)lst->content;
		env[i++] = ft_strjoin_pre(tmp->name, "=", tmp->value);
		lst = lst->next;
	}
	env[i] = NULL;
	return (env);
}

void	free_env(t_list *lst)
{
	t_list	*previous;

	while (lst)
	{
		free(((t_env*)lst->content)->name);
		free(((t_env*)lst->content)->value);
		free((t_env*)lst->content);
		previous = lst;
		lst = lst->next;
		free(previous);
	}
}
