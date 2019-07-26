/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_mlx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <msaliuta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 21:20:16 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/26 03:30:00 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_init(t_m *m)
{
	m->shift_ud = -WIDTH / 3;
	m->shift_lr = HEIGHT / 3 * 2;
	m->zoom = 2000;
	m->prsp = 1;
	C.r = M;
	C.g = M;
	C.b = M;
	m->depth = 0;
	m->prior = 0;
	C.qr = 0;
	C.qb = 0;
	C.qg = 0;
}

void				ft_put_point(t_m *m)
{
	int				i;
	int				j;

	i = -1;
	while ((++i < m->dot[0][0]->size_y) && (j = -1))
		while (++j < m->dot[i][0]->size_x)
		{
			m->prsp == 1 ? ft_iso_persp(m, i, j) : 0;
			m->prsp == 0 ? ft_paral_persp(m, i, j) : 0;
		}
}

void				init_colors(t_m *m)
{
	C.r = 0;
	C.g = 0;
	C.b = 0;
	m->prior = 0;
}

int					ft_key_hook(int keycode, t_m *m)
{
	m->key = keycode;
	if (m->key == ESC)
	{
		system("leaks -q fdf");
		exit(1);
	}
	m->key == UP ? m->shift_ud -= 30 : 0;
	m->key == DOWN ? m->shift_ud += 30 : 0;
	m->key == RIGHT ? m->shift_lr += 30 : 0;
	m->key == LEFT ? m->shift_lr -= 30 : 0;
	m->key == DEEP ? m->depth += 1 : 0;
	m->key == UNDEEP ? m->depth -= 1 : 0;
	if (m->key == ZOOM && m->prsp == 1)
	{
		m->zoom += 50;
		m->shift_lr -= 25;
		m->shift_ud -= 25;
	}
	else if (m->key == ZOOM && m->prsp != 1)
	{
		m->zoom += 10;
		m->shift_lr -= 5;
		m->shift_ud -= 5;
	}
	if (m->key == DEZOOM && m->prsp == 1)
	{
		m->zoom -= 50;
		m->shift_lr += 25;
		m->shift_ud += 25;
	}
	else if (m->key == DEZOOM && m->prsp != 1)
	{
		m->zoom -= 10;
		m->shift_lr += 5;
		m->shift_ud += 5;
	}
	m->key == R_ISO ? ft_reset_iso(m) : 0;
	m->key == R_PAR ? ft_reset_paral(m) : 0;
	m->key == 89 ? m->prior = 1 : 0;
	m->key == 91 ? m->prior = 2 : 0;
	m->key == 92 ? m->prior = 3 : 0;
	m->key == 82 ? init_colors(m) : 0;
	if (m->key == 86)
	{
		C.qr = (C.qr - 5 > -M & m->prior == 1) ? C.qr - 5 : -M;
		C.r = (C.r - 5) < 0 ? 0 : C.r - 5;
	}
	if (m->key == 87)
	{
		C.qg = (C.qg - 5 > -M & m->prior == 2) ? C.qg - 5 : -M;
		C.g = (C.g - 5) < 0 ? 0 : C.g - 5;
	}
	if (m->key == 88)
	{
		C.qb = (C.qb - 5 > -M & m->prior == 3) ? C.qb - 5 : -M;
		C.b = (C.b - 5) < 0 ? 0 : C.b - 5;
	}
	if (m->key == 83)
	{
		C.qr = (C.qr + 5 < 0 & m->prior == 1) ? C.qr + 5 : 0;
		C.r = (C.r + 5) > M ? M : C.r + 5;
	}
	if (m->key == 84)
	{
		C.qg = (C.qg + 5 < 0 & m->prior == 2) ? C.qg + 5 : 0;
		C.g = (C.g + 5) > M ? M : C.g + 5;
	}
	if (m->key == 85)
	{
		C.qb = (C.qb + 5 < 0 & m->prior == 3) ? C.qb + 5 : 0;
		C.b = (C.b + 5) > M ? M : C.b + 5;
	}
	ft_loop_key_hook(m);
	return (0);
}

int					exit_x(void)
{
	system("leaks -q fdf");
	exit(1);
}

int					ft_build_mlx(t_m *m)
{
	ft_init(m);
	m->mlx = mlx_init();
	m->win = mlx_new_window(m->mlx, WIDTH, HEIGHT, "fdf by msaliuta");
	m->img = mlx_new_image(m->mlx, WIDTH, HEIGHT);
	mlx_hook(m->win, 2, 2, ft_key_hook, m);
	mlx_hook(m->win, 17, 1L << 17, exit_x, m);
	mlx_loop(m->mlx);
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
