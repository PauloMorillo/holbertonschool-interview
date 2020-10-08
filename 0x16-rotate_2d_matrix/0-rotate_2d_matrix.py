#!/usr/bin/python3

import numpy as np


def rotate_2d_matrix(matrix):
    """This method rotate a matrix"""
    rotated = [list(reversed(col)) for col in zip(*matrix)]
    for i in range(len(rotated)):
        for j in range(len(rotated[i])):
            matrix[i][j] = rotated[i][j]
