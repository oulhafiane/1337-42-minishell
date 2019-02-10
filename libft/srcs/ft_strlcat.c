/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoulhafi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 23:52:46 by zoulhafi          #+#    #+#             */
/*   Updated: 2018/10/09 23:15:35 by zoulhafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char *src, size_t size)
{
	size_t i;
	size_t j;
	size_t len_dst;
	size_t total_length;

	i = 0;
	len_dst = ft_strlen(dst);
	j = len_dst;
	total_length = len_dst + ft_strlen(src);
	if (j >= size)
		return (total_length - (j - size));
	while (src[i] != '\0' && (i + len_dst) < size - 1)
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (total_length);
}
