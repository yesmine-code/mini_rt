/*
 * minire.h
 *
 *  Created on: 3 août 2020
 *      Author: user42
 */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "libft/libft.h"
#include <math.h>
#include <float.h>

#ifndef MINIRT_H_
#define MINIRT_H_

typedef struct 	s_config_map
{
	char	*key;
	char	*value[6];
}				t_config_map;

#endif /* MINIRT_H_ */

static const char A_KEY = 'A';
static const char R_KEY = 'R';

int	check_values(t_config_map *element);
int	get_num_of_non_null_value(char *value[]);
int	Check_values_if_Rkey(t_config_map *element);
int check_values_if_A_key(t_config_map *element);
int check_values_if_c_key(t_config_map *element);
int	get_num_of_non_null_value(char *value[]);
int	check_if_value_is_tab_of_colors(char *value);
int	check_if_limitted_float(char *value, double min, double max);
int check_values_if_c_key(t_config_map *element);
int Check_key(t_list *lines);
int ft_isspace(char c);
t_config_map *getMapFromLine(char *line);
int convert_char_to_float(char *value, double *new_float);
void	ft_free_tab(char **tab);
int Check_if_float(char *value);
int	check_if_strings_can_be_integer(char **tab);
int	check_if_strings_are__floats_or_int(char **tab);
int	check_if_value_is_tab_of__floats_or_int(char *value);
int	check_if_value_is_an_integer_between_0_and_180(char *value);
int	check_if_strings_are_n_floats(char **tab, int n);
int	check_if_value_is_tab_of_n_floats(char *value, int n);
int	check_limitted_n_floats_or_int(char **tab, double min, double max, int n);
int	check_n_limitted_floats_or_int(char *value, double min, double max, int n);
int value_is_int(char *value);

