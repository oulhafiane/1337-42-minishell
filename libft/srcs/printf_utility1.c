/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utility1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoulhafi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 17:37:05 by zoulhafi          #+#    #+#             */
/*   Updated: 2019/01/22 17:37:07 by zoulhafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		check_flag6(char *s)
{
	int i;

	i = 0;
	while (s[--i] != '%')
	{
		if (s[i] == '.')
			return (1);
	}
	return (0);
}

int		get_width(char **s, va_list ap, int flags[LEN])
{
	int		r;
	int		tmp;
	int		ok;

	ok = 0;
	if ((ok = (**s == '.' && is_conv(s[0][1], "0123456789*"))) == 1)
		(*s)++;
	if (**s == '*')
	{
		tmp = va_arg(ap, int);
		if (tmp < 0 && (ok == 0 || next_conv(*s) == 's'))
		{
			tmp = tmp * -1;
			flags[1] = '-';
		}
		return (tmp);
	}
	r = ft_atoi_pr(*s);
	if (**s == '0' && check_flag6(*s) == 0)
		flags[7] = '0';
	while (s[0][1] >= '0' && s[0][1] <= '9')
		(*s)++;
	return (r);
}

void	init_flags(int flags[LEN])
{
	int i;

	i = -1;
	while (++i < LEN)
		flags[i] = 0;
}

void	set_flags(int flags[LEN], char flag)
{
	if (flag == '-')
		flags[1] = flag;
	else if (flag == '+')
		flags[2] = flag;
	else if (flag == ' ')
		flags[3] = flag;
	else if (flag == '#')
		flags[4] = flag;
}

void	get_flags(char **s, va_list ap, int fl[LEN])
{
	(*s)++;
	init_flags(fl);
	while (is_conv(**s, "-+ #hlLjz.0123456789*") == 1)
	{
		if (**s == '-' || **s == '+' || **s == ' ' || **s == '#')
			set_flags(fl, jump(s, **s));
		else if ((fl[8] == 'h' && **s == 'h') || (fl[8] == 'l' && **s == 'l'))
			fl[8] = **s + 1;
		else if (**s == 'h' || **s == 'l' || **s == 'L' ||
					**s == 'j' || **s == 'z')
		{
			if (fl[8] < **s)
				fl[8] = **s;
		}
		else if (**s == '.')
			fl[6] = get_width(s, ap, fl);
		else if ((**s == '0' && (s[0][1] > '9' || s[0][1] <= '0')))
			fl[7] = '0';
		else if ((**s >= '0' && **s <= '9') || **s == '*')
			fl[5] = get_width(s, ap, fl);
		(*s)++;
	}
	fl[0] = **s;
	fl[9] = check_flag6(*s);
}
