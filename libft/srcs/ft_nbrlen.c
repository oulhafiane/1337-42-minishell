/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoulhafi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 18:22:59 by zoulhafi          #+#    #+#             */
/*   Updated: 2018/11/30 10:58:21 by zoulhafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_nbrlen(int n)
{
	int		count;
	int		extra;
	int		mult;

	mult = 1;
	if (n < 0)
		extra = 2;
	else
		extra = 1;
	count = 0;
	while (n / 10 != 0)
	{
		n = n / 10;
		mult = mult * 10;
		count++;
	}
	return (count + extra);
}
