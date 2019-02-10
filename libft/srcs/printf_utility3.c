/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utility3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoulhafi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 17:37:18 by zoulhafi          #+#    #+#             */
/*   Updated: 2019/01/22 17:37:22 by zoulhafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		get_max(int len1, int len2)
{
	if (len1 > len2)
		return (len1);
	else
		return (len2);
}

int		get_min(int len1, int len2)
{
	if (len1 < len2)
		return (len1);
	else
		return (len2);
}

int		print_format(int flags[LEN], va_list ap)
{
	convert_flags(flags);
	if (flags[0] == 's' || flags[0] == 'c')
	{
		if (putstr_flag(flags, ap) == -1)
			return (-1);
	}
	else if (flags[0] == 'd' || flags[0] == 'i')
		putnbr_flag(flags, ap);
	else if (flags[0] == 'u')
		putnbr_u_flag(flags, ap);
	else if (flags[0] == 'p' || flags[0] == 'x' || flags[0] == 'X' ||
			flags[0] == 'o')
		putnbrbase_flag(flags, ap);
	else
		putstr_pr((char*)&flags[0], flags);
	return (0);
}

char	*null_str(char str[7])
{
	str[0] = '(';
	str[1] = 'n';
	str[2] = 'u';
	str[3] = 'l';
	str[4] = 'l';
	str[5] = ')';
	str[6] = '\0';
	return (str);
}

char	next_conv(char *s)
{
	int i;

	i = -1;
	while (s[++i] != '\0')
	{
		if (is_conv(s[i], "sSpdDioOuUxXcCeEfFgGaAn%") == 1)
			return (s[i]);
	}
	return (0);
}
