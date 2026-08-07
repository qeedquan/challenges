/*

Given a set of numbers, return the additive inverse of each. Each positive becomes negatives, and the negatives become positives.

invert([1,2,3,4,5]) == [-1,-2,-3,-4,-5]
invert([1,-2,3,-4,5]) == [-1,2,-3,4,-5]
invert([]) == []

You can assume that all values are integers. Do not mutate the input array/list.

*/

import static java.util.stream.IntStream.of;
import java.util.*;

class Inverter {
	static int[] invert(int[] array) {
		return of(array).map(i -> -i).toArray();
	}

	public static void main(String[] args) {
		System.out.println(Arrays.toString(invert(new int[]{-1, -2, -3, -4, -5})));
		System.out.println(Arrays.toString(invert(new int[]{-1, 2, -3, 4, -5})));
		System.out.println(Arrays.toString(invert(new int[]{0})));
		System.out.println(Arrays.toString(invert(new int[]{})));
	}
}
