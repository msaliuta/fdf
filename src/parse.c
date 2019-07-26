/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <msaliuta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 07:02:15 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/26 08:24:56 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_dot				***parse_coords(t_m *m)
{
	int				i;
	t_dot			***dot;

	i = -1;
	parse_map(m);
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
		stock_coord(i, -1, dot, m);
	}
	m->map->tmp = NULL;
	return (dot);
}

void				parse_map(t_m *m)
{
	int				i;
	int				fd;
	char			*line;

	m->map->y = 0;
	fd = open(m->map->argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("Invalid argument\n");
		exit(1);
	}
	read(fd, 0, 0) < 0 ? exit_map() : 0;
	m->map->y = parse_nbr(fd);
	m->map->y == 0 ? exit_map() : 0;
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

int					parse_nbr(int fd)
{
	char			*str;
	int				nbr;
	int				sps;
	int				tmp;
	int				i;

	nbr = 0;
	tmp = 0;
	while (get_next_line(fd, &str) != 0 && (i = -1))
	{
		sps = 0;
		while (str[++i] && str[0] != '\0')
			if (((str[i] >= 48 && str[i] <= 57) || (str[i] >= 65 && str[i]
				<= 90) || (str[i] >= 97 && str[i] <= 122)) &&
				(str[i + 1] == ' ' || str[i + 1] == '\0'))
				sps++;
		nbr++;
		free(str);
		if (tmp != 0 && (tmp != sps))
			exit_map();
		tmp = sps;
	}
	return (nbr);
}

void				put_point(t_m *m)
{
	int				i;
	int				j;

	i = -1;
	while ((++i < m->dot[0][0]->size_y) && (j = -1))
		while (++j < m->dot[i][0]->size_x)
		{
			m->prsp == 1 ? iso(m, i, j) : 0;
			m->prsp == 0 ? paral(m, i, j) : 0;
		}
}
