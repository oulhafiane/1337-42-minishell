/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoulhafi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 22:06:26 by zoulhafi          #+#    #+#             */
/*   Updated: 2019/01/15 22:42:50 by zoulhafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_char(char *str, char c)
{
	int		count;

	count = 0;
	while (*str)
	{
		if (*str == c)
			count++;
		str++;
	}
	return (count);
}

char		*ft_remove_char(char **str, char c)
{
	char	*new;
	char	*cpy;
	int		indice;

	new = (char*)malloc(sizeof(char) * ((ft_strlen(*str) - count_char(*str, c))
				+ 1));
	cpy = *str;
	indice = 0;
	while (*cpy)
	{
		if (*cpy != c)
			new[indice++] = *cpy;
		cpy++;
	}
	new[indice] = '\0';
	free(*str);
	*str = new;
	return (new);
}
