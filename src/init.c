/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <msaliuta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 07:38:24 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/26 07:39:30 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void				init_iso(t_m *m)
{
	m->depth = 0;
	m->shift_ud = -WIDTH / 3;
	m->shift_lr = HEIGHT / 3 * 2;
	m->zoom = 2000;
	m->prsp = 1;
	C.r = M;
	C.g = M;
	C.b = M;
	m->prior = 0;
}

void				init_paral(t_m *m)
{
	m->depth = 0;
	m->shift_ud = 400;
	m->shift_lr = 900;
	m->zoom = 40;
	m->prsp = 0;
	C.r = M;
	C.g = M;
	C.b = M;
	m->prior = 0;
}

void				init(t_m *m)
{
	m->shift_ud = -WIDTH / 3;
	m->shift_lr = HEIGHT / 3 * 2;
	m->zoom = 2000;
	m->prsp = 1;
	C.r = M;
	C.g = M;
	C.b = M;
	m->depth = 0;
	m->prior = 0;
	C.qr = 0;
	C.qb = 0;
	C.qg = 0;
}

void				init_colors(t_m *m)
{
	C.r = 0;
	C.g = 0;
	C.b = 0;
	m->prior = 0;
}
