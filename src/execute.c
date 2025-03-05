/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeorgiy <dgeorgiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 11:48:53 by dgeorgiy          #+#    #+#             */
/*   Updated: 2025/03/05 16:31:23 by dgeorgiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"
#include <string.h>

void	execute(int i, int **fd, int *pid, t_list **head)
{
	char	**array;
	int		num_of_flags;
	t_list	*node;
	int		n;
	char	**envp;

	envp = (*head)->envp;
	node = ft_find_node(i, head);
	num_of_flags = ft_array_len(node->flags);
	array = malloc((2 + num_of_flags) * sizeof(char *));
	array[0] = node->path;
	if (!array[0])
	{
		ft_array_free(array);
		free_and_exit(pid, fd, head);
		exit (127);
	}
	n = 0;
	// while (++n <= num_of_flags)
	// 	array[n] = (node->flags)[n - 1];
	while (n < num_of_flags)
	{
		n++;
		array[n] = (node->flags)[n - 1];		
	}
	array[n] = NULL;
	if (execve(node->path, array, envp) < 0) // look into what needs to happen here
	{
		ft_array_free(array);
		free_and_exit(pid, fd, head);
		return ;
	}
}
