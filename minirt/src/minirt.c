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
t_config_map getMapFromLine(char *line) {
	int i = 0;
	int j = 0;
	int k = 0;
	char *key = NULL;
	char *value = NULL;
	t_config_map map;
	while (i < 5)
		map.value[i++] = NULL;
	i = 0;
	while (line[i] && ft_isalpha(line[++i]));
	if (i > 0) {
		key = ft_substr(line, 0, i);
		value = ft_strtrim(ft_substr(line, i, ft_strlen(line) - i), " \t\v\f");
	}
	if (key != NULL && value != NULL) {
		map.key = key;
		i = 0;
		while (value[i] != '\0' && j < 5) {
			k = i;
			while (ft_isspace(value[i]) == 0 && value[i] != '\0')
				i++;
			map.value[j] = ft_substr(value, k, i - k);
			while (ft_isspace(value[i]) == 1)
				i++;
			j++;
		}
	}
	return map;
}

int main() {
	int i = 0;
	char *line;
	int fd;

	fd = open("/home/user42/Bureau/minirt/ws/Minirt/src/yesmine.rt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error");
	//	printf("%s", strerror(errno));
	//	exit;
	}
	if(get_next_line(fd, &line) != 1)
		perror("Error");
	while(get_next_line(fd, &line))
	{
		t_config_map map = getMapFromLine(line);
		i = 0;
		while (i < 5 && map.value[i] != NULL) {
			printf("key: (%s), Value: (%s)\n", map.key, map.value[i]);
			i++;
		}
		free(line);
	}
	close(fd);
	return 0;
}

