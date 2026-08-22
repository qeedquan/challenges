/*

https://en.wikipedia.org/wiki/Hypercube

*/

class P4Vector {
  float x, y, z, w;
  
  P4Vector(float x, float y, float z, float w) {
    this.x = x;
    this.y = y;
    this.z = z;
    this.w = w;
  }
  
  void mult(float s) {
    x *= s;
    y *= s;
    z *= s;
    w *= s;
  }
  
  String toString() {
    return String.format("(%.2f, %.2f %.2f, %.2f)", x, y, z, w);
  }
}

P4Vector xform(PMatrix3D m, P4Vector v) {
  float x = m.m00*v.x + m.m01*v.y + m.m02*v.z + m.m03*v.w;
  float y = m.m10*v.x + m.m11*v.y + m.m12*v.z + m.m13*v.w;
  float z = m.m20*v.x + m.m21*v.y + m.m22*v.z + m.m23*v.w;
  float w = m.m30*v.x + m.m31*v.y + m.m32*v.z + m.m33*v.w;
  return new P4Vector(x, y, z, w);
}

P4Vector[] points;
float      angle;

void setup() {
  size(900, 900, P3D);
  angle = 0;
  points = new P4Vector[16];
  points[0] = new P4Vector(-1, -1, -1, 1);
  points[1] = new P4Vector(1, -1, -1, 1);
  points[2] = new P4Vector(1, 1, -1, 1);
  points[3] = new P4Vector(-1, 1, -1, 1);
  points[4] = new P4Vector(-1, -1, 1, 1);
  points[5] = new P4Vector(1, -1, 1, 1);
  points[6] = new P4Vector(1, 1, 1, 1);
  points[7] = new P4Vector(-1, 1, 1, 1);
  points[8] = new P4Vector(-1, -1, -1, -1);
  points[9] = new P4Vector(1, -1, -1, -1);
  points[10] = new P4Vector(1, 1, -1, -1);
  points[11] = new P4Vector(-1, 1, -1, -1);
  points[12] = new P4Vector(-1, -1, 1, -1);
  points[13] = new P4Vector(1, -1, 1, -1);
  points[14] = new P4Vector(1, 1, 1, -1);
  points[15] = new P4Vector(-1, 1, 1, -1);
}

void draw() {
  background(0);
  rotateX(-PI / 2);
  translate(width/2, 0, height/2);

  P4Vector[] projected3d = new P4Vector[points.length];
  for (int i = 0; i < points.length; i++) {    
    PMatrix3D rotationXY = new PMatrix3D(
      cos(angle), -sin(angle), 0, 0,
      sin(angle), cos(angle), 0, 0,
      0, 0, 1, 0,
      0, 0, 0, 1
    );
    
    PMatrix3D rotationZW = new PMatrix3D(
      1, 0, 0, 0,
      0, 1, 0, 0,
      0, 0, cos(angle), -sin(angle),
      0, 0, sin(angle), cos(angle)
    );
    
    P4Vector rotated = xform(rotationXY, points[i]);
    rotated = xform(rotationZW, rotated);
    
    float distance = 2.0;
    float w = 1 / (distance - rotated.w);
    
    PMatrix3D projection = new PMatrix3D(
      w, 0, 0, 0,
      0, w, 0, 0,
      0, 0, w, 0,
      0, 0, 0, 1
    );
    
    P4Vector projected = xform(projection, rotated);
    projected.mult(width / 8.0);
    projected3d[i] = projected;
    
    stroke(255, 230);
    strokeWeight(32);
    noFill();
    point(projected.x, projected.y, projected.z);
  }   

  // Connecting
  for (int i = 0; i < 4; i++) {
    connect(0, i, (i + 1) % 4, projected3d);
    connect(0, i + 4, ((i + 1) % 4) + 4, projected3d);
    connect(0, i, i + 4, projected3d);
  }

  for (int i = 0; i < 4; i++) {
    connect(8, i, (i + 1) % 4, projected3d);
    connect(8, i + 4, ((i + 1) % 4) + 4, projected3d);
    connect(8, i, i + 4, projected3d);
  }

  for (int i = 0; i < 8; i++) {
    connect(0, i, i + 8, projected3d);
  }
  
  angle += 0.02;
}

void connect(int offset, int i, int j, P4Vector[] points) {
  strokeWeight(4);
  stroke(255);
  P4Vector a = points[i + offset];
  P4Vector b = points[j + offset];
  line(a.x, a.y, a.z, b.x, b.y, b.z);
}
