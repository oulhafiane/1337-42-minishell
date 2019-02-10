/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoulhafi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 02:49:27 by zoulhafi          #+#    #+#             */
/*   Updated: 2018/11/11 17:34:56 by zoulhafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_lennbr(uintmax_t nbr, char flag9)
{
	int		count;

	if (nbr == 0 && flag9 == 1)
		return (0);
	count = 0;
	if (nbr / 10 == 0)
		count++;
	else
	{
		count += ft_lennbr(nbr / 10, 0);
		count++;
	}
	return (count);
}

static void		ft_putnbr_rec(uintmax_t nbr, char flag9)
{
	if (nbr == 0 && flag9 == 1)
		return ;
	if (nbr / 10 == 0)
		ft_putchar_pr(nbr + 48);
	else
	{
		ft_putnbr_rec(nbr / 10, 0);
		ft_putchar_pr((nbr % 10) + 48);
	}
}

void			ft_putnbr_u(uintmax_t nb, int flags[LEN])
{
	int len;

	len = ft_lennbr(nb, flags[9]);
	if (flags[1] != '-' && flags[5] > len && (flags[7] != '0' || flags[9] == 1))
		print_spaces(flags[5] - get_max(flags[6], len));
	else if (flags[7] == '0' && flags[1] != '-' && flags[6] == 0)
		print_zeroes(flags[5] - len);
	if (flags[6] != 0)
		print_zeroes(flags[6] - len);
	ft_putnbr_rec(nb, flags[9]);
	if (flags[1] == '-' && flags[5] > len)
		print_spaces(flags[5] - get_max(len, flags[6]));
}
