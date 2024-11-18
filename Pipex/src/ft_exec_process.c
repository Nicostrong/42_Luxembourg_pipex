/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 10:16:21 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/06/18 09:49:44 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

/*
 * <cat>process</cat>
 *
 * <summary>
 * 	void	ft_execute_child(t_info *info, int index, int *fd)
 * </summary>
 *
 * <description>
 * 	ft_execute_child execute each cmd in the child process. read and write on a 
 * 	pipe.
 * </description>
 *
 * <param type="t_info **" name="info">structure info</param>
 * <param type="int" name="index">index of the cmd to excecut</param>
 * <param type="int *" name="fd">pointer to fd variable (fd[2])</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */

void	ft_execute_child(t_info *info, int index, int *fd)
{
	char	**array;

	if (info->fd_in < 0)
		ft_exit(info, fd, "open fd_in: permission denied", 127);
	dup2(info->fd_in, STDIN_FILENO);
	close(info->fd_in);
	if (index == (info->nb_cmd - 1))
	{
		if (info->fd_out < 0)
			ft_exit(info, fd, "open fd_out: permission denied", 1);
		dup2(info->fd_out, STDOUT_FILENO);
		close(info->fd_out);
	}
	else
	{
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		close(info->fd_out);
	}
	close(fd[0]);
	array = ft_split(info->cmd_opt_array[index], ' ');
	execve(info->access_path[index], array, environ);
	free_array(&array);
	ft_exit(info, fd, "execve", 127);
}

/*
 * <cat>process</cat>
 *
 * <summary>
 * 	void	ft_execute_parent(t_info *info, int pid, int *fd)
 * </summary>
 *
 * <description>
 * 	ft_execute_parent execute a parent process. The parent make the reading side
 * 	 of the pipe on the struct info for the child process.
 * </description>
 *
 * <param type="t_info *" name="info">structure info</param>
 * <param type="int" name="pid">pid of the process</param>
 * <param type="int *" name="fd">pointer to fd variable (fd[2])</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */

void	ft_execute_parent(t_info *info, int *fd)
{
	close(fd[1]);
	if (info->fd_in > 0)
		close(info->fd_in);
	info->fd_in = fd[0];
}

/*
 * <cat>process</cat>
 *
 * <summary>
 * 	int	ft_wait_pid(int pid)
 * </summary>
 *
 * <description>
 * 	ft_wait_pid wait all children process will ending.
 * </description>
 *
 * <param type="int" name="pid">pid of the process</param>
 *
 * <return>
 * 	the status value of the last process or the code error.
 * </return>
 *
 */

int	ft_wait_pid(int pid)
{
	int		status_value;
	int		status;

	status_value = -1;
	if (waitpid(pid, &status, 0) > 0)
		if (WIFEXITED(status))
			status_value = WEXITSTATUS(status);
	while (wait(NULL) > 0)
		;
	return (status_value);
}

/*
 * <cat>process</cat>
 *
 * <summary>
 * 	void	ft_close_all(t_info *info, int *fd)
 * </summary>
 *
 * <description>
 * 	ft_close_all close all file descriptor of the pipe and on the info struct.
 * </description>
 *
 * <param type="t_info *" name="info">structure with all info</param>
 * <param type="int *" name="fd">fd of pipe</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */

void	ft_close_all(t_info *info, int *fd)
{
	if (info->fd_in > 0)
		close(info->fd_in);
	if (info->fd_out > 0)
		close(info->fd_out);
	close(fd[0]);
	close(fd[1]);
}

/*
 * <cat>memory/cat>
 *
 * <summary>
 * 	int	ft_exit(t_info *info, int *fd, char *message, int num_error)
 * </summary>
 *
 * <description>
 * 	ft_exit print an error message, close all file descriptor, free the struct 
 * 	info and return the code error.
 * </description>
 *
 * <param type="t_info *" name="info">structure with all info</param>
 * <param type="int *" name="fd">fd of pipe</param>
 * <param type="char *" name="message">message error to print</param>
 * <param type="int" name="num_error">code error sendin with exit</param>
 *
 * <return>
 * 	the status value of the last process or the code error.
 * </return>
 *
 */

int	ft_exit(t_info *info, int *fd, char *message, int num_error)
{
	perror(message);
	ft_close_all(info, fd);
	ft_free_info(&info, 0);
	exit(num_error);
}
