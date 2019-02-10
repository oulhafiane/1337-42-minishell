/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoulhafi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 13:42:24 by zoulhafi          #+#    #+#             */
/*   Updated: 2018/11/19 15:22:53 by zoulhafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_pr(char c)
{
	stock_char(c, 0);
}

void	ft_putstrr(char *str)
{
	int i;

	if (str == NULL)
		return (ft_putstrr("(null)"));
	i = 0;
	while (str[i])
	{
		ft_putchar_pr(str[i]);
		i++;
	}
}

void	ft_putstr_f(char *str, int flag)
{
	int i;

	if (str == NULL)
		return (ft_putstrr("(null)"));
	i = 0;
	while (str[i] && i < flag)
	{
		ft_putchar_pr(str[i]);
		i++;
	}
}

void	putstr_flag_continue(int len, int flags[LEN])
{
	if (flags[7] == '0' && flags[1] != '-' && (flags[6] == 0 ||
				(get_min(flags[6], len) < flags[5])))
		print_zeroes(flags[5] - len);
	else if (flags[1] != '-' && flags[5] > len && (flags[7] != '0'
				|| (flags[9] == 1 && flags[6] >= 0)))
	{
		if (flags[9] == 0)
			print_spaces(flags[5] - len);
		else
			print_spaces(flags[5] - get_min(len, flags[6]));
	}
	else if (flags[5] <= len && flags[9] == 1)
		print_spaces(flags[5] - get_min(len, flags[6]));
}

void	putstr_pr(char *str, int flags[LEN])
{
	int		len;
	char	tmp[7];

	if (str == NULL && (flags[9] == 1 && flags[6] <= 0))
		str = "";
	else if (str == NULL)
		str = null_str(tmp);
	len = ft_strlen(str);
	len += (flags[0] == 'c' && str[0] == 0);
	putstr_flag_continue(len, flags);
	if (str[0] == 0 && (flags[0] == 'c'))
		ft_putchar_pr(str[0]);
	else if (flags[9] == 1 && (flags[0] == 's'))
		ft_putstr_f(str, flags[6]);
	else
		ft_putstrr(str);
	if (flags[1] == '-' && flags[5] > len)
	{
		if (flags[6] != 0)
			print_spaces(flags[5] - get_min(len, flags[6]));
		else if (flags[6] == 0)
			print_spaces(flags[5] - len);
	}
}
