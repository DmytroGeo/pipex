/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeorgiy <dgeorgiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 10:48:20 by dgeorgiy          #+#    #+#             */
/*   Updated: 2025/02/25 16:13:14 by dgeorgiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pipex.h"

// There are still several things to do. For starters, error checking/

char **get_paths(int ac, char **av, char **envp)
{
		char **ptr = envp;
		char **paths = malloc((ac - 2) * sizeof(char *));
		while (!(ft_strnstr(*ptr, "PATH", ft_strlen(*ptr)) && **ptr == 'P'))
			ptr++;
		*ptr += 5;
		char **array = ft_split(*ptr, ':');
		int flag = 0;
		int i = 0;
		int k = 0;
		char *temp1;
		char *temp2;
		char **arr;
		while (k < ac - 3)
		{
			while (flag == 0 && array[i])
			{                
				temp1 = ft_strjoin(array[i], "/");
				arr = ft_split(av[k + 2], ' ');
				temp2 = ft_strjoin(temp1, arr[0]);
				ft_array_free(arr);
				free(temp1);
				if (access(temp2, F_OK) == 0)
					flag = 1;
				else
				{
					free(temp2);
					i++;				
				}
			}
			paths[k] = malloc((ft_strlen(temp2) + 1) * sizeof(char));
			paths[k] = ft_strcpy(paths[k], temp2);
			free(temp2);
			i = 0;
			flag = 0;
			k++;
		}
		ft_array_free(array);
		paths[k] = NULL;
		return(paths);    
}

char **get_flags(int ac, char **av)
{
	char **flags = malloc((ac - 2) * sizeof(char *));
	int k = 0;
	char **temp;
	while (k < ac - 3)
	{
		temp = ft_split(av[k + 2], ' ');
		if (ft_array_len(temp) < 2)
			flags[k] = NULL;
		else
		{
			flags[k] = malloc((ft_strlen(temp[1]) + 1) * sizeof(char));
			flags[k] = ft_strcpy(flags[k], temp[1]); // currently only taking one flag; need to account for more than one. Consider ...
		}
		ft_array_free(temp);
		k++;
	}
	flags[k] = NULL;
	return (flags);
}

int main(int ac, char **av, char **envp)
{
	if (!envp)
		return (0);
	if (ac < 5)
	{
		perror("Not enough arguments");
		exit(EXIT_FAILURE);
	}
	int fd[ac - 3][2]; // for pipes
	int pid[ac - 2]; // for children
	int i = 0;
	int k = 0;
	char **paths = get_paths(ac, av, envp);
	char **flags = get_flags(ac, av);
	while (k < ac - 3)
	{
		pid[k] = fork();
		if (pid[k] < 0)
			perror("fork didn't work \n");
		if (pid[k] == 0)
		{
			if (k == 0)
			{
				if (access(av[1], R_OK) < 0)
					perror("couldn't access \n");		
				int flag = open(av[1], O_RDONLY);
				if (flag < 0)
					perror("There's an opening the file \n");
				if (dup2(flag, STDIN_FILENO) < 0)
					perror("Can't redirect \n");
				if (dup2(fd[k][1], STDOUT_FILENO) < 0)
					perror("Can't redirect \n");
			}
			else if (k == ac - 4)
			{
				if (dup2(fd[k - 1][0], STDIN_FILENO) < 0)
					perror("Can't redirect \n");
				int flag = open(av[ac - 1], O_CREAT | O_TRUNC | O_WRONLY, 0777);
				if (dup2(flag, STDOUT_FILENO) < 0) 
					perror("Can't redirect \n");			
			}
			else
			{
				if (dup2(fd[k - 1][0], STDIN_FILENO) < 0) 
					perror("Can't redirect \n");
				if (dup2(fd[k][1], STDOUT_FILENO) < 0)
					perror("Can't redirect \n");
			}
			char *arr[] = {paths[k], flags[k], NULL}; // this line is wrong as you can have many flags. Fill in with loop
			// close all fds
			if (execve(paths[k], arr, envp) < 0)
			{
				// free resources
				exit(EXIT_FAILURE);
			}
		}
		k++; 
	}
	// close all fds
	waitpid(pid[k - 1], NULL, 0); // this line is also wrong. I need to output the error of the last command.
}
// experiment 2
// int main(int ac, char **av, char **envp)
// {
// 	int id = fork();
// 	if (id == 0)
// 	{
// 		int file = open("outfile.txt", O_RDWR | O_CREAT, 0777);	
// 		dup2(file, STDOUT_FILENO);
// 		char *arr[] = {"/usr/bin/wc", "test.txt", "-w", NULL};
// 		execve("/usr/bin/wc", arr, envp);
// 		return 0;
// 	}
// 	else 
// 	{
// 		wait(NULL);
// 	}
// 	return 0;
// }

// experiment 3