/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <msaliuta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 21:20:00 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/26 07:35:09 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void			pixel(t_m *m, int i, int j, float q)
{
	non_zero_c(m, q);
	if ((i > 0 && j > 0 && i < WIDTH && j < HEIGHT))
	{
		m->ret[((i * 4 + (j * m->size_line)))] = C.b;
		m->ret[((i * 4 + (j * m->size_line))) + 1] = C.r;
		m->ret[((i * 4 + (j * m->size_line))) + 2] = C.g;
	}
}

float			z_sort(t_m *m, t_dot *b, t_dot *a, int i)
{
	float		ret;
	float		dif;
	float		alt;

	if ((b->x - a->x) == 0)
	{
		ret = M * (float)((a->z) + (b->z - a->z) * 0.1) /
			(float)(m->max_hight - m->min_hight);
		return (ret);
	}
	dif = (float)(i - a->x) / (float)(b->x - a->x);
	alt = (float)(a->z + ((b->z - a->z) * dif)) /
	(float)(m->max_hight - m->min_hight);
	ret = M * alt;
	return (ret);
}

void			connect(t_m *m, t_dot *b, t_dot *a)
{
	int			i;
	int			j;
	int			k;

	if ((b->x - a->x) == 0)
	{
		i = a->x;
		j = a->y;
		while (j < b->y)
			pixel(m, i, j++, z_sort(m, b, a, i));
		while (j > b->y)
			pixel(m, i, j--, z_sort(m, b, a, i));
		return ;
	}
	i = a->x - 1;
	j = ((b->y - a->y) * (a->x - a->x)) / (b->x - a->x) + a->y;
	while (++i < b->x)
	{
		while (j <= ((b->y - a->y) * (i + 1 - a->x) / (b->x - a->x)) + a->y)
			pixel(m, i, j++, z_sort(m, b, a, i));
		while (j > ((b->y - a->y) * (i + 1 - a->x) / (b->x - a->x)) + a->y)
			pixel(m, i, j--, z_sort(m, b, a, i));
	}
}

void			iso(t_m *m, int i, int j)
{
	m->dot[i][j]->x = (m->zoom * (-i + j) / (m->dot[i][j]->size_x +
				m->dot[i][j]->size_y)) + m->shift_lr;
	m->dot[i][j]->y = m->zoom * (m->dot[i][j]->size_x + i + j) /
				(m->dot[i][j]->size_x + m->dot[i][j]->size_y) -
				(m->dot[i][j]->z) * m->depth + m->shift_ud;
	m->dot[i][j]->y = m->dot[i][j]->y / 2;
	j > 0 ? connect(m, m->dot[i][j], m->dot[i][j - 1]) : 0;
	i > 0 ? connect(m, m->dot[i - 1][j], m->dot[i][j]) : 0;
}

void			paral(t_m *m, int i, int j)
{
	m->dot[i][j]->y = m->zoom * i + m->shift_ud;
	m->dot[i][j]->x = m->zoom * j + m->shift_lr;
	i > 0 ? connect(m, m->dot[i][j], m->dot[i - 1][j]) : 0;
	j > 0 ? connect(m, m->dot[i][j], m->dot[i][j - 1]) : 0;
}
