/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeorgiy <dgeorgiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 18:41:49 by dgeorgiy          #+#    #+#             */
/*   Updated: 2025/03/03 19:33:45 by dgeorgiy         ###   ########.fr       */
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
	while (i > 2)
	{
		i--;
		array = ft_split(av[i], ' ');
		path = get_path(array[0], envp);
		if (!path)
			perror("Path not found\n");
		tmp = ft_lstnew(path, get_flags(&array[1]));
		tmp->index = i - 2;
		tmp->ac = ac;
		tmp->envp = envp;
		tmp->av = av;
		ft_lstadd_front(head, tmp);
		ft_array_free(array);
	}
	array = NULL;
}

void	init_setup(int *pid, int (*fd)[2], t_list **head)
{
	int	ac;
	int	i;

	i = 0;
	ac = (*head)->ac;
	pid = malloc((ac - 3) * sizeof(int));
	if (!pid)
		return ;
	fd = malloc((ac - 3) * sizeof(int) * 2);
	if (!pid)
		return ;
	while (i < ac - 3)
	{
		if (pipe(fd[i]) < 0)
		{
			perror("Piping didn't work \n");
			close_pipes(fd, i + 1);
			return ;
		}
		i++;
	}
}
