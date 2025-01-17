/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 19:39:19 by rbouizer          #+#    #+#             */
/*   Updated: 2024/07/30 02:54:06 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int ex_ber(char *str, int i)
{
	if (str[i] == '.' && str[i + 1] == 'b' && str[i + 2] == 'e'
		&& str[i + 3] == 'r' && str[i + 4] == '\0')
	{
		return 0; 
	}
	return 1; 
}

int fd_line(char *file)
{
    char *str;
    int fd;
    int i;

    i = 0;
    fd = open_fd(file);
    if (fd < 0)
        return (-1);
    str = read_fd(fd);
    while (str != NULL)
    {
        free(str);
        str = read_fd(fd);
        i++;
    }
    if (close_fd(fd) < 0)
        return (-1);
    return i;
}

char *ft_allocat(int fd )
{
    int i;
	char *str;
	char *str1;

	str1 = NULL;
	str = read_fd(fd);
    while (str != NULL)
    {
        i = 0;
        while(str[i]  == ' ' &&  str[i]  != '\n')
            i++;
        if(str[i]  == '\n')
            return (free(str1), free(str), NULL);
		str1 = ft_strjoin(str1, str);
        free(str);
        str = read_fd(fd);
    }
    return str1;
}

void cleanup(char **str)
{
    int i = 0;

    if (!str)
        return;

    while (str[i] != NULL)
    {
        free(str[i]);
        i++;
    }
    free(str);
}

int ft_count (char **strs, char c)
{
	int i;
	int nbr;
	int count;

	i = 0;
	count = 0;
	while (strs[i])
	{
		nbr = 0;
		while (strs[i][nbr])
		{
			if(strs[i][nbr] == c)
				count++;
			nbr++;
		}
		i++;
	}
	return count;
}
