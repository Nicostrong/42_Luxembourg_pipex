/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_pipex_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 09:31:41 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/06/18 09:24:41 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

/*
 * <cat>bash</cat>
 *
 * <summary>
 * 	void	ft_run_pipex(t_info *info)
 * </summary>
 *
 * <description>
 * 	ft_run_pipex execute all bash command in the struct info and create an 
 * 	output file with the result.
 * </description>
 *
 * <param type="t_info *" name="info">structure info</param>
 *
 * <return>
 * 	void but create a file with the return of the last bash command.
 * </return>
 *
 */

int	ft_run_pipex(t_info *info)
{
	int		index;
	int		fd[2];
	int		pid;
	int		last_pid;

	ft_get_fd_in_out(&info, fd);
	index = -1;
	last_pid = 0;
	while (++index < info->nb_cmd)
	{
		if (index < (info->nb_cmd - 1))
			ft_create_pipeline(fd, &info);
		pid = ft_create_process(info);
		if (pid == 0)
			ft_execute_child(info, index, fd);
		else
		{
			last_pid = pid;
			ft_execute_parent(info, fd);
		}
	}
	close(info->fd_in);
	close(info->fd_out);
	return (ft_wait_pid(last_pid));
}

/*
 * <cat>list</cat>
 *
 * <summary>
 * 	void	ft_get_fd_in_out(t_info **info, int *fd)
 * </summary>
 *
 * <description>
 * 	ft_get_fd_in_out open the source file and the destination file and save each
 * 	 file descriptor on the struct.
 * </description>
 *
 * <param type="t_info **" name="info">structure info</param>
 * <param type="int *" name="fd">pointer to fd variable (fd[2])</param>
 *
 * <return>
 * 	void but set the structure with the file descriptor.
 * </return>
 *
 */

void	ft_get_fd_in_out(t_info **info, int *fd)
{
	int	fd_out;

	if ((*info)->here_doc == 1)
	{
		ft_run_here_doc(info, fd);
		(*info)->fd_in = fd[0];
	}
	else
		(*info)->fd_in = open((*info)->file_in, O_RDONLY);
	if ((*info)->here_doc)
		fd_out = open((*info)->file_out, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		fd_out = open((*info)->file_out, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	(*info)->fd_out = fd_out;
}

/*
 * <cat>bash</cat>
 *
 * <summary>
 * 	void	ft_create_pipeline(int *fd, t_info **info)
 * </summary>
 *
 * <description>
 * 	ft_create_pipeline create a pipeline with the function pipe.
 * </description>
 *
 * <param type="int *" name="fd">pointer to fd variable (fd[2])</param>
 * <param type="t_info **" name="info">structure info</param>
 *
 * <return>
 * 	void but set the array fd.
 * </return>
 *
 */

void	ft_create_pipeline(int *fd, t_info **info)
{
	if (pipe(fd) < 0)
	{
		perror("pipe");
		ft_free_info(info, 2);
	}
}

/*
 * <cat>bash</cat>
 *
 * <summary>
 * 	int	ft_create_process(t_info *info)
 * </summary>
 *
 * <description>
 * 	ft_create_process create a child process.
 * </description>
 *
 * <param type="t_info *" name="info">structure info</param>
 *
 * <return>
 * 	the pid of the process.
 * </return>
 *
 */

int	ft_create_process(t_info *info)
{
	int	pid;

	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		ft_free_info(&info, 1);
	}
	return (pid);
}
