/*

Now that we have a Block let's move on to something slightly more complex: a Sphere.

Arguments for the constructor
radius -> integer or float (do not round it)
mass -> integer or float (do not round it)
Methods to be defined
get_radius()       =>  radius of the Sphere (do not round it)
get_mass()         =>  mass of the Sphere (do not round it)
get_volume()       =>  volume of the Sphere (rounded to 5 place after the decimal)
get_surface_area() =>  surface area of the Sphere (rounded to 5 place after the decimal)
get_density()      =>  density of the Sphere (rounded to 5 place after the decimal)

Example
ball = Sphere(2,50)
ball.get_radius() ->       2
ball.get_mass() ->         50
ball.get_volume() ->       33.51032
ball.get_surface_area() -> 50.26548
ball.get_density() ->      1.49208
Any feedback would be much appreciated

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	ball := Sphere{2, 50}
	fmt.Println(ball.Radius())
	fmt.Println(ball.Mass())
	fmt.Println(ball.Volume())
	fmt.Println(ball.SurfaceArea())
	fmt.Println(ball.Density())
}

type Sphere struct {
	radius float64
	mass   float64
}

func (c *Sphere) Radius() float64      { return c.radius }
func (c *Sphere) Mass() float64        { return c.mass }
func (c *Sphere) Volume() float64      { return 4.0 / 3 * math.Pi * c.radius * c.radius * c.radius }
func (c *Sphere) SurfaceArea() float64 { return 4 * math.Pi * c.radius * c.radius }
func (c *Sphere) Density() float64     { return c.Mass() / c.Volume() }
