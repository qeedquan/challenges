/*

https://en.wikipedia.org/wiki/Padovan_sequence

*/

int[] padovan;
int   numpadovan;

void setup() { 
  size(600, 600);

  numpadovan = 12;
  padovan = generate(numpadovan);
}

void draw() {
  background(255);
  
  var rectWidth = 2;
  var rectHeight = 20;
  var spacing = 2;
  var rowSpacing = 22;
  for (var i = 0; i < padovan.length; i++) {
    var yPosition = i * rowSpacing + 100;
    for (var j = 0; j < 50; j++) {
      rectWidth = padovan[i] + 2;
      fill(0);
      rect(j * (rectWidth + spacing), yPosition - rectHeight, rectWidth, rectHeight); 
    }
  }
}

void keyPressed() {
  if (keyCode == RIGHT)
    numpadovan += 1;
  else if (keyCode == LEFT)
    numpadovan -= 1;
  numpadovan = max(numpadovan, 1);
  padovan = generate(numpadovan);
}

int[] generate(int size) {
  var padovan = new int[size];
  for (var i = 0; i < padovan.length; i++)
    padovan[i] = padovanNumber(i);
  return padovan;
}

int padovanNumber(int n) {
  if (n < 0)
    return 0;
  if (n < 3)
    return 1;
  return padovanNumber(n - 2) + padovanNumber(n - 3);
}
