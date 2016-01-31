/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 15:57:30 by rorousse          #+#    #+#             */
/*   Updated: 2016/01/30 19:05:31 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include <ncurses.h>

#define SIZE 4

static void	move_right(int **grid)
{
	int		i;
	int		y;
	int		z;

	i = 0;
	y = 0;
	z = 0;
	while (i < SIZE)
	{
		z = 0;
		while (z < SIZE - 1)
		{
			y = 0;
			while (y < SIZE - 1)
			{
				if (grid[i][y] != 0 && grid[i][y + 1] == 0)
				{
					grid[i][y + 1] = grid[i][y];
					grid[i][y] = 0;
				}
				y++;
			}
			z++;
		}
		i++;
	}
}

static void	move_left(int **grid)
{
    int		i;
    int		y;
    int		z;

    i =0;
    y =0;
    z =0;
    while (i < SIZE)
    {
		z = 0;
		while (z < SIZE - 1)
        {
            y =0;
            while (y < SIZE - 1)
            {
				if (grid[i][y] == 0 && grid[i][y + 1] != 0)
				{
                    grid[i][y] = grid[i][y + 1];
					grid[i][y + 1] = 0;
				}
				y++;
			}
            z++;
        }
        i++;
    }
}

static void    move_down(int **grid)
{
    int     i;
    int     y;
    int     z;

    i = 0;
    y = 0;
    z = 0;
    while (y < SIZE)
    {
		z = 0;
		while (z < SIZE - 1)
		{
            i = 0;
            while (i < SIZE - 1)
            {
				if (grid[i + 1][y] == 0 && grid[i][y] != 0)
				{
                    grid[i + 1][y] = grid[i][y];
                    grid[i][y] = 0;
				}
				i++;
			}
			z++;
		}
        y++;
    }
}

static void    move_up(int **grid)
{
    int     i;
    int     y;
    int     z;

    i = 0;
    y = 0;
    z = 0;
    while (y < SIZE)
    {
        z = 0;
        while (z < SIZE - 1)
        {
            i = 0;
            while (i < SIZE - 1)
            {
                if (grid[i][y] == 0 && grid[i + 1][y] != 0)
                {
                    grid[i][y] = grid[i + 1][y];
                    grid[i + 1][y] = 0;
                }
                i++;
            }
            z++;
        }
        y++;
    }
}

void	move_grid(int **grid, int direction)
{
	if (direction == KEY_RIGHT)
		move_right(grid);
	else if (direction == KEY_LEFT)
		move_left(grid);
	else if (direction == KEY_UP)
		move_up(grid);
	else if (direction == KEY_DOWN)
		move_down(grid);
	collision(grid, direction);
	if (direction == KEY_RIGHT)
        move_right(grid);
    else if (direction == KEY_LEFT)
        move_left(grid);
    else if (direction == KEY_UP)
        move_up(grid);
    else if (direction == KEY_DOWN)
        move_down(grid);
}
