/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoulhafi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 03:02:24 by zoulhafi          #+#    #+#             */
/*   Updated: 2018/11/30 10:58:37 by zoulhafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstrev(t_list **begin_list)
{
	void	*tmp;
	void	*tmp2;
	void	*next;

	if (begin_list != NULL && begin_list[0] != NULL)
	{
		next = begin_list[0];
		tmp = NULL;
		while (begin_list[0]->next != NULL)
		{
			next = begin_list[0]->next;
			tmp2 = tmp;
			tmp = begin_list[0];
			begin_list[0]->next = tmp2;
			begin_list[0] = next;
		}
		begin_list[0]->next = tmp;
	}
}
