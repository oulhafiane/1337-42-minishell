/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoulhafi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 15:16:29 by zoulhafi          #+#    #+#             */
/*   Updated: 2018/10/09 23:07:36 by zoulhafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;
	int		found;

	if (needle[0] == '\0')
		return ((char*)haystack);
	i = 0;
	while (haystack[i] != '\0' && i < len)
	{
		k = 0;
		j = i;
		found = j;
		while (needle[k] != '\0')
		{
			if (haystack[j] != needle[k] || j >= len)
				found = -1;
			k++;
			j++;
		}
		if (found != -1)
			return ((char*)haystack + found);
		i++;
	}
	return (NULL);
}
