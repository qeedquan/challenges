#!/usr/bin/env python3

"""

#Gear Inch Calculator On a bicycle there are many ways to measure the size of the gear being used, one of which is gear inches. A gear inch refers to the equivelant diameter of the wheel of a penny farthing wheel in order to give the same gearing. As the safety bicycle (a bicycle where both the wheels are the same size) was developed, the gear inch remained a unit of measurement for gearing. The way gear inches is calculated is demonstated by this image from wikipedia:

gear inches = drive wheel diameter in inches * (number of teeth in front chain / number of teeth in rear sprocket)

 Of course, lots of bicycles now have variable gears, rather than just one, on these bicycles with more than one chainring and with multiple sprockets at the back there are quite a few different options for gear inches.

You are going to create a function which gives all of the options for gear inches for the given chainrings and rear sprockets. The gear inches will be calculated based on a 700c wheel with a 23c tyre, which gives a diameter of 26 inches (this is an approximate measurement, but for the sake of this kata we will be using 26 inches as the diameter).

You will return a two dimensional array where there is an array for each chainring, and in the array there is a list of the gear inches given the combination of the chainring and the given sprockets. The gear inches will be rounded to one decimal place. eg. ``` gearInchCalculator([50, 36], [11, 12, 13, 14, 16, 18, 21, 24, 28]) === [ [ 118.2, 108.3, 100, 92.9, 81.3, 72.2, 61.9, 54.2, 46.4 ], [ 85.1, 78, 72, 66.9, 58.5, 52, 44.6, 39, 33.4 ] ]

```

Everything passed to the function will be a valid input. Have fun!

If you want more information about what gear inches are, check out the wikipedia page

"""

import numpy as np

def gearinch(chainrings, sprockets):
    result = []
    for chainring in chainrings:
        array = []
        for sprocket in sprockets:
            array.append((26 * chainring) / sprocket)
        result.append(array)
    return result

def main():
    assert(np.allclose(gearinch([50, 36], [11, 12, 13, 14, 16, 18, 21, 24, 28]), [[118.2, 108.3, 100, 92.9, 81.3, 72.2, 61.9, 54.2, 46.4], [85.1, 78, 72, 66.9, 58.5, 52, 44.6, 39, 33.4]], atol=1e-1))

main()
