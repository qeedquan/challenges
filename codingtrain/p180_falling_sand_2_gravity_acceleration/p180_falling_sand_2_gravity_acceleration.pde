float[][] grid;
float[][] velocityGrid;

int w;
int cols, rows;
float hueValue;

float gravity;

void setup() {
  size(800, 600);
  colorMode(HSB, 360, 255, 255);
  reset();
}

void reset() {
  w = 5;
  hueValue = 200;
  gravity = 0.1;
  cols = width / w;
  rows = height / w;
  grid = new float[cols+1][rows+1];
  velocityGrid = new float[cols+1][rows+1];
}

void draw() {
  background(0);

  if (mousePressed) {
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
            velocityGrid[col][row] = 1;
          }
        }
      }
    }
    // Change the color of the sand over time
    hueValue += 0.5;
    if (hueValue > 360) {
      hueValue = 1;
    }
  }

  //frameRate(1);

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

  // Create a 2D array for the next frame of animation
  float[][] nextGrid = new float[cols+1][rows+1];
  float[][] nextVelocityGrid = new float[cols+1][rows+1];

  // Check every cell
  for (int i = 0; i < cols; i++) {
    for (int j = 0; j < rows; j++) {
      // What is the state?
      float state = grid[i][j];
      float velocity = velocityGrid[i][j];
      boolean moved = false;
      if (state > 0) {
        int newPos = int(j + velocity);
        for (int y = min(newPos, rows-1); y > j; y--) {
          float below = grid[i][y];
          if (y >= rows)
            below = -1;

          int dir = 1;
          if (random(1) < 0.5) {
            dir *= -1;
          }
          float belowA = -1;
          float belowB = -1;
          if (withinCols(i + dir)) belowA = grid[i + dir][y];
          if (withinCols(i - dir)) belowB = grid[i - dir][y];

          if (below == 0) {
            nextGrid[i][y] = state;
            nextVelocityGrid[i][y] = velocity + gravity;
            moved = true;
            break;
          } else if (below != -1 && belowA == 0) {
            nextGrid[i + dir][y] = state;
            nextVelocityGrid[i + dir][y] = velocity + gravity;
            moved = true;
            break;
          } else if (below != -1 && belowB == 0) {
            nextGrid[i - dir][y] = state;
            nextVelocityGrid[i - dir][y] = velocity + gravity;
            moved = true;
            break;
          }
        }
      }

      if (state > 0 && !moved) {
        nextGrid[i][j] = grid[i][j];
        nextVelocityGrid[i][j] = velocityGrid[i][j] + gravity;
      }
    }
  }
  grid = nextGrid;
  velocityGrid = nextVelocityGrid;
}

boolean withinCols(int i) {
  return i >= 0 && i <= cols - 1;
}

boolean withinRows(int j) {
  return j >= 0 && j <= rows - 1;
}
