/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolbox.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <msaliuta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 16:29:15 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/21 16:09:54 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __TOOLBOX_H
# define __TOOLBOX_H

# include "../libftprintf/includes/libft.h"
# include "../minilibx/mlx.h"

# define W 1300
# define HE 1000
# define LEN 40
# define WHITE 0xFFFFFF
# define RED 0xFF0000
# define GREEN 0x21610B
# define BLUE 0x0000FF
# define YELLOW 0xFFFF00

typedef struct		s_pce
{
	int				value;
	char			*line;
	char			**tmp;
	int				i;
	int				j;
	int				check;
}					t_pce;

typedef struct		s_pts
{
	int				x;
	int				y;
	int				i;
	int				j;
	long			x0;
	long			y0;
	long			x1;
	long			y1;
	int				next_x;
	int				next_y;
}					t_pts;

typedef struct		s_line
{
	int				dx;
	int				sx;
	int				dy;
	int				sy;
	int				err;
	int				e2;
}					t_line;

typedef struct		s_img
{
	int				sl;
	int				bpp;
	int				end;

	void			*img_ptr;
	int				*dta;
}					t_img;

typedef struct		s_mlx
{
	int				**stock;
	int				*taille;
	int				x;
	int				y;
	int				up;
	int				zoom;
	int				z;
	double			mlt;
	int				clr;
	char			*argv;
	void			*mlx;
	void			*win;
	int				fd;
	t_img			img;
}					t_mlx;
/*
** main.c
*/
void				ft_parce_file(t_mlx *ptr, t_pts *pts);
void				ft_fill_tab(int **sck, t_mlx *ptr, t_pts *pts, int *taille);

/*
**PRESSED_KEY
*/
int					pressed_key(int keycode, t_mlx *tool);
int					mouse_key(int keycode, t_mlx *tool);
/*
**error
*/
void				ft_print_err(int argc);
void				ft_help();
/*
**bresenham
*/
void				ft_line(t_pts *pts, t_mlx *ptr);
void				ft_line2(t_pts *pts, t_mlx *ptr);
void				ft_create_win(char *argv, t_mlx *ptr);
/*
**ft_math.h
*/
void				ft_solving(int **sck, t_pts *pts, t_mlx *ptr);
void				ft_solving2(int **sck, t_pts *pts, t_mlx *ptr);
void				ft_solving3(int **sck, t_pts *pts, t_mlx *ptr);
void				ft_solving4(int **sck, t_pts *pts, t_mlx *ptr);

#endif