/*

Let's use Google Guava Library to fight against the million dollar error.

As start point we have a simple sum function and we need it to validate the following, **in order**:

* that parameters are not null
 * if first parameter is null throw NPE with message "Illegal Argument passed: First parameter is Null."
 * if second parameter is null throw NPE with message "Illegal Argument passed: Second parameter is Null."
* that parameters are positive ( > 0 )
 * if this is not the case then throw IllegalArgumentException with message "Illegal Argument passed: Non-positive value d." where `d` is the non-positive value (no need to format the value, just turn it into a string). If both values are non-positive, use the first parameter.

Hint: you could use a reading to class `com.google.common.base.Preconditions`

*/

import java.util.Objects;

interface Sum {
	static double sum(Double a, Double b) {
		Objects.requireNonNull(a, "Illegal Argument passed: First parameter is Null.");
		Objects.requireNonNull(b, "Illegal Argument passed: Second parameter is Null.");
		if (a <= 0 && b <= 0)
			throw new IllegalArgumentException("Illegal Argument passed: Non-positive value " + (a <= 0 ? a : b) + ".");
		return a + b;
	}

	public static void main(String[] args) {
		System.out.println(sum(2.0, 4.0));
		try {
			System.out.println(sum(null, null));
		} catch (Exception e) {
			System.out.println(e);
		}
		try {
			System.out.println(sum(2.0, -4.0));
		} catch (Exception e) {
			System.out.println(e);
		}
	}
}

