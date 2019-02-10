/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utility2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoulhafi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 17:37:10 by zoulhafi          #+#    #+#             */
/*   Updated: 2019/01/22 17:37:15 by zoulhafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	jump(char **s, char c)
{
	while (s[0][1] == c)
		(*s)++;
	return (c);
}

void	print_spaces(int nb)
{
	int i;

	i = -1;
	while (++i < nb)
		ft_putchar_pr(' ');
}

void	print_zeroes(int nb)
{
	int i;

	i = -1;
	while (++i < nb)
		ft_putchar_pr('0');
}

int		is_conv(char c, char *s_conv)
{
	int i;

	i = -1;
	while (s_conv[++i] != '\0')
	{
		if (s_conv[i] == c)
			return (1);
	}
	return (0);
}

int		print_sub_0(intmax_t nb, int flags[LEN])
{
	if (nb != 0 && flags[4] == '#' && (flags[0] == 'o'
				|| flags[0] == 'O'))
	{
		ft_putchar_pr('0');
		return (1);
	}
	else if (nb != 0 && flags[4] == '#' && flags[0] == 'X')
	{
		ft_putstrr("0X");
		return (2);
	}
	else if (flags[0] == 'p' || (nb != 0
				&& ((flags[4] == '#' && flags[0] == 'x'))))
	{
		ft_putstrr("0x");
		return (2);
	}
	if (nb == 0 && flags[4] == '#' && flags[9] == 1 &&
			flags[6] == 0 &&
			(flags[0] == 'o' || flags[0] == 'O'))
	{
		ft_putchar_pr('0');
		return (1);
	}
	return (0);
}
