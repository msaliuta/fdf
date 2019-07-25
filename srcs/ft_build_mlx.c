/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_mlx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <msaliuta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 21:20:16 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/25 05:37:10 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_init(t_af *p)
{
	p->deep = 0;
	p->tight = -WIDTH / 3;
	p->tight2 = HEIGHT / 3 * 2;
	p->zoom = 2000;
	p->persp = 1;
	p->r = 255;
	p->v = 255;
	p->b = 255;
	p->degra = 0;
}

void				ft_put_point(t_af *af)
{
	int				i;
	int				j;

	i = -1;
	while ((++i < af->point[0][0]->size_y) && (j = -1))
		while (++j < af->point[i][0]->size_x)
		{
			af->persp == 1 ? ft_iso_persp(af, i, j) : 0;
			af->persp == 0 ? ft_paral_persp(af, i, j) : 0;
		}
}

int					ft_key_hook(int keycode, t_af *af)
{
	if (keycode == ECHAP)
	{
		system("leaks fdf");
		exit(1);
	}
	keycode == UP ? af->tight -= 30 : 0;
	keycode == DOWN ? af->tight += 30 : 0;
	keycode == RIGHT ? af->tight2 += 30 : 0;
	keycode == LEFT ? af->tight2 -= 30 : 0;
	keycode == 12 ? af->deep += 1 : 0;
	keycode == 14 ? af->deep -= 1 : 0;
	if (keycode == ZOOM && af->persp == 1)
	{
		af->zoom += 50;
		af->tight2 -= 25;
		af->tight -= 25;
	}
	else if (keycode == ZOOM && af->persp != 1)
	{
		af->zoom += 10;
		af->tight2 -= 5;
		af->tight -= 5;
	}
	if (keycode == DEZOOM && af->persp == 1)
	{
		af->zoom -= 50;
		af->tight2 += 25;
		af->tight += 25;
	}
	else if (keycode == DEZOOM && af->persp != 1)
	{
		af->zoom -= 10;
		af->tight2 += 5;
		af->tight += 5;
	}
	keycode == 29 ? ft_reset_iso(af) : 0;
	keycode == 18 ? ft_reset_paral(af) : 0;
	keycode == 89 ? af->degra = 1 : 0;
	keycode == 91 ? af->degra = 2 : 0;
	keycode == 92 ? af->degra = 3 : 0;
	if (keycode == 86)
	{
		if ((af->r -= 5) < 0)
			af->r = 0;
		else
			af->r -= 5;
	}
	if (keycode == 87)
	{
		if ((af->v -= 5) < 0)
			af->v = 0;
		else
			af->v -= 5;
	}
	if (keycode == 88)
	{
		if ((af->b -= 5) < 0)
			af->b = 0;
		else
			af->b -= 5;
	}
	if (keycode == 83)
	{
		if ((af->r += 5) > 255)
			af->r = 255;
		else
			af->r += 5;
	}
	if (keycode == 84)
	{
		if ((af->v += 5) > 255)
			af->v = 255;
		else
			af->v += 5;
	}
	if (keycode == 85)
	{
		if ((af->b += 5) > 255)
			af->b = 255;
		else
			af->b += 5;
	}
	ft_loop_key_hook(af);
	return (0);
}

static int			ft_loop_key_hook(t_af *af)
{
	af->ret = mlx_get_data_addr(af->img, &(af->bits_per_pixel),
		&(af->size_line), &(af->endian));
	ft_put_point(af);
	mlx_put_image_to_window(af->mlx, af->win, af->img, 0, 0);
	mlx_destroy_image(af->mlx, af->img);
	af->img = mlx_new_image(af->mlx, WIDTH, HEIGHT);
	ft_print_info(af);
	return (0);
}

int		ft_build_mlx(t_af *p)
{
	ft_init(p);
	p->mlx = mlx_init();
	p->win = mlx_new_window(p->mlx, WIDTH, HEIGHT, "fdf");
	p->img = mlx_new_image(p->mlx, WIDTH, HEIGHT);
	mlx_hook(p->win, 2, 2, ft_key_hook, p);
	mlx_loop(p->mlx);
	return (0);
}
