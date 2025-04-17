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
int	main(void)
{
	printf("testing if I can still code anything. :D");
	ft_printf("
