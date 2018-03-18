/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ollevche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 12:31:41 by ollevche          #+#    #+#             */
/*   Updated: 2018/01/06 12:31:43 by ollevche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	g_map_size;

void		delete_tetri(t_tetri *tetrimino, char **map)
{
	int i;
	int j;

	i = 0;
	while ((tetrimino->form)[i])
	{
		j = 0;
		while ((tetrimino->form)[i][j])
		{
			if (map[tetrimino->i + i][tetrimino->j + j] == tetrimino->index)
				map[tetrimino->i + i][tetrimino->j + j] = '.';
			j++;
		}
		i++;
	}
}

static int	check_space(int i, int j, char **map, t_tetri *tetrimino)
{
	int ti;
	int tj;
	int hash;

	ti = 0;
	hash = 0;
	while ((tetrimino->form)[ti] && map[i + ti])
	{
		tj = 0;
		while ((tetrimino->form)[ti][tj] && map[i + ti][j + tj])
		{
			if ((tetrimino->form)[ti][tj] != '.' && map[i + ti][j + tj] != '.')
				return (0);
			if ((tetrimino->form)[ti][tj] == '#')
				hash++;
			tj++;
		}
		ti++;
	}
	if (hash != 4)
		return (0);
	else
		return (1);
}

/*
**	takes a position on the map and tries to put a tetrimino
**	set a position of the tetrimino in struct, if successful
*/

static int	try_to_put(int i, int j, char **map, t_tetri *tetrimino)
{
	int ti;
	int tj;

	if (!check_space(i, j, map, tetrimino))
		return (0);
	ti = 0;
	while ((tetrimino->form)[ti] && map[i + ti])
	{
		tj = 0;
		while ((tetrimino->form)[ti][tj] && map[i + ti][j + tj])
		{
			if ((tetrimino->form)[ti][tj] == '#')
				map[i + ti][j + tj] = tetrimino->index;
			tj++;
		}
		ti++;
	}
	tetrimino->i = i;
	tetrimino->j = j;
	return (1);
}

/*
**	takes a map and a tetrimino
**	goes through map (from top right to bottom left)
**	and tries to put a form of the tetrimino
*/

static int	traverse(char **map, t_tetri *tetrimino)
{
	int		i;
	int		j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (i > tetrimino->i || (i == tetrimino->i && j > tetrimino->j))
				if (try_to_put(i, j, map, tetrimino))
					return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int			execute_algorithm(char **map, t_tetri *tetriminos, int map_size)
{
	int	i;

	g_map_size = map_size;
	i = 0;
	while ((tetriminos + i)->form)
	{
		if (!traverse(map, (tetriminos + i)))
		{
			(tetriminos + i)->i = -1;
			(tetriminos + i)->j = -1;
			i--;
			if (i == -1)
				return (0);
			delete_tetri(tetriminos + i, map);
		}
		else
			i++;
	}
	return (1);
}
