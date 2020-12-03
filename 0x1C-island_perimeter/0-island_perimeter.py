#!/usr/bin/python3
"""
This module has the turn, counter and island_perimeter methods
"""


def turn(grid):
    """
    This method return the new grid
    """
    new_grid = []
    for n in range(0, len(grid[0])):
        new_row = []
        for row in grid:
            new_row.append(row[n])
        new_grid.append(new_row)
    return new_grid


def counter(grid):
    """
    This method count horizontals
    """
    count = 0
    for i in range(0, len(grid)):
        if i == 0 or i == len(grid) - 1:
            for k in range(0, len(grid[i])):
                if grid[i][k]:
                    count += 1
        for j in range(0, len(grid[i])):
            if i < len(grid) - 1 and grid[i][j] != grid[i + 1][j]:
                count += 1
    return count


def island_perimeter(grid):
    """
    return the add of all sides
    """
    turned_grid = turn(grid)
    a = counter(grid)
    b = counter(turned_grid)
    r = a + b
    return r
