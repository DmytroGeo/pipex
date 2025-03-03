/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeorgiy <dgeorgiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:23:55 by dgeorgiy          #+#    #+#             */
/*   Updated: 2025/03/03 17:36:21 by dgeorgiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_array_len(char **array)
{
	int		n;
	char	**ptr;

	n = 0;
	ptr = array;
	if (!ptr)
		return (-1);
	while (ptr[n] != NULL)
		n++;
	return (n);
}
