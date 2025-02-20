/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeorgiy <dgeorgiy@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 12:12:58 by dgeorgiy          #+#    #+#             */
/*   Updated: 2025/02/19 16:03:34 by dgeorgiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
# define PROCESS_NUM 3
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

// int sum_integers(int *array, int len)
// {
// 	int sum = 0;
// 	int i = 0;
// 	while (i < len)
// 		{
// 			sum += array[i];
// 			i++;
// 		}
// 	return (sum);
// }
// int	main(int argc, char * argv[])
// {
// 	int fd[2];
// 	if (pipe(fd) == -1)
// 	{
// 		return 1;
// 	}
// 	int id = fork();
// 	if (id == -1)
// 		return 5;
// 	if (id == 0)
// 	{
// 		close(fd[0]);
// 		int arr[5] = {12, 20, 20, 7, 15};
// 		if (write(fd[1], arr, 5 * sizeof(int)) == -1)
// 		{
// 			return 3;
// 		}
// 		close(fd[1]);
// 	}
// 	else 
// 	{
// 		close(fd[1]);
// 		int array[5];
// 		if (read(fd[0], array, 5 * sizeof(int)) == -1)
// 		{
// 			return 4;
// 		}
// 		int k = 1;
// 		close(fd[0]);
// 		int sum = sum_integers(array, 5);
// 		ft_printf("The total is %d \n", sum);
// 		wait (NULL);
// 	}
// 	return (0);
// }

// int main(void)
// {
// 	int fd[2];
// 	if (pipe(fd) == -1)
// 		return 1;
// 	int id = fork();
// 	if (id == -1)
// 		return 2;
// 	if (id == 0)
// 	{
// 		close(fd[0]);
// 		char *str = "Hello World";
// 		while (*str)
// 		{
// 			if (write(fd[1], str, sizeof(char)) == -1)
// 				return 3;
// 			str++;
// 		}		
// 		close(fd[1]);
// 	}
// 	else
// 	{
// 		close(fd[1]);
// 		char array[12];
// 		char *ptr = array;
// 		while (read(fd[0], ptr, sizeof(char)))
// 			ptr++;
// 		*ptr = '\0';
// 		close(fd[0]);
// 		ft_printf("Received: %s\n", array);
// 		wait(NULL);
// 	}
// 	return 0;
// }

// int	main(void)
// {
// 	int p1[2];
// 	int p2[2];
// 	int p3[2]; 
// 	if (pipe(p1) < 0)
// 		return 3;
// 	if (pipe(p2) < 0)
// 		return 4;
// 	if (pipe(p3) < 0)
// 		return 5;
// 	int id1 = fork();
// 	if (id1 < 0)
// 		return 1;
// 	if (id1 == 0) // we're in the child1 process
// 	{
// 		int z;
// 		if (read(p1[0], &z, sizeof(int)) < 0)
// 			return 8;
// 		close(p1[0]);
// 		z += 5;
// 		if (write(p2[1], &z, sizeof(int)) < 0)
// 			return 9;
// 		close(p2[1]);
// 	}
// 	else // we're in the parent process
// 	{
// 		int x = 7;
// 		if (write(p1[1], &x, sizeof(int)) < 0)
// 			return 6;
// 		close(p1[1]);
// 		int id2 = fork();
// 		if (id2 < 0)
// 			return 2;
// 		if (id2 == 0) // we're in the child2 process
// 		{
// 			int w;
// 			if (read(p2[0], &w, sizeof(int)) < 0)
// 				return 8;
// 			close(p2[0]);
// 			w += 5;
// 			if (write(p3[1], &w, sizeof(int)) < 0)
// 				return 9;
// 			close(p3[1]);			
// 		}
// 		if (read(p3[0], &x, sizeof(int)) < 0)
// 			return 7;
// 		close(p3[0]);
// 		ft_printf("We've received : %d \n", x);
// 	}
// 	return (0);
// }

// int	main(void)
// {
// 	int p1[2];
// 	int p2[2];
// 	int p3[2]; 
// 	if (pipe(p1) < 0)
// 		return 3;
// 	if (pipe(p2) < 0)
// 		return 4;
// 	if (pipe(p3) < 0)
// 		return 5;
// 	int id1 = fork();
// 	if (id1 < 0)
// 		return 1;
// 	if (id1 == 0) // we're in the child1 process
// 	{
// 		int z;
// 		if (read(p1[0], &z, sizeof(int)) < 0)
// 			return 8;
// 		close(p1[0]);
// 		z += 6;
// 		if (write(p2[1], &z, sizeof(int)) < 0)
// 			return 9;
// 		close(p2[1]);
// 	}
// 	else // we're in the parent process
// 	{
// 		int id2 = fork();
// 		if (id2 < 0)
// 			return 2;
// 		if (id2 == 0) // we're in the child2 process
// 		{
// 			int w;
// 			if (read(p2[0], &w, sizeof(int)) < 0)
// 				return 8;
// 			close(p2[0]);
// 			w += 7;
// 			if (write(p3[1], &w, sizeof(int)) < 0)
// 				return 9;
// 			close(p3[1]);			
// 		}
// 		else 
// 		{
// 			int x = 5;
// 			if (write(p1[1], &x, sizeof(int)) < 0)
// 				return 6;
// 			ft_printf("We've sent : %d \n", x);
// 			close(p1[1]);
// 			if (read(p3[0], &x, sizeof(int)) < 0)
// 				return 7;
// 			close(p3[0]);
// 			ft_printf("We've received : %d \n", x);
// 			wait(NULL);
// 		}
// 	}
// 	return (0);
// }

// int main(int argc, char **argv)
// {
// 	int fd[3][2];
// 	int i = 0;
// 	while (i < 3)
// 	{
// 		if ((pipe(fd[i])) < 0)
// 			return 1;
// 		i++;
// 	}
// 	int id1 = fork();
// 	if (id1 < 0)
// 		return 2;
// 	if (id1 == 0)
// 	{
// 		// We're in the child1 process. We read from fd[0][0] and we write to fd[1][1]. Everything else is closed.
// 		close(fd[0][1]);
// 		close(fd[1][0]);
// 		close(fd[2][1]);
// 		close(fd[2][0]);
// 		int x;
// 		if (read(fd[0][0], &x, sizeof(int)) < 0)
// 			return 3;
// 		x += 5;
// 		if (write(fd[1][1], &x, sizeof(int)) < 0)
// 			return 4;
// 		close(fd[0][0]);
// 		close(fd[1][1]);
// 		return 0; // This line ensures that child 1 doesn't execute any of the code below this line.
// 	}
// 	int id2 = fork();
// 	if (id2 < 0)
// 		return 5;
// 	if (id2 == 0) // now we're in the child2 process. We read from fd[1][0] and we write to fd[2][1]. Everything else is closed. 
// 	{
// 		close(fd[0][1]);
// 		close(fd[2][0]);
// 		close(fd[0][0]);
// 		close(fd[1][1]);
// 		int y;
// 		if (read(fd[1][0], &y, sizeof(int)) < 0)
// 			return 6;
// 		y += 5;
// 		if (write(fd[2][1], &y, sizeof(int)) < 0)
// 			return 7;
// 		close(fd[1][0]);
// 		close(fd[2][1]);
// 		return (0); // This line ensures that child 2 doesn't execute any of the code below this line.
// 	}
// 	//We don't need an else statement because we've terminated child1 and child 2, so below this line we know we're in the parent.
// 	// We read from fd[2][0] and write to fd[0][1]. Everything else is closed.
// 	close(fd[1][0]);
// 	close(fd[2][1]);
// 	close(fd[0][0]);
// 	close(fd[1][1]);
// 	int z = 7;
// 	if (write(fd[0][1], &z, sizeof(int)) < 0)
// 		return 8;
// 	ft_printf("The number we sent was %d \n", z);
// 	if (read(fd[2][0], &z, sizeof(int)) < 0)
// 		return 9;
// 	ft_printf("The number we received was %d \n", z);
// 	close(fd[0][1]);
// 	close(fd[2][0]);
// 	waitpid(id1, NULL, 0);
// 	waitpid(id2, NULL, 0);
// 	return 0;
// }

// int main(void)
// {
// 	int id1 = fork();
// 	if (id1 < 0)
// 		return 1;
// 	if (id1 == 0)
// 	{
// 		sleep(4);
// 		ft_printf("finished execution %d \n", getpid());
// 		return 0;	
// 	}
// 	int id2 = fork();
// 	if (id2 < 0)
// 		return 2;
// 	if (id2 == 0)
// 	{
// 		sleep(1);
// 		ft_printf("finished execution %d \n", getpid());
// 		return 0;
// 	}
// 	int res1 = waitpid(-1, NULL, 0);
// 	ft_printf("Waited for %d \n", res1);
// 	int res2 = waitpid(-1, NULL, 0);
// 	ft_printf("Waited for %d \n", res2);
// 	return 0;
	
// }

// int main(void)
// {
// 	int fd[3][2];
// 	int id[2];
// 	int i = 0;
// 	while (i < 3)
// 	{
// 		if (pipe(fd[i]) < 0)
// 			return 1;
// 		i++;
// 	}
// 	id[0] = fork();
// 	if (id[0] == 0)
// 	{
// 		int x;
// 		if (read(fd[0][0], &x, sizeof(int)) < 0)
// 			return 5;
// 		x += 5;
// 		if (write(fd[1][1], &x, sizeof(int)) < 0)
// 			return 6;			
// 		return 0;
// 	}
// 	id[1] = fork();
// 	if (id[1] == 0)
// 	{
// 		int x;
// 		if (read(fd[1][0], &x, sizeof(int)) < 0)
// 			return 7;
// 		x += 5;
// 		if (write(fd[2][1], &x, sizeof(int)) < 0)
// 			return 8;
// 		return 0;
// 	}
// 	int x = 7;
// 	if (write(fd[0][1], &x, sizeof(int)) < 0)
// 		return 3;
// 	ft_printf("we've sent %d \n", x);
// 	if (read(fd[2][0], &x, sizeof(int)) < 0)
// 		return 4;
// 	ft_printf("We've received %d \n", x);
// 	waitpid(id[0], NULL, 0);
// 	waitpid(id[1], NULL, 0);
// 	return (0);
// }

void	close_others(int fd[][2], int len, int i)
{
	int p = 0;
	int q = 0;
	while (p < len)
	{
		while (q < 2)
		{
			if (!((p == i && q == 0) || (p == i + 1 && q == 1)))
				close(fd[p][q]);
			q++;
		}
		q = 0;
		p++;
	}
	return ;
}

void	close_final(int fd[][2], int len)
{
	int p = 0;
	int q = 0;
	while (p < len)
	{
		while (q < 2)
		{
			if (!((p == 0 && q == 1) || (p == len - 1 && q == 0)))
				close(fd[p][q]);
			q++;
		}
		q = 0;
		p++;
	}
	return ;	
}

// int main(int ac, char **av)
// {
// 	if (ac < 3)
// 		return 0;
// 	int m = atoi(av[1]);
// 	int n = atoi(av[2]);
// 	int fd[n + 1][2];
// 	int id[n];
// 	int i = 0;
// 	while (i < n + 1)
// 	{
// 		if (pipe(fd[i]) < 0)
// 			return 1;
// 		i++;
// 	}
// 	i = 0;
// 	while (i < n)
// 	{
// 		id[i] = fork();
//		if (id[i] < 0)
//			return 9;
// 		if (id[i] == 0)
// 		{
// 			close_others(fd, n + 1, i);
// 			int y;
// 			if (read(fd[i][0], &y, sizeof(int)) < 0)
// 				return (3);
// 			y += m;
// 			if (write(fd[i + 1][1], &y, sizeof(int)) < 0)
// 				return (4);
// 			close(fd[i][0]);
// 			close(fd[i + 1][1]);
// 			return (0);
// 		}
// 		i++;
// 	}
// 	close_final(fd, n + 1);
// 	int x = 0;
// 	if (write(fd[0][1], &x, sizeof(int)) < 0)
// 		return (5);
// 	if (read(fd[n][0], &x, sizeof(int)) < 0)
// 		return (6);
// 	close(fd[0][1]);
// 	close(fd[n][0]);
// 	ft_printf("Answer = %d \n", x);
// 	i = 0;
// 	while (i < n)
// 	{
// 		waitpid(id[i], NULL, 0);
// 		i++;
// 	}
// 	return (0);
// }
