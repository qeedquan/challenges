#!/usr/bin/env python3

"""

Description:
Step through my green glass door.

You can take the moon, but not the sun.

You can take your slippers, but not your sandals.

You can go through yelling, but not shouting.

You can't run through fast, but you can run with speed.

You can take a sheet, but not your blanket.

You can wear your glasses, but not your contacts.

Have you figured it out? Good! Then write a program that can figure it out as well.

"""

def stepthrough(s):
    i = 0
    while i+1 < len(s):
        if s[i] == s[i+1]:
            return True
        i += 1
    return False

def main():
	assert(stepthrough("moon") == True)
	assert(stepthrough("slippers") == True)
	assert(stepthrough("yelling") == True)
	assert(stepthrough("speed") == True)
	assert(stepthrough("sheet") == True)
	assert(stepthrough("glasses") == True)
	assert(stepthrough("comment") == True)

	assert(stepthrough("sun") == False)
	assert(stepthrough("sandals") == False)
	assert(stepthrough("shouting") == False)
	assert(stepthrough("fast") == False)
	assert(stepthrough("blanket") == False)
	assert(stepthrough("contacts") == False)

main()
