/*

Oh no, Timmy's created an infinite loop! Help Timmy find and fix the bug in his unfinished for loop!

*/

import java.util.*;

class Lister {
	static List<Integer> CreateList(int number) {
		var list = new ArrayList<Integer>();
		for (int i = 1; i <= number; i++) {
			list.add(i);
		}
		return list;
	}

	public static void main(String[] args) {
		System.out.println(CreateList(4));
		System.out.println(CreateList(5));
	}
}

