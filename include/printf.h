/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyniemit <jyniemit@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 11:48:02 by jyniemit          #+#    #+#             */
/*   Updated: 2025/04/17 17:28:26 by jyniemit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef    PRINTF_H
# define    PRINTF_H

//for INT_MIN & INT_MAX
#include <limits.h>
//args
#include <stdarg.h>
//write
#include <unistd.h>
//prototypes
int	ft_printf(char *format, ...);
# endif
