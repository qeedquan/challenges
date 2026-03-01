#!/usr/bin/env awk -f

# Instructions
# Given an unknown input string i with a value of either heads or tails, return 1 for heads or -1 for tails with the shortest code.
#
# Sample not golfed code (55b):
# if(i == "heads"){
#    print(1);
# }else{
#    print(-1);
# }
# Sample golfed code (16b):
# print("t">i||-1)
# Javascript was used for the example but it's not a requirement. Sorry if it's too simple for most users, it can be improved.

function randint(n) {
	return int(n * rand());
}

BEGIN {
	srand();
	print (randint(2) == 0) ? -1 : 1;
}
