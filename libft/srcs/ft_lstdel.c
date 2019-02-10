/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoulhafi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 02:47:00 by zoulhafi          #+#    #+#             */
/*   Updated: 2018/10/09 21:32:49 by zoulhafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*cpy;
	t_list	*next;

	if (alst == NULL || *alst == NULL || del == NULL)
		return ;
	cpy = *alst;
	while (cpy->next != NULL)
	{
		next = cpy->next;
		(*del)(cpy->content, cpy->content_size);
		free(cpy);
		cpy = next;
	}
	(*del)(cpy->content, cpy->content_size);
	free(cpy);
	*alst = NULL;
}
