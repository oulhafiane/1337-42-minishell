/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsearch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoulhafi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 12:57:31 by zoulhafi          #+#    #+#             */
/*   Updated: 2019/01/08 17:51:29 by zoulhafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstsearch(t_list *lst, void *obj, int (*f)())
{
	if (lst == NULL || obj == NULL || f == NULL)
		return (NULL);
	while (lst)
	{
		if (f(lst, obj) == 1)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}
