/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_w2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoulhafi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 05:28:08 by zoulhafi          #+#    #+#             */
/*   Updated: 2018/11/19 16:00:31 by zoulhafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strlen_w(wchar_t *str)
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
			while (s[++j] != '\0')
				r += 1;
		}
		else
			return (-1);
	}
	return (r);
}

int		ft_strlen_wf(wchar_t *str, int flag6)
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
			if (r + ft_strlen(s) > (size_t)flag6)
				return (r);
			while (s[++j] != '\0')
				r += 1;
		}
		else if (flag6 > r)
			return (-1);
		else
			return (r);
	}
	return (r);
}
