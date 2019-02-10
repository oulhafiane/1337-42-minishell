/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoulhafi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 02:55:02 by zoulhafi          #+#    #+#             */
/*   Updated: 2019/01/16 18:45:59 by zoulhafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;
	size_t	k;
	int		found;

	if (needle[0] == '\0')
		return ((char*)haystack);
	i = 0;
	while (haystack[i] != '\0')
	{
		k = 0;
		j = i;
		found = j;
		while (haystack[j] != '\0' && needle[k] != '\0')
		{
			if (haystack[j] != needle[k])
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
