/*

When a method in a subclass overrides a method in superclass, it is still possible to call the overridden method using super keyword. If you write super.func() to call the function func(), it will call the method that was defined in the superclass.

You are given a partially completed code in the editor. Modify the code so that the code prints the following text:

Hello I am a motorcycle, I am a cycle with an engine.
My ancestor is a cycle who is a vehicle with pedals.

*/

public class MethodOverride2 {
	public static void main(String[] args) {
		var motorcycle = new Motorcycle();
		motorcycle.print();
	}
}

class Cycle {
	public void print() {
		System.out.println("Hello I am a motorcycle, I am a cycle with an engine.");
	}
}

class Motorcycle extends Cycle {
	@Override
	public void print() {
		super.print();
		System.out.println("My ancestor is a cycle who is a vehicle with pedals.");
	}
}
