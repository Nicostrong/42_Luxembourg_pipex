/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 08:42:29 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/06/18 09:51:12 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/*
 *	Standard library
 */

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <fcntl.h>
# include <sys/wait.h>

/*
 *	Personal library
 */

# include "../libft/libft.h"

/*
 *	Externe variable
 */

extern char	**environ;

/*
 * 	struct for pipex
 */

typedef struct s_info
{
	int		nb_cmd;
	int		fd_in;
	int		fd_out;
	char	*file_in;
	char	*file_out;
	char	**path_array;
	char	**cmd_opt_array;
	char	**cmd_array;
	char	**access_path;
}	t_info;

/*
 * ft_check_arg.c
 */

int		ft_check_arg(int argc);

/*
 *	ft_free_info.c
 */

int		ft_free_info(t_info **info, int error);

void	free_array(char ***array);

/*
 *	ft_get_info.c
 */

char	**ft_get_path(char **env);
char	**ft_get_file(int argc, char **argv);
char	**ft_get_cmd_opt(int argc, char **argv);
char	**ft_concat_cmd_path(char **path, char *cmd);
char	**ft_get_only_cmd(char **cmd_option, int nb_cmd);

/*
 *	ft_get_access.c
 */

char	*ft_free_access(char **path, char **access);
char	*ft_concat_path_cmd(t_info *info, int index, char **access_array);

char	**ft_get_access(t_info *info);

/*
 *	ft_init_info.c
 */

int		ft_get_nb_cmd(char **array);

void	ft_get_all_array(t_info **info, int argc, char **argv);

t_info	*ft_init_info(int argc, char **argv);

/*
 *	ft_run_pipex.c
 */

int		ft_run_pipex(t_info *info);
int		ft_create_process(t_info *info);

void	ft_get_fd_in_out(t_info **info);
void	ft_create_pipeline(int *fd, t_info **info);

/*
 *	ft_exec_process.c
 */

int		ft_wait_pid(int pid);
int		ft_exit(t_info *info, int *fd, char *message, int num_error);

void	ft_close_all(t_info *info, int *fd);
void	ft_execute_parent(t_info *info, int *fd);
void	ft_execute_child(t_info *info, int index, int *fd);

#endif
