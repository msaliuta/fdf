/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <msaliuta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 21:20:34 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/26 03:20:29 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void				ft_degra2(t_m *m, int q)
{
	if (m->prior == 0)
		return ;
	else if (m->prior == 1)
		C.r = q - C.qr;
	else if (m->prior == 2)
		C.g = q - C.qg;
	else if (m->prior == 3)
		C.b = q - C.qb;
}

void				ft_exit_error(void)
{
	ft_putstr("Invalid map\n");
	system("leaks -q fdf");
	exit(1);
}

void				ft_print_info3(t_m *m, char *str)
{
	if (m->prior == 1)
	{
		str = "Green";
		mlx_string_put(m->mlx, m->win, 2140, 190, WHITE, str);
	}
	if (m->prior == 2)
	{
		str = "Red";
		mlx_string_put(m->mlx, m->win, 2140, 190, WHITE, str);
	}
	if (m->prior == 3)
	{
		str = "Blue";
		mlx_string_put(m->mlx, m->win, 2140, 190, WHITE, str);
	}
	str = " If you press w,a,s,d you will move map";
	mlx_string_put(m->mlx, m->win, 100, 30, WHITE, str);
	str = " If you press q,e you will move non zero cords.";
	mlx_string_put(m->mlx, m->win, 100, 50, WHITE, str);
	str = " FOR RIGHT SIDE OF KEYBOARD";
	mlx_string_put(m->mlx, m->win, 1900, 15, WHITE, str);
}

void				ft_print_info(t_m *m)
{
	char			*str;

	str = " If you press 7,8,9 colors g,r,b will work only for non zero dots.";
	mlx_string_put(m->mlx, m->win, 1900, 90, WHITE, str);
	str = " Press 1,2,3 to increase g,r,b";
	mlx_string_put(m->mlx, m->win, 1900, 30, WHITE, str);
	str = " Press 4,5,6 to reduce g,r,b";
	mlx_string_put(m->mlx, m->win, 1900, 50, WHITE, str);
	str = " Press 0 to zero all colors";
	mlx_string_put(m->mlx, m->win, 1900, 70, WHITE, str);
	str = " g:";
	mlx_string_put(m->mlx, m->win, 2140, 110, WHITE, str);
	str = ft_itoa(C.r);
	mlx_string_put(m->mlx, m->win, 2175, 110, WHITE, str);
	free(str);
	str = " r:";
	mlx_string_put(m->mlx, m->win, 2140, 130, WHITE, str);
	str = ft_itoa(C.g);
	mlx_string_put(m->mlx, m->win, 2175, 130, WHITE, str);
	free(str);
	str = " b:";
	mlx_string_put(m->mlx, m->win, 2140, 150, WHITE, str);
	str = ft_itoa(C.b);
	mlx_string_put(m->mlx, m->win, 2175, 150, WHITE, str);
	free(str);
	ft_print_info3(m, str);
}
