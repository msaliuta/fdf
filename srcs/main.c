/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <msaliuta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 21:20:26 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/23 19:23:29 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"


void				ft_reset(t_af *af)
{
	af->deep = 0;
	af->tight = 0;
	af->tight2 = 0;
	af->zoom = WIDTH;
	af->persp = 1;
	af->r = 255;
	af->v = 255;
	af->b = 255;
	af->opacity = 0;
	af->degra = 0;
}

void				ft_get_map_hight(t_af *af)
{
	int				i;
	int				j;

	i = -1;
	while (++i < af->point[0][0]->size_y && (j = -1))
		while (++j < af->point[i][0]->size_x)
		{
			af->point[i][j]->z > af->max_hight ? af->max_hight = af->point[i][j]->z : 0;
			if (af->point[i][j]->z < af->min_hight)
				af->min_hight = af->point[i][j]->z;
		}
}

int					main(int argc, char **argv)
{
	t_af			*af;

	if (argc != 2)
	{
		ft_putstr("Invalide argument\n");
		return (0);
	}
	af = (t_af *)malloc(sizeof(t_af));
	af->map = (t_map *)malloc(sizeof(t_map));
	af->map->argv = argv;
	af->point = ft_get_coord(af);
	ft_get_map_hight(af);
	ft_build_mlx(af);
	free(af->map);
	free(af->point);
	free(af);
	return (0);
}
