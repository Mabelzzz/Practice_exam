/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamwayk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 01:15:17 by pnamwayk          #+#    #+#             */
/*   Updated: 2022/11/17 01:32:24 by pnamwayk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	max(int* tab, unsigned int len)
{
	int	max;
	int	i;

	i = 0;
	max = 0;
	if (len > 0)
		max = tab[0];
	while (i < len)
	{
		if (tab[i] > max)
			max = tab[i];
		i++;
	}
	return (max);
}
/*
#include <stdio.h>
int main()
{
	int	*tab;
	tab[0] = 4;
	tab[1] = 1;
	tab[2] = 5;
	tab[3] = 0;
	printf("max : %d", max(tab, 4));
	return (0);
}
*/
