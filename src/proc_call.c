/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_call.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeorgiy <dgeorgiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 18:44:18 by dgeorgiy          #+#    #+#             */
/*   Updated: 2025/03/04 09:36:39 by dgeorgiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	proc_call(int i, char c)
{
	if (c == 'r' && i < 4)
	{
		ft_printf("Too few arguments \n");
		// Look into the above line, needs to be redirected to std_err
		exit(EXIT_FAILURE);
	}
	if (c == 'f' && i < 0)
		perror("Couldn't fork \n");
		// Look into this. If fork doesn't work need to kill program.
	else if (c == 'o' && i < 0)
		perror("Can't redirect output \n");
	else if (c == 'i' && i < 0)
		perror("Can't redirect input \n");
	else if (c == 'a' && i < 0)
		perror("Couldn't access file \n");
	return (0);
}
