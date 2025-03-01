/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_and_paths.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeorgiy <dgeorgiy@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:30:41 by dgeorgiy          #+#    #+#             */
/*   Updated: 2025/02/28 15:42:20 by dgeorgiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*get_path(int ac, char *str, char **envp)
{
	char	**ptr;
	char	*temp2;
	char	**arr;
	int		i;

	ptr = envp;
	i = -1;
	while (!(ft_strnstr(*ptr, "PATH", ft_strlen(*ptr)) && **ptr == 'P'))
		ptr++;
	*ptr += 5;
	arr = ft_split(*ptr, ':');
	while (arr[++i])
	{
		temp2 = ft_strjoin(ft_strjoin(arr[i], "/"), str);
		if (access(temp2, F_OK) == 0)
		{
			ft_array_free(arr);
			return (temp2);
		}
		free(temp2);
	}
	ft_array_free(arr);
	return (NULL);
}

char	**get_flags(char **arr)
{
	char	**flags;
	int		i;

	i = 0;
	while (arr[i])
	{
		flags[i] = malloc(ft_strlen(arr[i]) + 1);
		flags[i] = ft_strcpy(flags[i], arr[i]);
		i++;
	}
	return (flags);
}

// need to check whether I can ft_split from partway through a string.
// also need ot see if/why we need to malloc for **flags