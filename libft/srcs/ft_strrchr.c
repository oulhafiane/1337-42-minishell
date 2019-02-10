/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoulhafi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 01:13:33 by zoulhafi          #+#    #+#             */
/*   Updated: 2018/10/07 22:47:28 by zoulhafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *r;

	r = NULL;
	while (*s != '\0')
	{
		if (*s == c)
			r = (char*)s;
		s++;
	}
	if (r != NULL)
		return (r);
	else if (c == '\0')
		return ((char*)s);
	else
		return (NULL);
}
