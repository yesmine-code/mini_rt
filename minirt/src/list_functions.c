/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybesbes <ybesbes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 22:17:40 by ybesbes           #+#    #+#             */
/*   Updated: 2021/01/07 22:17:41 by ybesbes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"

void	*get_from_list_by_id(t_list *list, int object_id)
{
	if (object_id < 0)
		return (NULL);
	while (list && object_id > 0)
	{
		list = list->next;
		object_id--;
	}
	if (object_id > 0)
		return (NULL);
	return (list->content);
}
