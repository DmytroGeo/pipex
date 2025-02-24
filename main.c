/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeorgiy <dgeorgiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 10:48:20 by dgeorgiy          #+#    #+#             */
/*   Updated: 2025/02/24 12:46:36 by dgeorgiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pipex.h"

char **get_paths(int ac, char **av, char **envp)
{
		char **ptr = envp;
        char **paths = malloc((ac - 1) * sizeof(char *));
		while (!(ft_strnstr(*ptr, "PATH", ft_strlen(*ptr)) && **ptr == 'P'))
			ptr++;
		*ptr += 5;
		char **array = ft_split(*ptr, ':'); // remember to free at some point
		int flag = 0;
		int i = 0;
        int k = 0;
		char *temp1;
        char *temp2;
        while (k < ac - 1)
        {
            while (flag == 0 && array[i])
            {
                temp1 = ft_strjoin(array[i], "/");			
                temp2 = ft_strjoin(temp1, av[k + 2]);
                // free(temp); // remember to free if we haven't found the right thing.
                if (access(temp2, F_OK) == 0)
                    flag = 1;
                else
                {
                    // free(str2);
                    i++;				
                }
            }
            // if (flag == 0)
            // {
            //     perror("couldn't find command");
            //     // free(str2);
            //     exit(EXIT_FAILURE);
            // }
            paths[k] = ft_memcpy(paths[k], temp2, ft_strlen(temp2));
            free(temp1);
            free(temp2);
            i = 0;
            k++;
            
        }
        ft_array_free(array);
        paths[k] = NULL;
        return(paths);    
}

int main(int ac, char **av, char **envp)
{
    if (ac < 5)
    {
        perror("Not enough arguments");
        exit(EXIT_FAILURE);
    }
    int fd[ac - 2][2];
    // int pid[ac - 2];
    int i = 0;
    while (i < ac - 2)
    {
        if (pipe(fd[i]) < 0)
        {
            perror("problem with pipes");
            exit(EXIT_FAILURE);
        }
        i++;
    }
    // int k = 0;
    char **paths = get_paths(ac, av, envp);
    // char **flags = get_flags(ac, av, envp);
    char **temp = paths;
    while (temp)
    {
        ft_printf("%s\n", *temp);
        temp++;
    }
    // while (k < ac - 2)
    // {
    //     pid[k] = fork();
    //     if (pid[k] < 0)
    //     {
    //         perror("Fork failed");
    //         exit(EXIT_FAILURE);
    //     }            
    //     if (pid[k] == 0)
    //     {
    //         close_pipes();
    //         read();
    //         dup2();
    //         execute();
    //         write();
    //         close(); // close read end
    //         close(); // close write end
    //         return (0);
    //     }
    //     else
    //     {
    //         close_pipes2();
    //         open();
    //         write();
    //         dup2();
    //         read();
    //         close(); // close the read end
    //         close(); // close the write end
    //         wait_for_children();
    //         return (0);
    //     }
    // }
    return (0);
}