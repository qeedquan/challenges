#!/usr/bin/env python3

"""

An employer wants you to store some information about his employees in an easy to read list form. He wants you to input the names, ages, and the pay of his employees. Unfortunately, he is terrible with computers, and he'll call you in every time he wants to change something he's going to call you in, unless you add an easy way to edit the information.

use this list for testing:

New Years Baby, 1, $12.00 per hour

satan, 666, $66.66 per hour

Harry potter, 18, $15.00 per hour

Tarzan the wild man, 30, $12.00 dollars per hour

"""

import csv
import sys

def main():
    todo = [['New Years Baby', 1, 12.00],
            ['satan', 666, 66.66],
            ['Harry potter', 18, 15.00],
            ['Tarzan the wild man', 30, 12.00]]
    writer = csv.writer(sys.stdout)
    for entry in todo:
        writer.writerow(entry)

main()
