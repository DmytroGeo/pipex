/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeorgiy <dgeorgiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 19:29:36 by dgeorgiy          #+#    #+#             */
/*   Updated: 2025/03/05 12:49:24 by dgeorgiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	free_and_exit(int *pid, int **fd, t_list **head)
{
	int		ac;

	if (!fd)
		return ;
	ac = (*head)->ac;
	free(pid);
	ft_int_array_free(fd, ac - 4);
	ft_lstclear(head);
	return ;
}
