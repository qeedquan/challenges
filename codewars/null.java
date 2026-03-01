/*

I always thought that it was unfair null always seems to break code. So today, we're going to make a Null object that doesn't throw exceptions when you use it!

*/

class Null {
	@Override
	public String toString() {
		return "null";
	}

	@Override
	public int hashCode() {
		return 0;
	}

	@Override
	public boolean equals(Object obj) {
		return obj == null || obj instanceof Null;
	}
}

