/*

TL;DR
These challenges are simulations of algorithms that only require nature and your brain (and maybe some re-usable resources) to approximate Pi. If you really need Pi during the zombie apocalypse, these methods don't waste ammo! There are eight more challenges to come. Checkout the sandbox post to make recommendations.

Simulation
What are we simulating? Well, the probability that two random integers are relatively prime (ie coprime or gcd==1) is 6/Pi/Pi, so a natural way to calculate Pi would be to scoop up two buckets (or handfuls) of rocks; count them; see if their gcd is 1; repeat. After doing this a couple lot of times, sqrt(6.0 * total / num_coprimes) will tend towards Pi. If calculating the square-root in post-apocalyptic world makes you nervous, don't worry! There is Newton's Method for that.

How are we simulating this?

Take input N
Do the following N times:
Uniformly generate random positive integers, i and j
With 1 <= i , j <= 10^6
If gcd(i , j) == 1: result = 1
Else: result = 0
Take the sum of the N results, S
Return sqrt(6 * N / S)

https://i.sstatic.net/xjU5L.jpg

Specification
Input
Flexible, take input in any of the standard ways (eg function parameter,STDIN) and in any standard format (eg String, Binary)
Output
Flexible, give output in any of the standard ways (eg return, print)
White space, trailing and leading white space is acceptable
Accuracy, please provide at least 4 decimal places of accuracy (ie 3.1416)
Scoring
Shortest code wins!
Test Cases
Your output may not line up with these, because of random chance. But on average, you should get about this much accuracy for the given value of N.

Input     ->  Output
-----         ------
100       ->  3.????
10000     ->  3.1???
1000000   ->  3.14??

*/

class Rocks {
    public static void main(String[] args) {
        System.out.println(sim(100));
        System.out.println(sim(1000));
        System.out.println(sim(10000));
        System.out.println(sim(100000));
        System.out.println(sim(1000000));
        System.out.println(sim(10000000));
    }

    public static double sim(int n) {
        var t = 0;
        for (var i = 0; i < n; i++) {
            var x = 1 + (int)(Math.random() * 1e7);
            var y = 1 + (int)(Math.random() * 1e7);
            if (gcd(x, y) == 1)
                t += 1;
        }
        return Math.sqrt(6.0 * n / t);
    }

    // https://en.wikipedia.org/wiki/Binary_GCD_algorithm
    public static int gcd(int p, int q) {
        if (q == 0)
            return p;
        if (p == 0)
            return q;

        // p and q even
        if ((p & 1) == 0 && (q & 1) == 0)
            return gcd(p >> 1, q >> 1) << 1;

        // p is even, q is odd
        if ((p & 1) == 0)
            return gcd(p >> 1, q);

        // p is odd, q is even
        if ((q & 1) == 0)
            return gcd(p, q >> 1);

        // p and q odd, p >= q
        if (p >= q)
            return gcd((p - q) >> 1, q);

        // p and q odd, p < q
        return gcd(p, (q - p) >> 1);
    }
}
