/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*         fdf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleite <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/02 07:10:11 by vleite            #+#    #+#             */
/*   Updated: 2016/09/20 17:40:18 by vleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	malcoor(t_mlx *mlx)
{
	int i;
	int j;

	i = 0;
	j = 0;
	mlx->put.coor = (int ***)malloc(sizeof(int**) * mlx->tab.i);
	while (i <= mlx->tab.i)
	{
		mlx->put.coor[i] = (int **)malloc(sizeof(int *) * mlx->tab.j);
		while (j <= mlx->tab.j)
		{
			mlx->put.coor[i][j] = (int *)malloc(sizeof(int) * 2);
			j++;
		}
		i++;
	}
	//mlx->put.coor[0][0][0] = 12;
	printf("%d", mlx->put.coor[0][0][0]);
}

void	move(int keycode, t_mlx *mlx)
{
	erase(mlx);
	if (keycode == 123)
		mlx->x = mlx->x - 4;
	if (keycode == 124)
		mlx->x = mlx->x + 4;
	if (keycode == 125)
		mlx->y = mlx->y + 40;
	if (keycode == 126)
		mlx->y = mlx->y - 40;
	mlx->tmpx = mlx->x;
	mlx->tmpy = mlx->y;
	pixel_put(mlx);
}
