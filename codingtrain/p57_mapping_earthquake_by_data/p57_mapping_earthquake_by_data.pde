/*

https://en.wikipedia.org/wiki/Earthquake

*/

PImage worldmap;
String[] earthquakes;
float clon;
float clat;
float zoom;

void setup() {
  worldmap = loadImage("worldmap.png");
  earthquakes = loadStrings("all_month.csv");
  zoom = 1;
  clon = 0;
  clat = 0;
 
  size(1024, 512);
  translate(width/2, height/2);
  imageMode(CENTER);
  image(worldmap, 0, 0);

  var cx = mercX(clon);
  var cy = mercY(clat);

  for (var i = 1; i < earthquakes.length; i++) {
    var data = earthquakes[i].split(",(?=([^\"]|\"[^\"]*\")*$)");
    var lat = readFloat(data[1]);
    var lon = readFloat(data[2]);
    var mag = readFloat(data[4]);
    var x = mercX(lon) - cx;
    var y = mercY(lat) - cy;
    // This addition fixes the case where the longitude is non-zero and points can go off the screen.
    if (x < -width / 2) {
      x += width;
    } else if (x > width / 2) {
      x -= width;
    }
    mag = pow(10, mag);
    mag = sqrt(mag);
    var magmax = sqrt(pow(10, 10));
    var d = map(mag, 0, magmax, 0, 180);
    stroke(255, 0, 255);
    fill(255, 0, 255, 200);
    circle(x, y, d);
  }
}

float readFloat(String data) {
  try {
    return Float.parseFloat(data);
  } catch (Exception e) {
    return 0;
  }
}

float mercX(float lon) {
  lon = radians(lon);
  var a = (256 / PI) * pow(2, zoom);
  var b = lon + PI;
  return a * b;
}

float mercY(float lat) {
  lat = radians(lat);
  var a = (256 / PI) * pow(2, zoom);
  var b = tan(PI / 4 + lat / 2);
  var c = PI - log(b);
  return a * c;
}
