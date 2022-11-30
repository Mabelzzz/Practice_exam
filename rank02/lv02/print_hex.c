/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamwayk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 01:34:20 by pnamwayk          #+#    #+#             */
/*   Updated: 2022/11/17 02:11:26 by pnamwayk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_atoi(char *str)
{
	int	n;

	n = 0;
	while (*str != 0)
	{
		n *= 10;
		n += (*str - '0');
		str++;
	}
	return (n);
}
 

void	print_hex(int nbr)
{
	if (nbr >= 16)
		print_hex(nbr / 16);
	write(1, &"0123456789abcdef"[nbr % 16], 1);
}

int	main(int ac, char **av)
{
	if (ac == 2)
		print_hex(ft_atoi(av[1]));
	write(1, "\n", 1);
}

