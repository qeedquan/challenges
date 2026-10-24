/*

Implement a wrapper class MyDouble.

class MyDouble // Java
{
  private double a; // private variable
  MyDouble(double a) // Constructor
  public String toString() // Print the variable of type MyDouble
  public MyDouble Add(MyDouble b) // Add the value of type MyDouble
  public MyDouble Add(long b) // Add the value of type long
  public MyDouble Sub(MyDouble b) // Subtract the value of type MyDouble
  public MyDouble Sub(long b) // Subtract the value of type long
  public MyDouble Mult(MyDouble b) // Multiply by the value of type MyDouble
  public MyDouble Mult(long b) // Multiply by the value of type long
  public MyDouble Div(MyDouble b) // Divide by the value of type MyDouble
  public MyDouble Div(long b) // Divide by the value of type long
};

Input
Two double values a and b.

Output
Print the value of expression (a∗b+10)/3+(a+2/b−7)∗5−a−b/a.

Examples

Input #1
3.2 6.12

Answer #1
-12.61718

*/

package main

import "fmt"

func main() {
	fmt.Println(solve(3.2, 6.12))
}

func solve(a, b float64) float64 {
	return (a*b+10)/3 + (a+2/b-7)*5 - a - b/a
}
