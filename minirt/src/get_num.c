/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_num.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybesbes <ybesbes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 22:15:39 by ybesbes           #+#    #+#             */
/*   Updated: 2021/01/07 22:15:41 by ybesbes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	value_is_int(char *value)
{
	char	*str;
	int		ret;

	ret = -1;
	str = ft_itoa(ft_atoi(value));
	if (str != NULL && ft_strlen(str) == ft_strlen(value))
		ret = 1;
	if (str != NULL)
		free(str);
	return (ret);
}

int	check_sign(char *v, int *i)
{
	if (ft_isdigit(v[*i]) == 1 || v[*i] == '-' || v[*i] == '+')
		*i = *i + 1;
	else
		return (-1);
	if ((v[*i - 1] == '-' || v[*i - 1] == '+') && ft_isdigit(v[*i]) != 1)
		return (-1);
	return (1);
}

int	check_if_float(char *v)
{
	int	length;
	int	i;
	int	dots_num;

	i = 0;
	dots_num = 0;
	length = ft_strlen(v);
	if (check_sign(v, &i) == -1)
		return (-1);
	while (i < length)
	{
		if (ft_isdigit(v[i]) || v[i] == '.')
		{
			if (v[i] == '.')
				dots_num++;
			i++;
		}
		else
			break ;
	}
	if (i == length && dots_num == 1 && v[length - 1] != '.')
		return (1);
	return (-1);
}

int	check_if_limitted_float(char *value, double min, double max)
{
	double	float_value;

	float_value = 0;
	if (check_if_float(value) == 1 || value_is_int(value) == 1)
	{
		convert_char_to_float(value, &float_value);
		if (float_value >= min && float_value <= max)
			return (1);
	}
	return (-1);
}

int	convert_char_to_float(char *value, double *new_float)
{
	char	**tab;
	char	*new_value;
	int		length;

	if (check_if_float(value) == 1)
	{
		tab = ft_split(value, '.');
		length = ft_strlen(tab[1]);
		new_value = ft_strjoin(tab[0], tab[1]);
		*new_float = ft_atoi(new_value) * pow(10, length * -1);
		ft_free_tab((void **)tab, 1);
		free(new_value);
		return (1);
	}
	if (value_is_int(value) == 1)
	{
		*new_float = ft_atoi(value);
		return (1);
	}
	return (-1);
}
