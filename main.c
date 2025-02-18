/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeorgiy <dgeorgiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 12:12:58 by dgeorgiy          #+#    #+#             */
/*   Updated: 2025/02/18 18:00:41 by dgeorgiy         ###   ########.fr       */
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

// int main(void)
// {
// 	int id1 = fork();
// 	int id2 = fork();
// 	if (id1 == 0)
// 	{
// 		if (id2 == 0)
// 		{
// 			ft_printf("We are process y \n");
// 		}
// 		else 
// 		{
// 			ft_printf("We are process x \n");
// 		}
// 	}
// 	else 
// 	{
// 		if (id2 == 0)
// 		{
// 			ft_printf("We are process z \n");
// 		}
// 		else 
// 		{
// 			wait(&id1);
// 			ft_printf("we are the parent process \n");
// 		}
// 	}
// 	while (wait(NULL) != -1 || errno != ECHILD)
// 	{
// 		ft_printf("waited for child to finish \n");
// 	}
// 	return (0);
// }

// int	main(void)
// {
// 	int id1 = fork();
// 	int id2 = fork();
// 	if (id1 != 0)
// 		wait(NULL);
// 	if (id2 != 0)
// 		wait(NULL);
// 	ft_printf("My ID1 is %d and my ID2 is %d.\nMy PID is: %d and my PPID is: %d \n", id1, id2, getpid(), getppid());
// 	return (0);
// }

// int	main(void)
// {
// 	int fd[2];
// 	// fd[0] is the read end
// 	// fd[1] is the write end
// 	if (pipe(fd) == -1)
// 	{
// 		ft_printf("Error \n");
// 		return (1);		
// 	}
// 	int id = fork();
// 	if (id == -1)
// 	{
// 		ft_printf("The fork had an error \n");
// 		return (5);
// 	}
// 	if (id == 0)
// 	{
// 		close (fd[0]);
// 		int x;
// 		ft_printf("input : ");
// 		scanf("%d", &x);
// 		if (write(fd[1], &x, sizeof(int)) == -1)
// 		{
// 			ft_printf("Error \n");
// 			return (2);			
// 		}
// 		close(fd[1]);
// 	}
// 	else 
// 	{
// 		close (fd[1]);
// 		int y;
// 		if (read(fd[0], &y, sizeof(int)) == -1)
// 		{
// 			ft_printf("Error \n");
// 			return (3);			
// 		}
// 		close(fd[0]);
// 		y -= 42;
// 		ft_printf("Got from child process : %d \n", y);		
// 	}
// 	return (0);
// }

// int	main()
// {
// 	int arr[] = { 1, 2, 3, 4, 1, 2};
// 	int arrsize = sizeof(arr) / sizeof(int);
// 	int start;
// 	int end;
// 	int fd[2];
// 	if (pipe(fd) == -1)
// 		return (1);
// 	int id = fork();
// 	if (id == -1)
// 		return (2);
// 	if (id == 0)
// 	{
// 		start = 0;
// 		end = start + arrsize / 2;
		
// 	}
// 	else 
// 	{
// 		start = arrsize / 2;
// 		end = arrsize;
// 	}
// 	int sum = 0;
// 	int i = start;
// 	while (i < end)
// 	{
// 		sum += arr[i];
// 		i++;
// 	}
// 	ft_printf("Calculated partial sum: %d \n", sum);
// 	if (id == 0)
// 	{
// 		close(fd[0]);
// 		if (write(fd[1], &sum, sizeof(sum)) == -1)
// 			return (3);
// 		close(fd[1]);
// 	}
// 	else
// 	{
// 		int sumfromchild;
// 		close(fd[1]);
// 		if (read(fd[0], &sumfromchild, sizeof(sum)) == -1)
// 			return (4);
// 		close(fd[0]);
// 		int total = sum + sumfromchild;
// 		ft_printf("total sum = %d \n", total);
// 		wait(NULL);
// 	}
// 	return 0;
// }

// int	main(void)
// {
// 	int arr[] = {13, 9, 8, 7, 3, 2};
// 	int arraylen = sizeof(arr) / sizeof(int);
// 	int start;
// 	int end;
// 	int id2;
// 	int fd[2];
// 	if (pipe(fd) == -1)
// 		return (2);
// 	int id = fork();
// 	if (id != 0)
// 	{
// 		start = 0;
// 		end = arraylen / 3;
// 		wait(NULL);
// 		// waitpid(id, NULL, 0);
// 	}
// 	else
// 	{
// 		start = arraylen / 3;
// 		end = 2 * (arraylen / 3);
// 		id2 = fork();
// 		wait(NULL);
// 		// waitpid(id2, NULL, 0);
// 		if (id2 == 0 && id == 0)
// 		{
// 			start = 2 * (arraylen / 3);
// 			end = arraylen;
// 		}
// 	}
// 	int sum = 0;
// 	int i = start;
// 	while (i < end)
// 	{
// 		sum += arr[i];
// 		i++;
// 	}
// 	ft_printf("The partial sum is %d \n", sum);
// 	if (id == 0 && id2 == 0)
// 	{
// 		// close(fd[0]);
		
// 		if (write(fd[1], &sum, sizeof(sum)) == -1)
// 			return (3);
// 		// close(fd[1]);
// 	}
// 	else if (id == 0)
// 	{
// 		int inter;
// 		if (read(fd[0], &inter, sizeof(int)) == -1)
// 			return (4);
// 		// close(fd[0]);

// 		inter += sum;
// 		if (write(fd[1], &inter, sizeof(inter)) == -1)
// 			return (5);
// 		close(fd[1]);
// 		// waitpid(id2, NULL, 0);
// 		wait(NULL);
// 	}
// 	else
// 	{
// 		int total;
// 		if (read(fd[0], &total, sizeof(sum)) == -1)
// 			return (6);
// 		close(fd[0]);
// 		total += sum;
// 		ft_printf("total = %d \n", total);
// 		// waitpid(id, NULL, 0);
// 		wait(NULL);
// 	}
// 	return (0);
// }

// int main(void)
// {
// 	int p1[2]; // child to parent
// 	int p2[2]; // parent to child
// 	if (pipe(p1) == -1)
// 		return (1);
// 	if (pipe(p2) == -1)
// 		return (2);	
// 	int pid = fork();
// 	if (pid == -1)
// 		return 2;
// 	if (pid == 0)
// 	{
// 		//child process
// 		// we don't need p1[0] so we close it
// 		// same for p2[1]
// 		close(p1[0]);
// 		close(p2[1]);
// 		int x = 0;
// 		if (read(p2[0], &x, sizeof(x)) == -1)
// 			return 3;
// 		ft_printf("Child received: %d \n", x);
// 		x *= 4;
// 		if (write(p1[1], &x, sizeof(x)) == -1)
// 			return (4);
// 		ft_printf("Child wrote: %d \n", x);
// 		close(p1[1]);
// 		close(p2[0]);
// 	}
// 	else
// 	{
// 		// parent process.
// 		// we don't need p2[0] so we close it.
// 		// same for p1[1].
// 		close(p1[1]);
// 		close(p2[0]);
// 		int y = 5;
// 		if (write(p2[1], &y, sizeof(y)) == -1)
// 			return (5);
// 		ft_printf("Parent wrote: %d \n", y);
// 		if (read(p1[0], &y, sizeof(int)) == -1)
// 			return (6);
// 		ft_printf("Parent received: %d \n", y);
// 		close(p1[0]);
// 		close(p2[1]);
// 		wait(NULL);
// 	}
// 	return (0);
// }

// int main(int ac, char **av, char *envp[])
// {
// 	// char *env_variable = getenv("API_KEY");
// 	// if (env_variable == NULL)
// 	// {
// 	// 	ft_printf("Error \n");
// 	// 	return (1);		
// 	// }
// 	// ft_printf("Value : %s \n", env_variable);
// 	while (*envp)
// 	{
// 		ft_printf("%s\n", *envp);
// 		envp++;
// 	}
// 	return (0);
// }

// int main(int ac, char **av, char* envp[])
// {
// 	char *arr[] = {av[1], av[2], NULL};
// 	char *env[] = {"TEST=environment variable"};
// 	execve("/usr/bin/ping", arr, envp);
// 	int err = errno;
	
// 	ft_printf("Ping finished executing \n");
// 	return (0);
// }

// int	main(int argc, char *argv[], char *envp[])
// {
// 	int pid = fork();
// 	if (pid == -1)
// 		return 1;
// 	if (pid != 0)
// 	{
// 		int wstatus;
// 		wait(&wstatus);
// 		if (WIFEXITED(wstatus))
// 		{
// 			int statusCode = WEXITSTATUS(wstatus);
// 			if (statusCode == 0)
// 			{
// 				printf("Success! \n");
// 			}
// 			else
// 			{
// 				printf("Failure \n");
// 			}
			
// 		}
// 	}
// 	else
// 	{
// 		int file = open("pingResults.txt", O_WRONLY | O_CREAT, 0777);
// 		if (file == -1)
// 			return 2;
// 		int file2 = dup2(file, STDOUT_FILENO);
// 		close(file);
// 		char *arr[] = {"/usr/bin/ping", "-c", "3", "google.com", NULL};
// 		int err = execve("/usr/bin/ping", arr, envp);
// 		if (err == -1)
// 		{
// 			ft_printf("Could not find program to execute!\n");
// 			return 2;
// 		}
// 	}
// 	return (0);
// }

// 2 processes: 
// 1) Child process should generate random numbers and send them to the parent.
// 2) Parent is going to sum all the numbers and print the result

int sum_integers(int *array, int len)
{
	int sum = 0;
	int i = 0;
	while (i < len)
		{
			sum += array[i];
			i++;
		}
	return (sum);
}
int	main(int argc, char * argv[])
{
	int fd[2];
	if (pipe(fd) == -1)
	{
		return 1;
	}
	int id = fork();
	if (id == -1)
		return 5;
	if (id == 0)
	{
		close(fd[0]);
		int arr[5] = {12, 20, 20, 7, 15};
		if (write(fd[1], arr, 5 * sizeof(int)) == -1)
		{
			return 3;
		}
		close(fd[1]);
	}
	else 
	{
		close(fd[1]);
		int array[5];
		if (read(fd[0], array, 5 * sizeof(int)) == -1)
		{
			return 4;
		}
		int k = 1;
		close(fd[0]);
		int sum = sum_integers(array, 5);
		ft_printf("The total is %d \n", sum);
		wait (NULL);
	}
	return (0);
}