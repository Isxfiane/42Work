/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-rho <sben-rho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:48:17 by sben-rho          #+#    #+#             */
/*   Updated: 2023/11/20 18:08:50 by sben-rho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
void	string_function(unsigned int *cwrite, char *str);
void	ft_putnbr_count(unsigned int *cwrite, int nb);
void	ft_putnbr_base(unsigned long long n, char *base, unsigned int *cwrite);
void	print_float(double n, unsigned int *cwrite);
void	print_address(unsigned long long add, unsigned int *cwrite);
void	ft_putunbr_count(unsigned int *cwrite, unsigned int nb);
size_t	ft_strlen(const char *s);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

#endif