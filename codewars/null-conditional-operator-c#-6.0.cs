/*

In C# 6.0 there is new operator ?. called the Null-Conditional Operator.

It's nothing revolutionary - just an example of syntactic sugar but a pretty neat one.

Use case
Imagine you have a Car, the car has an Engine, the engine has a Gearbox and the gearbox has some property you are interested in, for example numberOfGears. Now, the car could be from junkyard and the gearbox or even the engine could be missing (null).

The name of each property is the name of the class it contains, converted to the appropriate case, such that if all components are present the final property could be accessed by:

Car.Engine.GearBox.NumberOfGears

How to determine the number of gears in a car?

Instructions
Write an extension method for Car called GetNumberOfGears. This method will return the value of NumberOfGears property of the gearbox or -1 if the gearbox (or anything else) is missing.

Constraints
Find some information about the ?. and ?? operators and try to write the method without using if or the ternary operator ?:.

References
Null-conditional Operators (?.)
Null-coalescing operator (??)
Conditional operator (?:)

*/

using System;

public static class CarInformation
{
	public class Car
	{
		public Engine Engine;
	}

	public class Engine
	{
		public GearBox GearBox;
	}

	public class GearBox
	{
		public int NumberOfGears;
	}

	public static void Main()
	{
		var car1 = new Car {
			Engine = new Engine {
				GearBox = new GearBox {
					NumberOfGears = 5 
				}
			}
		};
		
		var car2 = new Car();

		var car3 = new Car {
			Engine = new Engine {
				GearBox = new GearBox {
					NumberOfGears = 0
				}
			}
		};

		Console.WriteLine(car1.GetNumberOfGears());
		Console.WriteLine(car2.GetNumberOfGears());
		Console.WriteLine(car3.GetNumberOfGears());
	}

	public static int GetNumberOfGears (this Car car)
	{
		return car.Engine?.GearBox?.NumberOfGears ?? -1;
	}
}
