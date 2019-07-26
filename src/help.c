/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <msaliuta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 21:20:34 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/26 08:24:44 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void				non_zero_c(t_m *m, int q)
{
	if (m->prior == 0)
		return ;
	m->prior == 1 ? C.r = q - C.qr : 0;
	m->prior == 2 ? C.g = q - C.qg : 0;
	m->prior == 3 ? C.b = q - C.qb : 0;
}

void				rules_print(t_m *m)
{
	char			*str;

	str = " If you press 7,8,9 colors g,r,b will work only for non zero dots.";
	mlx_string_put(m->mlx, m->win, 1900, 90, WHITE, str);
	str = " Press 1,2,3 to increase g,r,b";
	mlx_string_put(m->mlx, m->win, 1900, 30, WHITE, str);
	str = " Press 4,5,6 to reduce g,r,b";
	mlx_string_put(m->mlx, m->win, 1900, 50, WHITE, str);
	str = " Press 0 to zero all colors";
	mlx_string_put(m->mlx, m->win, 1900, 70, WHITE, str);
	mlx_string_put(m->mlx, m->win, 2140, 110, WHITE, " g:");
	str = ft_itoa(C.r);
	mlx_string_put(m->mlx, m->win, 2175, 110, WHITE, str);
	free(str);
	mlx_string_put(m->mlx, m->win, 2140, 130, WHITE, " r:");
	str = ft_itoa(C.g);
	mlx_string_put(m->mlx, m->win, 2175, 130, WHITE, str);
	free(str);
	mlx_string_put(m->mlx, m->win, 2140, 150, WHITE, " b:");
	str = ft_itoa(C.b);
	mlx_string_put(m->mlx, m->win, 2175, 150, WHITE, str);
	free(str);
	pront_colo_menu(m, str);
}

int					key_hooks(int keycode, t_m *m)
{
	m->key = keycode;
	if (m->key == ESC)
	{
		exit(1);
	}
	m->key == UP ? m->shift_ud -= 30 : 0;
	m->key == DOWN ? m->shift_ud += 30 : 0;
	m->key == RIGHT ? m->shift_lr += 30 : 0;
	m->key == LEFT ? m->shift_lr -= 30 : 0;
	m->key == DEEP ? m->depth += 1 : 0;
	m->key == UNDEEP ? m->depth -= 1 : 0;
	m->key == R_ISO ? init_iso(m) : 0;
	m->key == R_PAR ? init_paral(m) : 0;
	return (hook_zoom(m));
}

int					hook_zoom(t_m *m)
{
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
	return (colors_keys(m));
}
