/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <msaliuta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 06:41:59 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/26 08:19:52 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int			key_hook_loop(t_m *m)
{
	int endian;
	int bpp;

	m->ret = mlx_get_data_addr(m->img, &bpp, &(m->size_line), &endian);
	put_point(m);
	mlx_put_image_to_window(m->mlx, m->win, m->img, 0, 0);
	mlx_destroy_image(m->mlx, m->img);
	m->img = mlx_new_image(m->mlx, WIDTH, HEIGHT);
	rules_print(m);
	return (0);
}

void				pront_colo_menu(t_m *m, char *str)
{
	if (m->prior == 1)
	{
		str = "Green";
		mlx_string_put(m->mlx, m->win, 2140, 190, WHITE, str);
	}
	if (m->prior == 2)
	{
		str = "Red";
		mlx_string_put(m->mlx, m->win, 2140, 190, WHITE, str);
	}
	if (m->prior == 3)
	{
		str = "Blue";
		mlx_string_put(m->mlx, m->win, 2140, 190, WHITE, str);
	}
	str = " If you press w,a,s,d you will move map";
	mlx_string_put(m->mlx, m->win, 100, 30, WHITE, str);
	str = " If you press q,e you will move non zero cords";
	mlx_string_put(m->mlx, m->win, 100, 50, WHITE, str);
	str = " If you press arroц down or up you will zoom picture.";
	mlx_string_put(m->mlx, m->win, 100, 70, WHITE, str);
	str = " FOR RIGHT SIDE OF KEYBOARD";
	mlx_string_put(m->mlx, m->win, 1900, 15, WHITE, str);
}

int					colors_keys(t_m *m)
{
	m->key == 89 ? m->prior = 1 : 0;
	m->key == 91 ? m->prior = 2 : 0;
	m->key == 92 ? m->prior = 3 : 0;
	m->key == 82 ? init_colors(m) : 0;
	if (m->key == 86)
	{
		C.qr = (C.qr - 5 > -M & m->prior == 1) ? C.qr - 5 : -M;
		C.r = ((C.r - 5) < 0 & m->prior != 1) ? 0 : C.r - 5;
	}
	if (m->key == 87)
	{
		C.qg = (C.qg - 5 > -M & m->prior == 2) ? C.qg - 5 : -M;
		C.g = ((C.g - 5) < 0 & m->prior != 2) ? 0 : C.g - 5;
	}
	if (m->key == 88)
	{
		C.qb = (C.qb - 5 > -M & m->prior == 3) ? C.qb - 5 : -M;
		C.b = ((C.b - 5) < 0 & m->prior != 3) ? 0 : C.b - 5;
	}
	return (colors_up(m));
}

int					colors_up(t_m *m)
{
	if (m->key == 83)
	{
		C.qr = (C.qr + 5 < 0 & m->prior == 1) ? C.qr + 5 : 0;
		C.r = ((C.r + 5) > M & m->prior != 1) ? M : C.r + 5;
	}
	if (m->key == 84)
	{
		C.qg = (C.qg + 5 < 0 & m->prior == 2) ? C.qg + 5 : 0;
		C.g = ((C.g + 5) > M & m->prior != 2) ? M : C.g + 5;
	}
	if (m->key == 85)
	{
		C.qb = (C.qb + 5 < 0 & m->prior == 3) ? C.qb + 5 : 0;
		C.b = ((C.b + 5) > M & m->prior != 3) ? M : C.b + 5;
	}
	key_hook_loop(m);
	return (0);
}
