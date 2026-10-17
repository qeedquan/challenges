function binomial(n: number, k: number): number {
	if (k < 0 || k > n)
		return 0;
	if (k == 0 || k == n)
		return 1;

	let r = 1;
	for (let i = 0; i < k; i++)
		r = r * (n - i) / (i + 1);
	return r;
}

console.log(binomial(4, 2));
console.log(binomial(10, 5));
console.log(binomial(49, 6));

