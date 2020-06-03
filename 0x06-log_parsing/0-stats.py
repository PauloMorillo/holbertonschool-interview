#!/usr/bin/python3
""" This script returns <status code>: <number>"""
import sys
import signal

if __name__ == "__main__":
    a = 1
    statusn = [0, 0, 0, 0, 0, 0, 0, 0]
    size = 0
    statuses = ["200", "301", "400", "401", "403", "404", "405", "500"]

    # def signal_handler(signal, frame):
    # """ Method to handle ctrl-c"""
    # print("File size: {}".format(size))
    # for i in range(len(statusn)):
    # if statusn[i] > 0:
    # print("{}: {}".format(statuses[i], statusn[i]))
    # sys.exit(0)
    # signal.signal(signal.SIGINT, signal_handler)
    try:
        for line in sys.stdin:
            # print(line)
            b = 0
            each_argvs = line.split(" ")
            if len(each_argvs) > 6:
                status = each_argvs[-2]
                size = size + int(each_argvs[-1][:])
                if status in statuses:
                    i = statuses.index(status)
                    statusn[i] = statusn[i] + 1
                if a % 10 == 0:
                    b = 1
                    print("File size: {}".format(size))
                    for i in range(len(statusn)):
                        if statusn[i] > 0:
                            print("{}: {}".format(statuses[i], statusn[i]))
            a = a + 1
        print("File size: {}".format(size))
        for i in range(len(statusn)):
            if statusn[i] > 0:
                print("{}: {}".format(statuses[i], statusn[i]))

    except KeyboardInterrupt:
        print("File size: {}".format(size))
        for i in range(len(statusn)):
            if statusn[i] > 0:
                print("{}: {}".format(statuses[i], statusn[i]))
