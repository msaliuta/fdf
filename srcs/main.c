/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <msaliuta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 20:54:59 by mikim             #+#    #+#             */
/*   Updated: 2019/07/18 18:04:45 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_fdf(t_env *e)
{
	ft_init_env(e);
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, e->w_x, e->w_y,
	"FdF - 42 Project by. MIKIM");
	ft_coord(e, -1, -1);
	ft_draw(e);
	mlx_hook(e->win, 2, 2, ft_key_hook, e);
	mlx_loop(e->mlx);
}

void	ft_parse(t_env *e)
{
	char	*line;
	int		fd;
	int		i;
	int		j;

	i = 0;
	line = ft_strnew(1);
	ft_check_valid(e);
	ft_error((fd = open(e->file, O_RDONLY)));
	ft_alloc_error((int)(e->pt =
	(t_point**)malloc(sizeof(t_point*) * (e->m_y + 1))));
	e->min_z = 0;
	e->min_z = 0;
	while (get_next_line(fd, &line) == 1)
	{
		j = -1;
		while (line[++j] != '\0')
		{
			ft_map_error((ft_isdigit(line[j]) || (line[j] > 64 && 71 > line[j])
			|| (line[j] > 96 && 103 > line[j]) || line[j] == ' ' ||
			line[j] == ',' || line[j] == '-' || line[j] == 'x'));
		}
		ft_tab_z(e, line, i);
		i++;
	}
}

int		main(int ac, char **av)
{
	t_env	e;

	ft_check_ac(&e, ac, av);
	ft_parse(&e);
	ft_fdf(&e);
	return (0);
}
