/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_call.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeorgiy <dgeorgiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 18:44:18 by dgeorgiy          #+#    #+#             */
/*   Updated: 2025/03/06 11:50:24 by dgeorgiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	proc_call(int i, char c)
{
	int	p;

	p = 2;
	if (c == 'r' && i < 4)
	{
		ft_putstr_fd("Too few arguments\n", p, &p);
		exit(EXIT_FAILURE);
	}
	else if ((c == 'o' || c == 'i') && i < 0)
		perror(NULL);
	else if (c == 'a' && i < 0)
		perror("Can't access file");
	return (0);
}
