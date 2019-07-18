/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 20:55:05 by mikim             #+#    #+#             */
/*   Updated: 2018/01/25 12:28:52 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_abs(int i)
{
	return (i > 0 ? i : -i);
}

void	ft_tab(t_point *pt, char *s)
{
	int		i;
	int		col;

	i = -1;
	col = 0;
	while (s[++i] != '\0')
		s[i] == ',' ? col++ : 0;
	col > 1 ? ft_map_error(-1) : 0;
	if (col == 0)
	{
		pt->z = ft_atoi(s);
		pt->col = 16777215;
	}
	else if (col == 1)
	{
		i = 0;
		pt->z = ft_atoi(s);
		while ((s[i] != '0' || s[i + 1] != 'x') && i++ > -1)
			;
		ft_strlen(s + i + 2) != 6 ? ft_map_error(-1) : 0;
		pt->col = ft_atoi_base(s + i + 2, 16);
	}
}

void	ft_tab_z(t_env *e, char *line, int i)
{
	char	**tmp;
	int		j;
	int		x;

	j = -1;
	x = 0;
	ft_alloc_error((int)(e->pt[i] =
	(t_point*)malloc(sizeof(t_point) * (e->m_x + 1))));
	tmp = ft_strsplit(line, ' ');
	while (tmp[++j] != NULL)
	{
		ft_tab(&e->pt[i][j], tmp[j]);
		e->min_z = (e->pt[i][j].z < e->min_z ? e->pt[i][j].z : e->min_z);
		e->max_z = (e->pt[i][j].z > e->max_z ? e->pt[i][j].z : e->max_z);
		free(tmp[j]);
	}
	free(tmp);
}
