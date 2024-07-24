
#ifndef SO_LONG_H
# define SO_LONG_H

#include "get_next_line/get_next_line.h"

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int open_fd(char *file);
int read_fd(int fd);
int ft_check(char *str,int i);

#endif