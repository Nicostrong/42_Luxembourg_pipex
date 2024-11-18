/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_info_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 09:02:49 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/06/18 09:57:52 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

/*
 * <cat>memory</cat>
 *
 * <summary>
 * 	int	ft_free_info(t_info **info, int error)
 * </summary>
 *
 * <description>
 * 	ft_free_info free all pointer in struct info, error is a bool value to set 
 * 	the correct exiting status.
 * </description>
 *
 * <param type="t_info **" name="info">structure of pipex</param>
 * <param type="int" name="error">bool value for error alloacation</param>
 *
 * <return>
 * 	0 if no error.
 * 	1 if error.
 * </return>
 *
 */

int	ft_free_info(t_info **info, int error)
{
	if (info != NULL && *info != NULL)
	{
		if ((*info)->limiter)
			free((*info)->limiter);
		if ((*info)->file_in)
			free((*info)->file_in);
		if ((*info)->file_out)
			free((*info)->file_out);
		if ((*info)->path_array)
			free_array(&(*info)->path_array);
		if ((*info)->cmd_opt_array)
			free_array(&(*info)->cmd_opt_array);
		if ((*info)->cmd_array)
			free_array(&(*info)->cmd_array);
		if ((*info)->access_path)
			free_array(&(*info)->access_path);
		free(*info);
		info = NULL;
	}
	if (error)
		exit(EXIT_FAILURE);
	return (0);
}

/*
 * <cat>memory</cat>
 *
 * <summary>
 * 	void	free_array(char ***array)
 * </summary>
 *
 * <description>
 * 	free_array free all element of the array and set by NULL each element.
 * </description>
 *
 * <param type="char ***" name="array">pointer to the array to free</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */

void	free_array(char ***array)
{
	int	index;

	if (!array || !*array)
		return ;
	index = -1;
	while ((*array)[++index])
	{
		free((*array)[index]);
		(*array)[index] = NULL;
	}
	free(*array);
	*array = NULL;
}
