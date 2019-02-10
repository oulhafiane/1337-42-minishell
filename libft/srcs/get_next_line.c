/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoulhafi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 02:52:47 by zoulhafi          #+#    #+#             */
/*   Updated: 2019/01/09 20:32:29 by zoulhafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		check_next_line(char **tmp, char **str)
{
	char	*cpy;
	size_t	i;
	size_t	n;

	if (tmp == NULL || *tmp == NULL)
		return (-1);
	cpy = *tmp;
	i = -1;
	n = ft_strlen(*tmp);
	while (++i < n)
	{
		if ((*tmp)[i] != '\n')
			(*str)[i] = ((char*)*tmp)[i];
		else
			break ;
	}
	if (i == n)
		*tmp = NULL;
	else
		*tmp = ft_strdup(*tmp + i + 1);
	free(cpy);
	if (*tmp != NULL)
		return (0);
	return (1);
}

static char		**get_tmp(int fd)
{
	t_fdlist		**lst;
	t_fdlist		*tmp;

	lst = get_static_list();
	tmp = *lst;
	if (tmp)
	{
		while (tmp->next)
		{
			if (tmp->fd == fd)
				return (&(tmp->tmp));
			tmp = tmp->next;
		}
		if (tmp->fd == fd)
			return (&(tmp->tmp));
		tmp->next = (t_fdlist*)malloc(sizeof(t_fdlist));
		tmp = tmp->next;
	}
	else
		*lst = (t_fdlist*)malloc(sizeof(t_fdlist));
	if (tmp == NULL)
		tmp = *lst;
	init_fdlist(&tmp, fd);
	return (NULL);
}

static int		search_new_line(int fd, char **line, int nbr_rep, int ret)
{
	size_t	i;
	size_t	n;
	char	*s_tmp;

	if (ft_strchr(*line, '\n') != NULL)
	{
		s_tmp = (char*)ft_memalloc(sizeof(char) * (2000 * (nbr_rep)));
		i = -1;
		n = ft_strlen(*line);
		while (++i < n)
		{
			if ((*line)[i] == '\n')
				break ;
			s_tmp[i] = ((char*)*line)[i];
		}
		if (i == n)
			*get_tmp(fd) = NULL;
		else
			*get_tmp(fd) = ft_strdup(*line + i + 1);
		free(*line);
		s_tmp[i] = '\0';
		*line = s_tmp;
		ret = 1;
	}
	return (ret);
}

static int		read_line(const int fd, char **line, int taille, size_t nbr_rep)
{
	int		ret;
	char	*s_tmp;
	size_t	count;

	count = ft_strlen(*line);
	while ((ret = read(fd, *line + count, BUFF_SIZE)) >= 1
			&& ft_strchr(*line, '\n') == NULL)
	{
		count += BUFF_SIZE;
		if (count + BUFF_SIZE >= (taille * nbr_rep))
		{
			s_tmp = *line;
			*line = (char*)ft_memalloc(sizeof(char) * ((taille * ++nbr_rep)));
			if (*line == NULL)
				return (-1);
			ft_strcpy(*line, s_tmp);
			free(s_tmp);
		}
	}
	return (search_new_line(fd, line, nbr_rep, ret));
}

int				get_next_line(const int fd, char **line)
{
	int		ret;
	int		taille;
	size_t	nbr_rep;

	nbr_rep = 1;
	taille = 2000;
	if (line == NULL)
		return (-1);
	if (taille <= BUFF_SIZE)
		nbr_rep = BUFF_SIZE / taille;
	nbr_rep++;
	*line = (char*)ft_memalloc(sizeof(char) * (taille * nbr_rep));
	if (*line == NULL || fd < 0)
		return (-1);
	ret = check_next_line(get_tmp(fd), line);
	if (ret == 0)
		return (1);
	ret = read_line(fd, line, taille, nbr_rep);
	if (ret == 0 && **line)
		ret = 1;
	if (ret != 1)
		free(*line);
	return (ret);
}
