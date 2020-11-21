/*
 ============================================================================
 Name        : Minirt.c
 Author      : yesmine
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "minirt.h"

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "libft/libft.h"

int ft_isspace(char c);
t_config_map *getMapFromLine(char *line)
{
	int i = 0;
	int j = 0;
	int k = 0;
	char *key = NULL;
	char *value = NULL;
	t_config_map *map = malloc(sizeof (t_config_map));

	while (i < 5)
		map->value[i++] = NULL;
	i = 0;
	while (line[i] && ft_isalpha(line[++i]));
	if (i > 0) {
		key = ft_substr(line, 0, i);
		value = ft_strtrim(ft_substr(line, i, ft_strlen(line) - i), " \t\v\f");
	}
	if (key != NULL && value != NULL) {
		map->key = key;
		i = 0;
		while (value[i] != '\0' && j < 5) {
			k = i;
			while (ft_isspace(value[i]) == 0 && value[i] != '\0')
				i++;
			map->value[j] = ft_substr(value, k, i - k);
			while (ft_isspace(value[i]) == 1)
				i++;
			j++;
		}
	}
	return map;
}

int main()
{
	int i;
	char *line;
	int fd;

	fd = open("/home/user42/Bureau/minirt/minirt_project/minirt/src/yesmine.rt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error");
	}
	t_list *lines = NULL;
	while(get_next_line(fd, &line))
	{
		if (ft_strlen(line) > 0)
		{
			t_config_map *map = getMapFromLine(line);
			t_list	*el = ft_lstnew(map);
			ft_lstadd_back(&lines, el);
			free(line);
		}
	}
	t_list	*tmp;
	tmp = lines;
	while(tmp->next != NULL)
	{
		i = 0;
		tmp = tmp->next;
		t_config_map *element = tmp->content;
		while(i < 5 )
			printf("key: (%s), Value: (%s)\n", element->key,element->value[i++]);
	}
	close(fd);
	return 0;
}

