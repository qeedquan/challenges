#!/usr/bin/env python3

"""

The year is 2070 and intelligent connected machines have replaced humans in most things. There are still a few critical jobs for mankind including machine software developer, for writing and maintaining the AI software, and machine forward deployed engineer for controlling the intelligent machines in the field. Lorimar is a forward deployed machine engineer and at any given time he controls thousands of BOT robots through real time interfaces and intelligent automation software. These interfaces are directly connected to his own brain so at all times his mind and the robots are one. They are pre-trained to think on their own but on occasion the human will direct the robot to perform a task.

There is an issue with the ultrasonic sensor data feed from BOT785 currently connected to Lorimar through a real time interface. The data feed from sensor five should be a series of floats representing the relative distance of objects within BOT785's path. The sensor error log has been saved for triage and Lorimar needs to search through the data to determine the mean and standard deviation of the distance variables.

You will be given a list of tuples extracted from the sensor logs:

sensor_data = [('Distance:', 116.28, 'Meters', 'Sensor 5 malfunction =>lorimar'), ('Distance:', 117.1, 'Meters', 'Sensor 5 malfunction =>lorimar'), ('Distance:', 123.96, 'Meters', 'Sensor 5 malfunction =>lorimar'), ('Distance:', 117.17, 'Meters', 'Sensor 5 malfunction =>lorimar')]

Return a tuple with the mean and standard deviation of the distance variables rounded to four decimal places. The variance should be computed using the formula for samples (dividing by N-1).

|Mean| |Standard Deviation|

(118.6275, 3.5779)

Hint ( http://math.stackexchange.com/questions/15098/sample-standard-deviation-vs-population-standard-deviation )

"""

from math import sqrt

def analyze(data):
    if len(data) == 0:
        return 0

    mean = 0
    for values in data:
        mean += values[1]
    mean /= len(data)

    stddev = 0
    for values in data:
        stddev += (values[1] - mean)**2
    stddev = sqrt(stddev / (len(data) - 1))
    return (mean, stddev)

def main():
    sensor_data1 = [('Distance:', 116.28, 'Meters', 'Sensor 5 malfunction =>lorimar'),
                    ('Distance:', 117.1, 'Meters', 'Sensor 5 malfunction =>lorimar'),
                    ('Distance:', 123.96, 'Meters', 'Sensor 5 malfunction =>lorimar'),
                    ('Distance:', 117.17, 'Meters', 'Sensor 5 malfunction =>lorimar')]
    
    sensor_data2 = [('Distance:', 295.68, 'Meters', 'Sensor 5 malfunction =>lorimar'), 
                    ('Distance:', 294.78, 'Meters', 'Sensor 5 malfunction =>lorimar'), 
                    ('Distance:', 298.21, 'Meters', 'Sensor 5 malfunction =>lorimar'), 
                    ('Distance:', 294.84, 'Meters', 'Sensor 5 malfunction =>lorimar'), 
                    ('Distance:', 296.54, 'Meters', 'Sensor 5 malfunction =>lorimar'), 
                    ('Distance:', 133.84, 'Meters', 'Sensor 5 malfunction =>lorimar'), 
                    ('Distance:', 294.41, 'Meters', 'Sensor 5 malfunction =>lorimar'), 
                    ('Distance:', 294.82, 'Meters', 'Sensor 5 malfunction =>lorimar'), 
                    ('Distance:', 134.61, 'Meters', 'Sensor 5 malfunction =>lorimar'), 
                    ('Distance:', 294.86, 'Meters', 'Sensor 5 malfunction =>lorimar'), 
                    ('Distance:', 170.88, 'Meters', 'Sensor 5 malfunction =>lorimar'), 
                    ('Distance:', 170.87, 'Meters', 'Sensor 5 malfunction =>lorimar'), 
                    ('Distance:', 170.47, 'Meters', 'Sensor 5 malfunction =>lorimar'), 
                    ('Distance:', 135.5, 'Meters', 'Sensor 5 malfunction =>lorimar'), 
                    ('Distance:', 170.9, 'Meters', 'Sensor 5 malfunction =>lorimar'), 
                    ('Distance:', 170.08, 'Meters', 'Sensor 5 malfunction =>lorimar'), 
                    ('Distance:', 171.36, 'Meters', 'Sensor 5 malfunction =>lorimar'), 
                    ('Distance:', 170.08, 'Meters', 'Sensor 5 malfunction =>lorimar'), 
                    ('Distance:', 170.92, 'Meters', 'Sensor 5 malfunction =>lorimar'), 
                    ('Distance:', 170.88, 'Meters', 'Sensor 5 malfunction =>lorimar')]

    print(analyze(sensor_data1))
    print(analyze(sensor_data2))

main()
