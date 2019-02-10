/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoulhafi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 02:49:27 by zoulhafi          #+#    #+#             */
/*   Updated: 2018/11/30 10:59:12 by zoulhafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_lennbr(intmax_t nb)
{
	long	nbr;
	int		count;

	count = 0;
	nbr = (long)nb;
	if (nbr < 0)
		nbr = nbr * -1;
	if (nbr / 10 == 0)
		count++;
	else
	{
		count += ft_lennbr(nbr / 10);
		count++;
	}
	return (count);
}

static void	print_sub(intmax_t nb, char flag)
{
	if (nb < 0)
		ft_putchar_pr('-');
	else if (flag == '+')
		ft_putchar_pr('+');
}

static void	ft_putnbr_rec_pr(intmax_t nb)
{
	uintmax_t	nbr;

	nbr = nb;
	if (nb < 0)
		nbr = nb * -1;
	if (nbr / 10 == 0)
		ft_putchar_pr(nbr + 48);
	else
	{
		ft_putnbr_rec_pr(nbr / 10);
		ft_putchar_pr((nbr % 10) + 48);
	}
}

void		ft_putnbr_pr(intmax_t nb, int fl[LEN])
{
	int len;

	len = ft_lennbr(nb) + (fl[2] == '+' || nb < 0 || fl[3] == ' ');
	if (fl[3] == ' ' && nb >= 0 && fl[2] != '+')
		print_spaces(1);
	if (nb == 0 && fl[5] > 0 && fl[9] == 1 && fl[6] == 0)
		print_spaces(1);
	fl[6] += (fl[2] == '+' || nb < 0 || fl[3] == ' ');
	if (fl[1] != '-' && fl[5] > len && (fl[7] != '0' || (fl[9] && fl[6] >= 0)))
		print_spaces(fl[5] - get_max(fl[6], len));
	else if (fl[7] == '0' && fl[1] != '-' && (fl[9] == 0 || fl[6] < 0))
	{
		print_sub(nb, fl[2]);
		print_zeroes(fl[5] - len);
	}
	if (fl[7] != '0' || fl[1] == '-' || (fl[9] != 0 && fl[6] >= 0))
		print_sub(nb, fl[2]);
	if (fl[6] != 0)
		print_zeroes(fl[6] - len);
	if (nb != 0 || fl[9] != 1 || (fl[6] - (fl[3] == ' ' || fl[2] == '+')) != 0)
		ft_putnbr_rec_pr(nb);
	if (fl[1] == '-' && fl[5] > len)
		print_spaces(fl[5] - get_max(len, fl[6]));
}
