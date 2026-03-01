/*

Saw this in a PHP challenge. The objective is to make a chessboard with 64 squares (8*8) with the minimum amount of code. Simple enough, I made mine in PHP in 356 bytes (not impressive, I know) and I would like to see some other aproaches. This can be made in a language of your choice, as long as you keep it vanilla, so no imports. Smallest byte count wins.

The output should look like this:

screencap

And my code:

<table><?php
$c='black';function p($c,$n){echo'<td style="width:50px;height:50px;background:'.$c.'"></td>';if($n==1){echo"<tr>";}}for($i=1;$i<=64;$i++){if($i%8==0&&$c=="black"){$c="white";$n=1;}elseif($i%8==0&&$c=="white"){$c="black";$n=1;}elseif(isset($n)&&$n==1){$n=0;}elseif($c=="black"){$n=0;$c="white";}elseif($c=="white"){$n=0;$c="black";}p($c,$n);}
Or readable:

<table><tr>
<?php
$color = 'black';
function printcolor($color, $nl) {

    echo '<td style="width:50px; height:50px; background:' . $color . '"></td>';
    if ($nl == true) {
        echo "</tr><tr>";
    }
}
for ($i=1; $i<=64;$i++) {
    if ($i % 8 == 0 && $color == "black") {
        $color = "white";
        $nl = true;
    } elseif ($i % 8 == 0 && $color == "white") {
        $color = "black";
        $nl = true;
    } elseif (isset($nl) && $nl == true) {      
        $nl = false;
    } elseif ($color == "black") {
        $nl = false;
        $color = "white";           
        } 
    elseif ($color == "white")  {
        $nl = false;
        $color = "black";
    }       
    printcolor($color, $nl);
}
Edit:

Sorry I wasn't very specific at first:

Squares should have 50px * 50px except for vectorial images.
Output format or size is not relevant nor it needs to be an image.
For evaluation purposes the output must be visible such as in an image file or a screenshot
No libraries written after the challenge was posted

*/

void setup() {
  size(800, 800);
}

void draw() {
  background(100);
  chessboard(100);
}

void chessboard(int scale) {
  for (int y = 0; y < 8; y++) {
    for (int x = 0; x < 8; x++) {
      int col = 1 - ((x^y) & 1);
      fill(col*255);
      rect(x*scale, y*scale, scale, scale);
    }
  }
}
