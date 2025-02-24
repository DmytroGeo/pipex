/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeorgiy <dgeorgiy@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:30:47 by dgeorgiy          #+#    #+#             */
/*   Updated: 2025/02/22 21:36:05 by dgeorgiy         ###   ########.fr       */
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
	if (ac < 2)
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
		char **ptr = envp;
		while (!(ft_strnstr(*ptr, "PATH", ft_strlen(*ptr)) && **ptr == 'P'))
			ptr++;
		*ptr += 5;
		char **array = ft_split(*ptr, ':'); // remember to free at some point
		int flag = 0;
		int i = 0;
		char *temp;
		char *str2;
		while (flag == 0 && array[i])
		{
			temp = ft_strjoin(array[i], "/");			
			str2 = ft_strjoin(temp, av[2]); // remember to free if we haven't found the right thing.
			if (access(str2, F_OK) == 0)
				flag = 1;
			else
			{
				free(temp);
				free(str2);
				i++;				
			}

		}
		free(temp);
		ft_array_free(array);
		if (flag == 0)
		{
			perror("Command not found");
			return (0);
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