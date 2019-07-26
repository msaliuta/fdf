/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <msaliuta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 03:45:04 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/26 08:15:37 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include "math.h"
# include "../libftprintf/includes/libft.h"

# define WHITE	0x0FFFFFF
# define WIDTH	2560
# define HEIGHT 1440
# define ESC	53
# define UP		13
# define DOWN	1
# define RIGHT	2
# define LEFT	0
# define DEEP	12
# define UNDEEP	14
# define ZOOM	126
# define DEZOOM	125
# define R_ISO	29
# define R_PAR	18
# define C		m->rgb
# define M		255

typedef struct		s_dot
{
	int				x;
	int				y;
	int				z;
	int				size_x;
	int				size_y;
}					t_dot;

typedef struct		s_map
{
	char			**argv;
	char			**map;
	char			**tmp;
	int				x;
	int				y;
}					t_map;

typedef	struct		s_rgb
{
	int				qr;
	int				qg;
	int				qb;
	int				r;
	int				g;
	int				b;
}					t_rgb;
typedef struct		s_af
{
	int				s_line;
	void			*win;
	void			*mlx;
	void			*img;
	t_dot			***dot;
	int				depth;
	unsigned int	shift_ud;
	unsigned int	shift_lr;
	int				zoom;
	int				prsp;
	int				size_line;
	char			*ret;
	int				key;
	t_rgb			rgb;
	int				min_hight;
	int				max_hight;
	int				prior;
	t_map			*map;
}					t_m;

/*
**main.c
*/

void				map_height(t_m *m);
int					exit_x();
void				exit_map(void);
int					start_mlx(t_m *m);

/*
**draw.c
*/

void				pixel(t_m *m, int i, int j, float q);
float				z_sort(t_m *m, t_dot *b, t_dot *a, int i);
void				connect(t_m *m, t_dot *b, t_dot *a);
void				iso(t_m *m, int i, int j);
void				paral(t_m *m, int i, int j);

/*
**colors.c
*/

void				pront_colo_menu(t_m *m, char *str);
int					colors_up(t_m *m);
int					colors_keys(t_m *m);
static int			key_hook_loop(t_m *m);

/*
**parse.c
*/

int					parse_nbr(int fd);
void				parse_map(t_m *m);
t_dot				***parse_coords(t_m *m);
void				put_point(t_m *m);

/*
**help.c
*/

void				non_zero_c(t_m *m, int q);
void				rules_print(t_m *m);
int					key_hooks(int keycode, t_m *m);
int					hook_zoom(t_m *m);

/*
**coord.c
*/

static	t_dot		*new_coords(int x, int y, int z, t_map *map);
void				stock_coord(int i, int y, t_dot ***dot, t_m *m);

/*
**init.c
*/

void				init(t_m *m);
void				init_colors(t_m *m);
void				init_iso(t_m *m);
void				init_paral(t_m *m);

#endif
