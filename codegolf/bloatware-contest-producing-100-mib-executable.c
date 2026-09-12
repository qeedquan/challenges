/*

Create short source code in your favourite compiled language that compiles into a big (not less than 104857600 bytes) executable file. The program must be runnable (assuming 1GB of free memory) and can do anything (preferrable something simple like a hello world).

Usage of non-obvious tricks is encouraged.

Boring example in C:

int a[1024*1024*25] = { 1 };

int main(){}
Bonus points if it can be "explained" why the executable can't be reduced in size (i.e. all bloat is actually used somehow).

*/

int data[1024 * 1024 * 25] = {1};

int
main(void)
{
	return 0;
}
