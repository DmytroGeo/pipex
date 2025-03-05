/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_for_processes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeorgiy <dgeorgiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 09:22:55 by dgeorgiy          #+#    #+#             */
/*   Updated: 2025/03/05 14:45:30 by dgeorgiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	wait_for_processes(int *pid, int ac)
{
	int	k;
	int	status;
	int	wpid;

	k = 0;
	while (k < ac - 3)
	{
		wpid = waitpid(pid[k], &status, 0);
		if (wpid == -1)
			free(pid);
		k++;
	}
	if (WIFEXITED(status))
		 return(WEXITSTATUS(status));
	return (status);
}
