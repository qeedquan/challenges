/*

https://en.wikipedia.org/wiki/Snake_(video_game_genre)

*/

Snake snake;
float rez;
PVector food;
float w;
float h;

void setup() {
  size(400, 400);
  reset();
}

void reset() {
  rez = 20;
  w = floor(width / rez);
  h = floor(height / rez);
  frameRate(5);
  snake = new Snake();
  foodLocation();
}

void foodLocation() {
  float x = floor(random(w));
  float y = floor(random(h));
  food = new PVector(x, y);
}

void keyPressed() {
  if (keyCode == LEFT) {
    snake.setDir(-1, 0);
  } else if (keyCode == RIGHT) {
    snake.setDir(1, 0);
  } else if (keyCode == DOWN) {
    snake.setDir(0, 1);
  } else if (keyCode == UP) {
    snake.setDir(0, -1);
  } else if (key == ' ') {
    snake.grow();
  }

}

void draw() {
  scale(rez);
  background(220);
  if (snake.eat(food)) {
    foodLocation();
  }
  snake.update();
  snake.show();


  if (snake.endGame()) {
    print("END GAME");
    background(255, 0, 0);
    noLoop();
  }

  noStroke();
  fill(255, 0, 0);
  rect(food.x, food.y, 1, 1);
}

class Snake {
  ArrayList<PVector> body;
  float xdir;
  float ydir;
  float len;

  Snake() {
    body = new ArrayList<PVector>();
    body.add(new PVector(floor(w/2), floor(h/2)));
    xdir = 0;
    ydir = 0;
    len = 0;
  }
  
  void setDir(float x, float y) {
    xdir = x;
    ydir = y;
  }
  
  PVector getHead() {
    return body.get(body.size() - 1).copy();
  }
  
  void update() {
    var head = getHead();
    body.remove(0);
    head.x += xdir;
    head.y += ydir;
    body.add(head);
  }
  
  void grow() {
    var head = getHead();
    len++;
    body.add(head);
  }
  
  boolean endGame() {
    var head = getHead();
    if(head.x > w-1 || head.x < 0 || head.y > h-1 || head.y < 0) {
       return true;
    }
    for(var i = 0; i < body.size()-1; i++) {
      var part = body.get(i);
      if(part.x == head.x && part.y == head.y) {
        return true;
      }
    }
    return false;
  }
  
  boolean eat(PVector pos) {
    var head = getHead();
    if (head.x == pos.x && head.y == pos.y) {
      grow();
      return true;
    }
    return false;
  }
  
  void show() {
    for (var part : body) {
      fill(0);
      noStroke();
      rect(part.x, part.y, 1, 1);
    }
  }
}
