#!/usr/bin/python3

import sys

if len(sys.argv) is not 2:
    print('Usage: nqueens N')
    exit(1)
n = sys.argv[1]
try:
    n = int(n)

except:
    print('N must be a number')
    exit(1)

if n < 4:
    print('N must be at least 4')
    exit(1)

q = 0
queens = []

while q < n:
    i = 0
    while i < n:
        j = 0
        while j < n:
            # print(queens)
            if len(queens) is 0:
                queens = [[i, j]]
            else:
                add_q = 0
                for pos_q in queens:
                    left = pos_q[0] + pos_q[1]
                    eq_l = i + j
                    right = pos_q[1] - pos_q[0] + i
                    if i == pos_q[0] or j == pos_q[1]\
                            or eq_l == left or right == j:
                        # print("aquí")
                        # print(i, j, pos_q[0], pos_q[1], n)
                        pass
                    else:
                        add_q = add_q + 1
                        # print(i, j, add_q, "veces que entra")
                if add_q == len(queens):
                    # print("esta entrando")
                    queens.append([i, j])
                else:
                    if j == n - 1 and queens[-1][0] != i:
                        i, j = queens.pop()
                        if j == n - 1 and i is not 0:
                            i, j = queens.pop()
                    # if j == n - 1:
                        # print("estoy entrando para pop")
                        # i, j = queens.pop()
                        # q = q - 1
                    if len(queens) == n:
                        print(queens)
                        i = queens[0][0]
                        j = queens[0][1]
                        # print(i, j, "esto es lo que devolvemos")
                        q = 0 - 1
                        queens = []
                        if j == n - 2:
                            i = n
                            q = n
                            break
            j = j + 1
        # print(i, "esta es la i")
        i = i + 1
    q = q + 1
# print(queens)
