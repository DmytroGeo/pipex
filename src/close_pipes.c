/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_pipes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeorgiy <dgeorgiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 22:39:29 by dgeorgiy          #+#    #+#             */
/*   Updated: 2025/03/04 13:38:39 by dgeorgiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

// void	close_pipes(int (*fd)[2], int len)
// {
// 	int	i;

// 	i = 0;
// 	while (i < len)
// 	{
// 		if (fd[i][0] != -1)
// 		{
// 			close(fd[i][0]);
// 			fd[i][0] = -1;
// 		}
// 		if (fd[i][1] != -1)
// 		{
// 			close(fd[i][1]);
// 			fd[i][1] = -1;
// 		}
// 		i++;
// 	}
// 	return ;
// }

void	close_pipes(int **fd, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		close(fd[i][0]);
		close(fd[i][1]);
		i++;
	}
	return ;
}
