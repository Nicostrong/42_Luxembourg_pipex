/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_arg_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 10:40:44 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/06/18 09:26:23 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

/*
 * <cat>str</cat>
 *
 * <summary>
 * 	int	ft_check_arg_bonus(int argc)
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

int	ft_check_arg_bonus(int argc)
{
	if (argc < 5)
	{
		ft_putendl_fd("Basic usage :", 2);
		ft_putendl_fd("\t./pipex file_in cmd1 cmd2 file_out", 2);
		ft_putendl_fd("Extend usage :", 2);
		ft_putendl_fd("\t./pipex file_in cmd1 cmd2 cmd3 cmd... file_out", 2);
		ft_putendl_fd("Here_doc usage :", 2);
		ft_putendl_fd("\t./pipex \"here_doc\" limiter cmd1 file_out", 2);
		exit(EXIT_FAILURE);
	}
	return (1);
}
