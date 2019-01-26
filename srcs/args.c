/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoulhafi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 22:06:26 by zoulhafi          #+#    #+#             */
/*   Updated: 2019/01/23 13:26:02 by zoulhafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		count_char_to_remove(char *str)
{
	int		count;
	char	previous_c;

	count = 0;
	previous_c = '\0';
	while (*str)
	{
		if (*str == '\\' && previous_c != '\\')
			count++;
		else if (*str == '\\' && previous_c == '\\')
		{
			previous_c = '\0';
			str++;
			continue;
		}
		else if ((*str == '\'' || *str == '"') && previous_c != '\\')
			count++;
		previous_c = *str;
		str++;
	}
	return (count);
}

void			remove_quotes(char **str)
{
	char	*new;
	char	*cpy;
	int		indice;
	char	previous_c;

	new = (char*)malloc(sizeof(char) * ((ft_strlen(*str) -
					count_char_to_remove(*str)) + 1));
	cpy = *str;
	indice = 0;
	previous_c = '\0';
	while (*cpy)
	{
		if (previous_c == '\\' || (*cpy != '"' && *cpy != '\'' && *cpy != '\\'))
			new[indice++] = *cpy;
		if (*cpy == '\\' && previous_c == '\\')
			previous_c = '\0';
		else
			previous_c = *cpy;
		cpy++;
	}
	new[indice] = '\0';
	free(*str);
	*str = new;
}

static char		*get_value(char *str)
{
	char	*value;
	int		i;

	while (*str)
	{
		if (*str == '$')
		{
			i = 0;
			while (ft_isalnum(str[++i]) == 1)
				;
			value = (char*)ft_memalloc(sizeof(char) * (i + 1));
			ft_strncpy(value, str, i);
			return (value);
		}
		str++;
	}
	return (NULL);
}

int				check_vars(char *str, t_list *env)
{
	char	*value;
	char	*env_value;

	while ((value = get_value(str)) != NULL)
	{
		if ((env_value = get_env_value(value + 1, env)) == NULL)
		{
			ft_printf_fd(2, "%s: Undefined variable.\n", value + 1);
			free(value);
			return (-1);
		}
		str = ft_strchr(str, '$') + 1;
		free(value);
	}
	return (1);
}

int				fix_line(char **line, t_list *env)
{
	char	*value;
	char	*env_value;

	remove_quotes(line);
	if (ft_strchr(*line, '$') == NULL)
		return (1);
	if (check_vars(*line, env) == -1)
		return (-1);
	while (ft_strchr(*line, '$') != NULL)
	{
		value = get_value(*line);
		if ((env_value = get_env_value(value + 1, env)) == NULL)
		{
			ft_printf_fd(2, "%s: Undefined variable.\n", value + 1);
			free(value);
			return (-1);
		}
		ft_str_replace(line, value, env_value);
		free(value);
	}
	return (1);
}
