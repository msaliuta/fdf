/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 20:54:53 by mikim             #+#    #+#             */
/*   Updated: 2017/04/03 20:54:54 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_get_color(t_env *e, t_color *c, t_point p)
{
	float	pct;

	pct = 255 / (float)(e->max_z - e->min_z);
	if (e->color == 18)
	{
		c->red = pct * (p.z - e->min_z);
		c->green = (p.z > (e->max_z - e->min_z) / 2 ? 255 -
		(pct * 2) * (e->min_z - p.z) : (pct * 2) * (e->min_z - p.z));
		c->blue = 255 - pct * (p.z - e->min_z);
	}
	else if (e->color == 19)
	{
		c->blue = pct * (p.z - e->min_z);
		c->red = (p.z > (e->max_z - e->min_z) / 2 ? 255 -
		(pct * 2) * (e->min_z - p.z) : (pct * 2) * (e->min_z - p.z));
		c->green = 255 - pct * (p.z - e->min_z);
	}
	else if (e->color == 20)
	{
		c->green = pct * (p.z - e->min_z);
		c->blue = (p.z > (e->max_z - e->min_z) / 2 ? 255 -
		(pct * 2) * (e->min_z - p.z) : (pct * 2) * (e->min_z - p.z));
		c->red = 255 - pct * (p.z - e->min_z);
	}
}

int		ft_set_color(t_env *e, t_point p1, t_point p2, int i)
{
	t_color	c[2];
	int		dif;

	dif = (e->diff == 0 ? 1 : e->diff);
	if (e->color == 21)
		return (p1.col - (p1.col - p2.col) / dif * i);
	ft_get_color(e, &c[0], p1);
	ft_get_color(e, &c[1], p2);
	return (c[0].red * 65536 + c[0].green * 256 + c[0].blue -
	(((c[0].red - c[1].red) / dif * i * 65536) +
	((c[0].green - c[1].green) / dif * i * 256) +
	((c[0].blue - c[1].blue) / dif * i)));
}

void	ft_draw_x(t_env *e, t_point p1, t_point p2)
{
	int		i;
	int		color;
	float	pct;

	i = -1;
	e->diff = p2.x - p1.x;
	while (p1.x + ++i <= p2.x)
	{
		color = ft_set_color(e, p1, p2, i);
		if (p1.y == p2.y)
			mlx_pixel_put(e->mlx, e->win, p1.x + i, p1.y, color);
		else if (p1.y != p2.y)
		{
			pct = ((float)p2.y - (float)p1.y) / ((float)p2.x - (float)p1.x);
			pct *= i;
			mlx_pixel_put(e->mlx, e->win, p1.x + i, p1.y + (int)pct, color);
		}
	}
}

void	ft_draw_y(t_env *e, t_point p1, t_point p2)
{
	int		i;
	int		color;
	float	pct;

	i = -1;
	e->diff = p2.y - p1.y;
	while (p1.y + ++i <= p2.y)
	{
		color = ft_set_color(e, p1, p2, i);
		if (p1.x == p2.x)
			mlx_pixel_put(e->mlx, e->win, p1.x, p1.y + i, color);
		else if (p1.x != p2.x)
		{
			pct = ((float)p2.x - (float)p1.x) / ((float)p2.y - (float)p1.y);
			pct *= i;
			mlx_pixel_put(e->mlx, e->win, p1.x + (int)pct, p1.y + i, color);
		}
	}
}

void	ft_draw(t_env *e)
{
	int y;
	int x;

	y = -1;
	mlx_clear_window(e->mlx, e->win);
	while (++y < e->m_y)
	{
		x = -1;
		while (++x < e->m_x - 1)
			if (e->rot_x < 90 || e->rot_x > 270)
				ft_draw_x(e, e->pt[y][x], e->pt[y][x + 1]);
			else
				ft_draw_x(e, e->pt[y][x + 1], e->pt[y][x]);
	}
	x = -1;
	while (++x < e->m_x)
	{
		y = -1;
		while (++y < e->m_y - 1)
			if (e->rot_y < 90 || e->rot_y > 270)
				ft_draw_y(e, e->pt[y][x], e->pt[y + 1][x]);
			else
				ft_draw_y(e, e->pt[y + 1][x], e->pt[y][x]);
	}
	ft_guide(e);
}
