#!/bin/sh

cat <<EOF >/dev/null

"Bracket" numerals are a type of 'numerals' I made up once, and thought would be a nice challenge here. Basically, you convert the input number into base 6, and then transliterate the 012345 respectively with ()[]{}†, so every 0 becomes (, every 1 becomes ), etc.
You don't have to use ()[]{} per se. As long as you specify what characters you use, you can use any other characters (except for digits, otherwise just converting to base-6 would have been enough!)

Since this is tagged code-golf, the score is in bytes, where the least amount of bytes wins.

A few examples: 6 = )(. 100200 = [(})}[(. 44790 = }{][)(.

Here is some lengthy JavaScript code which accomplishes what I described above. Since it's a snippet (using variable x) instead of a function or full program, it isn't valid however:

var [x,q,w] = [0,0,0];q = x.toString('6');w = q.replace(/0/g, '(');q = w.replace(/1/g, ')');w = q.replace(/2/g, '[');q = w.replace(/3/g, ']');w = q.replace(/4/g, '{');q = w.replace(/5/g, '}');console.log(q);
Yes, that is 207 bytes. You probably can do better! I will accept an answer on June 1st, 2019, but you can continue to post answers afterwards of course.

Standard rules apply for your answer with default I/O rules, so you are allowed to use STDIN/STDOUT, functions/method with the proper parameters and return-type, full programs. Your call. So you aren't allowed to have a var x like I did in my example JavaScript snippet.
Default Loopholes are forbidden.

EOF

solve() {
	echo "obase=6; $1" | bc | tr 012345 '()[]{}'
}

solve 6
solve 100200
solve 44790
