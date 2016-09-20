/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getnbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleite <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 18:01:13 by vleite            #+#    #+#             */
/*   Updated: 2016/09/03 16:15:08 by vleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int		count(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while(str[i] != '\0')
	{
		if(str[i] != ' ' && str[i] != '\0')
		{
			count++;
			while(str[i] != ' ' && str[i] != '\0')
				i++;
		}
		if(str[i] == ' ')
			i++;
	}
	return (count);
}

void	maltab(int fd, t_mlx *mlx)
{
	int		n;
	int		**tab;
	char	*line;

	n = 0;
	mlx->tab.i = 0;
	while(get_next_line(fd, &line))
	{
		if(mlx->tab.i == 0)
			mlx->tab.j = count(line);
		mlx->tab.i++;
	}
	tab = (int **)malloc(sizeof(int *) * mlx->tab.i);
	while(n <= mlx->tab.i)
	{
		tab[n] = (int *)malloc(sizeof(int) * mlx->tab.j);
		n++;
	}
	mlx->tab.tab = tab;
}

void	getint(int i, t_mlx *mlx, char *line)
{
	int	j;
	int n;

	j = 0;
	n = 0;
	while(line[j] != '\0')
	{
		if(line[j] != ' ' && line[j] != '\0' && line[j] != '-')
		{
			mlx->tab.tab[i][n] = line[j] - '0';
			if (j != 0 && line[j-1] == '-')
				mlx->tab.tab[i][n] = mlx->tab.tab[i][n] * -1;
			j++;
			while(line[j] != ' ' && line[j] != '\0')
			{
				mlx->tab.tab[i][n] = (mlx->tab.tab[i][n] * 10) + (line[j] - '0');
				j++;
			}
			n++;
		}
		if(line[j] == ' ' || line[j] == '-')
			j++;
	}
}

void	gettab(char *str, t_mlx *mlx)
{
	int		fd;
	int		fd2;
	int		i;
	char	*line;

	i = 0;
	fd = open(str, O_RDONLY);
	fd2 = open(str, O_RDONLY);
	maltab(fd, mlx);
	close(fd);
	while(get_next_line(fd2, &line))
	{
		getint(i, mlx, line);
		i++;
	}
}
