/*

The owner of the doggy daycare wants to know whether she can accept new dogs into her daycare and needs to check whether they have been wormed and vaccinated in order to accept them either by themselves or as well as other dogs.

There is a Dog prototype (class in Ruby) that needs to be extended with the method checkDog (check_dog). Dog currently has the following properties (attributes):

name
age
breed
vaccinated
wormed

You'll need to return the dog's name each time as well as " can be accepted", " can only be accepted by itself" and " can not be accepted".

If the dog is vaccinated and wormed, the dog can be accepted.
If the dog is only vaccinated or only wormed, the dog can only be accepted by itself.
If the dog has not be vaccianted or wormed, the dog can not be accepted.

Example:

var spot = new Dog("Spot", 5, "Labrador", true, false);
spot.checkDog(); // Should return: "Spot can only be accepted by itself".

*/

#include <stdio.h>

typedef struct {
	char name[32];
	int age;
	char breed[32];
	bool vaccinated;
	bool wormed;
} Dog;

char *
checkdog(Dog *dog, char *status)
{
	if (dog->vaccinated && dog->wormed)
		sprintf(status, "%s can be accepted", dog->name);
	else if (dog->vaccinated || dog->wormed)
		sprintf(status, "%s can only be accepted by itself", dog->name);
	else
		sprintf(status, "%s can not be accepted", dog->name);
	return status;
}

int
main()
{
	Dog spot = {"Spot", 5, "Labrador", true, false};
	char status[64];

	printf("%s\n", checkdog(&spot, status));
	return 0;
}
