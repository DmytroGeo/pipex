/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeorgiy <dgeorgiy@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:54:09 by dgeorgiy          #+#    #+#             */
/*   Updated: 2025/02/28 15:06:30 by dgeorgiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <errno.h>
# include <fcntl.h>

void	close_all_pipes(int fd[][2], int len);
int		proc_call(int i, char c);
char	*get_path(int ac, char *str, char **envp);
char	**get_flags(char **arr);
void	init_list(int ac, char **av, char **envp, t_list **head);
void	init_setup(int ac, int *pid, int fd[][2], t_list **head);
void	dup_process(int i, int fd[][2], char **av, int ac);
void	execute(int i, char **envp, int *pid, t_list **head);
#endif