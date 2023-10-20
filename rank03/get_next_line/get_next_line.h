#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
# endif

typedef struct gnl {
	char	*tmp;
	char	*line;
	char	*buf;
	int		byte;
	char	*tmp2;
} t_gnl;

#endif
