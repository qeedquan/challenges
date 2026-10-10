/*

This is my first question in Code golf I found it in stack-overflow (originally in JavaScript however all languages are acceptable):

Render on screen NxN (where N in range 1-16) grid where each cell have black boundary and red number inside - cells are numerated in hex starting from left-upper corner to bottom-right. Example output (for N=16) shows how result should looks like (font can be different than in picture):

https://i.sstatic.net/nZn8m.png

The image in text uri form (which works on major browsers) in output is also acceptable - a as example blow:

This is my (not optimised) attempt to this task

Hide code snippet

document.write('<style>.row { display: flex; font-size: 9.5px; text-align: center; color: red } .cell { width: 10px; height: 10px; margin: 1px; border: 1px solid black;}</style><div id="container"></div>')

let n=10, s='';

for(let i=0; i<n; i++) {
  s+= '<div class="row">'
  for(let j=0; j<n; j++) s+= `<div class="cell"> ${(i*n+j).toString(16)} </div>`;
  s+= '</div>'
}

container.innerHTML = s;

but I wonder how small code can produce similar effect?

*/

int fontsz = 20;

void setup() {
  size(900, 900);
  textSize(fontsz);
}

void draw() {
  numbergrid();
}

void numbergrid() {
  int x0 = 20;
  int y0 = 20;
  int n = 16;
  int s = 27;
  strokeWeight(3);
  for (int y = 0; y < n; y++) {
    for (int x = 0; x < n; x++) {
      int px = x0 + 2*x*s;
      int py = y0 + 2*y*s;
      
      fill(255);
      rect(px, py, s, s);

      fill(255, 0, 0);
      textAlign(CENTER);
      text(String.format("%x", y*n + x), px + fontsz/2 + 4, py + fontsz);
    }
  }
}
