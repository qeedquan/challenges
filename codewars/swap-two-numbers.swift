/*

Task
Write a swap function to swap 2 integers in place

NOTES

The input parameter is an integer array with 2 elements. ary.length == 2
You are not allowed to rename the input parameter
You are not allowed to use any other variables
You are not allowed to use any other functions
You are not allowed to use any other keywords

In other words, I want you to write the equivalent of

swap = ary => {
  tmp = ary[0]
  ary[0] = ary[1]
  ary[1] = tmp
}

But without the tmp !

:-)

*/

func swap(_ a: inout Int, _ b: inout Int) {
    (a, b) = (b, a)
}

var (a, b) = (3, 4)
print(a, b)
swap(&a, &b)
print(a, b)
