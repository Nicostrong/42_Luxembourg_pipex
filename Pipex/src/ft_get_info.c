/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 08:48:18 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/06/18 09:49:31 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

/*
 * <cat>array</cat>
 *
 * <summary>
 * 	char	**ft_get_cmd_opt(int argc, char **argv))
 * </summary>
 *
 * <description>
 * 	ft_get_cmd read all args passed to the program and creat an array with
 * 	all commands. All commands are all args without the first and the last.
 * </description>
 *
 * <param type="int" name="argc">number of arg</param>
 * <param type="char **" name="argv">list of arguments</param>
 *
 * <return>
 * 	an array with all arguments without the first and the last.
 * </return>
 *
 */

char	**ft_get_cmd_opt(int argc, char **argv)
{
	char	**cmd_array;
	int		i_arg;
	int		i_cmd;

	i_arg = 2;
	i_cmd = 0;
	cmd_array = (char **)malloc((argc - i_arg) * sizeof(char *));
	if (!cmd_array)
		return (NULL);
	while (i_arg <= argc - 2)
	{
		cmd_array[i_cmd] = ft_strdup(argv[i_arg]);
		if (!cmd_array[i_cmd])
			return (free_array(&cmd_array), NULL);
		i_cmd++;
		i_arg++;
	}
	cmd_array[i_cmd] = NULL;
	return (cmd_array);
}

/*
 * <cat>array</cat>
 *
 * <summary>
 * 	char	**ft_get_path(char **env)
 * </summary>
 *
 * <description>
 * 	ft_get_path read all env variables in env (is define in header file like 
 * 	extern char **environ) catch the $PATH variable and split the path in an 
 * 	array of path.
	lst = ft_init_list(argc, argv);
 * </description>
 *
 * <param type="char **" name="env">list of all env variables</param>
 *
 * <return>
 * 	an array with all path in the var $PATH.
 * </return>
 *
 */

char	**ft_get_path(char **env)
{
	char	**path_array;
	char	*path;
	int		index;

	index = 0;
	while (env[index] && ft_strncmp(env[index], "PATH=", 5))
		index++;
	if (!env[index])
		return (NULL);
	path = env[index] + 5;
	path_array = ft_split(path, ':');
	return (path_array);
}

/*
 * <cat>array</cat>
 *
 * <summary>
 * 	char	**ft_get_only_cmd(char **cmd_array, int nb_cmd)
 * </summary>
 *
 * <description>
 * 	ft_get_only_cmd create an array with just the command name.
 * </description>
 *
 * <param type="char **" name="cmd_array">array of cmd with options</param>
 * <param type="int" name="nb_cmd">number of cmd</param>
 *
 * <return>
 * 	an array with all file argument there're the first and the last.
 * </return>
 *
 */

char	**ft_get_only_cmd(char **cmd_option, int nb_cmd)
{
	int		i_array;
	int		i_cmd;
	int		i_row;
	char	**cmd;

	cmd = (char **)ft_calloc((nb_cmd + 1), sizeof(char *));
	if (!cmd)
		return (NULL);
	i_array = 0;
	i_row = 0;
	while (cmd_option[i_array])
	{
		i_cmd = 0;
		while (cmd_option[i_array][i_cmd] != ' ' && cmd_option[i_array][i_cmd])
			i_cmd++;
		cmd[i_row++] = ft_substr(cmd_option[i_array], 0, i_cmd);
		i_array++;
	}
	cmd[i_row++] = NULL;
	return (cmd);
}

/*
 * <cat>array</cat>
 *
 * <summary>
 * 	char	**ft_concat_cmd_path(char **path, char *cmd)
 * </summary>
 *
 * <description>
 * 	ft_concat_cmd_path concat all path with a simple command.
 * </description>
 *
 * <param type="char **" name="path">aray of path</param>
 * <param type="char *" name="cmd">command to join with all path</param>
 *
 * <return>
 * 	an array of path with the command.
 * </return>
 *
 */

char	**ft_concat_cmd_path(char **path, char *cmd)
{
	char	**path_cmd_array;
	char	**tmp;
	char	*joined;
	int		index;
	int		nb_row;

	index = 0;
	nb_row = 0;
	tmp = path;
	while (*tmp++)
		nb_row++;
	path_cmd_array = (char **)ft_calloc((nb_row + 1), sizeof(char *));
	if (!path_cmd_array)
		return (NULL);
	while (*path)
	{
		path_cmd_array[index] = NULL;
		joined = ft_strjoin(*path++, "/");
		path_cmd_array[index] = ft_strjoin(joined, cmd);
		free(joined);
		index++;
	}
	return (path_cmd_array);
}
