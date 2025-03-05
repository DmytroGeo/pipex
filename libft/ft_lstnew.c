/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeorgiy <dgeorgiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:26:13 by dgeorgiy          #+#    #+#             */
/*   Updated: 2025/03/05 11:31:39 by dgeorgiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(char *pa, char **fl)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->path = pa;
	new_node->flags = fl;
	new_node->next = NULL;
	new_node->ac = 0;
	new_node->index = 0;
	new_node->av = NULL;
	new_node->envp = NULL;
	return (new_node);
}
