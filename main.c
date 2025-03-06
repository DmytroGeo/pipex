/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeorgiy <dgeorgiy@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:31:46 by dgeorgiy          #+#    #+#             */
/*   Updated: 2025/03/06 08:17:47 by dgeorgiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// Everything seems to work fine no memory leaks, get Alonso to try and break it. 
// Also, make sure that every malloc has a check after.
// Also, make sure you get the correct message if one of the commans is invalid
// also see comments

int	main(int ac, char **av, char **envp)
{
	int		*pid;
	int		**fd;
	t_list	*head;
	int		exit_status;

	head = NULL;
	pid = NULL;
	fd = NULL;
	proc_call(ac, 'r');
	init_list(ac, av, envp, &head);
	init_setup(&pid, &fd, ac);
	process_loop(&head, pid, fd);
	close_pipes(fd, ac - 4);
	ft_lstclear(&head);
	ft_int_array_free(fd, ac - 4);
	exit_status = wait_for_processes(pid, ac);
	free(pid);
	return (exit_status);
}
