#include "../so_long.h"

int clean_mlx(t_map *map)
{
    cleanup(map->map);
    if (map->mlx)
    {
        if (map->win)
            mlx_destroy_window(map->mlx, map->win);
    }
    exit(0);
}


void xpm_put(t_map *maps, char *s, int y, int x)
{
    int width;
    int height;
    
    maps->img = mlx_xpm_file_to_image(maps->mlx, s, &width, &height);

    if (!maps->img)
    {
        printf("Error loading image: %s\n", s);
        clean_mlx(maps);
    }

    mlx_put_image_to_window(maps->mlx, maps->win, maps->img, x * 50, y * 50);
    mlx_destroy_image(maps->mlx, maps->img);
}

void	move_player(t_map *so, int x, int y)
{
	if (so->map[so->y + y][so->x + x] == '1')
		return ;
	else if (so->map[so->y + y][so->x + x] == 'E' && so->nc == 0)
	{
		printf("move : %d\n<<<<-GOOD!!! YOU WIN->>>\n", ++so->move);
		clean_mlx(so);
	}
	else if (so->map[so->y + y][so->x + x] == 'E')
		return ;
	else if (so->map[so->y + y][so->x + x] == 'C' )
		so->nc--;
	so->map[so->y][so->x] = '0';
	so->map[so->y + y][so->x + x] = 'P';
	printf("move : %d\n", ++so->move);
	xpm_put(so, GAZ, so->y, so->x);
	so->x += x;
	so->y += y;
	if (x == -1)
		xpm_put(so, A, so->y, so->x);
	else if(x == 1)
		xpm_put(so, D, so->y, so->x);
    if (y == -1)
		xpm_put(so, W, so->y, so->x);
	else if(y == 1)
		xpm_put(so, S, so->y, so->x);
}

void ft_put_img(char c, int y, int x, t_map *maps)
{
    char *s;

    if (c == '1')
        s = MUR;
    else if (c == '0')
        s = GAZ; 
    else if (c == 'E')
        s = EXIT; 
    else if (c == 'C')
        s = COL; 
    else
        s = S;  
    xpm_put(maps, s, y, x);
}

void fill_map(t_map *maps)
{
    char **str;
    int x;
    int y;

    str = maps->map;
    y = 0;

    while (str[y] != NULL) 
    {
        x = 0;
        while (str[y][x] != '\0') 
        {
            ft_put_img(str[y][x], y, x, maps);
            x++;
        }
        y++;
    }
}

int	ft_key(int key, t_map *so)
{
	if (key == 53)
		clean_mlx(so);
	else if (key == 0 || key == 123)
		move_player(so, -1, 0);
	else if (key == 1 || key == 125)
		move_player(so, 0, 1);
	else if (key == 2 || key == 124)
		move_player(so, 1, 0);
	else if (key == 13 || key == 126)
		move_player(so, 0, -1);
	return (0);
}

void ft_maps(t_map *maps)
{
    printf("Loading[......]\n");
    maps->mlx = mlx_init();
    if (!maps->mlx)
    {
        printf("Failed to initialize mlx\n");
        cleanup(maps->map);
        exit(1);
    }
    printf("GO!!\n");
    maps->win = mlx_new_window(maps->mlx, 50 * maps->lx, 50 * maps->ly, "Window");
    if (!maps->win)
    {
        printf("Failed to create new window\n");
        clean_mlx(maps);
    }

    fill_map(maps);
    mlx_hook(maps->win, 2, 0, ft_key, maps);
    mlx_hook(maps->win, 17, 0, clean_mlx, maps);
    mlx_loop(maps->mlx);
}

