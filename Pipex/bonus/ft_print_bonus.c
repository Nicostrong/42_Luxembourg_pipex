/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:06:57 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/06/17 11:30:13 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

/*
 * <cat>print</cat>
 *
 * <summary>
 * 	void	print_info(t_info *info)
 * </summary>
 *
 * <description>
 * 	ft_print_info print all value inn the struct info.
 * </description>
 *
 * <param type="t_info *" name="info">structure info</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */

void	print_info(t_info *info)
{
	if (!info)
	{
		ft_printf("La liste info n'existe pas !!! \n");
		return ;
	}
	ft_printf("\n==========  number of cmd :  ============\n");
	ft_putnbr_fd(info->nb_cmd, 1);
	ft_printf("\n==========  heredoc bool :  =============\n");
	ft_putnbr_fd(info->here_doc, 1);
	ft_printf("\n==========  limiter :  ==================\n");
	if (info->limiter)
		ft_putstr_fd(info->limiter, 1);
	else
		ft_putstr_fd("NULL", 1);
	ft_printf("\n==========  File IN :  ==================\n");
	if (info->file_in)
		ft_putstr_fd(info->file_in, 1);
	else
		ft_putstr_fd("NULL", 1);
	ft_printf("\n==========  File OUT :  =================\n");
	ft_putstr_fd(info->file_out, 1);
	ft_printf("\n==========  $PATH :  ====================\n");
	ft_putstrarray(info->path_array, 1);
	ft_printf("==========  cmd & opt array :  =========\n");
	ft_putstrarray(info->cmd_opt_array, 1);
	ft_printf("c==========  md array :  ================\n");
	ft_putstrarray(info->cmd_array, 1);
	ft_printf("==========  access path :  ==============\n");
	ft_putstrarray(info->access_path, 1);
}
