/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoulhafi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 13:42:24 by zoulhafi          #+#    #+#             */
/*   Updated: 2018/11/19 15:59:27 by zoulhafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_putstr_wf(wchar_t *str, int flag)
{
	int		i;
	int		j;
	int		r;
	char	s[5];

	r = 0;
	i = -1;
	while (str[++i] != '\0')
	{
		init_s(s);
		if ((str[i] < 0xD800 || str[i] >= 0xE000) && to_w(str[i], s) > 0)
		{
			j = -1;
			if (r + ft_strlen(s) > (size_t)flag)
				return (0);
			ft_putstrr(s);
			r += ft_strlen(s);
		}
		else if (flag > r)
			return (-1);
		else
			return (r);
	}
	return (0);
}

static int	ft_putstr_w(wchar_t *str)
{
	int		i;
	int		j;
	char	s[5];

	i = -1;
	while (str[++i] != '\0')
	{
		init_s(s);
		if ((str[i] < 0xD800 || str[i] >= 0xE000) && to_w(str[i], s) > 0)
		{
			j = -1;
			while (s[++j] != '\0')
				ft_putchar_pr(s[j]);
		}
		else
			return (-1);
	}
	return (0);
}

static void	putstr_flag_continue(int len, int flags[LEN])
{
	if (flags[7] == '0' && flags[1] != '-' && (flags[9] == 0 ||
				(get_min(flags[6], len) < flags[5])))
	{
		if (flags[9] == 1)
			print_zeroes(flags[5] - get_min(flags[6], len));
		else
			print_zeroes(flags[5] - len);
	}
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

int			putstr_w(wchar_t *str, int flags[LEN])
{
	int		len;
	int		r;
	wchar_t	tmp[7];

	r = 0;
	if (str == NULL)
		str = null_str_w(tmp, flags);
	if (flags[9] == 1)
		len = ft_strlen_wf(str, flags[6]);
	else
		len = ft_strlen_w(str);
	putstr_flag_continue(len, flags);
	if (flags[9] == 1)
		r = ft_putstr_wf(str, flags[6]);
	else
		r = ft_putstr_w(str);
	if (flags[1] == '-' && flags[5] > len)
	{
		if (flags[6] != 0)
			print_spaces(flags[5] - get_min(len, flags[6]));
		else if (flags[6] == 0)
			print_spaces(flags[5] - len);
	}
	return (r);
}
