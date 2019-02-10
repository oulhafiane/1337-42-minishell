/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoulhafi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 03:11:00 by zoulhafi          #+#    #+#             */
/*   Updated: 2018/10/09 21:33:45 by zoulhafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_list;
	t_list	*begin;
	t_list	*tmp;

	new_list = (t_list*)malloc(sizeof(t_list));
	begin = new_list;
	if (lst == NULL || new_list == NULL || f == NULL)
		return (NULL);
	while (lst->next != NULL)
	{
		tmp = (*f)(lst);
		new_list->content = ft_strdup(tmp->content);
		new_list->content_size = tmp->content_size;
		new_list->next = (t_list*)malloc(sizeof(t_list));
		new_list = new_list->next;
		lst = lst->next;
	}
	tmp = (*f)(lst);
	new_list->content = ft_strdup(tmp->content);
	new_list->content_size = tmp->content_size;
	new_list->next = NULL;
	return (begin);
}
