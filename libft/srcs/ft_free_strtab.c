/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_strtab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoulhafi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 17:38:42 by zoulhafi          #+#    #+#             */
/*   Updated: 2019/01/22 17:43:41 by zoulhafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_strtab(char **tab)
{
	char	**head;

	if (tab == NULL)
		return ;
	head = tab;
	while (*tab)
	{
		free(*tab);
		tab++;
	}
	free(head);
}
