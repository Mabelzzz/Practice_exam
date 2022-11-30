/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstr_capitalizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamwayk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:45:57 by pnamwayk          #+#    #+#             */
/*   Updated: 2022/11/17 15:26:00 by pnamwayk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

void	print_cap(char	*s, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (s[i] >= 'a' && s[i] <= 'z' && (!s[i + 1] || s[i + 1] == ' ' || s[i + 1] == '\t'))
			s[i] -= 32;
		else if (s[i] >= 'A' && s[i] <= 'Z' && s[i + 1] != ' ' && s[i + 1] != '\t' && s[i + 1])
			s[i] += 32;
		write(1, &s[i], 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	len;
	int	i;
	
	i = 1;
	while (i < argc)
	{
		len = ft_strlen(argv[i]);
		print_cap(argv[i], len);
		i++;
		write(1, "\n", 1);
	}
	if (argc < 2)
		write(1, "\n", 1);
}
