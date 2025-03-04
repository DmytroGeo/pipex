/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeorgiy <dgeorgiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 18:41:49 by dgeorgiy          #+#    #+#             */
/*   Updated: 2025/03/04 19:02:12 by dgeorgiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	init_list(int ac, char **av, char **envp, t_list **head)
{
	int		i;
	t_list	*temp;
	char	**array;
	char	*path;

	i = ac - 1;
	temp = NULL;
	while (i > 2)
	{
		i--;
		array = ft_split(av[i], ' ');
		path = get_path(array[0], envp);
		if (!path)
			perror(NULL);
		temp = ft_lstnew(path, get_flags(&array[1]));
		temp->index = i - 2;
		temp->ac = ac;
		temp->envp = envp;
		temp->av = av;
		ft_lstadd_front(head, temp);
		ft_array_free(array);
	}
	array = NULL;
}

void	init_setup(int **pid, int ***fd, int ac)
{
	int	i;

	i = 0;
	*pid = malloc((ac - 3) * sizeof(int));
	if (!pid)
		return ;
	*fd = malloc((ac - 4) * sizeof(int *));
	if (!fd)
		return ;
	while (i < ac - 4)
	{
		(*fd)[i] = malloc(2 * sizeof(int));
		if (pipe((*fd)[i]) < 0)
		{
			perror(NULL);
			close_pipes(*fd, i + 1);
			return ;
		}
		i++;
	}
}