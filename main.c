/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeorgiy <dgeorgiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:31:46 by dgeorgiy          #+#    #+#             */
/*   Updated: 2025/03/03 19:40:32 by dgeorgiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print_list(t_list **data)
{
	t_list	**ptr;
	ptr = data;
	while (*ptr)
	{
		ft_printf("%d\n", (*ptr)->ac);
		ft_printf("%s\n", (*ptr)->path);
		ft_printf("%s\n", (*ptr)->flags);
		(*ptr) = (*ptr)->next;
	}
}

int	main(int ac, char **av, char **envp)
{
	// int		i;
	int		*pid;
	int		(*fd)[2];
	t_list	*head;
	// int		exit_status;

	head = NULL;
	pid = NULL;
	fd = NULL;
	proc_call(ac, 'r');
	init_list(ac, av, envp, &head);
	init_setup(pid, fd, &head);
	print_list(&head);
	// process_loop(&head, pid, fd);
	// close_pipes(fd, ac - 3);
	// ft_lstclear(&head);
	// free(fd);
	// int k = 0;
	// while (k < ac - 3)
	// {
	// 	waitpid(pid[k], &exit_status, 0);
	// 	k++;
	// }
	// free(pid);
	// return (WIFEXITED(exit_status) || WEXITSTATUS(exit_status));
}
