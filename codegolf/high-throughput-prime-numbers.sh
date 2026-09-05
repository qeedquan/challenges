#!/bin/sh

cat << EOF>/dev/null

This challenge is inspired by the High throughput Fizz Buzz challenge.

The goal
Generate a list of prime numbers up to 10,000,000,000,000,000. The output of primes should be in decimal digits followed by a newline character '\n' in ascending order starting from the lowest prime 2. You may not skip a prime number or output a composite number.

Scoring
Your program's throughput will be measured on my Linux machine by the following command.

(timeout 1m ./your-program) | pv > /dev/null
At the timeout after 1 minute, your score will be the total size of output measured by pv.

An example
This is a simple example of a conforming program in C. It produces 49.6MiB of data in total for a minute, on my machine with 2.4GHz 4-core CPU and 4GiB RAM.

#include <stdio.h>

int main() {
    puts("2");
    for (long long i = 3; i < 10000000000000000; i += 2) {
        for (long long j = 3; j * j <= i; j += 2) {
            if (i % j == 0) {
                goto next;
            }
        }
        printf("%lld\n", i);
    next:;
    }
    return 0;
}
Rules
You should only print what's specified in the goal. You may not print garbage characters including ones that do not appear on the terminal.

The maximum size of your source code is 64Kib.

Otherwise, I'll accept any code that can be run on my Linux machine with 4 cores and AVX2 support.

EOF

primesieve 10000000000000000 --print > primes.txt
