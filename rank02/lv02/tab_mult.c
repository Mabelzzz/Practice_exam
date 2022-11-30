/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamwayk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 10:00:58 by pnamwayk          #+#    #+#             */
/*   Updated: 2022/11/18 11:50:37 by pnamwayk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	nbrlen(int nbr)
{
	int	i;

	i = 0;
	if (nbr == 0)
		return (1);
	while (nbr > 0)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

int	ft_atoi(char *s)
{
	int	n;
	int	i;

	i = 0;
	n = 0;
	while(s[i] != 0)
	{
		n = (n * 10) + (s[i] - '0');
		i++;
	}
	return (n);
}

void	put_str(char *s)
{
	int	i;

	i = 0;
	while (s[i] != 0)
	{
		write(1, &s[i], 1);
		i++;
	}
}

void	put_nbr(int nbr)
{
	int	len;
	int	mod;	
	int	tmp;
	
	len = nbrlen(nbr);
	
	char	s[len];

	tmp = len;
	len--;
	if (nbr == 0)
		s[len] = '0';
	while (nbr > 0)
	{
		mod = nbr % 10 + '0';
		s[len] = mod;
		nbr /= 10;
		len--;
	}
	write(1, &s, tmp);
}

int	main(int ac, char **av)
{
	int	i;
	int	j;
	int	n;

	i = 1;
	n = 0;
	if (ac == 2)
	{
		if (av[1][0] != '-' && av[1][0] != '0')
			n = ft_atoi(av[1]);
		while (i < 10)
		{
			j = i + '0';
			write(1, &j, 1);
			write(1, " x ", 3);
			put_nbr(n);
			write(1, " = ", 3);
			put_nbr(i * n);	
			write(1, "\n", 1);
			i++;		
		}
	}
	else
		write(1, "\n", 1);
}
