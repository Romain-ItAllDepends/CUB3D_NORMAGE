/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 11:14:48 by rgobet            #+#    #+#             */
/*   Updated: 2024/10/01 13:58:45 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

char	**get_file(int fd)
{
	int		size_get;
	char	*buffer;
	char	*getter;
	char	**file;

	size_get = 1;
	getter = NULL;
	file = NULL;
	buffer = ft_calloc(2, sizeof(char));
	if (!buffer)
		error_malloc(fd, NULL);
	while (size_get > 0)
	{
		size_get = read(fd, buffer, 1);
		if (size_get > 0)
			getter = ft_strjoin_free_s1(getter, buffer);
		buffer[0] = 0;
	}
	if (size_get == -1)
		error_read(fd, buffer, getter);
	free(buffer);
	file = ft_split(getter, '\n');
	if (verify_split(file, getter) == 1)
		return (NULL);
	return (file);
}

char	**get_map(char **file)
{
	int		i;
	int		j;
	char	**map;

	i = start_map(file);
	if (i == -1)
		map_error();
	j = 0;
	map = ft_calloc(len_db_char(&file[i]) + 1, sizeof(char *));
	if (!map)
		error_malloc(-1, NULL);
	while (file && file[i])
	{
		map[j] = copy(file[i]);
		if (!map[j])
			error_malloc(-1, map);
		j++;
		i++;
	}
	return (map);
}

void	get_borders(char *tab, char *line, int i)
{
	static int	n;

	if (i == 0)
	{
		tab[n] = line[i];
		n++;
	}
	else if (i == ft_strlen(line) - 1)
	{
		i = invert_skip_space(line);
		tab[n] = line[i];
		n++;
	}
}
