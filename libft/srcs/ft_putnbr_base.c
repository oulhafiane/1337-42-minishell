/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoulhafi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 18:57:12 by zoulhafi          #+#    #+#             */
/*   Updated: 2018/11/12 01:26:26 by zoulhafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	lennbr_base(uintmax_t nb, char *base, char f9)
{
	unsigned int		len;
	int					count;

	if (nb == 0 && f9 == 1)
		return (0);
	count = 0;
	len = ft_strlen(base);
	if (nb >= len)
		count += lennbr_base(nb / len, base, 0);
	count++;
	return (count);
}

static void	ft_putnbr_base_rec(uintmax_t nb, char *base, char f9)
{
	unsigned int		len;

	if (nb == 0 && f9 == 1)
		return ;
	len = ft_strlen(base);
	if (nb >= len)
		ft_putnbr_base_rec(nb / len, base, 0);
	ft_putchar_pr(base[nb % len]);
}

static int	len_flags(uintmax_t nb, int flags[8])
{
	int r;

	r = 0;
	if (nb == 0 && flags[4] == '#')
		return (0);
	if (flags[4] == '#' && (flags[0] == 'o' || flags[0] == 'O'))
		r += 1;
	else if (flags[4] == '#' && flags[0] == 'X')
		r += 2;
	else if ((flags[4] == '#' && flags[0] == 'x')
			|| (flags[0] == 'p' && flags[5] != 0))
		r += 2;
	return (r);
}

static void	putnbr_base_continue(int lf, int flags[LEN], int len, uintmax_t nb)
{
	int r;

	if (flags[1] != '-' && flags[5] > len && (flags[7] != '0'
				|| (flags[9] == 1 && flags[6] >= 0)))
	{
		print_spaces(flags[5] - get_max(flags[6], len) - lf);
		r = print_sub_0(nb, flags);
	}
	else if (flags[7] == '0' && flags[1] != '-' && flags[6] == 0)
	{
		r = print_sub_0(nb, flags);
		print_zeroes(flags[5] - len - lf);
	}
	else
		r = print_sub_0(nb, flags);
	if (flags[6] > flags[5] && (flags[0] == 'o' || flags[0] == 'O'))
		print_zeroes(flags[6] - len - r);
	else if (flags[6] != 0)
		print_zeroes(flags[6] - len);
}

void		ft_putnbr_base(uintmax_t nb, int flags[5])
{
	int		len;
	int		lf;

	lf = len_flags(nb, flags);
	if (flags[0] == 'p' || flags[0] == 'x' || flags[0] == 'X')
		len = lennbr_base(nb, "0123456789abcdef", flags[9]);
	else
		len = lennbr_base(nb, "01234567", flags[9]);
	putnbr_base_continue(lf, flags, len, nb);
	if (flags[0] == 'p' || flags[0] == 'x')
		ft_putnbr_base_rec(nb, "0123456789abcdef", flags[9]);
	else if (flags[0] == 'o' || flags[0] == 'O')
		ft_putnbr_base_rec(nb, "01234567", flags[9]);
	else if (flags[0] == 'X')
		ft_putnbr_base_rec(nb, "0123456789ABCDEF", flags[9]);
	if (flags[1] == '-' && flags[5] > len)
		print_spaces(flags[5] - get_max(flags[6], len) - lf);
}
