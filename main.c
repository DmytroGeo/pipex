/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeorgiy <dgeorgiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:30:47 by dgeorgiy          #+#    #+#             */
/*   Updated: 2025/02/22 16:01:14 by dgeorgiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int ac, char **av, char **envp)
{
	int fd[2];
	if (pipe(fd) == -1)
	{
		perror("The pipe failed \n");
		exit(EXIT_FAILURE);
	}
	if (ac < 1)
	{
		perror("Not enough parameters \n");
		exit(EXIT_FAILURE);
	}
	if (av == NULL)
	{
		perror("Not a valid argument \n");
		exit(EXIT_FAILURE);
	}
	int id = fork();
	if (id < 0)
	{
		perror("The fork failed \n");
		exit(EXIT_FAILURE);		
	}
	if (id == 0)
	{
		// loop over envp until you find the bit that goes "PATH=...".
		//	Then use ft_split on the line using ':' as a delimiter.
		// Use another loop to strjoin av[2] to eacch string from ft_split
		// Then use access() to check which link works, and then use that one.
		// remember that ft_split and ft_strjoin use malloc so free them. 
		// store the right path in str.
		char *arr[] = {str, av[1], "-w", NULL}; // the correct index for envp is 24.
		if (execve(str, arr, envp) < 0)
		{
			perror("The execution failed \n");
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