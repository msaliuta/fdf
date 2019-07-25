/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_mlx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <msaliuta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 21:20:16 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/26 00:35:28 by msaliuta         ###   ########.fr       */
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
	p->rgb.r = 255;
	p->rgb.g = 255;
	p->rgb.b = 255;
	p->degra = 0;
	p->rgb.qr = 0;
	p->rgb.qb = 0;
	p->rgb.qg = 0;
}

void				ft_put_point(t_af *af)
{
	int				i;
	int				j;

	i = -1;
	while ((++i < af->dot[0][0]->size_y) && (j = -1))
		while (++j < af->dot[i][0]->size_x)
		{
			af->persp == 1 ? ft_iso_persp(af, i, j) : 0;
			af->persp == 0 ? ft_paral_persp(af, i, j) : 0;
		}
}

void				init_colors(t_af *af)
{
	af->rgb.r = 0;
	af->rgb.g = 0;
	af->rgb.b = 0;
	af->degra = 0;
}

int					ft_key_hook(int keycode, t_af *af)
{
	af->key = keycode;
	if (af->key == ECHAP)
	{
		system("leaks -q fdf");
		exit(1);
	}
	af->key == UP ? af->tight -= 30 : 0;
	af->key == DOWN ? af->tight += 30 : 0;
	af->key == RIGHT ? af->tight2 += 30 : 0;
	af->key == LEFT ? af->tight2 -= 30 : 0;
	af->key == 12 ? af->deep += 1 : 0;
	af->key == 14 ? af->deep -= 1 : 0;
	if (af->key == ZOOM && af->persp == 1)
	{
		af->zoom += 50;
		af->tight2 -= 25;
		af->tight -= 25;
	}
	else if (af->key == ZOOM && af->persp != 1)
	{
		af->zoom += 10;
		af->tight2 -= 5;
		af->tight -= 5;
	}
	if (af->key == DEZOOM && af->persp == 1)
	{
		af->zoom -= 50;
		af->tight2 += 25;
		af->tight += 25;
	}
	else if (af->key == DEZOOM && af->persp != 1)
	{
		af->zoom -= 10;
		af->tight2 += 5;
		af->tight += 5;
	}
	af->key == 29 ? ft_reset_iso(af) : 0;
	af->key == 18 ? ft_reset_paral(af) : 0;
	af->key == 89 ? af->degra = 1 : 0;
	af->key == 91 ? af->degra = 2 : 0;
	af->key == 92 ? af->degra = 3 : 0;
	af->key == 82 ? init_colors(af) : 0;
	if (af->key == 86)
	{
		af->rgb.qr = (af->rgb.qr - 5 > -255 & af->degra == 1) ? af->rgb.qr - 5 : -255;
		af->rgb.r = (af->rgb.r - 5) < 0 ? 0 : af->rgb.r - 5;
	}
	if (af->key == 87)
	{
		af->rgb.qg = (af->rgb.qg - 5 > -255 & af->degra == 2) ? af->rgb.qg - 5 : -255;
		af->rgb.g = (af->rgb.g - 5) < 0 ? 0 : af->rgb.g - 5;
	}
	if (af->key == 88)
	{
		af->rgb.qb = (af->rgb.qb - 5 > -255 & af->degra == 3) ? af->rgb.qb - 5 : -255;
		af->rgb.b = (af->rgb.b - 5) < 0 ? 0 : af->rgb.b - 5;
	}
	if (af->key == 83)
	{
		af->rgb.qr = (af->rgb.qr + 5 < 0 & af->degra == 1) ? af->rgb.qr + 5 : 0;
		af->rgb.r = (af->rgb.r + 5) > 255 ? 255 : af->rgb.r + 5;
	}
	if (af->key == 84)
	{
		af->rgb.qg = (af->rgb.qg + 5 < 0 & af->degra == 2) ? af->rgb.qg + 5 : 0;
		af->rgb.g = (af->rgb.g + 5) > 255 ? 255 : af->rgb.g + 5;
	}
	if (af->key == 85)
	{
		af->rgb.qb = (af->rgb.qb + 5 < 0 & af->degra == 3) ? af->rgb.qb + 5 : 0;
		af->rgb.b = (af->rgb.b + 5) > 255 ? 255 : af->rgb.b + 5;
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

int					exit_x(void)
{
	system("leaks -q fdf");
	exit(1);
}

int					ft_build_mlx(t_af *p)
{
	ft_init(p);
	p->mlx = mlx_init();
	p->win = mlx_new_window(p->mlx, WIDTH, HEIGHT, "fdf");
	p->img = mlx_new_image(p->mlx, WIDTH, HEIGHT);
	mlx_hook(p->win, 2, 2, ft_key_hook, p);
	mlx_hook(p->win, 17, 1L << 17, exit_x, p);
	mlx_loop(p->mlx);
	return (0);
}
