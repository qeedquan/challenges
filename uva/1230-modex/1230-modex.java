import java.util.*;
import java.math.*;

class Modex {
	public static void main(String args[]) {
		System.out.println(expm("2 3 5"));	
		System.out.println(expm("2 2147483647 13"));
	}

	public static BigInteger expm(String input) {
		var scanner = new Scanner(input);
		var x = scanner.nextBigInteger();
		var y = scanner.nextBigInteger();
		var m = scanner.nextBigInteger();
		return x.modPow(y, m);
	}
}

