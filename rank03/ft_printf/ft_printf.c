#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

int	ft_printf(char *fmt, ...);
int	put_str(char *str, int len);
int	put_hex(unsigned int nb);
int	put_nbr(int nb);

int	ft_printf(char *fmt, ...)
{
	va_list	ap;
	int		len;

	len = 0;
	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt == '%' && *(fmt + 1) == 's' && fmt++)
			len += put_str(va_arg(ap, char *), 0);
		else if (*fmt == '%' && *(fmt + 1) == 'd' && fmt++)
			len += put_nbr(va_arg(ap, int));
		else if (*fmt == '%' && *(fmt + 1) == 'x' && fmt++)
			len += put_hex(va_arg(ap, unsigned int));
		else
			len += write(1, fmt, 1);
		fmt++;
	}
	va_end(ap);
	return (len);
}

int	put_str(char *str, int len)
{
	while (str && str[len] && ++len);
	if (len > 0)
		write(1, str, len);
	else
		write(1, "(null)", 6);
	return (len);
}

int	put_nbr(int nb)
{
	int	len = 0;

	if (nb < 0)
	{
		len += write(1, "-", 1);
		len += put_nbr((nb / 10) * -1);
		nb = (nb % 10) * -1;
	}
	else if(nb >= 10)
	{
		len += put_nbr(nb / 10);
	}
	len += write(1, &"0123456789"[nb % 10], 1);
	return (len);
}

int put_hex(unsigned int nb)
{
	int	len = 0;

	if (nb >= 16)
		len += put_hex(nb / 16);
	len += write(1, &"0123456789abcdef"[nb % 16], 1);
	return (len);
}
