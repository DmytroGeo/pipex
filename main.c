/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeorgiy <dgeorgiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 12:12:58 by dgeorgiy          #+#    #+#             */
/*   Updated: 2025/02/12 13:02:22 by dgeorgiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **av)
{
	if (argc != 5)
	{
		ft_printf("Error\n");
		return (0);
	}
	else
		error_checking(av);
	return (0);
}
