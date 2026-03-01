/*

We have a very famous and popular fellow in our problemsetters’ panel. He is so famous that his name is immaterial.
Some of his admirers have recently given him the nickname ’Emoogle’.
Let’s stick to that name in our discussion for now.
Being such a kind, friendly and generous person as he is, Emoogle is often known to give treats to the other problemsetters.
Some times, there is a strange rumor in the air that his treats are mostly due to the fact that, if he is not sparing enough for those treats, ’problems’ are likely to be created.
But let’s not pay heed to such nonsense!
Now, there is another word in the air that this remarkable man is going to get married soon.
To observe this special occasion with proper respect, his fellow troublemakers have decided to compile a book named ’99 reasons why Emoogle should give us a treat’.
Every single reason mentioned in this book is denoted by a number.
For example, Emoogle should give us a treat because
1. If he does not, problems will be created. :)
2. His giveaway problem has been solved by less than 10 teams in the recent programming contest.
3. He is going to join a world famous goggles manufacturing company soon.
4. He has found a ticket of a soccer world cup game while digging his backyard garden in the morning.
5. He has just got a new Facebook fan club.
6. Having forgotten about a date with his wife-to-be which collided with a Topcoder SRM (Single
Round Match), he participated in the SRM. (May God bless his soul!)
7. A programming contest (may be this one?) is being arranged celebrating his marriage.
8. He is getting engaged soon.
..................
99. Solely because he is the great and kind and sweet Emoogle.
If you have any more ideas about why he should throw a party, we would love to know. Drop us a
line at emoogle.party gmail.com.

At this point, Dear brother Emoogle might want to remind us about the number of times he has already thrown a party.
Hence we introduce the term Emoogle Balance. This is defined as:
Emoogle Balance = number of times Emoogle is supposed to give a treat according to the book - number of times he has actually given the treat.
In this problem, we want you to find Emoogle Balance. We also wish that Emoogle Balance always keeps a healthy negative value and may dear brother Emoogle have a very happy married life forever.

Input
There are around 75 test cases in the input file. Each test case describes a series of events.
A test case starts with an integer N (1 ≤ N ≤ 1000) denoting the number of events in this test case.
This integer is followed by a line with N integers, each describing an event. These integers have values between 0 and 99 (inclusive).
A value between 1 and 99 means a reason for Emoogle’s giving a treat has occurred while a 0 means he has given a treat.
The end of input will be denoted by a case with N = 0. This case should not be processed.

Output
For each test case, print a line in the format, ‘Case X: Y ’, where X is the case number and Y is the
Emoogle Balance for this case.

Sample Input
5
3 4 0 0 1
4
2 0 0 0
7
1 2 3 4 5 0 0
0

Sample Output
Case 1: 1
Case 2: -2
Case 3: 3

*/

fn main() {
    assert_eq!(emoogle_balance(vec![3, 4, 0, 0, 1]), 1);
    assert_eq!(emoogle_balance(vec![2, 0, 0, 0]), -2);
    assert_eq!(emoogle_balance(vec![1, 2, 3, 4, 5, 0, 0]), 3);
}

fn emoogle_balance(a: Vec<isize>) -> isize {
    let mut c = 0;
    for v in a {
        if v <= 0 {
            c -= 1;
        } else {
            c += 1;
        }
    }
    c
}
