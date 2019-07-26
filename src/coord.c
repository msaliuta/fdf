/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <msaliuta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 21:21:01 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/26 08:16:15 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static t_dot		*new_coords(int x, int y, int z, t_map *map)
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

void				stock_coord(int i, int y, t_dot ***dot, t_m *m)
{
	while (++y < m->map->x)
		if (m->map->tmp[y] && m->map->tmp[y][0] != '\n')
		{
			dot[i][y] = new_coords(y, i, ft_atoi(m->map->tmp[y]), m->map);
			free(m->map->tmp[y]);
		}
	free(m->map->tmp);
}
