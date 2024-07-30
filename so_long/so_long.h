/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 22:14:20 by rbouizer          #+#    #+#             */
/*   Updated: 2024/07/30 03:51:14 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "utils/utils.h"
#include <stdio.h>
#include <fcntl.h>
# include <mlx.h>
#include <string.h>

#define A "textures/A.xpm"
#define D "textures/D.xpm"
#define S "textures/S.xpm"
#define W "textures/W.xpm"
#define MUR "textures/mur.xpm"
#define GAZ "textures/gazon.xpm"
#define EXIT "textures/EXIT.xpm"
#define COL "textures/collect.xpm"

typedef struct s_map
{
	char	**map;
	char	**copy;
	void	*mlx;
	void	*win;
	void	*img;
	int		lx;
	int		ly;
	int		x;
	int		y;
	int		nc;
	int		move;
}	t_map;

int open_fd(char *file);
char *read_fd(int fd);
int close_fd(int fd);

char *ft_allocat(int fd);
void cleanup(char **str);

int ex_ber(char *str, int i);
int fd_line(char *file);
int ft_count (char **strs, char c);

int ft_stack(char *file);
int ft_chack_map(char **map, int y, int x);

int ft_find_x(char **s, char c);
int ft_find_y(char **s, char c);

void ft_maps(t_map *maps);

#endif
