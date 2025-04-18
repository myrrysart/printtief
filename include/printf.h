/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyniemit <jyniemit@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 11:48:02 by jyniemit          #+#    #+#             */
/*   Updated: 2025/04/18 16:25:01 by jyniemit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef    PRINTF_H
# define    PRINTF_H
# define    HEXLOW "0123456789abcdef"
# define    HEXHIGH "0123456789ABCDEF"

//for INT_MIN & INT_MAX
#include <limits.h>
//args
#include <stdarg.h>
//write
#include <unistd.h>
//prototypes
int	ft_printf(const char *format, ...);
int	handle_c(va_list args);
int	handle_s(va_list args);
int	handle_u(va_list args);
int	handle_d(va_list args);
int	handle_p(va_list args);
int	handle_x(va_list args);
int	handle_X(va_list args);
# endif
