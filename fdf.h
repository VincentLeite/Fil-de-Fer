/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleite <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 17:39:59 by vleite            #+#    #+#             */
/*   Updated: 2016/04/05 00:51:13 by vleite           ###   ########.fr       */
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

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	t_tab		tab;
}				t_mlx;

void	gettab(char *str, t_mlx *mlx);
int		get_next_line(int const fd, char **line);

#endif
