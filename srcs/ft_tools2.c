/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <msaliuta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 21:20:42 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/23 16:58:07 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int					ft_key_hook2(int keycode, t_af *af)
{
	if (keycode == DEZOOM)
	{
		af->zoom -= 50;
		af->tight2 += 25;
		af->tight += 25;
	}
	if (keycode == 86)
	{
		if ((af->r -= 10) < 0)
			af->r = 0;
		else
			af->r -= 10;
	}
	if (keycode == 87)
	{
		if ((af->v -= 10) < 0)
			af->v = 0;
		else
			af->v -= 10;
	}
	keycode == 89 ? af->degra = 1 : 0;
	keycode == 91 ? af->degra = 2 : 0;
	return (ft_key_hook3(keycode, af));
}

int					ft_key_hook3(int keycode, t_af *af)
{
	if (keycode == 88)
	{
		if ((af->b -= 10) < 0)
			af->b = 0;
		else
			af->b -= 10;
	}
	keycode == 92 ? af->degra = 3 : 0;
	if (keycode == 83)
	{
		if ((af->r += 10) > 255)
			af->r = 255;
		else
			af->r += 10;
	}
	if (keycode == 84)
	{
		if ((af->v += 10) > 255)
			af->v = 255;
		else
			af->v += 10;
	}
	return (ft_key_hook4(keycode, af));
}
