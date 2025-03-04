/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_call.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeorgiy <dgeorgiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 18:44:18 by dgeorgiy          #+#    #+#             */
/*   Updated: 2025/03/04 19:59:49 by dgeorgiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	proc_call(int i, char c)
{
	if (c == 'r' && i < 4)
	{
		dup2(STDOUT_FILENO, STDERR_FILENO);
		ft_printf("Too few arguments \n");
		exit(EXIT_FAILURE);
	}
	if (c == 'f' && i < 0)
	{
		perror(NULL);
		// Look into this. If fork doesn't work need to kill program.		
	}
	else if ((c == 'o' || c == 'i' || c == 'a') && i < 0)
		perror(NULL);
	return (0);
}
