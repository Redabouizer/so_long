/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 18:45:34 by rbouizer          #+#    #+#             */
/*   Updated: 2024/07/23 18:45:36 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int open_fd(char *file) {
    int fd;
    
    fd = open(file, O_RDONLY);

    if (fd == -1) {
        return 1; 
    }
    return fd; 
}

int read_fd(int fd)
{
    int i=0;
    char *str = get_next_line(fd);
    while(str != NULL)
    {
        if(ft_check(str,i) == 1)
            return (free(str) , 1);
        free(str);
        str = get_next_line(fd);
        i++;
    }
    return 0;
}