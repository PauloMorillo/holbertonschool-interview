#!/usr/bin/python3

import sys

if len(sys.argv) is not 2:
    print('Usage: nqueens N')
    exit(1)
n = sys.argv[1]
if type(n) is not int:
    print('Usage: nqueens N')
    exit(1)

if n < 4:
    print('N must be at least 4')
    exit(1)

q = 0
i = 0
j = 0
queens = []

while q < n:
    while i < n:
        while j < n:
            if len(queens) is 0:
                queens = [[i, j]]
            else:
                add_q = 0
                for pos_q in queens:
                    left = pos_q[0] + pos_q[1]
                    eq_l = i + j
                    right = pos_q[1] - pos_q[0] + i
                    if i == pos_q[0] or j == pos_q[1]\
                            or eq_l != left or right != j:
                        pass
                    else:
                        add_q = add_q + 1
                if add_q == n:
                    queens.append([i, j])
                else:
                    if j == n - 1:
                        i, j = queens.pop()
                        n = n - 1
                    if i == 0 and j == n -1:
                        break
            j = j + 1
        i = i + 1
    n = n + 1
print(queens)
