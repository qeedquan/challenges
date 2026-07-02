/*

Implement interfaces Eat, Fly, Sleep.

Implement class Bird that implements interfaces Eat, Fly, Sleep.

interface Fly {
  void fly();
}

interface Eat {
  void eat();
}

interface Sleep {
  void sleep();
}

class Bird implements Fly, Eat, Sleep {
  public void fly() {
    // Flight implementation
  }

  public void eat() {
    // Eating implementation
  }

  public void sleep() {
    // Sleep implementation
  }
}
Java
25 lines
313 bytes

Input
Each line contains one of the bird's action: fly, eat or sleep.

Output
For each bird's action print in a separate line the corresponding output.

Examples

Input #1
fly
sleep
eat

Answer #1
Bird flies
Bird sleeps
Bird eats

*/

package main

import "fmt"

func main() {
	var bird Bird
	bird.Fly()
	bird.Sleep()
	bird.Eat()
}

type Fly interface{ Fly() }
type Eat interface{ Eat() }
type Sleep interface{ Sleep() }

type Bird struct{}

func (Bird) Fly()   { fmt.Println("Bird flies") }
func (Bird) Eat()   { fmt.Println("Bird eats") }
func (Bird) Sleep() { fmt.Println("Bird sleeps") }
