/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_persp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <msaliuta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 21:20:00 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/25 06:15:37 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void			ft_my_pixel_put(t_af *af, int i, int j, float q)
{
	int			k;

	ft_degra2(af, q);
	if ((i > 0 && j > 0 && i < WIDTH && j < HEIGHT))
	{
		af->ret[((i * 4 + (j * af->size_line)))] = af->b;
		af->ret[((i * 4 + (j * af->size_line))) + 1] = af->r;
		af->ret[((i * 4 + (j * af->size_line))) + 2] = af->v;
	}
}

float			ft_degra(t_af *af, t_point *b, t_point *a, int i)
{
	float		ret;
	float		dif;
	float		alt;

	dif = (float)(i - a->x) / (float)(b->x - a->x);
	alt = (float)(a->z + ((b->z - a->z) * dif)) /
	(float)(af->max_hight - af->min_hight);
	ret = 255 * alt;
	return (ret);
}

void			ft_wire(t_af *af, t_point *b, t_point *a)
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
			ft_my_pixel_put(af, i, j++, ft_degra(af, b, a, i));
		while (j > ((b->y - a->y) * (i + 1 - a->x) / (b->x - a->x)) + a->y)
			ft_my_pixel_put(af, i, j--, ft_degra(af, b, a, i));
	}
}

void			ft_iso_persp(t_af *af, int i, int j)
{
	af->point[i][j]->x = (af->zoom * (-i + j) / (af->point[i][j]->size_x +
				af->point[i][j]->size_y)) + af->tight2;
	af->point[i][j]->y = af->zoom * (af->point[i][j]->size_x + i + j) /
				(af->point[i][j]->size_x + af->point[i][j]->size_y) -
				(af->point[i][j]->z) * af->deep + af->tight;
	af->point[i][j]->y = af->point[i][j]->y / 2;
	if (j > 0)
		ft_wire(af, af->point[i][j], af->point[i][j - 1]);
	if (i > 0)
		ft_wire(af, af->point[i - 1][j], af->point[i][j]);
}

void			ft_paral_persp(t_af *af, int i, int j)
{
	af->point[i][j]->y = af->zoom * i + af->tight;
	af->point[i][j]->x = af->zoom * j + af->tight2;
	if (j > 0)
		ft_wire(af, af->point[i][j], af->point[i][j - 1]);
	if (i > 0)
		ft_wire(af, af->point[i - 1][j], af->point[i][j]);
}
