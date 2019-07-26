/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_persp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <msaliuta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 21:20:00 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/26 03:20:45 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void			ft_my_pixel_put(t_m *m, int i, int j, float q)
{
	ft_degra2(m, q);
	if ((i > 0 && j > 0 && i < WIDTH && j < HEIGHT))
	{
		m->ret[((i * 4 + (j * m->size_line)))] = C.b;
		m->ret[((i * 4 + (j * m->size_line))) + 1] = C.r;
		m->ret[((i * 4 + (j * m->size_line))) + 2] = C.g;
	}
}

float			ft_degra(t_m *m, t_dot *b, t_dot *a, int i)
{
	float		ret;
	float		dif;
	float		alt;

	dif = (float)(i - a->x) / (float)(b->x - a->x);
	alt = (float)(a->z + ((b->z - a->z) * dif)) /
	(float)(m->max_hight - m->min_hight);
	ret = M * alt;
	return (ret);
}

void			ft_wire(t_m *m, t_dot *b, t_dot *a)
{
	int			i;
	int			j;

	if ((b->x - a->x) == 0)
		return ;
	i = a->x - 1;
	j = ((b->y - a->y) * (a->x - a->x)) / (b->x - a->x) + a->y;
	while (++i < b->x)
	{
		while (j <= ((b->y - a->y) * (i + 1 - a->x) / (b->x - a->x)) + a->y)
			ft_my_pixel_put(m, i, j++, ft_degra(m, b, a, i));
		while (j > ((b->y - a->y) * (i + 1 - a->x) / (b->x - a->x)) + a->y)
			ft_my_pixel_put(m, i, j--, ft_degra(m, b, a, i));
	}
}

void			ft_iso_persp(t_m *m, int i, int j)
{
	m->dot[i][j]->x = (m->zoom * (-i + j) / (m->dot[i][j]->size_x +
				m->dot[i][j]->size_y)) + m->shift_lr;
	m->dot[i][j]->y = m->zoom * (m->dot[i][j]->size_x + i + j) /
				(m->dot[i][j]->size_x + m->dot[i][j]->size_y) -
				(m->dot[i][j]->z) * m->depth + m->shift_ud;
	m->dot[i][j]->y = m->dot[i][j]->y / 2;
	j > 0 ? ft_wire(m, m->dot[i][j], m->dot[i][j - 1]) : 0;
	i > 0 ? ft_wire(m, m->dot[i - 1][j], m->dot[i][j]) : 0;
}

void			ft_paral_persp(t_m *m, int i, int j)
{
	m->dot[i][j]->y = m->zoom * i + m->shift_ud;
	m->dot[i][j]->x = m->zoom * j + m->shift_lr;
	j > 0 ? ft_wire(m, m->dot[i][j], m->dot[i][j - 1]) : 0;
	i < 0 ? ft_wire(m, m->dot[i + 1][j], m->dot[i][j]) : 0;
}
