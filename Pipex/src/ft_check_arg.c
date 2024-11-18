/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:52:51 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/06/18 09:49:50 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

/*
 * <cat>str</cat>
 *
 * <summary>
 * 	int	ft_check_arg(int argc)
 * </summary>
 *
 * <description>
 * 	ft_check_arg check the number of argument passed at the program.
 * </description>
 *
 * <param type="int" name="argc">number of arguments</param>
 *
 * <return>
 * 	0 if error.
 * 	1 if no error.
 * </return>
 *
 */

int	ft_check_arg(int argc)
{
	if (argc != 5)
	{
		ft_putendl_fd("Basic usage :", 2);
		ft_putendl_fd("\t./pipex file_in cmd1 cmd2 file_out", 2);
		exit(EXIT_FAILURE);
	}
	return (1);
}
