/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 15:57:30 by rorousse          #+#    #+#             */
/*   Updated: 2016/01/31 14:30:04 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include <ncurses.h>

#define SIZE 4

static int	move_right(int **grid)
{
	int		i;
	int		y;
	int		z;
	int		check;

	i = 0;
	y = 0;
	z = 0;
	check = 0;
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
					check = 1;
				}
				y++;
			}
			z++;
		}
		i++;
	}
	return (check);
}

static int	move_left(int **grid)
{
    int		i;
    int		y;
    int		z;
	int		check;

    i = 0;
    y = 0;
    z = 0;
	check = 0;
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
					check = 1;
				}
				y++;
			}
            z++;
        }
        i++;
    }
	return (check);
}

static int   move_down(int **grid)
{
    int     i;
    int     y;
    int     z;
	int		check;

    i = 0;
    y = 0;
    z = 0;
	check = 0;
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
					check = 1;
				}
				i++;
			}
			z++;
		}
        y++;
    }
	return (check);
}

static int    move_up(int **grid)
{
    int     i;
    int     y;
    int     z;
	int		check;

    i = 0;
    y = 0;
    z = 0;
	check = 0;
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
					check = 1;
                }
                i++;
            }
            z++;
        }
        y++;
    }
	return (check);
}

int	move_grid(int **grid, int direction)
{
	int		ret;

	ret = 0;
	if (direction == KEY_RIGHT)
		ret = ret + move_right(grid);
	else if (direction == KEY_LEFT)
		ret = ret + move_left(grid);
	else if (direction == KEY_UP)
		ret = ret + move_up(grid);
	else if (direction == KEY_DOWN)
		ret = ret + move_down(grid);
	ret = ret + collision(grid, direction);
	if (direction == KEY_RIGHT)
        move_right(grid);
    else if (direction == KEY_LEFT)
        move_left(grid);
    else if (direction == KEY_UP)
        move_up(grid);
    else if (direction == KEY_DOWN)
        move_down(grid);
	return (ret);
}
