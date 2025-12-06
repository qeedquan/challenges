/*

Task
Given an array of integers , Find the minimum sum which is obtained from summing each Two integers product .

Notes
Array/list will contain positives only .
Array/list will always have even size
Input >> Output Examples
minSum({5,4,2,3}) ==> return (22) 
Explanation:
The minimum sum obtained from summing each two integers product ,  5*2 + 3*4 = 22
minSum({12,6,10,26,3,24}) ==> return (342)
Explanation:
The minimum sum obtained from summing each two integers product ,  26*3 + 24*6 + 12*10 = 342
minSum({9,2,8,7,5,4,0,6}) ==> return (74)
Explanation:
The minimum sum obtained from summing each two integers product ,  9*0 + 8*2 +7*4 +6*5 = 74

*/

#include <cassert>
#include <algorithm>
#include <vector>

using namespace std;

int minsum(vector<int> &&array)
{
	sort(array.begin(), array.end());

	auto sum = 0;
	auto size = array.size();
	for (size_t index = 0; index < size / 2; index++)
		sum += array[index] * array[size - index - 1];

	return sum;
}

int main()
{
	assert(minsum({ 5, 4, 2, 3 }) == 22);
	assert(minsum({ 12, 6, 10, 26, 3, 24 }) == 342);
	assert(minsum({ 9, 2, 8, 7, 5, 4, 0, 6 }) == 74);
	return 0;
}
