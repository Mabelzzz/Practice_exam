/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamwayk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:17:18 by pnamwayk          #+#    #+#             */
/*   Updated: 2022/11/18 16:34:45 by pnamwayk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	expand_str(char *s)
{
	int	i;
	int	sp;

	i = 0;
	while (s[i] == ' ' || s[i] == '\t')
		i++;
	while (s[i] != 0)
	{
		while (s[i] != ' ' && s[i] != '\t' && s[i] != 0)
		{
			sp = 0;
			write(1, &s[i], 1);
			i++;
		}
		while ((s[i] == ' ' || s[i] == '\t') && s[i] != 0)
		{
			sp = 3;
			i++;
		}
		if (sp == 3 && s[i] != 0)
			write(1, "   ", 3);
	}
}

int	main (int ac, char **av)
{
	int	i;

	i = 0;
	if (ac == 2)
		expand_str(av[1]);
	write(1, "\n", 1);
}
