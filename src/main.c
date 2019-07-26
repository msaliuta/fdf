/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <msaliuta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 21:20:26 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/26 03:25:21 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void				ft_reset_iso(t_m *m)
{
	m->depth = 0;
	m->shift_ud = -WIDTH / 3;
	m->shift_lr = HEIGHT / 3 * 2;
	m->zoom = 2000;
	m->prsp = 1;
	C.r = M;
	C.g = M;
	C.b = M;
	m->prior = 0;
}

void				ft_reset_paral(t_m *m)
{
	m->depth = 0;
	m->shift_ud = 70;
	m->shift_lr = HEIGHT / 4 * 3;
	m->zoom = 40;
	m->prsp = 0;
	C.r = M;
	C.g = M;
	C.b = M;
	m->prior = 0;
}

void				ft_get_map_hight(t_m *m)
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
	m->dot = ft_get_coord(m);
	ft_get_map_hight(m);
	ft_build_mlx(m);
	free(m->map);
	free(m->dot);
	free(m);
	return (0);
}

static int			ft_loop_key_hook(t_m *m)
{
	int endian;
	int bpp;

	m->ret = mlx_get_data_addr(m->img, &bpp, &(m->size_line), &endian);
	ft_put_point(m);
	mlx_put_image_to_window(m->mlx, m->win, m->img, 0, 0);
	mlx_destroy_image(m->mlx, m->img);
	m->img = mlx_new_image(m->mlx, WIDTH, HEIGHT);
	ft_print_info(m);
	return (0);
}
