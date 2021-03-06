/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 12:04:22 by rorousse          #+#    #+#             */
/*   Updated: 2016/01/31 14:10:19 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include <stdlib.h>
#include <time.h>
#include <ncurses.h>

# define SIZE 16

/*static void	free_grid(int ***grid, int i)
{
	int		y;

	y = 0;
	while (y < i)
	{
		free(grid[0][y]);
		y++;
	}
	free(*grid);
}
*/
void			fill_grid(int *grid)
{
	int		i;

	i = 0;
	while (i < SIZE)
	{
		grid[i] = 0;
		i++;
	}
}

void			generation(int *grid, int times)
{
	int		random_i;
	int		i;

	i = 0;
	srand(time(NULL));
	while (i < times)
	{
		random_i = rand() % (SIZE);
	if (grid[random_i] == 0)
	{
			grid[random_i] = (rand() % 3) + 2;
			if (grid[random_i] == 3)
				grid[random_i] = 2;
			i++;
		}
	}
}

/*void	affichage_test(int **grid)
{
	int i = 0;
	int y = 0;

	printw("grille :\n\n");
	while (i <4)
	{
		y = 0;
		while (y < 4)
		{
			printw("%d",grid[i][y]);
			y++;
		}
		printw("\n");
		i++;
	}
}

int main()
{
	int		**grid;
	int		i;
	int		c;

	i = 0;
	if (!(grid = (int**)malloc(SIZE * sizeof(int*))))
		return (-1);
	while (i < SIZE)
	{
		if (!(grid[i] = (int*)malloc(SIZE * sizeof(int))))
		{
			free_grid(&grid, i - 1);
			return (-1);
		}
		i++;
	}
	initscr();
	fill_grid(grid);
	generation(grid,2);
	affichage_test(grid);
	while (check_end(grid) != 1)
	{
		c = getch();
		move_grid(grid, c);
		affichage_test(grid);
		refresh();
	}
	free_grid(&grid,SIZE);
	printw("fin\n");
	endwin();
	return (0);
}*/
