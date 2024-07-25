/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 18:45:34 by rbouizer          #+#    #+#             */
/*   Updated: 2024/07/25 22:38:06 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int open_fd(char *file) {
    int fd;
    
    fd = open(file, O_RDONLY);

    if (fd == -1)
        return (ft_putendl_fd("PROBLEM ON OPENING", 2), 1); 
    return fd; 
}

char *read_fd(int fd)
{
    char *str;

    str = get_next_line(fd);
    return str;
}

int close_fd(int fd) {
    if (close(fd) == -1)
        return (ft_putendl_fd("PROBLEM ON CLOSING", 2), 1);
    return 0;
}