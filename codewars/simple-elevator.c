/*

If the elevator is on the ground floor(0th level) and the user touches button '2' the elevator must go 2 levels up, so our function must return 2.

If the elevator is on the 3rd level and the user touches button '0' the elevator must go 3 levels down, so our function must return -3.

If the elevator is on the 2nd level, and the user touches button '2' the elevator must remain on the same level, so we return 0.

We cannot endanger the lives of our passengers, so if we get erronous inputs, our elevator must remain on the same level. So for example:

goto(2,'4') must return 0, because there is no button '4' in the elevator.
goto(4,'0') must return 0, because there is no level 4.
goto(3,undefined) must return 0.
goto(undefined,'2') must return 0.
goto([],'2') must return 0 because the type of the input level is array instead of a number.
goto(3,{}) must return 0 because the type of the input button is object instead of a string.

*/

#include <assert.h>

int
elevator(int level, int button)
{
	if (!(0 <= level && level <= 3))
		return 0;
	if (!('0' <= button && button <= '3'))
		return 0;
	return (button - '0') - level;
}

int
main()
{
	assert(elevator(0, '2') == 2);
	assert(3 + elevator(3, '1') == 1);
	assert(2 + elevator(2, '2') == 2);
	assert(2 + elevator(2, '2') == 2);
	assert(elevator(1, '3') == 2);
	assert(elevator(3, '0') == -3);

	return 0;
}
