#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_gnl g;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	init(&g);
	if (g.tmp && have_nl(g.tmp) != -1)
	{
		get_line(&g);
		g.tmp = get_tmp(g.tmp);
		return (g.line);
	}
	else
		read_file(fd, &g);
}

void	init(t_gnl *g)
{
	g->tmp = NULL;
	g->line = NULL;
	g->buf = NULL;
	g->tmp2 = NULL;
	g->byte = 1;
}

int	have_nl(char *s)
{
	int	i = -1;

	while(s[++i])
	{
		if (s[i] == '\n')
			return (i);
	}
	return (-1);
}

int		str_len(char *s)
{
	int	i = -1;

	while (s[++i]);
	return (i);
}

void	get_line(t_gnl *g)
{
	int	i = -1;

	if (g->line)
		free(g->line);
	g->line = malloc(sizeof(char) * (have_nl(g->tmp) + 2));
	while(g->tmp[++i])
	{
		g->line[i] = g->tmp[i];
		if (g->tmp[i] == '\n')
			break ;
	}
	g->line[i] = 0;
}

char	*get_tmp(char *s)
{
	int	i = have_nl(s);
	char	*tmp;

	tmp = malloc(sizeof(char) * (str_len(s) - i));
	int	j = -1;
	while (s[++i])
		tmp[++j] = s[i];
	tmp[j] = 0;
	free(s);
	return (tmp);
}

char	*str_join(char *s1, char *s2)
{
	if
}

int main(void)
{
	printf("len = %d nl = %d\n", str_len("Hello\nWorld"), have_nl("Hello\nWorld"));
}
