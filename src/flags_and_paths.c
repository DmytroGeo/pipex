/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_and_paths.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeorgiy <dgeorgiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:30:41 by dgeorgiy          #+#    #+#             */
/*   Updated: 2025/03/03 19:33:27 by dgeorgiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	**find_path(char **envp)
{
	char	**ptr;

	ptr = envp;
	while (!(ft_strnstr(*ptr, "PATH", ft_strlen(*ptr)) && **ptr == 'P'))
		ptr++;
	if (ptr == NULL)
		return (NULL);
	*ptr += 5;
	return (ptr);
}

char	*get_path(char *str, char **envp)
{
	char	**ptr;
	char	*temp1;
	char	*temp2;
	char	**arr;
	int		i;

	i = -1;
	ptr = find_path(envp);
	if (!ptr)
		return (NULL);
	arr = ft_split(*ptr, ':');
	while (arr[++i])
	{
		temp1 = ft_strjoin(arr[i], "/");
		temp2 = ft_strjoin(temp1, str);
		free(temp1);
		if (access(temp2, F_OK | X_OK) == 0)
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
	int		len;

	i = 0;
	len = ft_array_len(arr);
	if (len < 0)
		return (NULL);
	flags = malloc((len + 1) * sizeof(char *));
	if (!flags)
		return (NULL);
	while (i < len)
	{
		flags[i] = malloc(ft_strlen(arr[i]) + 1);
		// if (!flags[i])
		// 	do something
		flags[i] = ft_strcpy(flags[i], arr[i]);
		i++;
	}
	flags[i] = NULL;
	return (flags);
}
