/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamwayk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:01:58 by pnamwayk          #+#    #+#             */
/*   Updated: 2022/11/17 14:43:09 by pnamwayk         ###   ########.fr       */
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
#include <stdio.h>
void	print_last_word(char *str, int len)
{
	int	start;
	int	cnt;
	int	sp;
	int	tmp_len;

	tmp_len = len;
	sp = 0;
	len--;
	while ((str[len] == ' ' || str[len] == '\t') && len >= 0)
	{
		sp++;
		len--;
	}
	cnt = 0;
	while (str[len] != ' ' && str[len] != '\t' && len >= 0)
	{
		cnt++;
		len--;
	}
	write(1, &str[tmp_len - cnt - sp], cnt);
}	

int	main(int argc, char **argv)
{
	int	len;

	if (argc == 2)
	{
		len = ft_strlen(argv[1]);
		print_last_word(argv[1], len);
	}
	write(1, "\n", 1);
}
