/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:16:51 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/06/18 09:49:02 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

/*
 * <cat>program</cat>
 *
 * <summary>
 *	pipex
 * </summary>
 *
 * <description>
 *	pipex make the same thing like a pipe in bash. It can be running like 
 *	this :
 *	./pipex file_in "cmd1 opt1 opt2 opt3" file_out
 * </description>
 *
 * <param type="int" name="argc">number of arguments</param>
 * <param type="char **" name="argv">list of integer to sort</param>
 *
 * <return>
 *	create a file with the name in argument with the return of all cmd passed in
 *	 argument.
 * </return>
 *
 */

int	main(int argc, char **argv)
{
	t_info	*info;
	int		status;

	ft_check_arg(argc);
	info = ft_init_info(argc, argv);
	status = ft_run_pipex(info);
	ft_free_info(&info, 0);
	return (status);
}
