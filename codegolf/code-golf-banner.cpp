/*

Ouput the following banner:

   _____          _         _____       _  __ 
  / ____|        | |       / ____|     | |/ _|
 | |     ___   __| | ___  | |  __  ___ | | |_ 
 | |    / _ \ / _` |/ _ \ | | |_ |/ _ \| |  _|
 | |___| (_) | (_| |  __/ | |__| | (_) | | |  
  \_____\___/ \__,_|\___|  \_____|\___/|_|_|  

The code that has the fewest bytes wins! I'm interested to see what clever formulas some of you come up with, bare in mind I just created this in notepad with no clever formula in mind so you may not be likely in finding one.

*/

#include <iostream>
#include <string>

using namespace std;

const string BANNER = R"(
   _____          _         _____       _  __ 
  / ____|        | |       / ____|     | |/ _|
 | |     ___   __| | ___  | |  __  ___ | | |_ 
 | |    / _ \ / _` |/ _ \ | | |_ |/ _ \| |  _|
 | |___| (_) | (_| |  __/ | |__| | (_) | | |  
  \_____\___/ \__,_|\___|  \_____|\___/|_|_|  
)";

int main()
{
	cout << BANNER << endl;
	return 0;
}
