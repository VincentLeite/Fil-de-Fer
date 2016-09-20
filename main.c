
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleite <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 17:01:37 by vleite            #+#    #+#             */
/*   Updated: 2016/09/20 17:24:25 by vleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	erase(t_mlx *mlx)
{
	mlx_clear_window(mlx->mlx, mlx->win);
}

int		my_key_funct(int keycode, t_mlx *mlx)
{
	printf("keycode = %d\n", mlx->put.coor[0][0][0]);
	if (keycode >= 123 && keycode <= 126)
		move(keycode, mlx);
	if (keycode == 69)
	{
		erase(mlx);
		mlx->put.x++;
		pixel_put(mlx);
	}
	if (keycode == 78 && mlx->put.x > 0)
	{
		erase(mlx);
		mlx->put.x--;
		pixel_put(mlx);
	}
	if (keycode == 67)
	{
		erase(mlx);
		mlx->put.y++;
		pixel_put(mlx);
	}
	if (keycode == 75 && mlx->put.y > 0)
	{
		erase(mlx);
		mlx->put.y--;
		pixel_put(mlx);
	}
	if (keycode == 53)
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		free(mlx);
		exit(0);
	}
	return (0);
}

t_mlx	*mlxinit()
{
	t_mlx *mlx;

	mlx = malloc(sizeof(t_mlx));
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, 1000, 1000, "42");
	mlx->put.x = 10;
	mlx->x = -1;
	mlx->y = 250;
	mlx->nbr = 0;
	mlx->tmpx = mlx->x;
	mlx->tmpy = mlx->y;
	return (mlx);
}

int		main(int ac, char **av)
{
	t_mlx	*mlx;

	mlx = mlxinit();
	if (ac == 2)
	{
		gettab(av[1], mlx);
		malcoor(mlx);
		pixel_put(mlx);
		mlx_key_hook(mlx->win, my_key_funct, mlx);
		mlx_loop(mlx);
	}
	return (0);
}
