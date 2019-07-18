/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 20:55:07 by mikim             #+#    #+#             */
/*   Updated: 2017/04/03 20:55:08 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_word_count(char *s, char c)
{
	int i;
	int cnt;
	int flag;

	i = -1;
	cnt = 0;
	flag = 0;
	while (s[++i] != '\0')
	{
		if (s[i] == c)
			flag = 0;
		else if (s[i] != c && flag == 0)
		{
			flag = 1;
			cnt++;
		}
	}
	return (cnt);
}

void	ft_check_valid(t_env *e)
{
	char	*line;
	int		fd;
	int		cnt;
	int		first;

	cnt = 0;
	first = 0;
	e->m_x = 0;
	e->m_y = 0;
	ft_error((fd = open(e->file, O_RDONLY)));
	while (get_next_line(fd, &line) == 1)
	{
		cnt = ft_word_count(line, ' ');
		ft_map_error((!first++ || cnt == e->m_x));
		e->m_x = cnt;
		e->m_y++;
		free(line);
	}
}

void	ft_check_ac(t_env *e, int ac, char **av)
{
	int i;

	i = 1;
	(ac >= 2 && ac <= 6) ? 0 : ft_usage();
	e->file = ft_strdup(av[1]);
	e->w_x = 0;
	e->w_y = 0;
	while (i < ac)
	{
		if (!ft_strcmp(av[i], "-w") && i + 1 < ac)
			e->w_x = ft_atoi(av[i + 1]);
		else if (!ft_strcmp(av[i], "-h") && i + 1 < ac)
			e->w_y = ft_atoi(av[i + 1]);
		else if (!ft_strcmp(av[i], "--help"))
			ft_usage();
		i++;
	}
	e->w_x = (e->w_x < 600 || e->w_x > 1920 ? 1280 : e->w_x);
	e->w_y = (e->w_y < 600 || e->w_y > 1280 ? 1024 : e->w_y);
}
