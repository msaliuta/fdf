/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 20:54:39 by mikim             #+#    #+#             */
/*   Updated: 2017/04/05 15:09:34 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
///
void	ft_coord_alt(t_env *e, int y, int x)
{
	int	neg;
	int	rot_x;
	int	rot_y;

	neg = (e->rot_x > 180 ? -1 : 1);
	e->max_z - e->min_z == 0 ? e->alt = 0 : 0;
	rot_x = (e->rot_x > 180 ? 360 - e->rot_x : e->rot_x);
	e->pt[y][x].x += ((float)(e->w_x / 2 - e->g_x) / (float)((e->m_x - 1) / 2) *
	(float)((e->pt[y][x].z == e->max_z ? e->pt[y][x].z + e->alt :
	e->pt[y][x].z) - e->min_z) / 90) * (rot_x > 90 ? 180 - rot_x : rot_x) * neg;
	neg = (e->rot_y > 180 ? -1 : 1);
	rot_y = (e->rot_y > 180 ? 360 - e->rot_y : e->rot_y);
	e->pt[y][x].y += ((float)(e->w_y / 2 - e->g_y) / (float)((e->m_y - 1) / 2) *
	(float)((e->pt[y][x].z == e->max_z ? e->pt[y][x].z + e->alt :
	e->pt[y][x].z) - e->min_z) / 90) * (rot_y > 90 ? 180 - rot_y : rot_y) * neg;
}

void	ft_coord(t_env *e, int y, int x)
{
	e->g_x = (e->w_x / 4);
	e->g_y = (e->w_y / 4);
	while (++y < e->m_y)
	{
		x = -1;
		while (++x < e->m_x)
		{
			e->zoom_x = (x < (e->m_x / 2) ? e->g_zoom * (e->m_x / 2 - x) : 0);
			x > (e->m_x / 2) ? e->zoom_x = -e->g_zoom * (x - e->m_x / 2) : 0;
			e->pt[y][x].x = e->g_x - e->zoom_x + x * (e->w_x / 2 / (e->m_x));
			e->pt[y][x].x += (float)((float)(e->w_x / 2 - e->pt[y][x].x) / 90) *
			(float)(e->rot_x > 180 ? 360 - e->rot_x : e->rot_x);
			e->zoom_y = (y < (e->m_y / 2) ? e->g_zoom * (e->m_y / 2 - y) : 0);
			y > (e->m_y / 2) ? e->zoom_y = -e->g_zoom * (y - e->m_y / 2) : 0;
			e->pt[y][x].y = e->g_y - e->zoom_y + y * (e->w_y / 2 / (e->m_y));
			e->pt[y][x].y += (float)((float)(e->w_y / 2 - e->pt[y][x].y) / 90) *
			(float)(e->rot_y > 180 ? 360 - e->rot_y : e->rot_y);
			ft_coord_alt(e, y, x);
			e->pt[y][x].x += e->move_x;
			e->pt[y][x].y += e->move_y;
		}
	}
}
