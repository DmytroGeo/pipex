/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_array_free.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeorgiy <dgeorgiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:45:54 by dgeorgiy          #+#    #+#             */
/*   Updated: 2025/03/04 19:59:00 by dgeorgiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_int_array_free(int **fd, int len)
{
	int	i;

	i = 0;
	if (!fd)
		return ;
	while (i < len)
	{
		free(fd[i]);
		i++;
	}
	free(fd);
}
