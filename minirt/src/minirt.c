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
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <fcntl.h>
#include "libft/libft.h"

int Check_key(t_list *lines);
int ft_isspace(char c);
t_config_map *getMapFromLine(char *line)
{
	int i = 0;
	int j = 0;
	int start = 0;
	char *key = NULL;
	char *value = NULL;
	t_config_map *map = malloc(sizeof (t_config_map));

	while (i < sizeof(map->value) / sizeof(char*))
		map->value[i++] = NULL;
	i = 0;
	while (line[i] && ft_isspace(line[++i]) == 0);
	if (i > 0) {
		key = ft_substr(line, 0, i);
		value = ft_strtrim(ft_substr(line, i, ft_strlen(line) - i), " \t\v\f");
	}
	if (key != NULL && value != NULL) {
		map->key = key;
		i = 0;
		while (value[i] != '\0' && j < sizeof(map->value) / sizeof(char*)) {
			start = i;
			while (ft_isspace(value[i]) == 0 && value[i] != '\0')
				i++;
			map->value[j] = ft_substr(value, start, i - start);
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
	int ret;

	fd = open("/home/user42/Bureau/minirt/minirt_project/minirt/src/yesmine.rt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	t_list *lines = NULL;
	ret = get_next_line(fd, &line);
	while(ret != -1)
	{
		if (ft_strlen(line) > 0)
		{
			t_config_map *map = getMapFromLine(line);
			t_list	*el = ft_lstnew(map);
			ft_lstadd_back(&lines, el);
			free(line);
		}
		if(ret == 0)
			break;
		ret = get_next_line(fd, &line);
	}
	t_list	*tmp;
	tmp = lines;
	if(Check_key(lines) == 1)
	{
		while(tmp != NULL)
		{
			i = 0;
			t_config_map *element = tmp->content;
			while(i < sizeof(element->value) / sizeof(char*) )
				printf("key: (%s), Value: (%s)\n", element->key,element->value[i++]);
			tmp = tmp->next;
		}
	}
	else
		exit(EXIT_FAILURE);
	close(fd);
	return 0;
}

