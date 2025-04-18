/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_X.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyniemit <jyniemit@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:23:22 by jyniemit          #+#    #+#             */
/*   Updated: 2025/04/18 16:16:14 by jyniemit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "printf.h"

int	handle_X(va_list args)
{
	char	str[16];
	int		i;
	int		num;
	int		count;

	i = 0;
	count = 0;
	num = va_arg(args, int);
	if (num == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	while (num > 0)
	{
		str[i] = HEXHIGH[num % 16];
		num /= 16;
		i++;
	}
	while (i > 0)
	{
		i--;
		write(1, &str[i], 1);
		count++;
	}
	return (count);
}
