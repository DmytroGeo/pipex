/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeorgiy <dgeorgiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:30:47 by dgeorgiy          #+#    #+#             */
/*   Updated: 2025/02/24 11:32:29 by dgeorgiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int ac, char **av, char **envp)
{
	// int id = fork();
	// if (id < 0)
	// {
	// 	perror("The fork failed \n");
	// 	exit(EXIT_FAILURE);		
	// }
	if (id == 0)
	{

		if (flag == 0)
		{
			perror("Command not found");
			free(str2);
			return (EXIT_FAILURE);
		}
		int j = open(av[ac - 1], O_CREAT | O_RDWR, 0777);
		int file = dup2(j, STDOUT_FILENO);
		if (file < 0)
		{
			perror("Something wrong with file");
			free(str2);
			return (EXIT_FAILURE);			
		}
		char *arr[] = {str2, av[1], NULL};
		if (execve(str2, arr, envp) == -1)
		{
			exit(EXIT_FAILURE);
		}
		return (0);
	}
	else 
	{
		waitpid(id, NULL, 0);
	}

	return 0;
}