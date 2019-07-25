/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_persp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <msaliuta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 21:20:00 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/26 00:36:45 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void			ft_my_pixel_put(t_af *af, int i, int j, float q)
{
	int			k;

	ft_degra2(af, q);
	if ((i > 0 && j > 0 && i < WIDTH && j < HEIGHT))
	{
		af->ret[((i * 4 + (j * af->size_line)))] = af->rgb.b;
		af->ret[((i * 4 + (j * af->size_line))) + 1] = af->rgb.r;
		af->ret[((i * 4 + (j * af->size_line))) + 2] = af->rgb.g;
	}
}

float			ft_degra(t_af *af, t_dot *b, t_dot *a, int i)
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

void			ft_wire(t_af *af, t_dot *b, t_dot *a)
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
	af->dot[i][j]->x = (af->zoom * (-i + j) / (af->dot[i][j]->size_x +
				af->dot[i][j]->size_y)) + af->tight2;
	af->dot[i][j]->y = af->zoom * (af->dot[i][j]->size_x + i + j) /
				(af->dot[i][j]->size_x + af->dot[i][j]->size_y) -
				(af->dot[i][j]->z) * af->deep + af->tight;
	af->dot[i][j]->y = af->dot[i][j]->y / 2;
	j > 0 ? ft_wire(af, af->dot[i][j], af->dot[i][j - 1]) : 0;
	i > 0 ? ft_wire(af, af->dot[i - 1][j], af->dot[i][j]) : 0;
}

void			ft_paral_persp(t_af *af, int i, int j)
{
	af->dot[i][j]->y = af->zoom * i + af->tight;
	af->dot[i][j]->x = af->zoom * j + af->tight2;
	j > 0 ? ft_wire(af, af->dot[i][j], af->dot[i][j - 1]) : 0;
	i < 0 ? ft_wire(af, af->dot[i + 1][j], af->dot[i][j]) : 0;
}
