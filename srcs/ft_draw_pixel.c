/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_pixel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <msaliuta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 21:19:46 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/23 17:13:23 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int					ft_key_hook4(int keycode, t_af *af)
{
	if (keycode == 85)
		af->b = ((af->b + 10) > 255) ? 255 : (af->b + 20);
	(keycode == 82 & (af->opacity + 10) <= 255) ? af->opacity += 10 : 0;
	(keycode == 65 & (af->opacity - 10) >= 0) ? af->opacity -= 10 : 0;
	if (keycode == 18)
	{
		ft_reset(af);
		af->persp = 1;
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
	if (keycode == ZOOM)
	{
		af->zoom += 50;
		af->tight2 -= 25;
		af->tight -= 25;
	}
	keycode == 117 ? ft_reset(af) : 0;
	return (ft_key_hook2(keycode, af));
}

int					ft_mouse_hook(int button, int x, int y, t_af *af)
{
	if (button == 4)
		af->deep += 1;
	if (button == 5)
		af->deep -= 1;
	if (button == 1)
	{
		if ((af->r + 10) <= 255)
			af->r += 10;
		if ((af->v + 10) <= 255)
			af->v += 10;
		if ((af->b + 10) <= 255)
			af->b += 10;
	}
	if (button == 2)
	{
		if ((af->r - 10) >= 0)
			af->r -= 10;
		if ((af->v - 10) >= 0)
			af->v -= 10;
		if ((af->b - 10) >= 0)
			af->b -= 10;
	}
	ft_loop_key_hook(af);
	return (0);
}

void				ft_put_point(t_af *af)
{
	int				i;
	int				j;

	i = 0;
	while (i < af->point[0][0]->size_y)
	{
		j = 0;
		while (j < af->point[i][0]->size_x)
			ft_choose_persp(af, i, j++);
		i++;
	}
}
