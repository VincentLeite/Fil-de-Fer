/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleite <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 17:39:59 by vleite            #+#    #+#             */
/*   Updated: 2016/09/20 17:23:47 by vleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H
# include "mlx.h"
# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct  s_tab
{
    int         i;
    int         j;
    int         **tab;
}               t_tab;

typedef struct	s_put
{
	int			x;
	int			y;
	int			***coor;
}			   t_put;

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	int			nbr;
	int			x;
	int			y;
	int			tmpx;
	int			tmpy;
	t_tab		tab;
	t_put		put;
}				t_mlx;

void	gettab(char *str, t_mlx *mlx);
void	pixel_put(t_mlx *mlx);
int		get_next_line(int const fd, char **line);
void	erase(t_mlx *mlx);
void	malcoor(t_mlx *mlx);
void	move(int keycode, t_mlx*mlx);

#endif
