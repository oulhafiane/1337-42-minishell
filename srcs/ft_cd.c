/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoulhafi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 11:50:18 by zoulhafi          #+#    #+#             */
/*   Updated: 2019/01/23 13:24:34 by zoulhafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	called from ft_cd,
**	it get the environment variable called $HOME
**	from the t_list *lst that contains all t_env elements.
*/

static char	*get_home(t_list *lst)
{
	t_env	*env;

	while (lst)
	{
		env = (t_env*)lst->content;
		if (ft_strcmp(env->name, "HOME") == 0)
			return (env->value);
		lst = lst->next;
	}
	return (NULL);
}

/*
**	this function called by ft_cd function,
**	it's change the value of the environment variable
**	$PWD or $OLDPWD given as parameter char *pwd,
**	if this variable not found it creates a new one.
*/

static void	change_pwd(char *pwd, t_list **lst)
{
	t_list	*cpy;
	t_env	*env;
	char	*new_home;

	cpy = *lst;
	while (cpy)
	{
		env = (t_env*)cpy->content;
		if (ft_strcmp(env->name, pwd) == 0)
		{
			free(env->value);
			env->value = NULL;
			env->value = getcwd(env->value, 0);
			return ;
		}
		cpy = cpy->next;
	}
	new_home = NULL;
	add_env(lst, pwd, getcwd(new_home, 0), 1);
	free(new_home);
}

/*
**	called by ft_cd function,
**	it checks if the string home given as parameter
**	is a file or a directory and exist or not and it's permission.
*/

static int	check_dir(char *home)
{
	struct stat	st;
	int			ret;

	ret = -1;
	if (home == NULL)
		ret = ft_printf_fd(2, "$HOME variable not found (check env).\n");
	else if (stat(home, &st) != 0)
		ret = ft_printf_fd(2, "%s: No such file or directory.\n", home);
	else if (home != NULL && access(home, F_OK) != 0)
		ret = ft_printf_fd(2, "%s: No such file or directory.\n", home);
	else if (home != NULL && (st.st_mode & S_IFMT) != S_IFDIR)
		ret = ft_printf_fd(2, "%s: Not a directory.\n", home);
	else if (home != NULL && access(home, X_OK) != 0)
		ret = ft_printf_fd(2, "%s: Permission denied.\n", home);
	if (ret != -1)
		return (-1);
	else
		return (1);
}

/*
**	a builtin command, that move the current location to another one,
**	it changes the value of $PWD and $OLDPWD, and calls chdir() function,
**	it checks if the new location exists and it's permission
**	before it makes any change.
*/

void	ft_cd(char **args, t_list **env)
{
	char		*home;
	char		*new;

	new = NULL;
	if (*args == NULL)
		home = get_home(*env);
	else
		home = *args;
	if (home != NULL && ft_strcmp(home, "~") == 0)
		home = get_env_value("HOME", *env);
	else if (home != NULL && home[0] == '~' && home[1] == '/')
		new = ft_strjoin(get_env_value("HOME", *env), home + 1);
	else if (home != NULL && ft_strcmp(home, "-") == 0)
		new = ft_strdup(get_env_value("OLDPWD", *env));
	if (new != NULL)
		home = new;
	if (check_dir(home) == 1)
	{
		change_pwd("OLDPWD", env);
		chdir(home);
		change_pwd("PWD", env);
	}
	if (new != NULL)
		free(new);
}
