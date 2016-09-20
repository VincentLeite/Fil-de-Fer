/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleite <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 17:40:37 by vleite            #+#    #+#             */
/*   Updated: 2016/09/20 17:52:06 by vleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		pixel_put_zero(t_mlx *mlx)
{
	int i;
	int j;
	int tmp;

	i = 0;
	tmp = 0;

}

void		pixel_put(t_mlx *mlx)
{
	if (mlx->nbr == 0)
		pixel_put_zero(mlx);
	if (mlx->nbr == 1)
		pixel_put_one(mlx);
	if (mlx->nbr == 2)
		pixel_put_two(mlx);
	if (mlx->nbr == 3)
		pixel_put_three(mlx);
}
