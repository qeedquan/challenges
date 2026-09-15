/*

https://en.wikipedia.org/wiki/Tic-tac-toe
https://en.wikipedia.org/wiki/Minimax

*/


char board[][] = {
  {' ', ' ', ' '},
  {' ', ' ', ' '},
  {' ', ' ', ' '},
};

int w;
int h;

char ai = 'X';
char human = 'O';
char currentPlayer = human;

void setup() {
  size(400, 400);
  w = width / 3;
  h = height / 3;
  bestMove();
}

boolean equals3(char a, char b, char c) {
  return a == b && b == c && a != ' ';
}

String checkWinner() {
  String winner = null;

  // horizontal
  for (var i = 0; i < 3; i++) {
    if (equals3(board[i][0], board[i][1], board[i][2])) {
      winner = String.format("%c", board[i][0]);
    }
  }

  // Vertical
  for (var i = 0; i < 3; i++) {
    if (equals3(board[0][i], board[1][i], board[2][i])) {
      winner = String.format("%c", board[0][i]);
    }
  }

  // Diagonal
  if (equals3(board[0][0], board[1][1], board[2][2])) {
    winner = String.format("%c", board[0][0]);
  }
  if (equals3(board[2][0], board[1][1], board[0][2])) {
    winner = String.format("%c", board[2][0]);
  }

  var openSpots = 0;
  for (var i = 0; i < 3; i++) {
    for (var j = 0; j < 3; j++) {
      if (board[i][j] == ' ') {
        openSpots++;
      }
    }
  }

  if (winner == null && openSpots == 0)
    return "Tie";
  
  return winner;
}

void mousePressed() {
  if (currentPlayer == human) {
    // Human make turn
    var i = floor(mouseX / w);
    var j = floor(mouseY / h);
    // If valid turn
    if (board[i][j] == ' ') {
      board[i][j] = human;
      currentPlayer = ai;
      bestMove();
    }
  }
}

void draw() {
  background(255);
  strokeWeight(4);

  line(w, 0, w, height);
  line(w * 2, 0, w * 2, height);
  line(0, h, width, h);
  line(0, h * 2, width, h * 2);

  for (var j = 0; j < 3; j++) {
    for (var i = 0; i < 3; i++) {
      var x = w * i + w / 2;
      var y = h * j + h / 2;
      var spot = board[i][j];
      textSize(32);
      var r = w / 4;
      if (spot == human) {
        noFill();
        ellipse(x, y, r * 2, r *2);
      } else if (spot == ai) {
        line(x - r, y - r, x + r, y + r);
        line(x + r, y - r, x - r, y + r);
      }
    }
  }

  var result = checkWinner();
  if (result != null) {
    noLoop();
    print("Result: " + result);
  }
}

void bestMove() {
  // AI to make its turn
  var bestScore = Integer.MIN_VALUE;
  int move[] = {0, 0};
  for (var i = 0; i < 3; i++) {
    for (var j = 0; j < 3; j++) {
      // Is the spot available?
      if (board[i][j] == ' ') {
        board[i][j] = ai;
        var score = minimax(board, 0, false);
        board[i][j] = ' ';
        if (score > bestScore) {
          bestScore = score;
          move[0] = i;
          move[1] = j;
        }
      }
    }
  }
  board[move[0]][move[1]] = ai;
  currentPlayer = human;
}

int minimax(char board[][], int depth, boolean isMaximizing) {
  var result = checkWinner();
  if (result != null) {
    if (result.equals("X"))
      return 10;
    if (result.equals("O"))
      return -10;
    return 0;
  }

  var bestScore = (isMaximizing) ? Integer.MIN_VALUE : Integer.MAX_VALUE;
  if (isMaximizing) {
    for (var i = 0; i < 3; i++) {
      for (var j = 0; j < 3; j++) {
        // Is the spot available?
        if (board[i][j] == ' ') {
          board[i][j] = ai;
          var score = minimax(board, depth + 1, false);
          board[i][j] = ' ';
          bestScore = max(score, bestScore);
        }
      }
    }
  } else {
    for (var i = 0; i < 3; i++) {
      for (var j = 0; j < 3; j++) {
        // Is the spot available?
        if (board[i][j] == ' ') {
          board[i][j] = human;
          var score = minimax(board, depth + 1, true);
          board[i][j] = ' ';
          bestScore = min(score, bestScore);
        }
      }
    }
  }
  return bestScore;
}
