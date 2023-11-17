/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-rho <sben-rho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:48:17 by sben-rho          #+#    #+#             */
/*   Updated: 2023/11/17 13:51:56 by sben-rho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include "libft/libft.h"


void	string_function(unsigned int *cwrite, va_list args);
void	ft_putnbr_count(unsigned int *cwrite, va_list args);
void    ft_putnbr_base(int nbr, char *base, unsigned int *cwrite);
void	print_float(double n, unsigned int *cwrite);



#endif