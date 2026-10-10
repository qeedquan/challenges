#!/usr/bin/env python3

"""

Write a GOLF assembly program that reads an integer from stdin (followed by a trailing newline), and outputs its prime factors seperated by newlines, followed by a trailing newline on stdout.

The prime factors need not be in a particular order. 1 is not a prime factor.

Your GOLF binary (after assembling) must fit in 8192 bytes.

Your program will be scored by running it 10 times, each with one of the following inputs:

8831269065180497
2843901546547359024
6111061272747645669
11554045868611683619
6764921230558061729
16870180535862877896
3778974635503891117
204667546124958269
16927447722109721827
9929766466606501253
These numbers are roughly sorted in terms of difficulty. The first one should easily be solvable by trial division.

Optimization towards this set of numbers is against the spirit of the question, I may change the set of numbers at any point. Your program must work for any positive 64-bit input number, not just these.

Your score is the sum of CPU cycles used to factor the above numbers.
Because GOLF is very new I'll include some pointers here. You should read the GOLF specification with all instructions and cycle costs. In the Github repository example programs can be found. In particular look at the factorial example program, which demonstrates input/output.

Compile your program to a binary by running python3 assemble.py your_source.golf. Then run your program using python3 golf.py your_source.bin, this should print the cycle count as well. See the values of the register contents at program exit with the -d flag - use --help to see all flags.

"""

from sympy import factorint

"""

Ported from @Kevin solution

Number                Time (s)  Cycles
    8831269065180497       0.1         1148
 2843901546547359024      55.0      9535194
 6111061272747645669     351.4     60559378
11554045868611683619       0.8       135135
 6764921230558061729       1.0       155407
16870180535862877896   43067.5   7126449414
 3778974635503891117     148.7     22823483
  204667546124958269      87.4     13635943
16927447722109721827   16119.0   2739172134
 9929766466606501253  156158.3  26784802677

"""

CODE = r"""

main:
    call read
    call factor
    halt 0


# Prints factors. Pass number to be factored in register `a'.
factor:
    mov n, a # Write routine expects factor in `a', so we'll just keep it there.
    # Handle 2 specially
_factor_twos:               # do {
    geu b, n, 1
    jz _factor_ret, b   #   if (number <= 1) return
    and b, n, 1
    jnz _factor_rest, b #   if (number & 1 != 0) break
    mov a, 2
    call write          #   printf("%llu\n", 2)
    shr n, n, 1         #   number >>= 1
    jmp _factor_twos    # } while (0)
_factor_rest:
    mov a, 3            # factor = 3
_factor_rest_loop:          # do {
    cmp b, n, 1
    jnz _factor_ret, b  #   if (number == 1) return
    divu b, c, n, a     #   (quotient, remainder) = number / factor
    jnz _factor_not_divisible, c # if (remainder == 0) {
    call write                   #   printf("%llu\n", factor)
    mov n, b                     #   number = quotient
    jmp _factor_rest_loop
_factor_not_divisible:               # } else {
    leu c, b, a
    jnz _factor_print_last, c    #   if quotient < a, print n and return.
    add a, a, 2                  #   else a += 2 }
    jmp _factor_rest_loop # } while (0)
_factor_print_last:
    mov a, n
    call write # printf("%llu", n)
_factor_ret:
    ret


# Read stdin. Must be one decimal string, ending with a newline.
# Behavior on invalid input is unspecified.
# Return value stored in a.
read:
    mov a, 0
_read_loop_start:                # do {
    lw c, 0xffffffffffffffff #   c = getchar()
    sub b, c, ord('\n')
    jz _read_ret, b          #   if (c == '\n'), return
    sub c, c, ord('0')       #   c -= '0'
    mulu a, y, a, 10
    add a, a, c              #   a = 10*a + c
    jmp _read_loop_start     # } while (0)
_read_ret:
    ret a

# Write number in register a to stdout, followed by a newline.
# Fortunately, a 64-bit number has at most 20 digits, and we have 25 registers.
# So we can keep them in registers instead of pushing them onto the stack or heap,
# avoiding the fairly expensive read back.
write:
    divu a, b, a, 10
    jz _write_b, a
    divu a, c, a, 10
    jz _write_c, a
    divu a, d, a, 10
    jz _write_d, a
    divu a, e, a, 10
    jz _write_e, a
    divu a, f, a, 10
    jz _write_f, a
    divu a, g, a, 10
    jz _write_g, a
    divu a, h, a, 10
    jz _write_h, a
    divu a, i, a, 10
    jz _write_i, a
    divu a, j, a, 10
    jz _write_j, a
    divu a, k, a, 10
    jz _write_k, a
    divu a, l, a, 10
    jz _write_l, a
    divu a, m, a, 10
    jz _write_m, a
    divu a, n, a, 10
    jz _write_n, a
    divu a, o, a, 10
    jz _write_o, a
    divu a, p, a, 10
    jz _write_p, a
    divu a, q, a, 10
    jz _write_q, a
    divu a, r, a, 10
    jz _write_r, a
    divu a, s, a, 10
    jz _write_s, a
    divu a, t, a, 10
    jz _write_t, a
    add a, a, ord('0')
    sw 0xffffffffffffffff, a
_write_t:
    add t, t, ord('0')
    sw 0xffffffffffffffff, t
_write_s:
    add s, s, ord('0')
    sw 0xffffffffffffffff, s
_write_r:
    add r, r, ord('0')
    sw 0xffffffffffffffff, r
_write_q:
    add q, q, ord('0')
    sw 0xffffffffffffffff, q
_write_p:
    add p, p, ord('0')
    sw 0xffffffffffffffff, p
_write_o:
    add o, o, ord('0')
    sw 0xffffffffffffffff, o
_write_n:
    add n, n, ord('0')
    sw 0xffffffffffffffff, n
_write_m:
    add m, m, ord('0')
    sw 0xffffffffffffffff, m
_write_l:
    add l, l, ord('0')
    sw 0xffffffffffffffff, l
_write_k:
    add k, k, ord('0')
    sw 0xffffffffffffffff, k
_write_j:
    add j, j, ord('0')
    sw 0xffffffffffffffff, j
_write_i:
    add i, i, ord('0')
    sw 0xffffffffffffffff, i
_write_h:
    add h, h, ord('0')
    sw 0xffffffffffffffff, h
_write_g:
    add g, g, ord('0')
    sw 0xffffffffffffffff, g
_write_f:
    add f, f, ord('0')
    sw 0xffffffffffffffff, f
_write_e:
    add e, e, ord('0')
    sw 0xffffffffffffffff, e
_write_d:
    add d, d, ord('0')
    sw 0xffffffffffffffff, d
_write_c:
    add c, c, ord('0')
    sw 0xffffffffffffffff, c
_write_b:
    add b, b, ord('0')
    sw 0xffffffffffffffff, b
    sw 0xffffffffffffffff, ord('\n')
    ret
# End of write.

"""

def main():
    numbers = [
        8831269065180497,
        2843901546547359024,
        6111061272747645669,
        11554045868611683619,
        6764921230558061729,
        16870180535862877896,
        3778974635503891117,
        204667546124958269,
        16927447722109721827,
        9929766466606501253
    ]

    for number in numbers:
        factorint(number)
    print(CODE)

main()
