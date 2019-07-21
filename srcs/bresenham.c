/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <msaliuta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 13:59:20 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/21 16:53:25 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//переписать функции ft_line + ft_line2 + line_init сделав всего 2 ф-и
#include "../includes/toolbox.h"

void		line_init(t_line *line, t_pts *pts)
{
	line->dx = labs(pts->x1 - pts->x0);
	line->sx = pts->x0 < pts->x1 ? 1 : -1;
	line->dy = labs(pts->y1 - pts->y0);
	line->sy = pts->y0 < pts->y1 ? 1 : -1;
	line->err = (line->dx > line->dy ? line->dx : -line->dy) / 2;
}

void		ft_line(t_pts *pts, t_mlx *ptr)
{
	t_line line;

	line_init(&line, pts);
	while (WORK)
	{
		if ((((pts->x0 - pts->y0) > 0 && (pts->x0 - pts->y0) < W) &&
		(pts->y0 + pts->x0) > 0 && (pts->y0 + pts->x0) / 2 < HE))
			ptr->img.dta[(pts->x0 - pts->y0) +
			(pts->y0 + pts->x0) / 2 * W] = ptr->clr;
		if (pts->x0 == pts->x1 && pts->y0 == pts->y1)
			break ;
		line.e2 = line.err;
		if (line.e2 > -line.dx)
		{
			line.err -= line.dy;
			pts->x0 += line.sx;
		}
		if (line.e2 < line.dy)
		{
			line.err += line.dx;
			pts->y0 += line.sy;
		}
	}
}

void		ft_line2(t_pts *pts, t_mlx *ptr)
{
	t_line line;

	line_init(&line, pts);
	while (1)
	{
		if ((((pts->x0 - pts->y0) > 0 && (pts->x0 - pts->y0) < W) &&
		(pts->y0 + pts->x0 - ptr->y) > 0 &&
		(pts->y0 + pts->x0 - ptr->y) / 2 < HE))
			ptr->img.dta[(pts->x0 - pts->y0) + (pts->y0 + pts->x0 - ptr->y)
			/ 2 * W] = ptr->clr;
		if (pts->x0 == pts->x1 && pts->y0 == pts->y1)
			break ;
		line.e2 = line.err;
		if (line.e2 > -line.dx)
		{
			line.err -= line.dy;
			pts->x0 += line.sx;
		}
		if (line.e2 < line.dy)
		{
			line.err += line.dx;
			pts->y0 += line.sy;
		}
	}
}
