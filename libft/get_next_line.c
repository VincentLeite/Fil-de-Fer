/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleite <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 09:30:11 by vleite            #+#    #+#             */
/*   Updated: 2016/04/04 23:14:26 by vleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_listgnl	*createlist(int fd)
{
	t_listgnl	*list;

	list = malloc(sizeof(t_list));
	if (list)
	{
		list->fd = fd;
		list->nbl = 0;
		list->line = 0;
		list->next = NULL;
		return (list);
	}
	else
		return (NULL);
}

t_listgnl	*getlist(int fd)
{
	static t_listgnl	*begin = NULL;
	t_listgnl			*list;
	t_listgnl			*tmp;

	if (begin == NULL)
	{
		list = createlist(fd);
		begin = list;
		return (list);
	}
	list = begin;
	while (list)
	{
		if (fd == list->fd)
			return (list);
		list = list->next;
	}
	tmp = createlist(fd);
	list = begin;
	while (list->next)
		list = list->next;
	list->next = tmp;
	return (list->next);
}

void		ft_malcpy(char **line, t_listgnl *list)
{
	int i;
	int count;

	i = 0;
	count = 0;
	if (list->line == 1 && list->tab[0] != '\0')
		list->tab = &(list->tab[1]);
	list->line = 1;
	while (list->tab[count] != '\n' && list->tab[count] != '\0')
		count = count + 1;
	line[0] = (char *)malloc(sizeof(char) * (count + 1));
	while (list->tab[i] != '\n' && list->tab[i] != '\0')
	{
		line[0][i] = list->tab[i];
		i = i + 1;
	}
	line[0][i] = '\0';
	list->tab = &(list->tab[i]);
}

char		*ft_malstrcat(char *tab, char *buf, int i, int n)
{
	char	*cat;

	i = (-1);
	n = (-1);
	cat = (char *)malloc(sizeof(char) * (ft_strlen(tab) + ft_strlen(buf) + 1));
	while (tab[++i] == tab[++n] && tab[n] != '\0')
		cat[n] = tab[i];
	i = (-1);
	while (buf[++i] != '\0' && buf[i] != EOF)
	{
		cat[n] = buf[i];
		n = n + 1;
	}
	cat[n] = '\0';
	ft_strdel(&tab);
	return (cat);
}

int			get_next_line(int const fd, char **line)
{
	t_listgnl		*list;
	char			buf[BUFF_SIZE + 1];
	int				ret;

	list = getlist(fd);
	if (list->nbl == 0)
	{
		list->tab = (char *)malloc(sizeof(char) * 1);
		while ((ret = read(list->fd, buf, BUFF_SIZE)) && ret != -1)
		{
			buf[ret] = '\0';
			list->tab = ft_malstrcat(list->tab, buf, ret, ret);
		}
		if (list->fd < 0 || line == NULL || ret == (-1))
			return (-1);
		list->nbl = 1;
	}
	ft_malcpy(line, list);
	if (line[0][0] == '\0' && list->tab[0] == '\0')
		return (0);
	return (1);
}
