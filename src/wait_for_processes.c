/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_for_processes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeorgiy <dgeorgiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 09:22:55 by dgeorgiy          #+#    #+#             */
/*   Updated: 2025/03/04 17:50:48 by dgeorgiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h" 

// I need to output the error code of the last command. I don't know how to do that yet.

// int	wait_for_processes(int *pid, int ac)
// {
// 	int	k;
// 	int	exit_status;

// 	k = 0;
// 	exit_status = 0;
// 	while (k < ac - 3)
// 	{
// 		waitpid(pid[k], &exit_status, 0);
// 		k++;
// 	}
// 	return (exit_status);
// }

int	wait_for_processes(int *pid, int ac)
{
	int	exit_status;
	exit_status = waitpid(pid[ac - 4], &exit_status, 0);
	return (exit_status);
}
