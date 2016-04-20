/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleite <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 17:01:37 by vleite            #+#    #+#             */
/*   Updated: 2016/04/20 16:16:34 by vleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int		my_key_funct(int keycode)
{
	printf("keycode = %d", keycode);
	return (0);
}

t_mlx	*mlxinit()
{
	t_mlx *mlx;

	mlx = malloc(sizeof(t_mlx));
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, 1000, 1000, "42");
	return (mlx);
}

void	print(t_mlx *mlx)
{
	int i=0;
	int j;

	while(i < mlx->tab.i)
	{
		j = 0;
		while(j < mlx->tab.j)
		{
			printf("%d ", mlx->tab.tab[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

int		main(int ac, char **av)
{
	t_mlx	*mlx;

	mlx = mlxinit();
	if (ac == 2)
	{
		gettab(av[1], mlx);
		mlx_pixel_put(mlx->mlx, mlx->win, 200, 200, 0x00FFFFFF);
		mlx_key_hook(mlx->win, my_key_funct, mlx);
		mlx_loop(mlx);
	}
	print(mlx);
	return (0);
}
