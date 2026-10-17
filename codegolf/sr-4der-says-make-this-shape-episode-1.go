/*

Dialogue by a 3Der.

I was hired by Sr. 4Der to learn the 4D universe and I was willing to get to know more about it. But since I am a 3Der, I wouldn't see him, nor would I know how the real shapes look like. All I can do is illustrate.

Sr. 4Der is pretty much invisible to us. We can't see him, but we can hear his voice. Certainly, he would give us a task for each and one of us.

So I was employed as "Programmer", and the task is to illustrate 4D shapes by the use of ASCII art, and I came up with a design for a tesseract.

       ############################
      ####                       ####
     # #  ##                    # #  ##
    #  #    ##                 #  #    ##
   #   #      ##              #   #      ##
  #    #        ##           #    #        ##
 #     #          ###       #     #          ###
############################      #             ##
###    #              ###  ###    #               ###
#  ##  #                 ###  ##  #                  ##
#    ###                   ##   ###                    ##
#      ##                  # ##   ##                     ##
#      # ##                #   ## # ##                     ##
#      #######################################################
#     # ##    ##           #     ####    ##                 ##
#    #    ##    ###        #    # #  ##    ###             # #
#   #       ##     ##      #   #  #    ##     ##          #  #
#  #          ##     ##    #  #   #      ##     ##       #   #
# #             ##     ##  # #    #        ##     ##    #    #
##                ###    ####     #          ###    ## #     #
#######################################################      #
 ##                    ### ###    #               ### #      #
   ##                     ##  ##  #                  ##      #
     ##                    ###  ###                   ###    #
       ##                  #  ##  ##                  #  ##  #
         ###               #    ### ##                #    ###
            ##             #      ############################
              ###          #     #       ##           #     #
                 ##        #    #          ###        #    #
                   ##      #   #              ##      #   #
                     ##    #  #                 ##    #  #
                       ##  # #                    ##  # #
                         ####                       ####
                           ############################
And after bringing it to the office of our boss, he called on us and we listened the words.

Dear programmers, attention all. I have found a design by [say name here] of a tesseract and I would like every one of you to try and make a program to output the same outline.

A co-worker of mine then said:

Does it have to be only # or another character?

He replied:

Use the character you want to use. Use only one, then print the tesseract with the same character, over and over. Understood?

He nodded and we did our thing. Some did input, some just did the basic, and more. After our hard work, he congratulates us and the day has finished.

Now that I think about it, maybe it's your turn to make the same tesseract.

Objective
Given the code block representing the tesseract, replicate the outline with any char you want to use.
Do not change the type of tesseract to be made. Keep the same shape and the final output should be the same one in the code block. (Replace the # with what you want, but only a single ASCII character that is not a space)
This is a code-golf challenge, so the program with the smallest amount of bytes wins!
Bonus Objective (Not needed to complete the challenge)
Make a program where the user gives a char input and will be used to output the tesseract outline using the same character. Rules from the original objective is still applied.

*/

package main

import "fmt"

func main() {
	fmt.Println(ART)
}

const ART = `
       ############################
      ####                       ####
     # #  ##                    # #  ##
    #  #    ##                 #  #    ##
   #   #      ##              #   #      ##
  #    #        ##           #    #        ##
 #     #          ###       #     #          ###
############################      #             ##
###    #              ###  ###    #               ###
#  ##  #                 ###  ##  #                  ##
#    ###                   ##   ###                    ##
#      ##                  # ##   ##                     ##
#      # ##                #   ## # ##                     ##
#      #######################################################
#     # ##    ##           #     ####    ##                 ##
#    #    ##    ###        #    # #  ##    ###             # #
#   #       ##     ##      #   #  #    ##     ##          #  #
#  #          ##     ##    #  #   #      ##     ##       #   #
# #             ##     ##  # #    #        ##     ##    #    #
##                ###    ####     #          ###    ## #     #
#######################################################      #
 ##                    ### ###    #               ### #      #
   ##                     ##  ##  #                  ##      #
     ##                    ###  ###                   ###    #
       ##                  #  ##  ##                  #  ##  #
         ###               #    ### ##                #    ###
            ##             #      ############################
              ###          #     #       ##           #     #
                 ##        #    #          ###        #    #
                   ##      #   #              ##      #   #
                     ##    #  #                 ##    #  #
                       ##  # #                    ##  # #
                         ####                       ####
                           ############################
`
