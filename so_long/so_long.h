/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 22:14:20 by rbouizer          #+#    #+#             */
/*   Updated: 2024/07/25 23:30:51 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "utils/utils.h"
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

int open_fd(char *file);
char *read_fd(int fd);
int close_fd(int fd);

char *ft_allocat(int fd);
void cleanup(char **str, int fd);

int ex_ber(char *str, int i);
int fd_line(char *file);
int ft_count (char **strs, char c);

int ft_stack(char *file);

#endif
