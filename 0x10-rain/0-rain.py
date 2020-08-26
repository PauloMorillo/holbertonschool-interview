#!/usr/bin/python3
""" this module has the method rain """


def rain(walls):
    """
    This method calculate how much water
    will be retained after it rains.
    """
    if len(walls) == 0:
        return 0

    v_l = [0] * len(walls)
    v_r = [0] * len(walls)
    v_l[0] = walls[0]
    v_r[-1] = walls[-1]

    for i in range(1, len(walls)):
        v_l[i] = max(v_l[i - 1], walls[i])

    for i in range(len(walls) - 2, -1, -1):
        v_r[i] = max(v_r[i + 1], walls[i])

    water = 0
    for i in range(len(walls)):
        water += min(v_r[i], v_l[i]) - walls[i]

    return water
