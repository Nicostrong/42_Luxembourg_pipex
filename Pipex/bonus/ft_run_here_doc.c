/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_here_doc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:45:14 by nfordoxc          #+#    #+#             */
/*   Updated: 2025/02/20 14:05:57 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	ft_exit_here_doc(char **line, int *fd)
{
	ft_free((void **)line);
	get_next_line(-1);
	close(fd[1]);
	return ;
}

/*
 * <cat>bash</cat>
 *
 * <summary>
 * 	void	ft_run_here_doc(t_info **info, int *fd)
 * </summary>
 *
 * <description>
 * 	ft_run_here_doc wait the input on STDIN and save all input in a pipe while 
 * 	the string isn't equal to a limiter word.
 * </description>
 *
 * <param type="t_info **" name="info">structure info</param>
 * <param type="int *" name="fd">pointer to fd variable (fd[2])</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */

void	ft_run_here_doc(t_info **info, int *fd)
{
	char	*line;
	size_t	len_limiter;

	if (pipe(fd) < 0)
	{
		perror("pipe");
		ft_free_info(info, 2);
	}
	len_limiter = ft_strlen((*info)->limiter);
	while (1)
	{
		ft_putstr_fd("heredoc> ", 1);
		line = get_next_line(STDIN_FILENO);
		if (line)
		{
			if (!ft_strncmp(line, (*info)->limiter, len_limiter) \
				&& line[len_limiter] == '\n')
				return (ft_exit_here_doc(&line, fd));
			write(fd[1], line, ft_strlen(line));
			ft_free((void **)&line);
		}
		else
			return (ft_exit_here_doc(&line, fd));
	}
}
