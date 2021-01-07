/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybesbes <ybesbes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 22:05:52 by ybesbes           #+#    #+#             */
/*   Updated: 2021/01/07 22:06:07 by ybesbes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"

int		get_pixel(t_vars *vars, int x, int y)
{
	int	ptr;

	ptr = *(int*)(vars->img->addr + (4 * (int)vars->scene->resolution.width
				* ((int)vars->scene->resolution.height - 1 - y)) + (4 * x));
	return ((ptr & 0xFF0000) | (ptr & 0x00FF00) | (ptr & 0x0000FF));
}

void	extract_char_from_int(int filesize, unsigned char *str)
{
	str[0] = (unsigned char)(filesize);
	str[1] = (unsigned char)(filesize >> 8);
	str[2] = (unsigned char)(filesize >> 16);
	str[3] = (unsigned char)(filesize >> 24);
}

size_t	image_header(t_vars *vars, int fd, int filesize)
{
	unsigned char			str[INFO_HEADER_SIZE];

	ft_bzero(str, INFO_HEADER_SIZE);
	str[0] = (unsigned char)('B');
	str[1] = (unsigned char)('M');
	extract_char_from_int(filesize, str + 2);
	str[10] = (unsigned char)(54);
	str[14] = (unsigned char)(40);
	extract_char_from_int(vars->scene->resolution.width, str + 18);
	extract_char_from_int(vars->scene->resolution.height - 1, str + 22);
	str[26] = (unsigned char)(1);
	str[28] = (unsigned char)(24);
	return (write(fd, str, INFO_HEADER_SIZE));
}

size_t	image_pixels(t_vars *vars, int fd, int pad)
{
	char			rgb[3];
	int				i;
	int				j;
	int				color;
	size_t			ret;

	ft_bzero(rgb, 3);
	i = 0;
	ret = 0;
	while (i < vars->scene->resolution.height)
	{
		j = 0;
		while (j < vars->scene->resolution.width)
		{
			color = get_pixel(vars, j, i);
			ret = write(fd, &color, 3);
			j++;
		}
		ret += write(fd, &rgb, pad);
		i++;
	}
	return (ret);
}

void	save_image(t_vars *vars)
{
	int			fd;
	int			filesize;
	int			pad;

	pad = (4 - (vars->scene->resolution.width * 3) % 4) % 4;
	filesize = 54 + (vars->scene->resolution.height
			* (3 * vars->scene->resolution.width + pad));
	fd = open("miniRT.bmp", O_WRONLY | O_CREAT | O_TRUNC
			| O_APPEND, 0666);
	if (fd < 0)
	{
		vars->error_msg = "bmp file could not be created";
		ft_exit_failure(*vars);
	}
	image_header(vars, fd, filesize);
	image_pixels(vars, fd, pad);
	close(fd);
}
