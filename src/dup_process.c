/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeorgiy <dgeorgiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 23:42:24 by dgeorgiy          #+#    #+#             */
/*   Updated: 2025/03/04 17:37:54 by dgeorgiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	dup_process(int i, int **fd, t_list **head)
{
	int		flag1;
	int		flag2;
	int 	ac;
	char	**av;
	
	ac = (*head)->ac;
	av = (*head)->av;
	if (i == 0)
	{
		proc_call(access(av[1], R_OK), 'a');
		flag1 = open(av[1], O_RDONLY);
		if (flag1 < 0)
		{
			perror("There's an error opening the infile \n");
			// free and exit
		}
		proc_call(dup2(flag1, STDIN_FILENO), 'i');
		close(flag1);
	}
	else
		proc_call(dup2(fd[i - 1][0], STDIN_FILENO), 'i');
	if (i == ac - 4)
	{
		flag2 = open(av[ac - 1], O_CREAT | O_TRUNC | O_WRONLY, 0644);
		if (flag2 < 0)
		{
			perror("There's an error opening the outfile \n");
			// free and exit
		}
		proc_call(dup2(flag2, STDOUT_FILENO), 'o');
		close(flag2);
	}
	else
		proc_call(dup2(fd[i][1], STDOUT_FILENO), 'o');
	return ;
}