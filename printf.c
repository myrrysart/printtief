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
int	main(void)
{
	printf("testing if I can still code anything. :D");
	ft_printf("
