#!/usr/bin/python3
def canUnlockAll(boxes):
    """ Function returns false or true """
    llavero = [0]
    if not boxes:
        return False

    if type(boxes) != list:
        return False

    if len(boxes) > 0:
        for llave in llavero:
            for key in boxes[llave]:
                if key in llavero:
                    continue
                else:
                    if key < len(boxes):
                        llavero.append(key)
        return (len(llavero) == len(boxes))
