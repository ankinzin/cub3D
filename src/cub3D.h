/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgodecke <cgodecke@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 09:30:40 by cgodecke          #+#    #+#             */
/*   Updated: 2023/08/28 13:45:56 by cgodecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <float.h>
# include <errno.h>

# include <X11/X.h>
# include <X11/keysym.h>
# include "minilibx-linux/mlx.h"

# define MLX_ERROR 30
# define BlUE_PIXEL 0x0000FF
# define RED_PIXEL 0xFF0000
# define BLACK_PIXEL 0x000000
# define GREEN_PIXEL 3110932

# define SOUTH 16764424
# define EAST 581375
# define NORTH 3148994
# define WEST 15437613

typedef struct s_texture
{
	int width;
	int height;
	int bitmap[8][8];
	int color0;
	int color1;

}	t_texture;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_data
{
	//mlx
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	int		cur_img;

	//map
	int		map_columns;
	int		map_rows;
	int		win_width;
	int		win_height;
	int img_width;       // Image width
    int img_height;      // Image height


	//raycaster
	int		win_half_width;
	int		win_half_height;
	double 	FOV;
	double 	half_FOV;
	double 	player_x;
	double 	player_y;
	double 	player_angle;
	double	ray_angle;
	double	ray_increment_angle;
	double	ray_precision;
	int		sky_direction;
	int		prev_sky_direction;
	int		prev_prev_sky_direction;
	t_texture texture;
}	t_data;

// mlx
int		window_close(t_data *data);
int		start_mlx(t_data *data);
int		handle_keypress(int keysym, t_data *data);
void	img_pix_put(t_img *img, int x, int y, int color);

// raycaster
int		render_image(t_data *data);
void	draw_line(t_data *data, int raycount, int y0, int y1, int raycolor);
double	deg_to_rad(double degree);
void	sky_direction(t_data *data, double ray_x, double ray_y);
void	check_sky_direction(t_data *data, int ray_count, int wall_height);

#endif
