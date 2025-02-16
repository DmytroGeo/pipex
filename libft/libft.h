/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeorgiy <dgeorgiy@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 12:03:25 by dgeorgiy          #+#    #+#             */
/*   Updated: 2025/02/15 22:33:18 by dgeorgiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdint.h>
# include <limits.h>
# include <stdio.h>
# include <stdarg.h>

void	ft_putchar_fd(char c, int fd, int *count);
void	ft_putchex_fd(unsigned int n, int fd, int *count);
void	ft_puthex_fd(unsigned int n, int fd, int *count);
void	ft_putnbr_fd(int n, int fd, int *count);
void	ft_putptr_fd(void *ptr, int fd, int *count);
void	ft_putstr_fd(char *s, int fd, int *count);
void	ft_putuns_fd(unsigned int n, int fd, int *count);

int		ft_printf(const char *str, ...);

#endif