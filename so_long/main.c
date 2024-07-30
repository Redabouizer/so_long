/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 19:48:00 by rbouizer          #+#    #+#             */
/*   Updated: 2024/07/30 06:30:00 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void f()
{
    system ("leaks so_long");
}
int main(int ac, char *av[])
{
    atexit(f);
    char    *file;
    int     i;
    int     e;

    if (ac == 2)
    {
        file = av[1]; 
        i = 0;
        e = 1;
        while (file[i])
        {
            if ((e = ex_ber(file, i)) == 0)
                break;
            i++;
        }
        if (e == 1)
           return (ft_putendl_fd("Error\nINCORRECT EXTENTION", 2), 1);
        else if(ft_stack(file) == -1)
            return (1);
    }
    else
        return (ft_putendl_fd("Error\nARGUMENT INCORRECT", 2), 1);
    return (0);
}
