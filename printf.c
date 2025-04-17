#include "include/printf.h"

//debug
#include <stdio.h>

int	handle_s(va_list args)
{
	int		i;
	char	*str;

	i = 0;
	str = va_arg(args, char *);
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	handle_c(va_list args)
{
	char	c;
	c = (char)va_arg(args, int);
	write(1, &c, 1);
	return (1);
}

int	handle_d(va_list args)
{
	char	*str;
	int		len;

	str = itoa(va_arg(args, int));
	len = strlen(str);
	write(1, str, len);
	return (len);
}

int	handle_p_hex(unsigned long num)
{
	char	str[16];
	int		count;
	int		i;

	count = 0;
	while(num > 0)
	{
		str[i] = HEXLOW[num / 16];
		num /= 16;
		i++;
	}
	while(i >0)
	{
		i--;
		write(1, &str[i], 1);
		count++;
	}
	return (count);
}

int	handle_p(va_list args)
{
	void	*ptr;
	unsigned long	num;
	int		count;

	ptr = va_arg(args, void *);

	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}

	write(1, "0x", 2);
	count = 2;

	num = (unsigned long)ptr;
	count += handle_p_hex(num);
	return(count);
}

int	handle_X(va_list args)
{
	char	str[16];
	int		i;
	int		num;
	int		count;

	i = 0;
	count = 0;
	num = va_arg(args, int);
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
	}
	return (count);
}

int	handle_x(va_list args)
{
	char	str[16];
	int		i;
	int		num;
	int		count;

	i = 0;
	count = 0;
	num = va_arg(args, int);
	while (num > 0)
	{
		str[i] = HEXLOW[num % 16];
		num /= 16;
		i++;
	}
	while (i > 0)
	{
		i--;
		write(1, &str[i], 1);
	}
	return (count);
}

int	handle_cases(char *format, va_list args, int count)
{
	int	i;

	i = 0;
	if (*format == 'c')
		i = handle_c(args);
	else if (*format == 's')
		i = handle_s(args);
//	else if (*format == 'p')
//		i = handle_p(args);
	else if (*format == 'd' || *format == 'i')
		i = handle_d(args);
//	else if (*format == 'u')
//		i = handle_u(args);
	else if (*format == 'x')
		i = handle_x(args);
	else if (*format == 'X')
		i = handle_X(args);
	else
		return (-1);
	return (count + i);
}
int	ft_printf(char *format, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '%')
				write(1, format, 1);
			else
			{
				count = handle_cases(format, args, count);
				if (count < 0)
					return (count);
			}
		}
		else
			write(1, format, 1);
		format++;
		count++;
	}
	return (count);
}

int	main(void)
{
	char	*str = "Testing if I can still code anything. :D\n";
	int		i = ft_printf("%% And rest of some text%s    AND MORE TEXT\n", str);
	printf("%s", str);
	printf("%d", i);
	return (0);
}
