/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoulhafi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 19:04:39 by zoulhafi          #+#    #+#             */
/*   Updated: 2019/01/23 13:26:47 by zoulhafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			g_output_fd;

int			print_stack(char **s, int *i, int *len, int nb)
{
	int tmp;

	if (*i + 1 < LEN_BUF * nb)
		s[0][++(*i)] = '\0';
	tmp = ft_strlen(*s);
	write(g_output_fd, *s, tmp);
	*i = -1;
	while (++(*i) < LEN_BUF * nb)
		s[0][*i] = '\0';
	*i = -1;
	tmp += *len;
	*len = 0;
	return (tmp);
}

int			stock_char(char c, int print)
{
	char		**s;
	static int	i = -1;
	static int	nb = 1;
	static int	len = 0;

	s = get_static_str();
	ft_alloc_mem(s, nb, 0, 0);
	if (print == 1)
		return (print_stack(s, &i, &len, nb));
	if (c == '\0')
	{
		len = ft_strlen(*s);
		write(g_output_fd, *s, len);
		write(g_output_fd, &c, 1);
		i = -1;
		while (++i < LEN_BUF * nb)
			s[0][i] = '\0';
		i = -1;
		len++;
		return (0);
	}
	if (i + 2 >= LEN_BUF * nb)
		ft_alloc_mem(s, ++nb, 1, i + 1);
	s[0][++i] = c;
	return (0);
}

static int	my_printf(int fd, const char *format, va_list ap)
{
	int			count;
	int			flags[LEN];

	g_output_fd = fd;
	count = 0;
	while (*format)
	{
		if (*format == '%' && format[1] != '\0')
		{
			get_flags((char**)&format, ap, flags);
			if (print_format(flags, ap) != -1)
				count += stock_char('\0', 1);
			else
				return (-1);
		}
		else if (*format != '%')
			stock_char(*format, 0);
		if (*format != '\0')
			format++;
	}
	count += stock_char('\0', 1);
	return (count);
}

int			ft_printf_fd(int fd, const char *format, ...)
{
	va_list		ap;
	int			ret;

	va_start(ap, format);
	ret = my_printf(fd, format, ap);
	free_printf(&ap);
	return (ret);
}

int			ft_printf(const char *format, ...)
{
	va_list		ap;
	int			ret;

	va_start(ap, format);
	ret = my_printf(1, format, ap);
	free_printf(&ap);
	return (ret);
}
