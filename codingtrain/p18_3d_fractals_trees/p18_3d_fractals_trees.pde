import peasy.*;

Tree tree;

PeasyCam cam;

float min_dist = 5;
float max_dist = 200;

void setup() {
  size(600, 900, P3D);
  cam = new PeasyCam(this, 500);
  tree = new Tree();
}

void draw() {
  background(51);
  tree.show();
  tree.grow();
}

void keyPressed() {
  if (keyCode == ' ') {
    tree = new Tree();
  }
}

class Branch {
  Branch parent;
  PVector pos;
  PVector dir;
  int count = 0;
  PVector saveDir;
  float len = 5;
  
  Branch(PVector v, PVector d) {
    parent = null;
    pos = v.copy();
    dir = d.copy();
    saveDir = dir.copy();
  }

  Branch(Branch p) {
    parent = p;
    pos = parent.next();
    dir = parent.dir.copy();
    saveDir = dir.copy();
  }

  void reset() {
    count = 0;
    dir = saveDir.copy();
  }

  PVector next() {
    PVector v = PVector.mult(dir, len);
    PVector next = PVector.add(pos, v);
    return next;
  }
}


class Leaf {
  PVector pos;
  boolean reached = false;

  Leaf() {
    pos = PVector.random3D();
    pos.mult(random(width/2));
    pos.y -= height/4;
  }

  void reached() {
    reached = true;
  }

  void show() {
    fill(255);
    noStroke();
    pushMatrix();
    translate(pos.x, pos.y, pos.z);
    ellipse(0,0, 4, 4);
    popMatrix();
  }
}

class Tree {
  ArrayList<Branch> branches = new ArrayList<Branch>();
  ArrayList<Leaf> leaves = new ArrayList<Leaf>();

  Tree() {
    for (int i = 0; i < 2000; i++) {
      leaves.add(new Leaf());
    }    
    Branch root = new Branch(new PVector(0,height/2), new PVector(0, -1));
    branches.add(root);
    Branch current = new Branch(root);

    while (!closeEnough(current)) {
      Branch trunk = new Branch(current);
      branches.add(trunk);
      current = trunk;
    }
  }

  boolean closeEnough(Branch b) {

    for (Leaf l : leaves) {
      float d = PVector.dist(b.pos, l.pos);
      if (d < max_dist) {
        return true;
      }
    }
    return false;
  }

  void grow() {
    for (Leaf l : leaves) {
      Branch closest = null;
      PVector closestDir = null;
      float recorded = -1;

      for (Branch b : branches) {
        PVector dir = PVector.sub(l.pos, b.pos);
        float d = dir.mag();
        if (d < min_dist) {
          l.reached();
          closest = null;
          break;
        } else if (d > max_dist) {
        } else if (closest == null || d < recorded) {
          closest = b;
          closestDir = dir;
          recorded = d;
        }
      }
      if (closest != null && closestDir != null) {
        closestDir.normalize();
        closest.dir.add(closestDir);
        closest.count++;
      }
    }

    for (int i = leaves.size()-1; i >= 0; i--) {
      if (leaves.get(i).reached) {
        leaves.remove(i);
      }
    }

    for (int i = branches.size()-1; i >= 0; i--) {
      Branch b = branches.get(i);
      if (b.count > 0) {
        b.dir.div(b.count);
        PVector rand = PVector.random2D();
        rand.setMag(0.3);
        b.dir.add(rand);
        b.dir.normalize();
        Branch newB = new Branch(b);
        branches.add(newB);
        b.reset();
      }
    }
  }

  void show() {
    for (Leaf l : leaves) {
      l.show();
    }
    for (int i = 0; i < branches.size(); i++) {
      Branch b = branches.get(i);
      if (b.parent != null) {
        float sw = map(i, 0, branches.size(), 6, 0);
        strokeWeight(sw);
        stroke(255);
        line(b.pos.x, b.pos.y, b.pos.z, b.parent.pos.x, b.parent.pos.y, b.parent.pos.z);
      }
    }
  }
}
