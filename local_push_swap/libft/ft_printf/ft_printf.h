/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-rho <sben-rho@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:48:17 by sben-rho          #+#    #+#             */
/*   Updated: 2023/12/22 12:28:46 by sben-rho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
int		string_function(int *cwrite, char *str);
int		f_putnbr_count(int *cwrite, int nb);
int		f_putnbr_base(unsigned long long n, int i, int *cwrite);
int		print_address(unsigned long long add, int *cwrite);
int		f_putunbr_count(int *cwrite, unsigned int nb);
size_t	f_strlen(const char *s);
int		f_putchar_fd(char c, int fd);
int		f_putstr_fd(char *s, int fd);
int		f_putnbr_fd(int n, int fd);

#endif