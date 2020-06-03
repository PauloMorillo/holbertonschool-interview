#!/usr/bin/python3
""" This script returns <status code>: <number>"""
import sys
import signal


a = 1
statusn = [0, 0, 0, 0, 0, 0, 0, 0]
size = 0
statuses = ["200", "301", "400", "401", "403", "404", "405", "500"]


def signal_handler(signal, frame):
    """ Method to handle ctrl-c"""
    print("File size: {}".format(size))
    for i in range(len(statusn)):
        if statusn[i] > 0:
            print("{}: {}".format(statuses[i], statusn[i]))
    sys.exit(0)


signal.signal(signal.SIGINT, signal_handler)


for line in sys.stdin:
    each_argvs = line.split(" ")
    if len(each_argvs) == 9:
        status = each_argvs[-2]
        if status in statuses:
            i = statuses.index(status)
            statusn[i] = statusn[i] + 1
            size = size + int(each_argvs[-1][:-1])
            if a % 10 == 0:
                print("File size: {}".format(size))
                for i in range(len(statusn)):
                    if statusn[i] > 0:
                        print("{}: {}".format(statuses[i], statusn[i]))
    a = a + 1
