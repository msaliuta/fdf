/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <msaliuta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 03:45:04 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/26 03:37:45 by msaliuta         ###   ########.fr       */
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

void				ft_reset_iso(t_m *m);
void				ft_reset_paral(t_m *m);
void				ft_get_map_hight(t_m *m);

/*
**ft_tools.c
*/

void				ft_degra2(t_m *m, int q);
void				ft_exit_error(void);
void				ft_print_info3(t_m *m, char *str);
void				ft_print_info2(t_m *m, char *str);
void				ft_print_info(t_m *m);

/*
**ft_persp.c
*/

void				ft_my_pixel_put(t_m *m, int i, int j, float q);
float				ft_degra(t_m *m, t_dot *b, t_dot *a, int i);
void				ft_wire(t_m *m, t_dot *b, t_dot *a);
void				ft_iso_persp(t_m *m, int i, int j);
void				ft_paral_persp(t_m *m, int i, int j);

/*
**ft_get_map.c
*/

int					ft_count_size(int fd);
void				ft_get_map(t_m *m);
static	t_dot		*ft_new_coord(int x, int y, int z, t_map *map);
void				ft_stock_coord(int i, int y, t_dot ***dot, t_m *m);
t_dot				***ft_get_coord(t_m *m);

/*
**build_mlx.c
*/

void				ft_init(t_m *m);
void				ft_put_point(t_m *m);
void				init_colors(t_m *m);
int					ft_key_hook(int keycode, t_m *m);
static int			ft_loop_key_hook(t_m *m);
int					exit_x(void);
int					ft_build_mlx(t_m *m);

#endif
