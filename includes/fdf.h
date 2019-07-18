/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <msaliuta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 17:54:00 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/18 17:55:10 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <libft.h>
# include <math.h>
# include <mlx.h>

typedef struct	s_point
{
	int		x;
	int		y;
	int		z;
	int		col;
}				t_point;

typedef struct	s_color
{
	int		red;
	int		green;
	int		blue;
}				t_color;

typedef struct	s_env
{
	t_point	**pt;
	void	*mlx;
	void	*win;
	char	*file;
	int		w_x;
	int		w_y;
	int		m_x;
	int		m_y;
	int		g_x;
	int		g_y;
	int		g_zoom;
	int		zoom_x;
	int		zoom_y;
	int		alt;
	int		min_z;
	int		max_z;
	int		diff;
	int		move_x;
	int		move_y;
	int		rot_x;
	int		rot_y;
	int		color;
}				t_env;

/*
** main
*/

void			ft_fdf(t_env *e);
void			ft_parse(t_env *e);

/*
** init
*/

void			ft_init_pt(t_env *e);
void			ft_init_env(t_env *e);
int				ft_key_hook(int keycode, t_env *e);

/*
** message
*/

void			ft_alloc_error(int error);
void			ft_map_error(int error);
void			ft_error(int error);
void			ft_usage(void);
void			ft_guide(t_env *e);

void			ft_coord_alt(t_env *e, int y, int x);
void			ft_coord(t_env *e, int y, int x);

/*
** util
*/

int				ft_abs(int i);
void			ft_tab(t_point *pt, char *s);
void			ft_tab_z(t_env *e, char *line, int i);

/*
** validation
*/

int				ft_word_count(char *s, char c);
void			ft_check_valid(t_env *e);
void			ft_check_ac(t_env *e, int ac, char **av);

/*
** draw
*/

void			ft_get_color(t_env *e, t_color *c, t_point p);
int				ft_set_color(t_env *e, t_point p1, t_point p2, int i);
void			ft_draw_x(t_env *e, t_point p1, t_point p2);
void			ft_draw_y(t_env *e, t_point p1, t_point p2);
void			ft_draw(t_env *e);

#endif
