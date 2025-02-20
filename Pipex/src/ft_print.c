/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:06:57 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/02/20 13:09:32 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

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
		ft_putendl_fd("La liste info n'existe pas !!!", 2);
		return ;
	}
	ft_putendl_fd("==========  number of cmd :  ============", 1);
	ft_putnbr_fd(info->nb_cmd, 1);
	ft_putendl_fd("\n==========  heredoc bool :  =============", 1);
	ft_putnbr_fd(info->here_doc, 1);
	ft_putendl_fd("\n==========  limiter :  ==================", 1);
	if (info->limiter)
		ft_putendl_fd(info->limiter, 1);
	else
		ft_putendl_fd("NULL", 1);
	ft_putendl_fd("==========  File IN :  ==================", 1);
	if (info->file_in)
		ft_putendl_fd(info->file_in, 1);
	else
		ft_putendl_fd("NULL", 1);
	ft_putendl_fd("==========  File OUT :  =================", 1);
	ft_putendl_fd(info->file_out, 1);
	ft_putendl_fd("==========  $PATH :  ====================", 1);
	ft_putstrarray(info->path_array);
	ft_putendl_fd("==========  cmd & opt array :  =========", 1);
	ft_putstrarray(info->cmd_opt_array);
	ft_putendl_fd("==========  md array :  ================", 1);
	ft_putstrarray(info->cmd_array);
	ft_putendl_fd("==========  access path :  ==============", 1);
	ft_putstrarray(info->access_path);
}
