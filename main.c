/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeorgiy <dgeorgiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:31:46 by dgeorgiy          #+#    #+#             */
/*   Updated: 2025/03/04 17:08:43 by dgeorgiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// void	print_av(t_list *ptr, int i)
// {
// 	int k = 0;
// 	while ((ptr->av)[k])
// 	{
// 		ft_printf("av[%d] of node %d is %s, ", k, i, (ptr->av)[k]);
// 		k++;
// 	}
// 	ft_printf("\n");
// 	return ;
// }

// void	print_flags(t_list *ptr, int i)
// {
// 	int k = 0;
// 	while ((ptr->flags)[k])
// 	{
// 		ft_printf("Flag %d of node %d is %s, ", k, i, (ptr->flags)[k]);
// 		k++;
// 	}
// 	ft_printf("\n");
// 	return ;
// }

// void	print_list(t_list **data)
// {
// 	t_list	**ptr;
// 	int		i = 0;
// 	ptr = data;
// 	while (*ptr)
// 	{
// 		ft_printf("The ac of node %d is %d\n", i, (*ptr)->ac);
// 		print_av(*ptr, i);
// 		ft_printf("The path of node %d is %s\n", i, (*ptr)->path);
// 		print_flags(*ptr, i);
// 		i++;
// 		(*ptr) = (*ptr)->next;
// 	}
// }

int	main(int ac, char **av, char **envp)
{
	int		*pid;
	int		**fd;
	t_list	*head;
	int		exit_status;

	head = NULL;
	pid = NULL;
	fd = NULL;
	proc_call(ac, 'r');
	init_list(ac, av, envp, &head);
	init_setup(&pid, &fd, ac);
	process_loop(&head, pid, fd);
	close_pipes(fd, ac - 4);
	ft_lstclear(&head);
	ft_int_array_free(fd, ac - 4);
	exit_status = wait_for_processes(pid, ac);
	free(pid);
	// return (WIFEXITED(exit_status) || WEXITSTATUS(exit_status));
	return (WIFEXITED(exit_status));
}
