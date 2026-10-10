%{

Background:
Standard operation math like basic addition and multiplication in the real world work like these:

12 + 123 = 135
and

12 * 123 = 1476
That's not interesting and boring! Many schools are already interpreting this as practice, practice, practice of formal algorithms. That implies a pretty rigid and boring mathematical diet and is not what is intended in this challenge. Get ready to play some fun on our beloved site.

Consider the process of adding two positive integer numbers, then adding again all the digits of its result. Repeating with the addition until only a single digit is obtained. For example:

The result of 12 + 123 is 135.
Adding all the digits of 135 we obtain 1 + 3 + 5 = 9.
The number of steps required to obtain a single digit value 9 in this repeated addition is 2.

As with the previous process of the addition, the multiplication of two positive integer numbers follows the same process. Multiply all the digits of its result and then repeating this process until only a single digit remains. Take the above example:

The result of 12 * 123 is 1476.
Multiply all the digits of 1476 we obtain 1 * 4 * 7 * 6 = 168.
Multiply again all the digits of 168 we obtain 1 * 6 * 8 = 48.
Multiply again all the digits of 48 we obtain 4 * 8 = 32.
Multiply once again all the digits of 32 we obtain 3 * 2 = 6.
The number of steps required to obtain a single digit value 6 this repeated multiplication is 5.

For this challenge's sake and avoiding any misuse of math notations, I introduce these two dummy notations: (+) and (*), but you may use any notation you like, which work like the followings:

The operation of repeated addition process to obtain a single value is 12 (+) 123 = 9.
The operation of repeated multiplication process to obtain a single value is 12 (*) 123  = 6.
Challenge:
The challenge is to write either a program or a function which can perform both of operations as explained in the background section: (+) and (*).

Input:
The inputs of the program or the function are two positive integers and one operation either (+) and (*). The format of the input is an arbitrary choice of the programmer. You may format the input, for example, a (+) b or F(a, (+), b) or any format you wish.

Output:
The output of the program or the function must contain the result of operation and the number of steps required with freestyle format as you wish.

Test Cases (ignore the input and output format):

    81 (+) 31       -->   (4 ; 2)
    351 (+) 14568   -->   (6 ; 3)
    21 (*) 111      -->   (8 ; 3)
    136 (*) 2356    -->   (0 ; 2)

General rules:
This is code-golf, so the shortest answer in bytes wins the challenge.
Don't let esolangs discourage you from posting an answer with regular languages. Enjoy this challenge by providing an answer as short as possible with your programming language. If you post a clever answer and a clear explanation, your answer will be appreciated (hence the upvotes) regardless of the programming language you use.
Standard rules apply for your answer, so you are allowed to use STDIN/STDOUT, functions/ method with the proper parameters, full programs, etc. The choice is yours.
If possible, your program can properly handle large numbers. If not, that will just be fine.
Let the game begin!!

%}

function [r, n] = drill(r0, f)
	r = r0;
	n = 1;
	while r >= 10
		d = sprintf("%d", r) - '0';
		r = f(d);
		n += 1;
	end
end

function [r, n] = add(a, b)
	[r, n] = drill(a + b, @sum);
end

function [r, n] = mul(a, b)
	[r, n] = drill(a * b, @prod);
end

[a, b] = add(12, 123);
printf("(%d ; %d)\n", a, b);

[a, b] = add(81, 31);
printf("(%d ; %d)\n", a, b);

[a, b] = add(351, 14568);
printf("(%d ; %d)\n", a, b);

[a, b] = mul(21, 111);
printf("(%d ; %d)\n", a, b);

[a, b] = mul(136, 2356);
printf("(%d ; %d)\n", a, b);
