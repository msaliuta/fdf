/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <msaliuta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 21:20:26 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/26 08:24:52 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void				exit_map(void)
{
	ft_putstr("Invalid map\n");
	exit(1);
}

int					exit_x(void)
{
	exit(1);
}

int					start_mlx(t_m *m)
{
	char	*str;

	init(m);
	m->mlx = mlx_init();
	m->win = mlx_new_window(m->mlx, WIDTH, HEIGHT, "fdf by msaliuta");
	m->img = mlx_new_image(m->mlx, WIDTH, HEIGHT);
	str = "PRESS ANY KEY";
	mlx_string_put(m->mlx, m->win, 1216, 150, WHITE, str);
	mlx_hook(m->win, 2, 2, key_hooks, m);
	mlx_hook(m->win, 17, 87654, exit_x, m);
	mlx_loop(m->mlx);
	return (0);
}

void				map_height(t_m *m)
{
	int				i;
	int				j;

	i = -1;
	while (++i < m->dot[0][0]->size_y && (j = -1))
		while (++j < m->dot[i][0]->size_x)
		{
			m->dot[i][j]->z > m->max_hight ? m->max_hight = m->dot[i][j]->z : 0;
			if (m->dot[i][j]->z < m->min_hight)
				m->min_hight = m->dot[i][j]->z;
		}
}

int					main(int argc, char **argv)
{
	t_m			*m;

	if (argc != 2)
	{
		ft_putstr("Invalide argument\n");
		return (0);
	}
	m = (t_m *)malloc(sizeof(t_m));
	m->map = (t_map *)malloc(sizeof(t_map));
	m->map->argv = argv;
	m->dot = parse_coords(m);
	map_height(m);
	start_mlx(m);
	free(m->map);
	free(m->dot);
	free(m);
	return (0);
}
