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

void	free_exec_cmd(char *error, char *full_path, char **head_path)
{
	free(error);
	free(full_path);
	ft_free_strtab(head_path);
}

void	free_elem_env(t_list *elem)
{
	t_env	*env;

	env = (t_env*)elem->content;
	free(env->name);
	free(env->value);
	free(env);
	free(elem);
}
