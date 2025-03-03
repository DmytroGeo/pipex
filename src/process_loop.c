/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeorgiy <dgeorgiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:12:37 by dgeorgiy          #+#    #+#             */
/*   Updated: 2025/03/03 19:38:27 by dgeorgiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	process_loop(t_list **head, int *pid, int (*fd)[2])
{
	int		i;

	i = 0;
	while (i < (*head)->ac - 3)
	{
		pid[i] = fork();
		proc_call(pid[i], 'f');
		if (pid[i] == 0)
		{
			dup_process(i, fd, (*head)->av, (*head)->ac);
			close_pipes(fd, (*head)->ac - 3);
			execute(i, fd, pid, head);
			exit(EXIT_FAILURE); // if execute didn't work.
		}
		i++;
	}
}
