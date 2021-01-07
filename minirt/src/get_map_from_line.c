/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_from_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybesbes <ybesbes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 22:14:53 by ybesbes           #+#    #+#             */
/*   Updated: 2021/01/07 22:14:55 by ybesbes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"

void			get_map_key_and_value(char *key, char *value, t_config_map *map)
{
	int	i;
	int	start;
	int	j;

	i = 0;
	j = 0;
	if (key != NULL && value != NULL)
	{
		map->key = ft_strdup(key);
		while (value[i] != '\0' &&
			(unsigned)j < sizeof(map->value) / sizeof(char*))
		{
			start = i;
			while (ft_isspace(value[i]) == 0 && value[i] != '\0')
				i++;
			map->value[j] = ft_substr(value, start, i - start);
			while (ft_isspace(value[i]) == 1)
				i++;
			j++;
		}
	}
	if (key != NULL)
		free(key);
	if (value != NULL)
		free(value);
}

void			get_value_from_line(int i, char *line, char **value)
{
	char	*str;

	str = NULL;
	str = ft_substr(line, i, ft_strlen(line) - i);
	if (str != NULL)
	{
		*value = ft_strtrim(str, " \t\v\f");
		free(str);
	}
}

t_config_map	*get_map_from_line(char *line)
{
	int				i;
	char			*key;
	char			*value;
	t_config_map	*map;

	key = NULL;
	value = NULL;
	i = 0;
	map = malloc(sizeof(t_config_map));
	if (map == NULL)
		return (NULL);
	while ((unsigned)i < sizeof(map->value) / sizeof(char*))
		map->value[i++] = NULL;
	i = 0;
	while (line[i] && ft_isspace(line[i + 1]) == 0)
		i++;
	i++;
	if (i > 0)
	{
		key = ft_substr(line, 0, i);
		get_value_from_line(i, line, &value);
	}
	get_map_key_and_value(key, value, map);
	return (map);
}
