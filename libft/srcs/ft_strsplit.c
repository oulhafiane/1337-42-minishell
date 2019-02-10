/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoulhafi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 23:35:26 by zoulhafi          #+#    #+#             */
/*   Updated: 2018/10/09 23:21:25 by zoulhafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	count;
	int		is_as;

	count = 0;
	is_as = 0;
	while (*s != '\0')
	{
		if (*s != c)
			is_as = 1;
		else if (*s == c && is_as == 1)
		{
			is_as = 0;
			count++;
		}
		s++;
	}
	if (is_as == 1)
		count++;
	return (count);
}

static size_t	next_c(char const *s, char c)
{
	size_t count;

	count = 0;
	while (*s != '\0')
	{
		if (*s != c)
			count++;
		else
			break ;
		s++;
	}
	return (count + 1);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		count;
	size_t	i;

	if (s == NULL)
		return (NULL);
	tab = (char**)malloc(sizeof(tab) * (count_words(s, c) + 1));
	if (tab == NULL)
		return (NULL);
	count = 0;
	while (*s != '\0')
	{
		if (*s != c)
		{
			tab[count] = (char*)malloc(sizeof(char) * next_c(s, c));
			i = 0;
			while (*s != c && *s != '\0')
				tab[count][i++] = *s++;
			tab[count++][i] = '\0';
			s--;
		}
		s++;
	}
	tab[count] = NULL;
	return (tab);
}
