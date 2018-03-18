/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ollevche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 11:24:34 by ollevche          #+#    #+#             */
/*   Updated: 2018/01/12 12:28:00 by ollevche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	error(int error_code)
{
	ft_putstr(error_code == 1 ? "usage: ./fillit file\n" : "error\n");
	exit(0);
}

void	free_strarr(char **arr)
{
	int i;

	i = 0;
	while (*(arr + i))
	{
		free(*(arr + i));
		i++;
	}
	free(arr);
	arr = NULL;
}

void	free_tetri(t_tetri **tetriminos)
{
	int		i;

	i = 0;
	while (*(tetriminos + i))
	{
		free((*(tetriminos + i))->form);
		free(*(tetriminos + i));
		i++;
	}
	free(tetriminos);
	tetriminos = NULL;
}

int		main(int argc, char **argv)
{
	t_tetri	*tetriminos;
	char	**output;
	int		size;

	if (argc != 2)
		error(1);
	size = read_file(argv[1]);
	if (!(tetriminos = (t_tetri*)malloc(sizeof(t_tetri) * (size + 1)))
		|| size < 1)
		error(2);
	(tetriminos + size)->form = NULL;
	fill_struct(tetriminos, argv[1]);
	output = set_tetriminos(tetriminos, size);
	ft_putstrarr(output);
	return (1);
}
