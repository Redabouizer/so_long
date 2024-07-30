/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 18:49:22 by rbouizer          #+#    #+#             */
/*   Updated: 2024/07/30 06:23:41 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int ft_is_elem(char c)
{
    if (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P')
        return (1);
    return (0);
}

int ft_one(char *str, int len)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] != '1')
            return (ft_putendl_fd("Error\nFirst and last lines must contain only '1'", 2), 1);
        i++;
    }
    if (i == len)
        return (0);
    return (ft_putendl_fd("Error\nLine length must be consistent", 2), 1);
}

int ft_ml(char *str, int len)
{
    int i;
    int l;

    l = ft_strlen(str);
    i = 0;
    if (str[0] != '1' || str[l - 1] != '1')
        return (ft_putendl_fd("Error\nLines must start and end with '1'", 2), 1);
    while (str[i])
    {
        if (!ft_is_elem(str[i]))
            return (ft_putendl_fd("Error\nInvalid character in the map", 2), 1);
        i++;
    }
    if (i == len)
        return (0);
    return (ft_putendl_fd("Error\nLine length must be consistent", 2), 1);
}

int ft_check(char **str, int len)
{
    int i;
    int l;

    l = ft_strlen(str[0]);
    i = -1;
    while (str[++i])
    {
        if (i == 0 || i == (len - 1))
        {
            if (ft_one(str[i], l) == 1)
                return (1);
        }
        else
        {
            if (ft_ml(str[i], l) == 1)
                return (1);
        }
    }
    if ((ft_count(str, 'C') == 0) || (ft_count(str, 'E') != 1) || (ft_count(str, 'P') != 1))
        return (ft_putendl_fd("Error\nThere must be exactly one 'E', one 'P', and at least one 'C'", 2), 1);
    return (0);
}

t_map *add_maps(char *s, int len)
{
    t_map *maps = malloc(sizeof(t_map));
    if (!maps)
        return (ft_putendl_fd("Error\nFailed to allocate memory for t_map", 2), NULL);

    maps->map = ft_split(s, '\n');
    maps->copy = ft_split(s, '\n');
    maps->lx = ft_strlen(maps->map[0]);
    maps->ly = len;
    maps->x = ft_find_x(maps->map, 'P');
    maps->y = ft_find_y(maps->map, 'P');
    maps->nc = ft_count(maps->map, 'C');
    maps->move = 0;

    return (maps);
}



int ft_stack(char *file)
{
    int i;
    char **str;
    char *s;
    int fd;
    int len;
    t_map *map;

    str = NULL;
    i = 0;
    len = fd_line(file);
    if (len < 0)
        return (-1);
    fd = open_fd(file);
    if (fd < 0)
        return (-1);
    s = ft_allocat(fd);
    str = ft_split(s, '\n');
    if (!str || !s)
        return (ft_putendl_fd("Error\nEmpty place in file", 2), close(fd), -1);
    if (ft_check(str, len) == 1)
        return (cleanup(str), close(fd), -1);
    close(fd);
    map = add_maps(s, len);
    free(s);
    if (!map)
        return (cleanup(str), -1);
    ft_chack_map(map->copy, map->y, map->x);
    ft_maps(map);
    return (0);
}


