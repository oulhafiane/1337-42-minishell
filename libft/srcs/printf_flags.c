/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoulhafi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 17:37:40 by zoulhafi          #+#    #+#             */
/*   Updated: 2019/01/22 17:37:48 by zoulhafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	putnbr_u_flag(int flags[LEN], va_list ap)
{
	if (flags[8] == 'l' + 1)
		ft_putnbr_u(va_arg(ap, unsigned long long), flags);
	else if (flags[8] == 'l')
		ft_putnbr_u(va_arg(ap, unsigned long), flags);
	else if (flags[8] == 'h' + 1)
		ft_putnbr_u((unsigned char)va_arg(ap, unsigned int), flags);
	else if (flags[8] == 'h')
		ft_putnbr_u((unsigned short)va_arg(ap, unsigned int), flags);
	else if (flags[8] == 'z')
		ft_putnbr_u(va_arg(ap, size_t), flags);
	else if (flags[8] == 'j')
		ft_putnbr_u(va_arg(ap, uintmax_t), flags);
	else
		ft_putnbr_u(va_arg(ap, unsigned int), flags);
}

void	putnbr_flag(int flags[LEN], va_list ap)
{
	if (flags[8] == 'l' + 1)
		ft_putnbr_pr(va_arg(ap, long long), flags);
	else if (flags[8] == 'l')
		ft_putnbr_pr(va_arg(ap, long), flags);
	else if (flags[8] == 'h' + 1)
		ft_putnbr_pr((char)va_arg(ap, int), flags);
	else if (flags[8] == 'h')
		ft_putnbr_pr((short)va_arg(ap, int), flags);
	else if (flags[8] == 'z')
		ft_putnbr_pr(va_arg(ap, size_t), flags);
	else if (flags[8] == 'j')
		ft_putnbr_pr(va_arg(ap, intmax_t), flags);
	else
		ft_putnbr_pr(va_arg(ap, int), flags);
}

void	putnbrbase_flag(int flags[LEN], va_list ap)
{
	if (flags[0] == 'p')
		ft_putnbr_base(va_arg(ap, uintmax_t), flags);
	else if (flags[8] == 'l' + 1)
		ft_putnbr_base(va_arg(ap, unsigned long long), flags);
	else if (flags[8] == 'l')
		ft_putnbr_base(va_arg(ap, unsigned long), flags);
	else if (flags[8] == 'h' + 1)
		ft_putnbr_base((unsigned char)va_arg(ap, int), flags);
	else if (flags[8] == 'h')
		ft_putnbr_base((unsigned short)va_arg(ap, int), flags);
	else if (flags[8] == 'z')
		ft_putnbr_base(va_arg(ap, size_t), flags);
	else if (flags[8] == 'j')
		ft_putnbr_base(va_arg(ap, uintmax_t), flags);
	else
		ft_putnbr_base(va_arg(ap, unsigned int), flags);
}

int		to_w(wchar_t c, char s[5])
{
	int i;

	i = -1;
	if ((c >= 0 && c <= 0x7F) || (c > 0x7F && c <= 0xFF && MB_CUR_MAX == 1))
		s[++i] = c;
	else if (c > 0x7F && c <= 0x7FF && MB_CUR_MAX == 4)
	{
		s[++i] = (c >> 6) + 0xC0;
		s[++i] = (c & 0x3F) + 0x80;
	}
	else if (c > 0x7FF && c <= 0xFFFF && MB_CUR_MAX == 4)
	{
		s[++i] = (c >> 12) + 0xE0;
		s[++i] = ((c >> 6) & 0x3F) + 0x80;
		s[++i] = (c & 0x3F) + 0x80;
	}
	else if (c > 0xFFFF && c <= 0x10FFFF && MB_CUR_MAX == 4)
	{
		s[++i] = (c >> 18) + 0xF0;
		s[++i] = ((c >> 12) & 0x3F) + 0x80;
		s[++i] = ((c >> 6) & 0x3F) + 0x80;
		s[++i] = (c & 0x3F) + 0x80;
	}
	s[++i] = '\0';
	return (i);
}

int		putstr_flag(int flags[LEN], va_list ap)
{
	char	s[5];
	wchar_t	c;

	if (flags[0] == 's' && flags[8] == 'l')
		return (putstr_w(va_arg(ap, wchar_t*), flags));
	else if (flags[0] == 'c' && flags[8] == 'l')
	{
		c = va_arg(ap, wchar_t);
		if ((c < 0xD800 || c >= 0xE000) && to_w(c, s) > 0)
			putstr_pr(s, flags);
		else
			return (-1);
	}
	else if (flags[0] == 'c')
	{
		s[0] = va_arg(ap, int);
		s[1] = '\0';
		putstr_pr(s, flags);
	}
	else
		putstr_pr(va_arg(ap, char*), flags);
	return (0);
}
