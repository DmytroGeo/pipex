/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeorgiy <dgeorgiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 14:28:57 by dgeorgiy          #+#    #+#             */
/*   Updated: 2025/03/03 14:44:30 by dgeorgiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_find_node(int i, t_list **head)
{
	t_list	**temp;

	temp = head;
	if (!temp || !*temp)
		return (NULL);
	while ((*temp)->index != i && (*temp))
		(*temp) = (*temp)->next;
	return (*temp);
}
