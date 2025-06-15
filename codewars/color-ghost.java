/*

Create a class Ghost

Ghost objects are instantiated without any arguments.

Ghost objects are given a random color attribute of white" or "yellow" or "purple" or "red" when instantiated

```
Ghost ghost = new Ghost();
ghost.getColor(); //=> "white" or "yellow" or "purple" or "red"
```

*/

import java.security.SecureRandom;

class Ghost {
	String getColor() {
		var rng = new SecureRandom();
		var colors = new String[]{"white", "yellow", "purple", "red"};
		var index = rng.nextInt(colors.length);
		return colors[index];
	}
}

class Test {
	public static void main(String[] args) {
		for (var i = 0; i <= 10; i++) {
			var ghost = new Ghost();
			System.out.println(ghost.getColor());
		}
	}
}
