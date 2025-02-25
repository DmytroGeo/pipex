/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeorgiy <dgeorgiy@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 10:48:20 by dgeorgiy          #+#    #+#             */
/*   Updated: 2025/02/24 22:38:29 by dgeorgiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pipex.h"

// char **get_paths(int ac, char **av, char **envp)
// {
// 		char **ptr = envp;
// 		char **paths = malloc((ac - 2) * sizeof(char *));
// 		while (!(ft_strnstr(*ptr, "PATH", ft_strlen(*ptr)) && **ptr == 'P'))
// 			ptr++;
// 		*ptr += 5;
// 		char **array = ft_split(*ptr, ':');
// 		int flag = 0;
// 		int i = 0;
// 		int k = 0;
// 		char *temp1;
// 		char *temp2;
// 		char **arr;
// 		while (k < ac - 3)
// 		{
// 			while (flag == 0 && array[i])
// 			{                
// 				temp1 = ft_strjoin(array[i], "/");
// 				arr = ft_split(av[k + 2], ' ');
// 				temp2 = ft_strjoin(temp1, arr[0]);
// 				ft_array_free(arr);
// 				free(temp1);
// 				if (access(temp2, F_OK) == 0)
// 					flag = 1;
// 				else
// 				{
// 					free(temp2);
// 					i++;				
// 				}
// 			}
// 			paths[k] = malloc((ft_strlen(temp2) + 1) * sizeof(char));
// 			paths[k] = ft_strcpy(paths[k], temp2);
// 			free(temp2);
// 			i = 0;
// 			flag = 0;
// 			k++;
// 		}
// 		ft_array_free(array);
// 		paths[k] = NULL;
// 		return(paths);    
// }

// char **get_flags(int ac, char **av)
// {
// 	char **flags = malloc((ac - 2) * sizeof(char *));
// 	int k = 0;
// 	char **temp;
// 	while (k < ac - 3)
// 	{
// 		temp = ft_split(av[k + 2], ' ');
// 		if (ft_array_len(temp) < 2)
// 			flags[k] = NULL;
// 		else
// 		{
// 			flags[k] = malloc((ft_strlen(temp[1]) + 1) * sizeof(char));
// 			flags[k] = ft_strcpy(flags[k], temp[1]); // currently only taking one flag; need to account for more than one. Consider ...
// 		}
// 		ft_array_free(temp);
// 		k++;
// 	}
// 	flags[k] = NULL;
// 	return (flags);
// }

// int main(int ac, char **av, char **envp)
// {
// 	if (!envp)
// 		return (0);
// 	if (ac < 2)
// 	{
// 		perror("Not enough arguments");
// 		exit(EXIT_FAILURE);
// 	}
// 	int fd[ac - 2][2];
// 	// int pid[ac - 2];
// 	int i = 0;
// 	while (i < ac - 2)
// 	{
// 		if (pipe(fd[i]) < 0)
// 		{
// 			perror("problem with pipes");
// 			exit(EXIT_FAILURE);
// 		}
// 		i++;
// 	}
// 	int k = 0;
// 	char **paths = get_paths(ac, av, envp);
// 	char **tmp = paths;
// 	while (*tmp)
// 	{
// 		ft_printf("%s\n", *tmp);
// 		tmp++;
// 	}
// 	char **flags = get_flags(ac, av);
// 	ft_array_free(paths);
// 	ft_array_free(flags);
// 	// while (k < ac - 2)
// 	// {
// 	//     pid[k] = fork();
// 	//     if (pid[k] < 0)
// 	//     {
// 	//         perror("Fork failed");
// 	//         exit(EXIT_FAILURE);
// 	//     }            
// 	//     if (pid[k] == 0)
// 	//     {
// 	//         close_pipes();
// 	//         read();
// 	//         dup2();
// 	//         execute();
// 	//         write();
// 	//         close(); // close read end
// 	//         close(); // close write end
// 	//         return (0);
// 	//     }
// 	//     else
// 	//     {
// 	//         close_pipes2();
// 	//         open();
// 	//         write();
// 	//         dup2();
// 	//         read();
// 	//         close(); // close the read end
// 	//         close(); // close the write end
// 	//         wait_for_children();
// 	//         return (0);
// 	//     }
// 	// }
// 	return (0);
// }

int main(int ac, char **av, char **envp)
{
	int p1[2];
	int p2[2];
	if (pipe(p1) < 0)
		return (1);
	if (pipe(p2) < 0)
		return (1);
	int id = fork();
	if (id == 0)
	{
		char *arr[] = {"/usr/bin/wc", "test.txt", NULL};
		int file = dup2(p2[1], 1);
		execve("/usr/bin/wc", arr, envp);
		return 0;
	}
	else 
	{
		int id2 = open("outfile.txt", O_CREAT | O)
		wait(NULL);
	}
	return 0;
}