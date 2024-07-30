/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 19:48:49 by rbouizer          #+#    #+#             */
/*   Updated: 2024/07/30 06:19:47 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void flood_fill(char **map, int y, int x)
{
    if (map[y][x] == 'E')
        map[y][x] = '1';
    
    if (map[y][x] != '1')
    {
        map[y][x] = '1';
        flood_fill(map, y - 1, x);
        flood_fill(map, y + 1, x);
        flood_fill(map, y, x - 1);
        flood_fill(map, y, x + 1);
    }
}

int ft_chack_map(char **map, int y, int x)
{
    flood_fill(map,y,x);
    if (ft_count (map, 'E') != 0)
    {
        cleanup(map);
        return (ft_putendl_fd("Error\nPlayer does not have access to EXIT", 2), 1);
    }
    else if (ft_count (map, 'C') != 0)
    {
        cleanup(map);
        return (ft_putendl_fd("Error\nPlayer does not have access to all collectible", 2), 1);
    }
    cleanup(map);
    return(0);
}