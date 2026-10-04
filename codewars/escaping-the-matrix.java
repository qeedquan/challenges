/*

Help Neo to escape the matrix by throwing himself out!

Neo is an exception, which is defined already:

public final class Neo extends Exception {}

The example test is the same one as the real test case, so if your code pass the example test case,
you are good to go!

*/

final class Neo extends Exception {
}

interface Matrix {
	static <T extends Throwable> void enter() throws T {
		throw (T) new Neo();
	}
}
