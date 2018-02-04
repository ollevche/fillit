/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_tetriminos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ollevche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 17:53:54 by ollevche          #+#    #+#             */
/*   Updated: 2017/12/07 17:54:18 by ollevche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	allocates memory for a map, fills it with '.'
*/

static char	**make_map(int map_size)
{
	char	**map;
	int		i;
	int		j;

	if (!(map = (char**)malloc(sizeof(char*) * (map_size + 1))))
		error(2);
	map[map_size] = NULL;
	i = 0;
	while (i < map_size)
	{
		map[i] = (char*)malloc(sizeof(char) * (map_size + 1));
		if (!map[i])
		{
			map[i] = NULL;
			free_strarr(map);
			error(2);
		}
		j = 0;
		while (j < map_size)
			map[i][j++] = '.';
		map[i][j] = '\0';
		i++;
	}
	return (map);
}

/*
**	creates a map, tries to set tetriminos.
**	if every tetrimino is placed, returns map
**	else creates larger map and tries over and over
*/

char		**set_tetriminos(t_tetri *tetriminos, int map_size)
{
	char	**map;
	int		i;

	map_size *= 4;
	i = 2;
	while (i * i != map_size)
	{
		if (i * i > map_size)
		{
			i = 1;
			map_size++;
		}
		i++;
	}
	map_size = i;
	map = make_map(map_size);
	while (!execute_algorithm(map, tetriminos, map_size))
	{
		free_strarr(map);
		map_size++;
		map = make_map(map_size);
	}
	return (map);
}
