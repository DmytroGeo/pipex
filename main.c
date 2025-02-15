/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeorgiy <dgeorgiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 12:12:58 by dgeorgiy          #+#    #+#             */
/*   Updated: 2025/02/15 18:13:24 by dgeorgiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(void)
{
	// int id = fork();
	// ft_printf("hello world from id: %d \n", id);
	// if (id == 0)
	// 	ft_printf("hello from the child process \n");
	// else 
	// 	ft_printf("hello from the main process \n");
	int id = fork();
	if (id != 0)
		fork();
	ft_printf("Hello World \n");	
	return (0);
}
