#!/usr/bin/python3
"""
This script has the method makechange
"""


def makeChange(coins, total):
    """
    this method say how many coins we need for change
    """
    sum = 0
    i = 0
    j = 0

    if total <= 0:
        return 0

    new_coins = sorted(coins, reverse=True)
    dif_t_s = total - sum

    while sum < total and i < len(new_coins):
        while new_coins[i] <= dif_t_s:
            sum = sum + new_coins[i]
            j = j + 1
            if sum == total:
                return j
            dif_t_s = total - sum
        i = i + 1

    return -1
