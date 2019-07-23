/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <msaliuta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 21:21:01 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/23 18:29:18 by msaliuta         ###   ########.fr       */
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

	i = 0;
	af->map->y = 0;
	fd = open(af->map->argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("Invalid argument\n");
		system("leaks fdf");
		exit(1);
	}
	af->map->y = ft_count_size(fd);
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

static	t_point		*ft_new_coord(int x, int y, int z, t_map *map)
{
	t_point			*point;

	if (!(point = (t_point *)malloc(sizeof(t_point))))
		return (NULL);
	point->size_x = (map->x);
	point->size_y = (map->y);
	point->z = z;
	point->x = x - point->size_x / 2;
	point->y = y - map->y / 2;
	return (point);
}

void				ft_stock_coord(int i, int y, t_point ***point, t_af *af)
{
	while (++y < af->map->x)
		if (af->map->tmp[y] && af->map->tmp[y][0] != '\n')
		{
			point[i][y] = ft_new_coord(y, i, ft_atoi(af->map->tmp[y]), af->map);
			free(af->map->tmp[y]);
		}
	free(af->map->tmp);
}

t_point				***ft_get_coord(t_af *af)
{
	int				i;
	t_point			***point;

	i = -1;
	ft_get_map(af);
	if (!(point = (t_point ***)malloc(sizeof(t_point **) * af->map->y + 1)))
		return (NULL);
	while (++i < af->map->y)
	{
		af->map->tmp = ft_strsplit(af->map->map[i], ' ');
		af->map->x = 0;
		while (af->map->tmp[af->map->x])
			af->map->x++;
		if (!(point[i] = (t_point **)malloc(sizeof(t_point *) * (af->map->x + 1))))
			return (NULL);
		ft_stock_coord(i, -1, point, af);
	}
	af->map->tmp = NULL;
	return (point);
}
