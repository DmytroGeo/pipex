/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeorgiy <dgeorgiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 10:22:22 by dgeorgiy          #+#    #+#             */
/*   Updated: 2025/03/06 10:42:48 by dgeorgiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_free(char **ptr, size_t k)
{
	size_t	j;

	j = 0;
	while (j < k)
	{
		free(ptr[j]);
		j++;
	}
	free(ptr);
	return (NULL);
}
