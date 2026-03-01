/*

The golfing languages 05AB1E and Vyxal have a "canvas" builtin that draws a string on a ASCII grid. In this challenge, you'll be implementing a simplified form of this.

You should take a string of ASCII characters, along with a list of directions as integers 0-7, where 0 is directly upwards and the rest continue clockwise - 1 is up-right, 2 is right, etc up to 7 being up-left.

7 0 1
 \|/
6-x-2
 /|\
5 4 3
For example, given the string abcde and the directions 0,2,5,6:

Draw a at the center, then move up (0) and draw b:

b
a
Then move right (2) and draw c:

bc
a
Then move down-left (5) and draw d, overwriting the a:

bc
d
And finally move left (6) and draw e:

 bc
ed
For a more complex example that I won't work through, given the string octagon! and the directions 1,2,3,4,5,6,7, you should draw:

 ct
o  a
!  g
 no
Empty space should be filled with spaces, and you can output with any amount of leading and trailing whitespace so long as the pattern at the centre is still correct. There will always be exactly one more character than directions, so that one character can be drawn at the centre.

You may take directions as any subset of the integers from 0 to 10 inclusive, or take them as direction vectors [1,-1],[0,1],[-1,0] / complex numbers / similar, and/or reorder them in any way. The input string may contain spaces.

This is code-golf, shortest wins!

Testcases
Input  Output
[1,1,1,1], "aaaaa"  
    a
   a 
  a  
 a   
a    
[1,2,3,4,5,6,7],"octagon!"  
 ct 
o  a
!  g
 no 
[2,4,2,4,2,4,2,4],"staircase"  
st   
 ai  
  rc 
   as
    e
[1,1,1,1,1,1],"s s s s"  
      s
       
    s  
       
  s    
       
s      
[2,2,2,2,0,0,6,6,4,4], "overwriting"  
  iti
  n r
ovgrw
[2,2,2,4,4,5,5,6,6,6,0,0,1,5,2,2,2,1,5,4], "+--+|+/+--+|X/+--X/+|"  
  +--+
 /  /|
+--+ +
|  |/ 
+--+  
[6,7,0,1,2,2,3,3,4,4,5,5,6,6,6,7,7,7,0,0,0,1,1,1,2,2,2],
"spiralspiralspiralspiralspir"
   spir  
  l      
 a       
r   als  
i  r   p 
p  i    i
s   ps  r
 l      a
  a    l 
   rips  

*/

int fontsize;
int selection;

void setup() {
  size(1024, 768);
  selection = 0;
  fontsize = 24;
  textSize(fontsize);
}

void draw() {
  background(70, 80, 90);
  push();
  translate(width/2, height/2);
  canvas(DIRS[selection], STRS[selection]);
  pop();
}

void canvas(int[] dir, String str) {
  if (str.length() == 0 || dir.length+1 != str.length())
    return;

  var ch = str.charAt(0);
  var x = 0;
  var y = 0;
  text(String.format("%c", ch), x*fontsize, y*fontsize);
   
  for (int i = 0; i < dir.length; i++) {    
    switch (dir[i]) {
    case 0:
      y -= 1;
      break;
    case 1:
      x += 1;
      y -= 1;
      break;
    case 2:
      x += 1;
      break;
    case 3:
      x += 1;
      y += 1;
      break;
    case 4:
      y += 1;
      break;
    case 5:
      x -= 1;
      y += 1;
      break;
    case 6:
      x -= 1;
      break;
    case 7:
      x -= 1;
      y -= 1;
      break;
    }
    ch = str.charAt(i + 1);
    text(String.format("%c", ch), x*fontsize, y*fontsize);
  }
}

void keyPressed() {
  if (key != CODED)
    return;
  
  if (keyCode == LEFT) {
    if (selection > 0)
      selection -= 1;
  }
  if (keyCode == RIGHT) {
    if (selection+1 < DIRS.length)
      selection += 1;
  }
}

int DIR1[] = {1, 1, 1, 1};
int DIR2[] = {1, 2, 3, 4, 5, 6, 7};
int DIR3[] = {2, 4, 2, 4, 2, 4, 2, 4};
int DIR4[] = {1, 1, 1, 1, 1, 1};
int DIR5[] = {2, 2, 2, 2, 0, 0, 6, 6, 4, 4};
int DIR6[] = {2, 2, 2, 4, 4, 5, 5, 6, 6, 6, 0, 0, 1, 5, 2, 2, 2, 1, 5, 4};
int DIR7[] = {6, 7, 0, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 6, 7, 7, 7, 0, 0, 0, 1, 1, 1,2, 2, 2};
int DIRS[][] = {DIR1, DIR2, DIR3, DIR4, DIR5, DIR6, DIR7};

String STR1 = "aaaaa";
String STR2 = "octagon!";
String STR3 = "staircase";
String STR4 = "s s s s";
String STR5 = "overwriting";
String STR6 = "+--+|+/+--+|X/+--X/+|";
String STR7 = "spiralspiralspiralspiralspir";
String STRS[] = {STR1, STR2, STR3, STR4, STR5, STR6, STR7};
