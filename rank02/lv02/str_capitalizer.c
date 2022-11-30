/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamwayk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:07:35 by pnamwayk          #+#    #+#             */
/*   Updated: 2022/11/17 16:22:24 by pnamwayk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}

void	first_cap(char *s, int len)
{
	int	i;

	i = 0;
	while (s[i] != 0)
	{
		if (s[i] >= 'a' && s[i] <= 'z' && (i == 0 || s[i - 1] == ' ' || s[i - 1] == '\t'))
		       s[i] -= 32;
		else if (s[i] >= 'A' && s[i] <= 'Z' && (i != 0 && s[i - 1] != ' ' && s[i - 1] != '\t'))
			s[i] += 32;
		write(1, &s[i], 1);
		i++;	
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	len;

	i = 1;
	while (i < argc)
	{
		len = ft_strlen(argv[i]);
		first_cap(argv[i], len); 
		write(1, "\n", 1);
		i++;
	}
	if (argc < 2)
		write(1, "\n", 1);

}

