/*
 * list_functions.c
 *
 *  Created on: 10 déc. 2020
 *      Author: user42
 */


#include "vec.h"

void	*get_from_list_by_id(t_list *list, int object_id)
{
	if (object_id < 0)
		return NULL;
	while (list && object_id > 0)
	{
		list = list->next;
		object_id--;
	}
	if (object_id > 0)
		return NULL;
	return(list->content);
}

