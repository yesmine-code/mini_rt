/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybesbes <ybesbes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 22:09:41 by ybesbes           #+#    #+#             */
/*   Updated: 2021/01/07 22:09:44 by ybesbes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"

void	get_map(char *line, t_vars *vars, t_list **lines)
{
	t_config_map	*map;
	t_list			*el;

	while (ft_isspace(*line) == 1)
		line++;
	if (ft_strlen(line) > 0 && line[0] != '#')
	{
		map = get_map_from_line(line);
		if (map == NULL)
		{
			vars->error_msg = ft_strdup("technical error");
			ft_exit_failure(*vars);
		}
		el = ft_lstnew(map);
		ft_lstadd_back(lines, el);
	}
}

void	ft_file_error(t_vars *vars, char *str)
{
	vars->error_msg = ft_strdup(str);
	ft_exit_failure(*vars);
}

void	read_config_file(char *config_file, t_vars *vars)
{
	t_list	*lines;
	int		fd;
	int		ret;
	char	*line;

	lines = NULL;
	fd = open(config_file, O_RDONLY);
	if (fd == -1)
		ft_file_error(vars, "corrupted file");
	ret = get_next_line(fd, &line);
	while (ret != -1)
	{
		get_map(line, vars, &lines);
		if (line != NULL)
			free(line);
		if (ret == 0)
			break ;
		ret = get_next_line(fd, &line);
	}
	close(fd);
	if (lines == NULL)
		ft_file_error(vars, "empty file");
	vars->lines = lines;
}

int		check_file_extention(char *filename)
{
	char	*ptr;
	int		ret;

	ret = 0;
	ptr = NULL;
	if (ft_strlen(filename) > 3)
	{
		ptr = ft_substr(filename, ft_strlen(filename) - 3, 3);
		if (ptr != NULL && ft_strncmp(ptr, ".rt", 3) == 0)
			ret = 1;
	}
	if (ptr != NULL)
		free(ptr);
	return (ret);
}
