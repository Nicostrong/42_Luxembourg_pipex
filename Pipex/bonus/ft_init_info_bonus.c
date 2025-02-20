/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_info_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 09:00:46 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/02/20 14:05:24 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

/*
 * <cat>list</cat>
 *
 * <summary>
 * 	t_info	*ft_init_info(int argc, char **argv)
 * </summary>
 *
 * <description>
 * 	ft_init_info initialise all variable in the struct info with all parameters 
 * 	passed to the program.
 * </description>
 *
 * <param type="int" name="argc">number of arguments</param>
 * <param type="char **" name="argv">array of arguments</param>
 *
 * <return>
 * 	a pointer to the list info.
 * </return>
 *
 */

t_info	*ft_init_info(int argc, char **argv)
{
	t_info	*info;

	info = (t_info *)ft_calloc(1, sizeof(t_info));
	if (!info)
	{
		ft_putendl_fd("Error: Malloc fail for struct info.", 2);
		exit(EXIT_FAILURE);
	}
	if (!ft_strncmp(argv[1], "here_doc", 8))
	{
		info->here_doc = 1;
		info->limiter = ft_strdup(argv[2]);
		info->file_in = NULL;
	}
	else
		info->file_in = ft_strdup(argv[1]);
	if (!info->limiter && !info->file_in)
		ft_free_info(&info, 1);
	ft_get_all_array(&info, argc, argv);
	return (info);
}

/*
 * <cat>list</cat>
 *
 * <summary>
 * 	void	ft_get_all_array(t_info **info, int argc, char **argv)
 * </summary>
 *
 * <description>
 * 	ft_get_all_array initialise all array in the struct info with all parameters 
 * 	passed to the program. It's to split the function init.
 * </description>
 *
 * <param type="t_info **" name="info">structure to complete</param>
 * <param type="int" name="argc">number of arguments</param>
 * <param type="char **" name="argv">array of arguments</param>
 *
 * <return>
 * 	void, complete directely the struct.
 * </return>
 *
 */

void	ft_get_all_array(t_info **info, int argc, char **argv)
{
	char	**cmd_array;

	(*info)->file_out = ft_strdup(argv[argc - 1]);
	if (!(*info)->file_out)
		ft_free_info(info, 1);
	(*info)->cmd_opt_array = ft_get_cmd_opt(argc, argv);
	if (!(*info)->cmd_opt_array)
		ft_free_info(info, 1);
	cmd_array = (*info)->cmd_opt_array;
	(*info)->nb_cmd = ft_get_nb_cmd(cmd_array);
	(*info)->path_array = ft_get_path(environ);
	if (!(*info)->path_array)
		ft_free_info(info, 1);
	(*info)->cmd_array = ft_get_only_cmd(cmd_array, (*info)->nb_cmd);
	if (!(*info)->cmd_array)
		ft_free_info(info, 1);
	(*info)->access_path = ft_get_access(*info);
	if (!(*info)->access_path)
		ft_free_info(info, 1);
}

/*
 * <cat>array</cat>
 *
 * <summary>
 * 	int	ft_get_nb_cmd(char **array)
 * </summary>
 *
 * <description>
 * 	ft_get_nb_cmd cunt the number of row in an array. 
 * </description>
 *
 * <param type="char **" name="array">array to evaluate</param>
 *
 * <return>
 * 	the number of row in an array.
 * </return>
 *
 */

int	ft_get_nb_cmd(char **array)
{
	int	index;

	index = 0;
	while (*array++)
		index++;
	return (index);
}
