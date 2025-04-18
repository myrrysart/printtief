/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyniemit <jyniemit@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:24:59 by jyniemit          #+#    #+#             */
/*   Updated: 2025/04/18 16:23:58 by jyniemit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "printf.h"

int	handle_u(va_list args)
{
	int				i;
	unsigned int	num;
	int				ret;
	char			str[10];

	ret = 0;
	i = 0;
	num = va_arg(args,unsigned int);
	if (num == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	while (num > 0)
	{
		str[i] = num % 10 + 48;
		num /= 10;
		i++;
	}
	while (i > 0)
	{
		i--;
		write(1, &str[i], 1);
		ret++;
	}
	return (ret);
}
