/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyniemit <jyniemit@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:25:58 by jyniemit          #+#    #+#             */
/*   Updated: 2025/04/18 15:52:35 by jyniemit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "printf.h"


int	handle_d(va_list args)
{
	char	str[11];
	int		i;
	int		num;
	int		ret;

	i = 0;
	ret = 0;
	num	= va_arg(args, int);
	if (num == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	if (num == INT_MIN)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	while (num < 0)
	{
		write(1, "-", 1);
		ret++;
		num *= -1;
	}
	while (num > 0)
	{
		str[i] = num % 10 + 48;
		num /= 10;
		i++;
		ret++;
	}
	while (i > 0)
	{
		i--;
		write(1, &str[i], 1);
	}
	return (ret);
}
