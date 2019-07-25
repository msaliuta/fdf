/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <msaliuta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 21:20:34 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/25 05:23:08 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void				ft_degra2(t_af *af, int q)
{
	if (af->degra == 0)
		return ;
	else if (af->degra == 1)
		af->b = q;
	else if (af->degra == 2)
		af->r = q;
	else if (af->degra == 3)
		af->v = q;
}

void				ft_exit_error(void)
{
	ft_putstr("Invalid map\n");
	system("leaks fdf");
	exit(1);
}

void				ft_print_info3(t_af *p, char *str)
{
	if (p->degra > 0)
	{
		if (p->degra == 1)
		{
			str = "Blue";
			mlx_string_put(p->mlx, p->win, 200, 190, 0x0FFFFFF, str);
		}
		if (p->degra == 2)
		{
			str = "Green";
			mlx_string_put(p->mlx, p->win, 200, 190, 0x0FFFFFF, str);
		}
		if (p->degra == 3)
		{
			str = "Red";
			mlx_string_put(p->mlx, p->win, 200, 190, 0x0FFFFFF, str);
		}
	}
}

void				ft_print_info2(t_af *p, char *str)
{
	str = " g:";
	mlx_string_put(p->mlx, p->win, 385, 110, 0x0FFFFFF, str);
	str = ft_itoa(p->r);
	mlx_string_put(p->mlx, p->win, 420, 110, 0x0FFFFFF, str);
	free(str);
	str = " r:";
	mlx_string_put(p->mlx, p->win, 385, 130, 0x0FFFFFF, str);
	str = ft_itoa(p->v);
	mlx_string_put(p->mlx, p->win, 420, 130, 0x0FFFFFF, str);
	free(str);
	str = " b:";
	mlx_string_put(p->mlx, p->win, 385, 150, 0x0FFFFFF, str);
	str = ft_itoa(p->b);
	mlx_string_put(p->mlx, p->win, 420, 150, 0x0FFFFFF, str);
	free(str);
	ft_print_info3(p, str);
}

void				ft_print_info(t_af *p)
{
	char			*str;

	ft_print_info2(p, str);
}
