function solve(a: number, b: number, c: number): number {
	if (a <= 0 || b <= 0 || c <= 0)
		return 0;

	let s = (a + b + c) / 2;
	let area = Math.sqrt(s*(s-a)*(s-b)*(s-c));
	return area / s;
}

console.log(solve(12, 12, 8));

