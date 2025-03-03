/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeorgiy <dgeorgiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 11:49:18 by dgeorgiy          #+#    #+#             */
/*   Updated: 2025/03/03 14:41:03 by dgeorgiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	k;
	char	*b;
	char	*l;

	k = 0;
	b = (char *)big;
	l = (char *)little;
	if (!*b || !b)
	{
		if (!*l || !l)
			return (b);
		return (NULL);
	}
	else
	{
		while (len - k >= ft_strlen(l))
		{
			if (ft_strncmp(b + k, l, ft_strlen(l)) == 0)
				return (b + k);
			k++;
		}
	}
	return (NULL);
}
