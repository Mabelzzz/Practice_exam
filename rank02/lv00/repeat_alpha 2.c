/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamwayk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:54:39 by pnamwayk          #+#    #+#             */
/*   Updated: 2022/11/18 12:17:04 by pnamwayk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	check_order(char c)
{
	int	i;

	if (c >= 'a' && c <= 'z')
		i = c - 96;
	else if (c >= 'A' && c <= 'Z')
		i = c - 64;
	else 
		i = 1;
       	//printf("c = %d\n", i);
	return (i);	

}
int	main(int ac, char **av)
{
	int	i;
	int	rp;

	i = 0;
	if (ac == 2)
	{
		while (av[1][i] != 0)
		{
			rp = check_order(av[1][i]);
			while (rp > 0)
			{
				write(1, &av[1][i], 1);
				rp--;	
			}	
			i++;	
		}
	}
	write(1, "\n", 1);
}
