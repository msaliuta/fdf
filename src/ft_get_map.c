/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <msaliuta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 21:21:01 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/26 03:42:18 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int					ft_count_size(int fd)
{
	char			*line;
	int				n;
	int				sps;
	int				tmp;
	int				i;

	tmp = 0;
	n = 0;
	while (get_next_line(fd, &line) != 0 && (i = -1))
	{
		sps = 0;
		while (line[++i] && line[0] != '\0')
			if (((line[i] >= 48 && line[i] <= 57) || (line[i] >= 65 && line[i]
				<= 90) || (line[i] >= 97 && line[i] <= 122)) &&
				(line[i + 1] == ' ' || line[i + 1] == '\0'))
				sps++;
		n++;
		free(line);
		if (tmp != 0 && (tmp != sps))
			ft_exit_error();
		tmp = sps;
	}
	return (n);
}

void				ft_get_map(t_m *m)
{
	int				i;
	int				fd;
	char			*line;

	m->map->y = 0;
	fd = open(m->map->argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("Invalid argument\n");
		system("leaks -q fdf");
		exit(1);
	}
	read(fd, 0, 0) < 0 ? ft_exit_error() : 0;
	m->map->y = ft_count_size(fd);
	m->map->y == 0 ? ft_exit_error() : 0;
	close(fd);
	fd = open(m->map->argv[1], O_RDONLY);
	m->map->map = (char **)malloc(sizeof(char *) * m->map->y + 1);
	while ((get_next_line(fd, &line)) != 0)
		if (line[0] != '\0')
			m->map->map[i++] = line;
		else
			m->map->y--;
	close(fd);
}

static t_dot		*ft_new_coord(int x, int y, int z, t_map *map)
{
	t_dot			*dot;

	if (!(dot = (t_dot *)malloc(sizeof(t_dot))))
		return (NULL);
	dot->size_x = (map->x);
	dot->size_y = (map->y);
	dot->z = z;
	dot->x = dot->size_x / 2 - x;
	dot->y = map->y / 2 - y;
	return (dot);
}

void				ft_stock_coord(int i, int y, t_dot ***dot, t_m *m)
{
	while (++y < m->map->x)
		if (m->map->tmp[y] && m->map->tmp[y][0] != '\n')
		{
			dot[i][y] = ft_new_coord(y, i, ft_atoi(m->map->tmp[y]), m->map);
			free(m->map->tmp[y]);
		}
	free(m->map->tmp);
}

t_dot				***ft_get_coord(t_m *m)
{
	int				i;
	t_dot			***dot;

	i = -1;
	ft_get_map(m);
	if (!(dot = (t_dot ***)malloc(sizeof(t_dot **) * m->map->y + 1)))
		return (NULL);
	while (++i < m->map->y)
	{
		m->map->tmp = ft_strsplit(m->map->map[i], ' ');
		m->map->x = 0;
		while (m->map->tmp[m->map->x])
			m->map->x++;
		if (!(dot[i] = (t_dot **)malloc(sizeof(t_dot *) * (m->map->x + 1))))
			return (NULL);
		ft_stock_coord(i, -1, dot, m);
	}
	m->map->tmp = NULL;
	return (dot);
}
