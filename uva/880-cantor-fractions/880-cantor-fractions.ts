function cantor(n: number): [number, number] {
	if (n < 0)
		return [0, 0];
	if (n == 0)
		return [0, 1];

	let i = Math.floor(Math.sqrt(2 * n) - 1);
	let s = Math.floor(i * (i + 1) / 2);
	i += 1;
	for (;;) {
		if (s + i >= n)
			break;
		s += i;
		i += 1;
	}
	return [i - n + s + 1, n - s];
}

for (let i = 0; i <= 10; i++)
	console.log(cantor(i));

