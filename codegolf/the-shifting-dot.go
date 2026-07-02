/*

Your program has to print out a number of spaces, followed by a dot and a newline. The number of spaces is the x position of your dot defined with 0 < x < 30

Every new line is a turn. Your program runs for 30 turns. Your program starts with a random x position and every turn shifts this position randomly by 1 to the left or right, while staying inside the defined area. Every turn your dot has to change its position by 1.

Your score is the number of characters. You get 10 bonus points, if every printed line consists of exactly 30 characters (and newline). You get 50 bonus points, if, while random, your program tends to stay in the middle of the defined area.

Edit: The 50 bonus points are intended to pull your dot to the middle. For example, this apply's if your dot is at x=20 and has a chance of 66% to go left and 33% to go right. This has to be independent from starting point and should only happen by altering the percentage value of left/right dynamically.

No input of any kind allowed, output has to be on the executing console!

For better understanding, here is a readable example in java, that would give you a score of 723:

public class DotJumper{
    public static void main(String[] args){
        int i = (int)(Math.random()*30);
        int max = 29;
        int step = 1;
        int count = 30;
        while(count>0){
            if(i<=1){
                i+=step;
            }else if(i>=max){
                i-=step;
            }else{
                if(Math.random() > 0.5){
                    i+=step;
                }else{
                    i-=step;
                }
            }
            print(i);
            count--;
        }
    }
    public static void print(int i){
        while(i>0){
            System.out.print(' ');
            i--;
        }
        System.out.println('.');
    }
}

*/

package main

import (
	"fmt"
	"math/rand"
	"strings"
)

func main() {
	dots(30)
}

func dots(n int) {
	xm := n - 1
	x := rand.Intn(n)
	dx := 1
	for c := n; c > 0; c-- {
		switch {
		case x <= 1:
			x += dx
		case x >= xm:
			x -= dx
		default:
			if rand.Float64() > 0.5 {
				x += dx
			} else {
				x -= dx
			}
		}
		fmt.Printf("%s.\n", strings.Repeat(" ", x))
	}
}
