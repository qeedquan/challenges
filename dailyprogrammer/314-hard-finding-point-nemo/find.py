#!/usr/bin/env python3

"""

Description
What point on the world's oceans is furthest from any land? On Earth, it's slightly more than 1450 nautical miles from Ducie Island, Motu Nui, and Maher Island. The geographic coordinates of the real Point Nemo are: s48:52:31.748 w123:23:33.069. The point was named after Jules Verne’s submarine Captain Nemo, a Latin name that also happens to mean “no one.”

Your task today is given an ASCII art map, calculate the location of Point Nemo. The map will use ASCII symbols to shade land - mountains, grassland, desert, etc. The blank spaces are ocean. Find the spot in the ocean that is furthest away from any land.

Input Descripton
You'll be given a two integers on a line telling you how wide (in characters) the map is at its maximum and how many lines to read. Then you'll be given the ASCII art map with the land filled in. Assume the blank space is ocean. The world wraps around, too, just like a real map. Unlike the real world, however, assume this world is a cylinder - it makes the geometry a lot easier.

Output Description
Your progam should emit the location of Point Nemo as a grid coordinate in x-y (e.g. 40,25). Count the upper left corner as 0,0. Calculate the Euclidean distance and report the closest whole number position (e.g. round to the nearest x,y coordinate).

Challenge Input
80 25
 ## #     # #    #               #      #                       ## ###
  ####   ###### ########   ######        ##### ######### #### #######
   ########## ## #####    ####    #          #####################
    #######################      ##            ### ##  #### ####  ##
	 ######### #########         ###            ##  #   ### ##   ##
#	  # #####   #######         ###                      #      #
	  #   ###       ##                          #######
	  #    ###                                 ###########     #
	        ###   ##                          ##############              #
#    		 ###                              ##############                #
			  ##                               #############
			#####                               ###########       ##
		  #########                             ##########      ##
		############                              #########     ##
	  ###############                              #######
	 ##############                                 #####           #########
	############### ##                               ###           ###########
	 ###############                                  #           ############
	  ############                                                ###   ####
	   #########      #
#	      #####

		  ########                        ######               #######
		###################### ###########################  ##############
##############################################################################

"""

from math import sqrt

# ported from @moeghoeg solution

class tile:
    def __init__(self, x, y):
        self.x = x
        self.y = y

def dist(x0, y0, x1, y1, mapwidth):
    d1 = sqrt((x0 - x1)**2 + (y0 - y1)**2)
    d2 = sqrt((min(x0, x1) + mapwidth - max(x0, x1))**2 + (y0 - y1)**2)
    return min(d1, d2)

def find_nemo(land, sea, mapwidth):
    return max(sea, key = lambda s: min(dist(s.x, s.y, l.x, l.y, mapwidth) for l in land))

def read_map():
    land = []
    sea = []
    width, height = (int(i) for i in input().split())
    for y in range(height):
        line = input()
        for x in range(width):
            t = tile(x, y)
            if x < len(line) and line[x] == '#':
                land.append(t)
            else:
                sea.append(t)
    return (width, height, land, sea)

def main():
    width, _, land, sea = read_map()
    nemo = find_nemo(land, sea, width)
    print(nemo.x, nemo.y)

main()
