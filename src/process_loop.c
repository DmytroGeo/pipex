/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeorgiy <dgeorgiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:12:37 by dgeorgiy          #+#    #+#             */
/*   Updated: 2025/03/06 11:43:33 by dgeorgiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	process_loop(t_list **head, int *pid, int **fd)
{
	int		i;
	int		ac;

	i = 0;
	ac = (*head)->ac;
	while (i < ac - 3)
	{
		pid[i] = fork();
		if (pid[i] < 0)
		{
			free_and_exit(pid, fd, head);
			exit(EXIT_FAILURE);
		}
		if (pid[i] == 0)
		{
			dup_read_side(i, fd, pid, head);
			dup_write_side(i, fd, pid, head);
			close_pipes(fd, ac - 4);
			execute(i, fd, pid, head);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}
