/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeorgiy <dgeorgiy@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 23:42:24 by dgeorgiy          #+#    #+#             */
/*   Updated: 2025/02/28 11:44:17 by dgeorgiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	dup_process(int i, int fd[][2], char **av, int ac)
{
	int	flag1;
	int	flag2;

	if (i == 0)
	{
		proc_call(access(av[1], R_OK), 'a');
		flag1 = open(av[1], O_RDONLY);
		if (flag1 < 0)
			perror("There's an erorr opening the infile \n");
		proc_call((flag1, STDIN_FILENO), 'i');
	}
	else
		proc_call(dup2(fd[i - 1][0], STDIN_FILENO), 'i');
	if (i == ac - 4)
	{
		flag2 = open(av[ac - 1], O_CREAT | O_TRUNC | O_WRONLY, 0777);
		if (flag2 < 0)
			perror("There's an error opening the outfile \n");
		proc_call(dup2(flag2, STDOUT_FILENO), 'o');
	}
	else
		proc_call(dup2(fd[i][1], STDOUT_FILENO), 'o');
	return ;
}
