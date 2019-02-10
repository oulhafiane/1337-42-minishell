/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoulhafi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 02:06:37 by zoulhafi          #+#    #+#             */
/*   Updated: 2018/10/13 03:40:16 by zoulhafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, void *src, int c, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char*)dst;
	while (i < n)
	{
		str[i] = ((char*)src)[i];
		if (str[i] == (char)c)
			return (str + i + 1);
		i++;
	}
	return (NULL);
}
