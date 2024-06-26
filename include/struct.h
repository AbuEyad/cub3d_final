/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habu-zua <habu-zua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 15:11:32 by habu-zua          #+#    #+#             */
/*   Updated: 2024/06/02 13:14:15 by habu-zua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_info
{
	char	**map;
	int		len_map;
	int		len_x;
	int		len_y;
	int		rx;
	int		ry;
	char	north_t[256];
	char	south_t[256];
	char	west_t[256];
	char	east_t[256];
	int		colorf;
	int		colorc;
	int		player_y;
	int		player_x;
	char	player_start;
	int		info_count;
}				t_info;

typedef struct s_player
{
	double	pos_y;
	double	pos_x;
	float	x;
	float	y;
	double	dir_x;
	double	dir_y;
	double	ms;
	double	rot_s;
}				t_player;

typedef struct s_mlx
{
	void	*ptr;
	void	*win;
	char	*img;
	char	*data_img;
	int		bpixel;
	int		size_line;
	int		endian;
}				t_mlx;

typedef struct s_move
{
	int		esc;
	int		foward;
	int		retreat;
	int		left;
	int		right;
	int		turn_left;
	int		turn_right;
	int		sprint;
	int		texture;
}				t_move;

typedef struct s_ray
{
	double		plane_x;
	double		plane_y;
	double		cam_x;
	double		raydir_x;
	double		raydir_y;
	int			map_x;
	int			map_y;
	double		sidedist_x;
	double		sidedist_y;
	double		deltadist_x;
	double		deltadist_y;
	double		perpwalldist;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
}					t_ray;

typedef struct s_len_map
{
	int		l1;
	int		l2;
	int		check;
}				t_len_map;

typedef struct s_text_info
{
	int		lh;
	int		dr_st;
	int		dr_en;
	double	wallx;
	int		x;
	int		y;
	int		w;
	int		h;
}				t_text_info;

typedef struct s_texture
{
	void	*ptr;
	char	*img;
	int		bpixel;
	int		size_line;
	int		endian;
}				t_texture;

typedef struct s_mini_map
{
	int		y;
	int		x;
	int		x_max;
	int		t_x;
	int		t_y;
	int		line;
}				t_mini_map;

typedef struct s_storage
{
	t_info		*info;
	t_mlx		*mlx;
	t_player	*player;
	t_move		*move;
	t_ray		*ray;
	t_texture	*texture;
	double		*zbuffer;
}				t_storage;

#endif
