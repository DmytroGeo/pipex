/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_read_and_write.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeorgiy <dgeorgiy@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 23:42:24 by dgeorgiy          #+#    #+#             */
/*   Updated: 2025/03/06 08:02:08 by dgeorgiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	dup_read_side(int i, int **fd, int *pid, t_list **head)
{
	int		flag1;
	char	**av;
	int		ac;

	ac = (*head)->ac;
	av = (*head)->av;
	if (i == 0)
	{
		proc_call(access(av[1], R_OK), 'a');
		flag1 = open(av[1], O_RDONLY);
		if (flag1 < 0)
		{
			perror(NULL);
			free(pid);
			ft_int_array_free(fd, ac - 4);
			ft_lstclear(head);
			free_and_exit(pid, fd, head);
			exit(EXIT_FAILURE);
		}
		proc_call(dup2(flag1, STDIN_FILENO), 'i');
		close(flag1);
	}
	else
		proc_call(dup2(fd[i - 1][0], STDIN_FILENO), 'i');
	return ;
}

void	dup_write_side(int i, int **fd, int *pid, t_list **head)
{
	int		flag2;
	char	**av;
	int		ac;

	ac = (*head)->ac;
	av = (*head)->av;
	if (i == ac - 4)
	{
		flag2 = open(av[ac - 1], O_CREAT | O_TRUNC | O_WRONLY, 0644);
		if (flag2 < 0)
		{
			perror(NULL);
			free_and_exit(pid, fd, head);
			exit(EXIT_FAILURE);
		}
		proc_call(dup2(flag2, STDOUT_FILENO), 'o');
		close(flag2);
	}
	else
		proc_call(dup2(fd[i][1], STDOUT_FILENO), 'o');
	return ;
}
