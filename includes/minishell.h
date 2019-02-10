/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoulhafi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 01:26:35 by zoulhafi          #+#    #+#             */
/*   Updated: 2019/01/16 23:16:53 by zoulhafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <dirent.h>
# include <sys/stat.h>
# include "libft.h"

typedef struct			s_builtin
{
	char				*cmd;
	void				(*f)();
}						t_builtin;

typedef struct			s_env
{
	char				*name;
	char				*value;
}						t_env;

/*
**	minishell.c
*/
void					exec_cmd(char **cmds, char **path, t_list **env);

/*
**	args.c
*/
int					fix_line(char **line, t_list *env);

/*
**	builtin.c
*/
void					free_builtin(t_list *lst);
void					init_builtin(t_list **lst);
int					check_builtin(t_list *elem, void *obj);

/*
**	env.c
*/
char					**get_path(t_list *env);
void					add_env(t_list **lst, char *name, char *value, int end);
void					init_env(t_list **lst, char **env);
char					**env_to_tab(t_list *lst);
void					free_env(t_list *lst);

/*
**	errors.c
*/
void					print_error(char *error, char *cmd);

/*
**	free.c
*/
void					free_elem_env(t_list *elem);
void					free_exec_cmd(char *error, char *full_path,
		char **head_path);

/*
**	ft_env.c
*/
char					*get_env_value(char *name, t_list *lst);

/*
**	builtins commands.
*/
void					ft_cd(char **args, t_list **env);
void					ft_echo(char **args, t_list **env);
void					ft_env(char **args, t_list **env);
void					ft_setenv(char **args, t_list **env);
void					ft_unsetenv(char **args, t_list **env);
void					ft_pwd(char **args, t_list **env);

#endif
