/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorttab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoulhafi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 06:26:10 by zoulhafi          #+#    #+#             */
/*   Updated: 2018/11/22 19:54:36 by zoulhafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sorttab(void **tab, int len, int (*cmp)())
{
	int		i;
	int		edited;
	char	*tmp;

	edited = 1;
	while (edited == 1)
	{
		edited = 0;
		i = 1;
		while (i < len)
		{
			if (cmp(tab[i - 1], tab[i]) > 0)
			{
				tmp = tab[i - 1];
				tab[i - 1] = tab[i];
				tab[i] = tmp;
				edited = 1;
			}
			i++;
		}
	}
}
