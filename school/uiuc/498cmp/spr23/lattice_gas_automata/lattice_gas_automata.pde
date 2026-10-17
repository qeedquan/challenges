/*

Cellular Automata
In physics, you have a state of the universe and you have some rules to update the state.
In classical physics, the rules are always local (even in E&M, you can write things in terms of local fields).

If your goal is to write down a model which captures these simple principles, cellular automata are the simplest way to do this.
In cellular automata you have a bunch of grid points (say on a square or a honeycomb) and you have some local rules to update these cells.

Lattice Gas Automata

In a lattice gas automata, you have two colors (black and white). You can treat the black color as the gas and the white color as empty space.

Our state, then, is going to be where the gas and empty space is.

We will start with the right half of the system filled with gas and the left half empty (i.e. the right half is black and the left half is white).

The rule then is:

randomly select a site.
  
randomly select a neighbor.

swap the site and the neighbor (even if they are the same color).

You should use open boundary conditions (i.e. the top and the bottom don’t wrap).

You have to be a bit careful about the boundaries. You don’t want to access memory not in your array.
Write a Python code that does this and prints out snapshots configurations every so often.
Work on a 100 x 100 lattice.

Other interesting automatas:
The game of life
Turing Machines
One-dimensional automata (Rule 30 and 110)

Billiard Balls
You might wonder if Billiard Balls can also be universal computers.
In fact, they can. You can just make collisions of the billiard balls (with mirrors) act like gates.
See Margolus, N. H. (1988). Physics and computation (No. MIT/LCS/TR-415).

Interacting lattice gases automata
We can generalize our original lattice gas cellular automaton a bit by adding interactions between the atoms.
This gives us a more realistic model of a gas.
We can also look at how entropy increases in the interacting system and compare it with the entropy in the non-interacting system.

Cellular Automata for Fluids
Not only can cellular automata be used to model gases, they can also be used to model fluids.
By designing a cellular automaton with simple rules based on a cartoon model of molecular dynamics, you can obtain, from a non-microscopic viewpoint, dynamical behavior that mimics fluid flow.
A particular cellular automaton that does this is known at the lattice gas FHP model.
The sites of the automaton are arranged on a triangular lattice (with hexagonal symmetry) and each site has six possible states.

*/

import java.util.zip.Deflater;

CA ca;
boolean paused;
int iterations;

void setup() {
  size(512, 512);
  ca = new CA(width, height);
  paused = false;
  iterations = 50000;
}

void draw() {
  if (!paused) {
    for (int i = 0; i < iterations; i++)
      ca.update();
    
    calcEntropy();    
  }
  ca.draw();
}

void keyPressed() {
  if (key == 'r')
    ca.reset();
  else if (keyCode == ' ')
    paused = !paused;
}

/*

As the (non-interacting) system evolves, entropy goes up in the sense that we can't compress the input very well anymore.
The output becomes random over long periods of time, assuming we have a uniform random number generator.
This aligns with the second law of thermodynamics.

*/

void calcEntropy() {
  byte[] output = new byte[width*height*2];
  Deflater compresser = new Deflater();
  compresser.setInput(ca.state);
  compresser.finish();
  int outputLength = compresser.deflate(output);
  compresser.end();
  println("Entropy Estimate: " + outputLength*1.0/ca.state.length);
}

class CA {
  byte[] state;
  int width;
  int height;
  
  CA(int width, int height) {
    this.width = width;
    this.height = height;
    this.state = new byte[width * height];
    reset();
  }
  
  void reset() {
    for (int y = 0; y < height; y++) {
      for (int x = 0; x < width; x++) {
          if (x < width/2)
            state[y*width + x] = 0;
          else
            state[y*width + x] = 1;
      }
    }
  }
  
  void draw() {
    for (int y = 0; y < height; y++) {
      for (int x = 0; x < width; x++) {
        if (state[y*width + x] != 0)
          set(x, y, color(0, 0, 0));
        else
          set(x, y, color(255, 255, 255));
      }
    }
  }
  
  void update() {
    int x = (int)random(width);
    int y = (int)random(height);
    int nx = x + round(random(-1, 1));
    int ny = y + round(random(-1, 1));
    if (nx < 0 || ny < 0 || nx >= width || ny >= height)
      return;

    int i = y*width + x;
    int j = ny*width + nx;
    
    var temp = state[i];
    state[i] = state[j];
    state[j] = temp;
  }
}
