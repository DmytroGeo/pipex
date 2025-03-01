/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_call.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeorgiy <dgeorgiy@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 18:44:18 by dgeorgiy          #+#    #+#             */
/*   Updated: 2025/02/28 11:44:35 by dgeorgiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	proc_call(int i, char c)
{
	if (c == 'r' && i < 5)
	{
		ft_putstr_fd("Too few arguments \n", 2, 0);
		exit(EXIT_FAILURE);
	}
	if (c == 'f' && i < 0)
		perror("Couldn't fork \n");
	else if (c == 'o' && i < 0)
		perror("Can't redirect output \n");
	else if (c == 'i' && i < 0)
		perror("Can't redirect input \n");
	else if (c == 'a' && i < 0)
		perror("Couldn't access file \n");
	return (0);
}
