/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybesbes <ybesbes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 19:27:35 by ybesbes           #+#    #+#             */
/*   Updated: 2020/05/19 19:12:25 by ybesbes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int	ft_putstr_fd(char *s, int fd)
{
	int	i;
	int ret;

	i = 0;
	ret = 0;
	if (s == NULL)
		return (ret);
	while (s[i] != '\0')
	{
		ret += write(fd, &s[i], 1);
		i++;
	}
	return (ret);
}
