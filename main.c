/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeorgiy <dgeorgiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:30:47 by dgeorgiy          #+#    #+#             */
/*   Updated: 2025/02/22 18:01:57 by dgeorgiy         ###   ########.fr       */
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
		char **ptr = envp;
		while (!(ft_strnstr(*ptr, "PATH", ft_strlen(*ptr)) && **ptr == 'P'))
			ptr++;
		*ptr += 5;
		char **array = ft_split(*ptr, ':'); // remember to free at some point
		int flag = 0;
		int i = 0;
		char *str1;
		char *str2;
		while (flag == 0 && array[i])
		{
			str1 = ft_strjoin(array[i], "/");			
			str2 = ft_strjoin(str1, av[2]); // remember to free if we haven't found the right thing.
			if (access(str2, F_OK) == 0)
				flag = 1;
			else
				i++;
		}
		if (flag == 1)
			ft_printf("%s\n", str2);
		else 
			ft_printf("Not Found");
		// while (*array)
		// {
		// 	ft_printf("%s\n", *array);
		// 	array++;
		// }
		// Use another loop to strjoin av[2] to each string from ft_split
		// Then use access() to check which link works, and then use that one.
		// remember that ft_split and ft_strjoin use malloc so free them. 
		// store the right path in str.
		// char *arr[] = {str, av[1], "-w", NULL}; // the correct index for envp is 24.
		// if (execve(str, arr, envp) < 0)
		// {
		// 	perror("The execution failed \n");
		// 	exit(EXIT_FAILURE);		
		// }
		return (0);
	}
	else 
	{
		waitpid(id, NULL, 0);
	}

	return 0;
}