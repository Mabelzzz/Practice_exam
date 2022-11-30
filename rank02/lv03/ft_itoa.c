/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamwayk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 02:16:04 by pnamwayk          #+#    #+#             */
/*   Updated: 2022/11/17 02:56:25 by pnamwayk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	cnt_base(int nbr)
{
	int	i;

	i = 0;
	if (nbr <= 0)
	{
		nbr *= -1;
		i++;
	}
	while (nbr > 0)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int nbr)
{
	int	len;
	char	*str;
	int	div;
	int	i;

	i = 0;
	len = cnt_base(nbr);
	str = malloc(sizeof(char) * (len + 1));
	str[len] = 0;
	if (nbr < 0)
	{
		str[0] = '-';
		nbr *= -1;
	}
	else if (nbr == 0)
		str[0] = '0';
	while (nbr > 0)
	{
		len--;
		str[len] = nbr % 10 + '0';
		nbr /= 10;
	}
	return (str);
}
/*
#include <stdio.h>
int main()
{
	printf("str -1232334 : %s\n", ft_itoa(-1232334));
	printf("str -12345634 : %s\n", ft_itoa(-12345634));
	printf("str -1 : %s\n", ft_itoa(-1));
	printf("str -0 : %s\n", ft_itoa(-0));
}*/
