/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamwayk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:24:50 by pnamwayk          #+#    #+#             */
/*   Updated: 2022/11/17 17:24:40 by pnamwayk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	check_prime(int	nbr)
{
	int	i;
	int	pr;

	pr = 0;
	i = 2;
	while ( i <= (nbr / 2))
	{
		if (nbr % i == 0 && nbr > 0)
		{
			pr = 1;
			printf("%d*", i);
			nbr /= i;
			//printf("nbr=%d  i=%d  ans=%d  \n", nbr, i, ans);
			i = 2;
		}
		i++;
	}
	if (pr == 1)
		printf("%d", nbr);
	return (pr);
}

int	main(int argc, char **argv)
{
	int	i;
	int	nbr;
	int	ck;

	i = 0;
	if (argc == 2)
	{
		nbr = atoi(argv[1]);
		ck = check_prime(nbr);
		if (ck == 0 && nbr > 0)
			printf("%d", nbr);
	}
	printf("\n");

}
