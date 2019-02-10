/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoulhafi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 15:12:12 by zoulhafi          #+#    #+#             */
/*   Updated: 2019/01/23 13:24:19 by zoulhafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	this function called from exec_cmd,
**	if the file not found or it's permission is denied,
**	this function if the string error not null, the function prints
**	the string error, otherwise it prints a msg Command not found...
*/

void	print_error(char *error, char *cmd)
{
	if (error != NULL)
	{
		ft_printf_fd(2, "%s\n", error);
		free(error);
	}
	else
		ft_printf_fd(2, "%s: Command not found.\n", cmd);
}
