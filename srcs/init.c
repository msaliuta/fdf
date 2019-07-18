/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 20:54:56 by mikim             #+#    #+#             */
/*   Updated: 2017/04/03 20:54:57 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_init_pt(t_env *e)
{
	int i;

	i = -1;
	e->pt = (t_point**)malloc(sizeof(t_point*) * e->m_y);
	while (++i < e->m_y)
		e->pt[i] = (t_point*)malloc(sizeof(t_point) * e->m_x);
}

void	ft_init_env(t_env *e)
{
	e->g_zoom = 0;
	e->zoom_x = 0;
	e->zoom_y = 0;
	e->rot_x = 0;
	e->rot_y = 0;
	e->move_x = 0;
	e->move_y = 0;
	e->alt = 0;
	e->color = 21;
}

int		ft_key_hook(int keycode, t_env *e)
{
	keycode == 53 ? exit(0) : 0;
	keycode == 0 ? e->rot_x -= 6 : 0;
	e->rot_x == -6 ? e->rot_x = 354 : 0;
	keycode == 2 ? e->rot_x += 6 : 0;
	e->rot_x == 366 ? e->rot_x = 6 : 0;
	keycode == 13 ? e->rot_y -= 6 : 0;
	e->rot_y == -6 ? e->rot_y = 354 : 0;
	keycode == 1 ? e->rot_y += 6 : 0;
	e->rot_y == 366 ? e->rot_y = 6 : 0;
	keycode == 12 ? e->alt += 1 : 0;
	keycode == 14 ? e->alt -= 1 : 0;
	keycode == 126 ? e->move_y -= 9 : 0;
	keycode == 125 ? e->move_y += 9 : 0;
	keycode == 123 ? e->move_x -= 9 : 0;
	keycode == 124 ? e->move_x += 9 : 0;
	keycode == 69 ? e->g_zoom += 1 : 0;
	keycode == 78 ? e->g_zoom -= 1 : 0;
	if (18 <= keycode && keycode <= 21)
		e->color = keycode;
	ft_coord(e, -1, -1);
	ft_draw(e);
	return (0);
}
