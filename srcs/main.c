/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <msaliuta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 21:20:26 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/26 00:35:28 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void				ft_reset_iso(t_af *af)
{
	af->deep = 0;
	af->tight = -WIDTH / 3;
	af->tight2 = HEIGHT / 3 * 2;
	af->zoom = 2000;
	af->persp = 1;
}

void				ft_reset_paral(t_af *af)
{
	af->deep = 0;
	af->tight = 70;
	af->tight2 = HEIGHT / 4 * 3;
	af->zoom = 40;
	af->persp = 0;
}

void				ft_get_map_hight(t_af *af)
{
	int				i;
	int				j;

	i = -1;
	while (++i < af->dot[0][0]->size_y && (j = -1))
		while (++j < af->dot[i][0]->size_x)
		{
			af->dot[i][j]->z > af->max_hight ? af->max_hight = af->dot[i][j]->z : 0;
			if (af->dot[i][j]->z < af->min_hight)
				af->min_hight = af->dot[i][j]->z;
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
	af->dot = ft_get_coord(af);
	ft_get_map_hight(af);
	ft_build_mlx(af);
	free(af->map);
	free(af->dot);
	free(af);
	return (0);
}
