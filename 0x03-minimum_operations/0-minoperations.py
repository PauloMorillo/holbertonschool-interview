#!/usr/bin/python3
"""
Module with minoperations function
"""


def minOperations(n):
    """This method returns the number of operations to copy paste"""
    if type(n) is not int:
        return 0
    if n < 1:
        return 0
    h = 1
    p = 0
    co = 0
    copiados = 0
    pegados = 1
    pa = 0
    ant = 1
    nohacopiado1 = 0
    nohacopiado2 = 0
    nohacopiado3 = 0
    while h < n:
        if n % (h * 2) == 0:
            if nohacopiado1 == 1:
                nohacopiado1 = 0
            nohacopiado3 = 0
            co += 1
            ant = h
            pa += 1
            h = 2 * h
            copiados += ant
            pegados += (2 * ant) - pegados
            # print("entra en por 2", co, pegados)
        elif n % h == 0 and h != 1:
            if n % pegados == 0:
                ant = pegados
                nohacopiado1 = 0
                h = pegados
            else:
                ant = h
            nohacopiado3 = 0
            if nohacopiado1 == 0:
                nohacopiado1 = 1
                co += 1

            # h = 2 * h
            pa += 1
            pegados += ant
            # print("entra en por 1", co, pegados)
        else:
            nohacopiado1 = 0
            if nohacopiado3 == 0:
                nohacopiado3 = 1
                co += 1
                ant = h
            h = h + ant
            pa += 1
            pegados += ant
            # print("entra en sumar 1", co, pegados)
        if pegados >= n:
            break

    return co + pa

    # manejar primos
    i = 1
    p = 0
    co = 0
    pa = 0
    while i <= n:
        print("esto es i", i)
        if n % i == 0:
            co = co + 1
            pa = pa + 1
            i = i + 1
            if (n % (i * 2)) == 0:

                while (i) < n:
                    co = co + 1
                    pa = pa + 1
                    i = i * 2
            i = i
            print(co, pa)
        else:
            i = i + 1
            pa = pa + 1
        p = p + i
        if p >= n:
            break
    mult = []

    for i in range(1, n):
        if (n % i) == 0:
            mult = mult + [i]
    print(mult)
    return pa + co

    # no primos
