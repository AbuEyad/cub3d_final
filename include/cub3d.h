/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habu-zua <habu-zua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 15:11:08 by habu-zua          #+#    #+#             */
/*   Updated: 2024/06/02 18:54:39 by habu-zua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "get_next_line.h"
# include "../libs/mlx-mac/mlx.h"
# include "struct.h"
# include <stdio.h>

# define KEYPRESS_EVENT 2
# define KEYPRESS_MASK 1
# define KEYRELEASE_EVENT 3
# define KEYRELEASE_MASK 2

int		ft_expose(t_storage *storage);
void	ft_color_wall_mini_map(t_storage *storage, int y, int x, int color);
void	ft_draw_mini_map(t_storage *storage);
int		ft_read_info(char *s, t_info *info_map);
int		ft_read_management(char *s, t_info *info_map);
int		ft_check_extension(char *s);
int		ft_parse_info(t_info *info_map);
int		ft_parse_management(t_info *info_map, t_len_map *len);
int		ft_parse_map_line_updown(t_info *info_map);
int		ft_parse_map_line_between(t_info *info_map, t_len_map *len);
int		ft_get_resolution(char *s, t_info *info_map);
int		ft_get_texture_path_north_south(char *s, t_info *info_map);
int		ft_get_texture_path_west_east_s(char *s, t_info *info_map);
int		ft_get_color(char *s, t_info *info_map);
int		ft_get_info_map(char *s, t_info *info_map);
int		ft_mgt_error(int error, char *s);
void	ft_init_struct_infomap(t_info *info_map);
void	ft_init_struct_move(t_move *move);
void	ft_init_struct_player(t_player *player);
void	ft_init_struct_ray(t_ray *ray);
void	ft_init_pos_player(t_storage *storage, t_player *player);
void	ft_init_storage(t_info *i_map, t_mlx *mlx, t_player *p, t_storage *s);
void	ft_fill_storage(t_move *move, t_ray *ray, t_storage *storage);
void	ft_init1(t_move	*move, t_player *player, t_ray *ray);
void	ft_check_len_map(t_info *info_map);
int		ft_exit_prog(t_storage *storage);
int		ft_keyrelease(int keycode, t_move *move);
int		ft_keypress(int keycode, t_move *move);
void	ft_move_player_mini_map(t_storage *storage);
void	ft_player_pos_cam(t_storage *storage, t_player *player);
void	ft_raycaster(t_storage *storage, t_ray *ray);
int		ft_init_texture(t_storage *storage, t_texture *texture, int w, int h);
void	ft_management_texture(t_storage *storage, t_ray *ray, int x);
void	ft_draw_wall_color(t_storage *storage, t_ray *ray, int x);
void	ft_drw_wl_txr_sn(t_storage *s, t_texture *txr, t_text_info *t_i, int x);
void	ft_drw_wl_txr_ew(t_storage *s, t_texture *txr, t_text_info *t_i, int x);
void	*ft_memcpy(void *dst, const void *src, int n);
int		ft_get_pos_player(t_info *info_map, int i, int x);
void	ft_get_sprite_nb(t_info *info_map);
void	ft_get_pos_sprite(t_info *info_map, t_storage *storage);
int		ft_strlen(char *s);
void	ft_putstr(char *s);
void	ft_put2str(char *s1, char *s2);
int		ft_is_wall(char *c);
int		ft_atoi(char *s);
char	*ft_strjoin_point(char *s1, char *s2);
int		ft_verif_rgb_is_valid(int nb[4], int n);
int		ft_get_info_map_resolution(char *s, t_info *info_map);
void	ft_free_tab(char **tab);
int		ft_check_space_rgb(char **tab, int i);
char	*ft_strdup_map(char *s);
char	*ft_strcpy(char *dest, char *src);
int		get_next_line(int fd, char **line);
char	**ft_split(char const *s, char c);
void    print_map(char **map);
int     open_zero(char **map);
char    **ft_check_last_line(char *map_tmp, char *line);

#endif
