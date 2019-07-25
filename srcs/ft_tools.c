/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <msaliuta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 21:20:34 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/26 00:30:09 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void				ft_degra2(t_af *af, int q)
{
	if (af->degra == 0)
		return ;
	else if (af->degra == 1)
		af->rgb.r = q - af->rgb.qr;
	else if (af->degra == 2)
		af->rgb.g = q - af->rgb.qg;
	else if (af->degra == 3)
		af->rgb.b = q - af->rgb.qb;
}

void				ft_exit_error(void)
{
	ft_putstr("Invalid map\n");
	system("leaks -q fdf");
	exit(1);
}

void				ft_print_info3(t_af *p, char *str)
{
	if (p->degra > 0)
	{
		if (p->degra == 1)
		{
			str = "Green";
			mlx_string_put(p->mlx, p->win, 2140, 190, 0x0FFFFFF, str);
		}
		if (p->degra == 2)
		{
			str = "Red";
			mlx_string_put(p->mlx, p->win, 2140, 190, 0x0FFFFFF, str);
		}
		if (p->degra == 3)
		{
			str = "Blue";
			mlx_string_put(p->mlx, p->win, 2140, 190, 0x0FFFFFF, str);
		}
	}
}

void				ft_print_info2(t_af *p, char *str)
{
	str = " If you press 7,8,9 colors g,r,b will work only for non zero dots.";
	mlx_string_put(p->mlx, p->win, 1900, 90, 0x0FFFFFF, str);
	str = " Press 1,2,3 to increase g,r,b";
	mlx_string_put(p->mlx, p->win, 1900, 30, 0x0FFFFFF, str);
	str = " Press 4,5,6 to reduce g,r,b";
	mlx_string_put(p->mlx, p->win, 1900, 50, 0x0FFFFFF, str);
	str = " Press 0 to zero all colors";
	mlx_string_put(p->mlx, p->win, 1900, 70, 0x0FFFFFF, str);
	str = " g:";
	mlx_string_put(p->mlx, p->win, 2140, 110, 0x0FFFFFF, str);
	str = ft_itoa(p->rgb.r);
	mlx_string_put(p->mlx, p->win, 2175, 110, 0x0FFFFFF, str);
	free(str);
	str = " r:";
	mlx_string_put(p->mlx, p->win, 2140, 130, 0x0FFFFFF, str);
	str = ft_itoa(p->rgb.g);
	mlx_string_put(p->mlx, p->win, 2175, 130, 0x0FFFFFF, str);
	free(str);
	str = " b:";
	mlx_string_put(p->mlx, p->win, 2140, 150, 0x0FFFFFF, str);
	str = ft_itoa(p->rgb.b);
	mlx_string_put(p->mlx, p->win, 2175, 150, 0x0FFFFFF, str);
	free(str);
	ft_print_info3(p, str);
}

void				ft_print_info(t_af *p)
{
	char			*str;

	ft_print_info2(p, str);
}
