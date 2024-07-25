/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 18:49:22 by rbouizer          #+#    #+#             */
/*   Updated: 2024/07/25 23:47:14 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_is_elem(char c)
{
	if(c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P' )
		return (0);
	return (1);
}

int ft_one(char *str, int len)
{
	int i;

	i = 0;
	while (str[i])
	{
		if(str[i] != '1')
			return (1);
		i++;
	}
	if( i == len)
		return (0);
	return (1);
}

int ft_ml(char *str, int len)
{
	int i;
	int l;

	l = ft_strlen(str);
	i = 0;
	while (str[i])
	{
		if(str[0] != '1' || ft_is_elem(str[i]) == 1 || str[l - 1] != '1')
			return (1);
		i++;
	}
	if( i == len)
		return (0);
	return (1);
}

int	ft_check(char **str, int len)
{
	int i;
	int l;

	l = ft_strlen(str[0]);
	i = 0;
	while (str[i])
	{
		if( i == 0 || i == (len - 1) )
		{
			if(ft_one(str[i], l) == 1)
				return 1;
		}else
		{
			if(ft_ml(str[i], l) == 1)
				return 1;
		}
		i++;
	}
	if((ft_count(str, 'C') == 0) || (ft_count(str, 'E') != 1) || (ft_count(str, 'P') != 1))
		return 1;
    return 0;
}

int	ft_stack(char *file)
{
	int		i;
	char	**str;
	char	*s;
	int		fd;
	int		len;

	str= NULL;
	i = 0;
	len = fd_line(file);
	if (len < 0)
		return (-1);
	fd = open_fd(file);
	if (fd < 0)
		return (-1);
	s = ft_allocat(fd);
	str = ft_split(s,'\n');
	if (!str || s[0] == '\n')
		return (close(fd),-1);
	if (ft_check(str, len) == 1)
	     return (cleanup(str, fd),-1);
	return (cleanup(str, fd), 0);
}
