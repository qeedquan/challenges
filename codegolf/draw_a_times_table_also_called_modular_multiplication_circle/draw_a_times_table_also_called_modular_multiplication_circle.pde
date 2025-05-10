/*

Not to be confused with this question.

You need to draw a times table (also known as Cremona's method for cardioid generation) as shown in this video. The number n and k will be the inputs.

In the video n and k are 2 and 10 respectively.

How to draw?
Draw a circle, divide its perimeter into equal spaced parts with k points and number them with 0,1,2,…,k−1.
Draw k line segments between i and i×n mod k for all integers i, 0≤i<k.
You can use any graphing library that your language allows.

Remember this is a code-golf so keep the answer short and sweet.

Examples
Input : n = 2 and k = 27

https://i.stack.imgur.com/DhID6.png

Input : n = 5 and k = 10

https://i.stack.imgur.com/hsysK.png

You can also play around with it here. The modulus/points is k while multiplication factor is n.

Challenge
You need to draw at least the circle and the lines.

You can output any file format (svg, png, jpeg) and HTML rendering is also allowed.

You can also write the image to STDOUT

Best of luck because you are going to need it!

*/

int N, K;
int fontsize;

void setup() {
  size(1400, 900);
  N = 2;
  K = 27;
  fontsize = 32;
  textSize(fontsize);
  render();
}

void render() {
  background(100, 110, 120);
  text(String.format("N: %d K: %d", N, K), fontsize, fontsize);
  cremona(N, K);
}

void draw() {
}

void cremona(int n, int k) {
  var segments = new ArrayList<PVector>();
  float radius = max(width/2, height/2)/2;
  circle(width/2, height/2, radius*2);
  for (int i = 0; i < k; i++) {
    float t = 2*PI*i / k;
    float x = radius*cos(t) + width/2;
    float y = radius*sin(t) + height/2;
    
    strokeWeight(15);
    stroke(67, 143, 80);
    point(x, y);
    
    segments.add(new PVector(x, y));
  }
  
  for (int i = 0; i < k; i++) {    
    PVector p0 = segments.get(i);
    PVector p1 = segments.get((i*n) % k);
    
    strokeWeight(2);
    stroke(147, 126, 194);
    line(p0.x, p0.y, p1.x, p1.y);
  }
}

void keyPressed() {
  var n = N;
  var k = K;
  if (keyCode == LEFT)
    n -= 1;
  else if (keyCode == RIGHT)
    n += 1;
  else if (keyCode == UP)
    k += 1;
  else if (keyCode == DOWN)
    k -= 1;

  if (n > 0 && k > 0 && (n != N || k != K)) {
    N = n;
    K = k;
    render();
  }
}
