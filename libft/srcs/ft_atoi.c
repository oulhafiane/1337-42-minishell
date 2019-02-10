/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoulhafi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 19:43:34 by zoulhafi          #+#    #+#             */
/*   Updated: 2018/10/09 22:15:42 by zoulhafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			check_sign(int nbr, int sign)
{
	if (sign == '-')
		return (nbr * -1);
	else
		return (nbr);
}

int					ft_atoi(const char *str)
{
	size_t	i;
	int		sign;
	long	nbr;

	i = 0;
	nbr = 0;
	sign = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
		sign = str[i++];
	while (str[i] >= '0' && str[i] <= '9')
	{
		if ((nbr * 10) + (str[i] - 48) < 0 && sign == '-')
			return (0);
		else if ((nbr * 10) + (str[i] - 48) < 0)
			return (-1);
		else
			nbr = (nbr * 10) + (str[i] - 48);
		i++;
	}
	return (check_sign(nbr, sign));
}
