#include <cstdio>
#include <cstring>
#include <cstdint>

struct BF
{
	int ip;
	uint8_t mem[100];

	void reset();
	void run(const char *cmd);
	void show();
};

void BF::reset()
{
	ip = 0;
	memset(mem, 0, sizeof(mem));
}

void BF::run(const char *cmd)
{
	for (; *cmd; cmd++)
	{
		switch (*cmd)
		{
		case '>':
			ip++;
			break;
		case '<':
			ip--;
			break;
		case '+':
			mem[ip]++;
			break;
		case '-':
			mem[ip]--;
			break;
		}

		if (ip >= (int)sizeof(mem))
			ip = 0;
		else if (ip < 0)
			ip = sizeof(mem) - 1;
	}
}

void BF::show()
{
	for (auto i = 0u; i < sizeof(mem); i++)
	{
		printf("%02X ", mem[i]);
		if ((i & 15) == 15)
			printf("\n");
	}
	printf("\n");
}

void test(const char *cmd)
{
	BF bf;

	bf.reset();
	bf.run(cmd);
	bf.show();
}

int main()
{
	const char *cmd =
		"..++<><<+++>>++++++++++++++++++++++++++>>>+++"
		"<+...++<><<+++>>++++++++++++++++++++++++++>>>"
		"+++<+...++<><<+++>>++++++++++++++++++++++++++"
		">>>+++<+.";

	test(cmd);
	return 0;
}
