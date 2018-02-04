/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ollevche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 11:24:44 by ollevche          #+#    #+#             */
/*   Updated: 2018/01/05 14:48:21 by ollevche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft/libft.h"
# include <fcntl.h>

typedef struct	s_tetri
{
	char	index;
	char	**form;
	int		i;
	int		j;
}				t_tetri;

void			error(int error_code);
void			free_tetri(t_tetri **tetriminos);
void			free_strarr(char **arr);
int				read_file(char *filename);
void			fill_struct(t_tetri *tetriminos, char *filename);
char			**set_tetriminos(t_tetri *tetriminos, int tetri_size);
int				execute_algorithm(char **map, t_tetri *tetriminos,
									int map_size);

#endif
