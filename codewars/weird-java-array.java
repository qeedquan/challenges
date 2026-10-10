/*

I want to create an array of `List`s of `Integers`, like so:

import java.util.*;

class Codewarrior {
  public static List<Integer>[] arrayOfLists = new List<Integer>[]{
      Arrays.asList(1, 2, 3),
      Arrays.asList(4, 5, 6),
      Arrays.asList(7, 8, 9),
  };
}

However, this code does not compile :(

Can you fix the code ?

arrayOfLists should hold the 3 lists shown above, (1, 2, 3), (4, 5, 6), (7, 8, 9).

*/

import java.util.List;

final class Codewarrior {
	static final List<?>[] arrayOfLists = new List[]{
		List.of(1, 2, 3),
		List.of(4, 5, 6),
		List.of(7, 8, 9)
	};

	private Codewarrior() {}

	public static void main(String[] args) {}
}
