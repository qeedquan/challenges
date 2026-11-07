/*

https://www.mysimulator.uk/physics/sand/
https://pvigier.github.io/2020/12/12/procedural-death-animation-with-falling-sand-automata.html

*/

int[][] grid;
int[][] nextGrid;

int w;
int cols, rows;
int hueValue;

void setup() {
  size(800, 600);
  colorMode(HSB, 360, 255, 255);
  reset();
}

void reset() {
  w = 5;
  hueValue = 200;
  cols = width / w;
  rows = height / w;
  grid = new int[cols + 1][rows + 1];
  nextGrid = new int[cols + 1][rows + 1];
}

void mouseDragged() {
  int mouseCol = floor(mouseX / w);
  int mouseRow = floor(mouseY / w);
  
  // Randomly add an area of sand particles
  int matrix = 5;
  int extent = floor(matrix / 2);
  for (int i = -extent; i <= extent; i++) {
    for (int j = -extent; j <= extent; j++) {
      if (random(1) < 0.75) {
        int col = mouseCol + i;
        int row = mouseRow + j;
        if (withinCols(col) && withinRows(row)) {
          grid[col][row] = hueValue;
        }
      }
    }
  }
  // Change the color of the sand over time
  hueValue += 1;
  if (hueValue > 360) {
    hueValue = 1;
  }
}

void draw() {
  background(0);
  
  // Draw the sand
  for (int i = 0; i < cols; i++) {
    for (int j = 0; j < rows; j++) {
      noStroke();
      if (grid[i][j] > 0) {
        fill(grid[i][j], 255, 255);
        int x = i * w;
        int y = j * w;
        square(x, y, w);
      }
    }
  }

  // Check every cell
  for (int i = 0; i < cols; i++) {
    for (int j = 0; j < rows; j++) {
      // What is the state?
      int state = grid[i][j];
      
      // If it's a piece of sand!
      if (state > 0) {
        // What is below?
        int below = grid[i][j + 1];
        if (j+1 >= rows)
          below = -1;
        
        // Randomly fall left or right
        int dir = 1;
        if (random(1) < 0.5) {
          dir *= -1;
        }

        // Check below left or right
        int belowA = -1;
        int belowB = -1;
        if (withinCols(i + dir)) {
          belowA = grid[i + dir][j + 1];
        }
        if (withinCols(i - dir)) {
          belowB = grid[i - dir][j + 1];
        }
        
        // Can it fall below or left or right?
        if (below == 0) {
          nextGrid[i][j + 1] = state;
        } else if (below != -1 && belowA == 0) {
          nextGrid[i + dir][j + 1] = state;
        } else if (below != -1 && belowB == 0) {
          nextGrid[i - dir][j + 1] = state;
        // Stay put!
        } else {
          nextGrid[i][j] = state;
        }
      }
    }
  }

  for (int i = 0; i < grid.length; i++) {
    for (int j = 0; j < grid[i].length; j++) {
      grid[i][j] = nextGrid[i][j];
      nextGrid[i][j] = 0;
    }
  }
}

boolean withinCols(int i) {
  return i >= 0 && i <= cols - 1;
}

boolean withinRows(int j) {
  return j >= 0 && j <= rows - 1;
}
