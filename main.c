/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeorgiy <dgeorgiy@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 12:12:58 by dgeorgiy          #+#    #+#             */
/*   Updated: 2025/02/16 15:08:26 by dgeorgiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// int	main(void)
// {
// 	int id = fork();
// 	int n;
// 	if (id == 0) // child process
// 	{
// 		n = 1;
// 	}
// 	else // main process
// 	{
// 		n = 6;
// 	}
// 	if (id != 0)
// 	{
// 		wait(&id); // wait for the child process
// 		// ft_printf("\n");
// 	}
// 	int i;
// 	for (i = n; i < n + 5; i++)
// 	{
// 		ft_printf("%d ", i);
// 		fflush(stdout);
// 	}
// 	if (id != 0)
//  		ft_printf("\n");
// 	return (0);
// }

// int	main(void)
// {
// 	int id = fork();
// 	if (id == 0)
// 	{
// 		sleep(0.1);
// 	}
// 	int res = wait(NULL);
// 	if (res == -1)
// 		ft_printf("No childrent to wait for \n");
// 	else 
// 		ft_printf("%d finished execution \n ", res);
// 	ft_printf("Current ID : %d, Parent ID : %d \n", id, getpid(), getppid());
// 	return (0);
// }

int main(void)
{
	int id1 = fork();
	int id2 = fork();
	if (id1 == 0)
	{
		if (id2 == 0)
		{
			ft_printf("We are process y \n");
		}
		else 
		{
			ft_printf("We are process x \n");
		}
	}
	else 
	{
		if (id2 == 0)
		{
			ft_printf("We are process z \n");
		}
		else 
		{
			wait(&id1);
			ft_printf("we are the parent process \n");
		}
	}
	while (wait(NULL) != -1 || errno != ECHILD)
	{
		ft_printf("waited for child to finish \n");
	}
	return (0);
}
