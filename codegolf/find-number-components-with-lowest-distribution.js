/*

Let us assume that we have number X.
Let us assume that we have positive integer "components" (C) of this X number.
We can add these components together like C1+C2+...+Cn = X.
We have N as limit of number of components.
We have B as limit of biggest component
Distribution: if we have [8;8;5] then avg of components is 7, distribution is abs(8-7)+abs(8-7)+abs(5-7) = 4
Lowest distribution: dist([8;8;5])=4 dist([7;7;7])=0 -> lowest distribution from these sets is [7;7;7]
Component order does not matter.
Components shall be the same number except one item which can be lower.
Examples

X = 17
N = 3
B = 8
Then possible component sets are [8;8;1], [7;7;3] and [6;6;5].
The lowest distribution between the components is in [6;6;5], that's what we need.
X = 21
N = 3
B = 8
Possible sets: [8;8;5] and [7;7;7].
Winner is [7;7;7].
X = 22
N = 3
B = 8
Possible sets: [8;8;6] and no more.
Winner: [8;8;6]
X = 25
N = 3
B = 8
Possible sets: - (due to B = 8)
I'm looking for the shortest script for this problem written in Javascript. I have a 10 Line solution.

My solution:

const findComponents = (X, B, N) => {
    let S = null;
    let mainComponent = Math.ceil(X / N);
    if (mainComponent <= B){
      let otherComponent = X % mainComponent;
      S = Array(N - 1).fill(mainComponent);
      S.push(otherComponent == 0 ? mainComponent : otherComponent);
    }
    return S;
  }

*/

function findComponents(X, B, N) {
	let S = null;
	let mainComponent = Math.ceil(X / N);
	if (mainComponent <= B) {
		let otherComponent = X % mainComponent;
		S = Array(N - 1).fill(mainComponent);
		S.push(otherComponent == 0 ? mainComponent : otherComponent);
	}
	return S;
}

console.log(findComponents(17, 3, 8));
console.log(findComponents(21, 3, 8));
console.log(findComponents(22, 3, 8));
console.log(findComponents(25, 3, 8));
