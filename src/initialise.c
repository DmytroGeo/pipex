/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeorgiy <dgeorgiy@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 18:41:49 by dgeorgiy          #+#    #+#             */
/*   Updated: 2025/02/28 15:21:03 by dgeorgiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	init_list(int ac, char **av, char **envp, t_list **head)
{
	int		i;
	t_list	*tmp;
	char	**array;
	char	*path;

	i = ac - 1;
	tmp = NULL;
	while (--i > 1)
	{
		array = ft_split(av[i], ' ');
		path = get_path(ac, array[0], envp);
		if (!path)
			perror("Path not found\n");
		tmp = ft_lstnew(path, get_flags(&array[1]));
		tmp->index = i - 2;
		ft_lstadd_front(head, tmp);
		ft_array_free(array);
	}
	array = NULL;
}

void	init_fd(int ac, int fd[][2], t_list **head)
{
	// need to look into this.
}

void	init_pid(int ac, int *pid)
{
	pid = malloc((ac - 3) * sizeof(int));
	return ; 
}

void	init_pipes(int ac, int fd[][2])
{
	int	i;

	i = 0;
	while (i < ac - 3)
	{
		if (pipe(fd[i]) < 0)
			perror("Piping didn't work \n");
		i++;
	}
	return ;
}

// Looks into how init_pid works with init_pipes:

void	init_setup(int ac, int *pid, int fd[][2], t_list **head)
{
	return (init_pid(ac, pid), init_fd(ac, fd, head), init_pipes(ac, fd));
}
