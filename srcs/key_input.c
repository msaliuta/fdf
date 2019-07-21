/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <msaliuta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 13:59:51 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/21 15:53:40 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/toolbox.h"

void	clear_and_reput(t_mlx *tl, t_pts *pts)
{
	tl->img.img_ptr = mlx_new_image(tl->mlx, W, HE);
	tl->img.dta = (int *)mlx_get_data_addr(tl->img.img_ptr,
	&tl->img.bpp, &tl->img.sl, &tl->img.end);
	ft_fill_tab(tl->stock, tl, pts, tl->taille);
	mlx_put_image_to_window(tl->mlx, tl->win, tl->img.img_ptr, 0, 0);
}

void	ft_key_code(int keycode, t_mlx *tool, t_pts *pts)
{
	keycode == 0 ? tool->up -= 5 : 0;
	keycode == 2 ? tool->up += 5 : 0;
	keycode == 69 ? tool->zoom += 1 : 0;
	keycode == 78 ? tool->zoom -= 1 : 0;
	keycode == 1 ? tool->z += 5 : 0;
	keycode == 13 ? tool->z -= 5 : 0;
	keycode == 12 ? tool->mlt += 0.17 : 0;
	keycode == 14 ? tool->mlt -= 0.17 : 0;
	if (keycode == 8)
	{
		tool->up = 0;
		tool->zoom = 0;
		tool->z = 0;
		tool->mlt = 0;
	}
	clear_and_reput(tool, pts);
}

int		pressed_key(int keycode, t_mlx *tool)
{
	t_pts pts;

	if (keycode == 53)
	{
		system("leaks fdf");
		exit(EXIT_SUCCESS);
	}
	ft_bzero(&pts, sizeof(t_pts));
	ft_bzero(&tool->img, sizeof(t_img));
	if (keycode == 2 || keycode == 0 || keycode == 69 || keycode == 78 ||
	keycode == 1 || keycode == 13 || keycode == 12 || keycode == 14
	|| keycode == 8)
		ft_key_code(keycode, tool, &pts);
	return (0);
}
