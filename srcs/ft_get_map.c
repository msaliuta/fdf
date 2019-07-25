/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <msaliuta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 21:21:01 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/26 00:37:42 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int					ft_count_size(int fd)
{
	char			*line;
	int				count;
	int				spaces;
	int				tmp;
	int				i;

	tmp = 0;
	count = 0;
	while (get_next_line(fd, &line) != 0 && (i = -1))
	{
		spaces = 0;
		while (line[++i] && line[0] != '\0')
			if (((line[i] >= 48 && line[i] <= 57) || (line[i] >= 65 && line[i]
				<= 90) || (line[i] >= 97 && line[i] <= 122)) &&
				(line[i + 1] == ' ' || line[i + 1] == '\0'))
				spaces++;
		count++;
		free(line);
		if (tmp != 0 && (tmp != spaces))
			ft_exit_error();
		tmp = spaces;
	}
	return (count);
}

void				ft_get_map(t_af *af)
{
	int				i;
	int				fd;
	char			*line;

	af->map->y = 0;
	fd = open(af->map->argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("Invalid argument\n");
		system("leaks -q fdf");
		exit(1);
	}
	read(fd, 0, 0) < 0 ? ft_exit_error() : 0;
	af->map->y = ft_count_size(fd);
	af->map->y == 0 ? ft_exit_error() : 0;
	close(fd);
	fd = open(af->map->argv[1], O_RDONLY);
	af->map->map = (char **)malloc(sizeof(char *) * af->map->y + 1);
	while ((get_next_line(fd, &line)) != 0)
		if (line[0] != '\0')
			af->map->map[i++] = line;
		else
			af->map->y--;
	close(fd);
}

static	t_dot		*ft_new_coord(int x, int y, int z, t_map *map)
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

void				ft_stock_coord(int i, int y, t_dot ***dot, t_af *af)
{
	while (++y < af->map->x)
		if (af->map->tmp[y] && af->map->tmp[y][0] != '\n')
		{
			dot[i][y] = ft_new_coord(y, i, ft_atoi(af->map->tmp[y]), af->map);
			free(af->map->tmp[y]);
		}
	free(af->map->tmp);
}

t_dot				***ft_get_coord(t_af *af)
{
	int				i;
	t_dot			***dot;

	i = -1;
	ft_get_map(af);
	if (!(dot = (t_dot ***)malloc(sizeof(t_dot **) * af->map->y + 1)))
		return (NULL);
	while (++i < af->map->y)
	{
		af->map->tmp = ft_strsplit(af->map->map[i], ' ');
		af->map->x = 0;
		while (af->map->tmp[af->map->x])
			af->map->x++;
		if (!(dot[i] = (t_dot **)malloc(sizeof(t_dot *) * (af->map->x + 1))))
			return (NULL);
		ft_stock_coord(i, -1, dot, af);
	}
	af->map->tmp = NULL;
	return (dot);
}
