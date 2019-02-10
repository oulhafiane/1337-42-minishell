/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoulhafi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 05:09:49 by zoulhafi          #+#    #+#             */
/*   Updated: 2018/10/09 23:10:34 by zoulhafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_last(const char *s)
{
	while (*s != '\0')
	{
		if (*s != ' ' && *s != '\n' && *s != '\t')
			return (0);
		s++;
	}
	return (1);
}

static int	count_trim(const char *s)
{
	size_t	i;

	i = 0;
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	while (*s != '\0')
	{
		if ((*s == ' ' || *s == '\n' || *s == '\t') && is_last(s))
			break ;
		s++;
		i++;
	}
	return (i + 1);
}

char		*ft_strtrim(char const *s)
{
	char	*new_str;
	size_t	i;

	if (s == NULL)
		return (NULL);
	new_str = (char*)malloc(sizeof(char) * count_trim(s));
	if (new_str == NULL)
		return (NULL);
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	i = 0;
	while (*s != '\0')
	{
		if ((*s == ' ' || *s == '\n' || *s == '\t') && is_last(s))
			break ;
		new_str[i] = *s;
		s++;
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
