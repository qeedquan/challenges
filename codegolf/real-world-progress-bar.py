#!/usr/bin/env python3

"""

Backstory, skip if you like
Generating high quality pseudo random numbers is a tricky business but the fine engineers at < enter company you love to hate > have mastered it. Their progress bars effortlessly rise above the primitive notion of linearly passing time and add an exhilarating sense of unpredictability to the waiting experience.

Cynics have dismissed the entire matter as a ploy to prevent employees from being able to assess whether there is enough time to grab a coffee. All I can say is I feel sorry for those people.

It so happens that your boss believes to have reverse-engineered the secret of the < enter company you love to hate > (tm) progress bar and has tasked you with golfing up a simulator.

Task
Given a length L and list of tasks, each represented by a list of times each of the task's steps is expected to take, implement a progress bar that at each time indicates the percentage of steps expected to have completed by that time assuming the tasks are independent. The length of the bar should be L at 100%.

I/O
Flexible within reason. You may pass list lengths separately if you wish.

You may also input a time in which case the output should be a single horizontal bar of correctly rounded integer length.

Otherwise you may represent time as actual time in a unit of your choice or as one axis (top-to-bottom) in a 2D plot.

Examples
I: [20,[2,2,2],[3,3,3],[10]]

O:

###
######
#########
#########
##############
##############
##############
#################
####################

I: [8,[1,1],[2,1],[3,2],[12,1]]

O:
#
###
#####
#####
######
######
######
######
######
######
######
#######
########

I: [30,[1,2,3],[2,4,7],[2,2,2,2,2,2,2,2],[9,10],[1,1,3,2]]

O:
###
########
#########
###########
############
#################
##################
####################
#####################
#######################
#######################
########################
##########################
###########################
###########################
#############################
#############################
#############################
##############################

I: [4.7,20,[1,2,3],[10,10],[1,1,1],[4,10]]

O:
############
Scoring/rules/loopholes:
code-golf as usual.

Reference implementation Python >= 3.8
def f(l,S,c=0):
 T=len(sum(S,[]))            # total number of steps
 while S:=[*filter(None,S)]: # check whether any tasks still runnimg
  for s in S:                # go through tasks
   if s[0]>1:s[0]-=1         # current step terminating? no: update time left
   else:c+=s.pop(0)	     # yes: remove step and increment step counter
  print((T//2+l*c)//T*"#")   # output bar

"""

def progress_bar(length, tasks):
    steps = len(sum(tasks, []))
    count = 0
    while True:
        tasks = [*filter(None, tasks)]
        if not tasks:
            break
        for task in tasks:
            if task[0] > 1:
                task[0] -= 1
            else:
                count += task.pop(0)
        print((steps//2 + length*count)//steps * "#") 
    print()

def main():
    progress_bar(20, [[2, 2, 2], [3, 3, 3], [10]])
    progress_bar(8, [[1, 1], [2, 1], [3, 2], [12, 1]])
    progress_bar(30, [[1, 2, 3], [2, 4, 7], [2, 2, 2, 2, 2, 2, 2, 2], [9, 10], [1, 1, 3, 2]])

main()
