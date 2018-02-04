/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ollevche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 16:18:46 by ollevche          #+#    #+#             */
/*   Updated: 2018/01/06 16:18:49 by ollevche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**  global vars mean the point from which to trim
*/

int g_i_start = -1;
int g_j_start = -1;

/*
**  goes through every *column* to find the width
**  sets g_j_start if it is -1 (initial value) to the first occurance of '#'
*/

static size_t	size_j(char **block)
{
	int i;
	int j;
	int size_j;

	i = 0;
	j = 0;
	size_j = 0;
	while (block[j] && j < 4)
	{
		while (i < 4)
		{
			if (block[i][j] == '#')
			{
				if (g_j_start == -1)
					g_j_start = j;
				size_j++;
				break ;
			}
			i++;
		}
		i = 0;
		j++;
	}
	return (size_j);
}

/*
**  goes through every *row* to find the height
**  sets g_i_start if it is -1 (initial value) to the first occurance of '#'
*/

static size_t	size_i(char **block)
{
	int i;
	int j;
	int size_i;

	i = 0;
	j = 0;
	size_i = 0;
	while (block[i])
	{
		while (block[i][j])
		{
			if (block[i][j] == '#')
			{
				if (g_i_start == -1)
					g_i_start = i;
				size_i++;
				break ;
			}
			j++;
		}
		i++;
		j = 0;
	}
	return (size_i);
}

/*
**  sets g_vars to initial value.
**  returns trimmed block.
*/

static char		**trim_array(char **block)
{
	char	**trimmed_block;
	size_t	i;
	size_t	j;
	size_t	temp_s_j;

	g_j_start = -1;
	g_i_start = -1;
	if (!(trimmed_block = (char**)malloc(sizeof(char*) * (size_i(block) + 1))))
		return (0);
	i = 0;
	j = 0;
	temp_s_j = g_j_start;
	while (i < size_i(block))
	{
		trimmed_block[i] = ft_strnew(size_j(block));
		while (j < size_j(block))
			trimmed_block[i][j++] = block[g_i_start][g_j_start++];
		i++;
		g_i_start++;
		j = 0;
		g_j_start = temp_s_j;
	}
	trimmed_block[size_i(block)] = 0;
	return (trimmed_block);
}

static void		set_index_form_i_j(t_tetri *tetriminos, int i, char **stone)
{
	(tetriminos + i)->index = i + 'A';
	(tetriminos + i)->form = trim_array(stone);
	free_strarr(stone);
	(tetriminos + i)->i = -1;
	(tetriminos + i)->j = -1;
}

/*
**  works only with valid files
**  reads from a file, sets struct vars and allocates memory for struct form
*/

void			fill_struct(t_tetri *tetriminos, char *filename)
{
	int		fd;
	int		i;
	char	*buf;
	char	**stone;

	fd = open(filename, O_RDONLY);
	buf = ft_strnew(20);
	if (fd < 0 || !buf)
		error(2);
	i = 0;
	while (read(fd, buf, 20))
	{
		stone = ft_strsplit(buf, '\n');
		if (!stone)
		{
			free_tetri(&tetriminos);
			close(fd);
			error(2);
		}
		set_index_form_i_j(tetriminos, i, stone);
		i++;
		read(fd, buf, 1);
	}
	close(fd);
}
