/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utility4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoulhafi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 17:37:26 by zoulhafi          #+#    #+#             */
/*   Updated: 2019/01/22 17:37:30 by zoulhafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strlen_null(char *s, int cpt_null)
{
	int i;
	int cpt;

	cpt = -1;
	i = -1;
	while (++cpt < cpt_null)
	{
		while (s[++i] != '\0')
			;
	}
	return (i - 1);
}

wchar_t	*null_str_w(wchar_t str[7], int flags[LEN])
{
	if (flags[9] == 1 && flags[6] <= 0)
		return (L"");
	str[0] = '(';
	str[1] = 'n';
	str[2] = 'u';
	str[3] = 'l';
	str[4] = 'l';
	str[5] = ')';
	str[6] = '\0';
	return (str);
}

void	init_s(char s[5])
{
	int i;

	i = -1;
	while (++i < 5)
		s[i] = '\0';
}

void	convert_flags(int flags[LEN])
{
	if (flags[0] == 'D' || flags[0] == 'O' || flags[0] == 'U'
			|| flags[0] == 'C' || flags[0] == 'S')
	{
		flags[0] += 32;
		flags[8] = 'l';
	}
}

int		ft_atoi_pr(const char *str)
{
	int	i;
	int	sign;
	int	nbr;
	int	c;

	i = 0;
	nbr = 0;
	sign = 0;
	while (str[i] == ' ')
		i++;
	c = i;
	while ((str[i] >= '0' && str[i] <= '9') ||
			(c == i && sign == 0 && (str[i] == '-' || str[i] == '+')))
	{
		if (str[i] == '-' || str[i] == '+')
			sign = str[i];
		else
			nbr = (nbr * 10) + (str[i] - 48);
		i++;
	}
	if (sign == '-')
		nbr = nbr * -1;
	return (nbr);
}
