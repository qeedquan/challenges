/*

Description
There is an intersection of two roads. First road is road A where cars travel from North to South in direction 1 and from South to North in direction 2. Second road is road B where cars travel from West to East in direction 3 and from East to West in direction 4.

https://camo.githubusercontent.com/bd38ceb4012ba6aa235569d653122637e8e2b7fd882fb2db64c513f2564dc5bc/68747470733a2f2f666173746c792e6a7364656c6976722e6e65742f67682f646f6f63732f6c656574636f6465406d61696e2f736f6c7574696f6e2f313230302d313239392f313237392e547261666669632532304c69676874253230436f6e74726f6c6c6564253230496e74657273656374696f6e2f696d616765732f6578702e706e67

There is a traffic light located on each road before the intersection. A traffic light can either be green or red.

Green means cars can cross the intersection in both directions of the road.
Red means cars in both directions cannot cross the intersection and must wait until the light turns green.
The traffic lights cannot be green on both roads at the same time. That means when the light is green on road A, it is red on road B and when the light is green on road B, it is red on road A.

Initially, the traffic light is green on road A and red on road B. When the light is green on one road, all cars can cross the intersection in both directions until the light becomes green on the other road. No two cars traveling on different roads should cross at the same time.

Design a deadlock-free traffic light controlled system at this intersection.

Implement the function void carArrived(carId, roadId, direction, turnGreen, crossCar) where:

carId is the id of the car that arrived.
roadId is the id of the road that the car travels on.
direction is the direction of the car.
turnGreen is a function you can call to turn the traffic light to green on the current road.
crossCar is a function you can call to let the current car cross the intersection.
Your answer is considered correct if it avoids cars deadlock in the intersection. Turning the light green on a road when it was already green is considered a wrong answer.



Example 1:

Input: cars = [1,3,5,2,4], directions = [2,1,2,4,3], arrivalTimes = [10,20,30,40,50]
Output: [
"Car 1 Has Passed Road A In Direction 2",    // Traffic light on road A is green, car 1 can cross the intersection.
"Car 3 Has Passed Road A In Direction 1",    // Car 3 crosses the intersection as the light is still green.
"Car 5 Has Passed Road A In Direction 2",    // Car 5 crosses the intersection as the light is still green.
"Traffic Light On Road B Is Green",          // Car 2 requests green light for road B.
"Car 2 Has Passed Road B In Direction 4",    // Car 2 crosses as the light is green on road B now.
"Car 4 Has Passed Road B In Direction 3"     // Car 4 crosses the intersection as the light is still green.
]
Example 2:

Input: cars = [1,2,3,4,5], directions = [2,4,3,3,1], arrivalTimes = [10,20,30,40,40]
Output: [
"Car 1 Has Passed Road A In Direction 2",    // Traffic light on road A is green, car 1 can cross the intersection.
"Traffic Light On Road B Is Green",          // Car 2 requests green light for road B.
"Car 2 Has Passed Road B In Direction 4",    // Car 2 crosses as the light is green on road B now.
"Car 3 Has Passed Road B In Direction 3",    // Car 3 crosses as the light is green on road B now.
"Traffic Light On Road A Is Green",          // Car 5 requests green light for road A.
"Car 5 Has Passed Road A In Direction 1",    // Car 5 crosses as the light is green on road A now.
"Traffic Light On Road B Is Green",          // Car 4 requests green light for road B. Car 4 blocked until car 5 crosses and then traffic light is green on road B.
"Car 4 Has Passed Road B In Direction 3"     // Car 4 crosses as the light is green on road B now.
]
Explanation: This is a dead-lock free scenario. Note that the scenario when car 4 crosses before turning light into green on road A and allowing car 5 to pass is also correct and Accepted scenario.

Constraints:

1 <= cars.length <= 20
cars.length = directions.length
cars.length = arrivalTimes.length
All values of cars are unique
1 <= directions[i] <= 4
arrivalTimes is non-decreasing

*/

#include <stdio.h>
#include <threads.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef struct {
	mtx_t lock;
	int road;
} Traffic;

int
init(Traffic *t)
{
	t->road = 'A';
	return mtx_init(&t->lock, mtx_plain);
}

void
crosscar(int road, int car, int direction)
{
	printf("Car %d Has Passed Road %c In Direction %d\n", car, road, direction);
}

void
turngreen(int road)
{
	printf("Traffic Light On Road %c Is Green\n", road);
}

void
cararrived(Traffic *t, int car, int road, int direction, void (*turngreen)(int), void (*crosscar)(int, int, int))
{
	mtx_lock(&t->lock);
	if (t->road != road) {
		t->road = road;
		turngreen(road);
	}
	crosscar(road, car, direction);
	mtx_unlock(&t->lock);
}

void
sim(int *cars, int *directions, size_t len)
{
	Traffic t[1];
	size_t i;
	int road;

	init(t);
	for (i = 0; i < len; i++) {
		road = (directions[i] <= 2) ? 'A' : 'B';
		cararrived(t, cars[i], road, directions[i], turngreen, crosscar);
	}
	printf("\n");
}

int
main()
{
	int cars1[] = { 1, 3, 5, 2, 4 };
	int cars2[] = { 1, 2, 3, 4, 5 };

	int directions1[] = { 2, 1, 2, 4, 3 };
	int directions2[] = { 2, 4, 3, 3, 1 };

	sim(cars1, directions1, nelem(cars1));
	sim(cars2, directions2, nelem(cars2));

	return 0;
}
