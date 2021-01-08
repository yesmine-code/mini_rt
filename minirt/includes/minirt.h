/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybesbes <ybesbes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 22:21:53 by ybesbes           #+#    #+#             */
/*   Updated: 2021/01/07 22:22:02 by ybesbes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"
# include "mlx.h"
# include <math.h>
# include <float.h>

typedef struct	s_config_map
{
	char	*key;
	char	*value[6];
}				t_config_map;

typedef struct	s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

typedef struct	s_resolution
{
	int		width;
	int		height;

}				t_resolution;

int				get_num_of_non_null_value(char *value[]);
int				get_num_of_non_null_value(char *value[]);
int				check_if_value_is_tab_of_colors(char *value);
int				check_if_limitted_float(char *value, double min, double max);
int				ft_isspace(char c);
t_config_map	*get_map_from_line(char *line);
int				check_if_value_is_an_integer_between_0_and_180(char *value);
int				convert_char_to_float(char *value, double *new_float);
void			ft_free_tab(void **tab, int free_tab_parent);
void			ft_free_list(t_list *list);
int				check_if_float(char *value);
int				check_if_strings_can_be_integer(char **tab);
int				check_if_strings_are__floats_or_int(char **tab);
int				check_if_value_is_tab_of__floats_or_int(char *value);
int				check_if_value_is_a_float_between_0_and_180(char *value);
int				check_if_strings_are_n_floats(char **tab, int n);
int				check_if_value_is_tab_of_n_floats(char *value, int n);
int				check_limitted_n_floats_or_int(char **tab,
				double min, double max, int n);
int				check_n_limitted_floats_or_int(char *value,
				double min, double max, int n);
int				value_is_int(char *value);
t_resolution	get_resolution_values(t_config_map *element);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
int				check_file_extention(char *filename);
int				converting_ints_or_floats(char **tab, int *i,
				double min, double max);
void			ft_free_map(t_list *list);
void			*get_from_list_by_id(t_list *list, int object_id);

#endif
