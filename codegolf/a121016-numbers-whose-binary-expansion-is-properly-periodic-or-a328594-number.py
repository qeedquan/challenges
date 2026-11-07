#!/usr/bin/env python3

"""

I have been studying how to compress the Dis programs into their equvalent ones. One of the possibly easiest subset is programs with only } and { (and optionally _) characters.

For example, two programs }{{}{{ and }{{}{{}{{ are equivalent to }{{; they output every input character twice. Similarly }}{{, }}{{}}{{ and }}{{}}{{}}{{ are equivalent programs. I have an idea to apply s/^([}{]+)\1$/\1/ to accomplish the task.

This task is similar to deciding whether a given binary integer is represented by a regular expression ([01]+)\1+ but I could not find the exactly matching sequence registered at OEIS; my problem seems to be equivalent to whether the given non-negative integer is in A121016 or A328594.

A121016: Numbers whose binary expansion is properly periodic.
For example, 204=(1100 1100)_2 and 292=(100 100 100)_2 belong to the sequence, but 30=(11110)_2 cannot be split into repeating periods.

A328594: Numbers whose binary expansion is aperiodic.
It's complement of A121016; every nonnegative integer not belonged to A121016 is A328594, for example 30 is in but 204, 292 are not.

Challenge
This is sequence challenge applied for either A121016 or A328594; you can choose which challenge to take. For your chosen sequence, do one of these (by your choice):

Given no input output every number in the sequence in accessing order.
Given an integer N, output first N or N+1 (your choice) items in the sequence.
Given an integer N, output N-th (either 0-indexed or 1-indexed but not 2-indexed or 3-indexed) item in the sequence.
First 79 items in A121016 upto 4096
3    7   10   15   31   36   42   45   54   63
 127  136  153  170  187  204  221  238  255  292
 365  438  511  528  561  594  627  660  682  693
 726  759  792  825  858  891  924  957  990 1023
2047 2080 2145 2184 2210 2275 2340 2405 2457 2470
2535 2600 2665 2730 2795 2860 2925 2990 3003 3055
3120 3185 3250 3276 3315 3380 3445 3510 3549 3575
3640 3705 3770 3822 3835 3900 3965 4030 4095
First 238 items in A328594 upto 256
0    1    2    4    5    6    8    9   11   12
  13   14   16   17   18   19   20   21   22   23
  24   25   26   27   28   29   30   32   33   34
  35   37   38   39   40   41   43   44   46   47
  48   49   50   51   52   53   55   56   57   58
  59   60   61   62   64   65   66   67   68   69
  70   71   72   73   74   75   76   77   78   79
  80   81   82   83   84   85   86   87   88   89
  90   91   92   93   94   95   96   97   98   99
 100  101  102  103  104  105  106  107  108  109
 110  111  112  113  114  115  116  117  118  119
 120  121  122  123  124  125  126  128  129  130
 131  132  133  134  135  137  138  139  140  141
 142  143  144  145  146  147  148  149  150  151
 152  154  155  156  157  158  159  160  161  162
 163  164  165  166  167  168  169  171  172  173
 174  175  176  177  178  179  180  181  182  183
 184  185  186  188  189  190  191  192  193  194
 195  196  197  198  199  200  201  202  203  205
 206  207  208  209  210  211  212  213  214  215
 216  217  218  219  220  222  223  224  225  226
 227  228  229  230  231  232  233  234  235  236
 237  239  240  241  242  243  244  245  246  247
 248  249  250  251  252  253  254
Other rules
code-golf. Standard loopholes. Standard I/O.

If you choose multiple challenges in a language, only shorter program or function is counted as code-golf entry.

"""

# https://oeis.org/A121016
def A121016(n):
    r = []
    i = 1
    while len(r) < n:
        s = f"{i:b}"
        s2 = (s + s)[1:-1]
        if s in s2 and s2 != i:
            r.append(i)
        i += 1
    return r

def main():
    XA121016 = [
        3, 7, 10, 15, 31, 36, 42, 45, 54, 63, 127, 136, 153, 170, 187, 204, 221,
        238, 255, 292, 365, 438, 511, 528, 561, 594, 627, 660, 682, 693, 726,
        759, 792, 825, 858, 891, 924, 957, 990, 1023, 2047, 2080, 2145, 2184,
        2210, 2275, 2340, 2405, 2457, 2470, 2535
    ]

    assert(A121016(len(XA121016)) == XA121016)

main()
