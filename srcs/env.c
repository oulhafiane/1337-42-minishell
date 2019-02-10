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

/*
**	this function get the element called PATH 
**	from the list that contains t_env elements
**	and split it with the delimited :
**	to get an array of strings containing all paths.
*/

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

/*
**	called from init_env, and other functions from ft_cd.c and ft_env.c,
**	it create a new element of struct t_env and fill it,
**	and call ft_lstadd libft function to add this element to the list
**	the variable end, it have a boolean value 0 or 1
**	that needed to check to add the element at the end of list or the beginning.
*/

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

/*
**	function that initiates the environment variables
**	it create a t_list from the **env (a copy of it)
*/

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

/*
**	called from forkit function,
**	needed to convert the list of t_env elements
**	to an array of strings, to send it with the execve function.
**	and this function add a NULL pointer at the end of the array,
**	this array can be freed with the call of ft_free_strtab libft function.
*/

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

/*
**	it frees all memory allocated in the heap created by add_env
**	and frees the t_list element.
*/

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
