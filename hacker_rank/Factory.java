/*

According to Wikipedia, a factory is simply an object that returns another object from some other method call, which is assumed to be "new".

In this problem, you are given an interface Food. There are two classes Pizza and Cake which implement the Food interface, and they both contain a method getType().

The main function in the Main class creates an instance of the FoodFactory class. The FoodFactory class contains a method getFood(String) that returns a new instance of Pizza or Cake according to its parameter.

You are given the partially completed code in the editor. Please complete the FoodFactory class.

Sample Input 1

cake

Sample Output 1

The factory returned class Cake
Someone ordered a Dessert!

Sample Input 2

pizza

Sample Output 2

The factory returned class Pizza
Someone ordered Fast Food!

*/

public class Factory {
	public static void main(String[] args) {
		serve("pizza");
		serve("cake");
	}

	public static void serve(String type) {
		var foodFactory = new FoodFactory();
		var food = foodFactory.getFood(type);
		var foodType = food.getType();
		if (foodType.equals("pizza")) {
			System.out.println("The factory returned class Pizza");
			System.out.println("Someone ordered Fast Food!");
		} else if (foodType.equals("cake")) {
			System.out.println("The factory returned class Cake");
			System.out.println("Someone ordered a Dessert!");
		}
	}
}

interface Food {
	public String getType();
}

class FoodFactory {
	Food getFood(String type) {
		if (type.equals("pizza")) {
			return new Pizza();
		} else if (type.equals("cake")) {
			return new Cake();
		}
		return null;
	}
}

class Pizza implements Food {
	public String getType() {
		return "pizza";
	}
}

class Cake implements Food {
	public String getType() {
		return "cake";
	}
}
