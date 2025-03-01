/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeorgiy <dgeorgiy@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 11:48:53 by dgeorgiy          #+#    #+#             */
/*   Updated: 2025/02/28 15:17:03 by dgeorgiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	execute(int i, char **envp, int *pid, t_list **head)
{
	char	**array;
	int	num_of_flags;
	t_list	*node;
	int		n;

	node = ft_find_node(i, head);
	num_of_flags = ft_array_len(node->flags);
	array = malloc((2 + num_of_flags) * sizeof(char *));
	array[0] = node->path;
	n = 1;
	while (n <= num_of_flags)
	{
		array[n] = (node->flags)[n - 1];
		n++;
	}
	array[n] = NULL;
	if (execve(node->path, array, envp) < 0)
	{
		free(pid);
		ft_lstclear(head);
		exit(EXIT_FAILURE);
	}	
}