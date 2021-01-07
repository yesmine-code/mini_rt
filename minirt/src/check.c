/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybesbes <ybesbes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 22:07:51 by ybesbes           #+#    #+#             */
/*   Updated: 2021/01/07 22:07:56 by ybesbes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"

void	keys_init(const char *keys[9])
{
	keys[0] = "R";
	keys[1] = "A";
	keys[2] = "c";
	keys[3] = "l";
	keys[4] = "pl";
	keys[5] = "sp";
	keys[6] = "sq";
	keys[7] = "cy";
	keys[8] = "tr";
}

int		error_function(t_vars *vars, char *str, char *element_key)
{
	vars->error_msg = ft_strjoin(element_key, str);
	return (-1);
}

int		find_key_in_tab(t_config_map *element)
{
	int				i;
	const char		*keys[9];

	keys_init(keys);
	i = 0;
	while ((unsigned)i < sizeof(keys) / sizeof(char *))
	{
		if (ft_strnstr(keys[i], element->key, ft_strlen(keys[i]))
			&& ft_strlen(element->key) == ft_strlen(keys[i]))
			break ;
		else
			i++;
	}
	if (i == sizeof(keys) / sizeof(char *))
		return (1);
	return (0);
}

int		count_r_and_akey(t_config_map *element, int *var_r, int *var_a)
{
	if (ft_strchr(element->key, 'R') && ft_strlen(element->key) == 1)
		*var_r = *var_r + 1;
	else if (ft_strchr(element->key, 'A') && ft_strlen(element->key) == 1)
		*var_a = *var_a + 1;
	if (*var_r > 1 || *var_a > 1)
		return (1);
	return (0);
}

int		check_keys_and_values(t_vars *vars)
{
	t_list			*tmp;
	t_config_map	*element;
	int				var_r;
	int				var_a;

	var_r = 0;
	var_a = 0;
	tmp = vars->lines;
	while (tmp != NULL)
	{
		element = tmp->content;
		if (find_key_in_tab(element) == 1)
			return (error_function(vars, "is not correct", element->key));
		if (count_r_and_akey(element, &var_r, &var_a) != 0)
			return (error_function(vars, "couldn't be reused", element->key));
		if (check_values(element, vars) == -1)
			return (-1);
		tmp = tmp->next;
	}
	return (1);
}
