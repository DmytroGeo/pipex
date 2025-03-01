/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeorgiy <dgeorgiy@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:31:46 by dgeorgiy          #+#    #+#             */
/*   Updated: 2025/02/28 15:08:33 by dgeorgiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	int		i;
	int		*pid;
	int		*fd[2];
	t_list	*head;

	i = -1;
	head = NULL;
	error_message(ac, 'r');
	(init_list(ac, av, envp, &head), init_setup(ac, pid, fd, &head));
	while (++i < ac - 3)
	{
		pid[i] = fork();
		error_message(pid[i], 'f');
		if (pid[i] == 0)
		{
			dup_process(i, fd, av, ac);
			close_all_pipes(fd, ac - 3);
			execute(i, envp, pid, head);
		}
	}
	(close_all_pipes(fd, ac - 3), ft_lstclear(&head)); // we still do need to free pid but not yet, maybe wait/waitpid needs it.
// wait for the last child.
// output error of the last command.
}
