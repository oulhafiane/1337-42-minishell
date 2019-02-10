/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoulhafi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 14:49:45 by zoulhafi          #+#    #+#             */
/*   Updated: 2019/01/23 13:25:37 by zoulhafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	called from exec_cmd,
**	it needed just because of the norm of 42,
**	there is no more line left in the exec_cmd
**	it frees the 3 elements given as parametes.
*/

void	free_exec_cmd(char *error, char *full_path, char **head_path)
{
	free(error);
	free(full_path);
	ft_free_strtab(head_path);
}

/*
**	called from ft_unsetenv,
**	it frees all memory allocated by the element t_env and t_list.
*/

void	free_elem_env(t_list *elem)
{
	t_env	*env;

	env = (t_env*)elem->content;
	free(env->name);
	free(env->value);
	free(env);
	free(elem);
}
