/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyniemit <jyniemit@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 11:48:02 by jyniemit          #+#    #+#             */
/*   Updated: 2025/04/17 11:56:13 by jyniemit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef    PRINTF_H
# define    PRINTF_H
# endif

//for INT_MIN & INT_MAX
#include <limits.h>
//args
#include <stdarg.h>

//prototypes
int	ft_printf(char *format, ...);
