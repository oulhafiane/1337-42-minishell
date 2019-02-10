/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtabdup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoulhafi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 13:22:48 by zoulhafi          #+#    #+#             */
/*   Updated: 2019/01/08 13:25:29 by zoulhafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strtabdup(char **tab)
{
	char	**new;
	int		i;

	new = (char**)malloc(sizeof(char*) * (ft_strtablen(tab) + 1));
	i = 0;
	while (*tab)
	{
		new[i++] = ft_strdup(*tab);
		tab++;
	}
	new[i] = NULL;
	return (new);
}
