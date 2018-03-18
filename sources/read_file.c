/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpozinen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 09:36:13 by dpozinen          #+#    #+#             */
/*   Updated: 2017/12/01 09:36:13 by dpozinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	takes block and position. looks for nearby '#' (connections), counts them.
*/

static int	tet_surround(char **block, int i, int j)
{
	int c;

	c = 0;
	if (i + 1 < 4 && block[i + 1][j] == '#')
		c++;
	if (j + 1 < 4 && block[i][j + 1] == '#')
		c++;
	if (i - 1 >= 0 && block[i - 1][j] == '#')
		c++;
	if (j - 1 >= 0 && block[i][j - 1] == '#')
		c++;
	return (c);
}

/*
**	takes block. '#' = 4. Counts connections. if < 6 -> wrong
*/

static int	valid_tet(char **block)
{
	int i;
	int j;
	int connections;

	connections = 0;
	i = 0;
	j = 0;
	while (block[i])
	{
		while (block[i][j])
		{
			if (block[i][j] == '#')
			{
				if ((connections += tet_surround(block, i, j)) == 0)
					return (-1);
			}
			j++;
		}
		j = 0;
		i++;
	}
	if (connections < 6)
		return (-1);
	return (1);
}

/*
**	takes block. counts '#' (int c); chars in string (int j).
*/

static int	valid_block(char **block)
{
	int i;
	int j;
	int c;

	i = 0;
	j = 0;
	c = 0;
	while (block[i] && i < 4)
	{
		while (block[i][j] == '.' || block[i][j] == '#')
		{
			if (block[i][j] == '#')
				c++;
			j++;
		}
		if (j != 4)
			return (-1);
		j = 0;
		i++;
	}
	if (c != 4)
		return (-1);
	return (valid_tet(block));
}

static int	close_return(int fd)
{
	close(fd);
	return (-2);
}

/*
**	makes a string of 21 (20 chars + '\0').
**	checks normes returns number of tetriminos or -1 if errors occured.
*/

int			read_file(char *filename)
{
	int		fd;
	char	line_block[21];
	char	**block;
	int		size;

	if (((fd = open(filename, O_RDONLY)) == -1))
		return (-1);
	size = 0;
	ft_bzero(line_block, 21);
	while (read(fd, &line_block, 20))
	{
		if (line_block[0] == '\n' || !(block = ft_strsplit(line_block, '\n')))
			return (close_return(fd));
		if (valid_block(block) == -1)
			return (close_return(fd));
		ft_bzero(line_block, 21);
		if (read(fd, &line_block, 1))
			if (line_block[0] != '\n')
				return (close_return(fd));
		size++;
	}
	if (line_block[0] == '\n')
		return (close_return(fd));
	close(fd);
	return (size);
}
