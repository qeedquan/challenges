/*

Return the secret integer in a range based on the response from the guess_bot.

You are given a low and high range (inclusive) and an instance of GuessBot (guess_bot).

You are only to interact with guess_bot by its method: guess_number(num) which returns a string.

guess_bot is a bit of an asshole and only returns the following strings when you call guess_number(number):

'Smaller': Your guess is too big
'Larger': Your guess is too small
'Correct': Your guess is correct
'You failed, you bring great shame to your family name': You ran out of tries
'What are you, deaf?': Returned if you continously call guess_number after you already guessed the correct number

You only have log2(N) calls to guess_number before the bot starts calling you a failure. N is the number of possible integers in the [low, high] range.

1 <= N <= 10^14

low <= high

Hint: use binary search

*/

#include <iostream>
#include <string>
#include <climits>

using namespace std;

struct Bot
{
	int secret;
	int tries;
	int status;

	Bot(int secret, int tries=INT_MAX)
	{
		this->secret = secret;
		this->tries = tries;
		this->status = 0;
	}

	string guess_number(int number)
	{
		if (tries <= 0)
			status = 'L';

		if (status == 'W')
			return "What are you, deaf?";

		if (status == 'L')
			return "You failed, you bring great shame to your family name";

		if (secret == number)
		{
			status = 'W';
			return "Correct";
		}
		
		tries -= 1;
		if (secret > number)
			return "Larger";
		return "Smaller";
	}
};

int find_secret_number(int low, int high, Bot &&bot)
{
	for (;;)
	{
		auto number = low + (high - low) / 2;
		auto response = bot.guess_number(number);
		if (response == "Correct" || response == "What are you, deaf?")
			return number;
		if (response == "Larger")
			low = number + 1;
		else
			high = number - 1;
	}
}

int main()
{
	cout << find_secret_number(-100, 100, Bot(10)) << endl;
	cout << find_secret_number(-1000, 1000, Bot(137)) << endl;
	cout << find_secret_number(1077, 10000, Bot(1078)) << endl;

	return 0;
}
