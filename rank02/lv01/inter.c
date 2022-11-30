/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamwayk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:46:51 by pnamwayk          #+#    #+#             */
/*   Updated: 2022/11/17 16:04:30 by pnamwayk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != 0)
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	check_double(char *s, char c, int len)
{
	len--;
	while (len >= 0)
	{
		if (s[len] == c)
			return (1);
		len--;
	}
	return (0);
}
	
int	main(int argc, char ** argv)
{
	int	i;

	i = 0;
	if (argc == 3)
	{
		while (argv[1][i] != 0)
		{
			if (ft_strcmp(argv[2], argv[1][i]) == 1)
				if (check_double(argv[1], argv[1][i], i) == 0)
					write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
}

