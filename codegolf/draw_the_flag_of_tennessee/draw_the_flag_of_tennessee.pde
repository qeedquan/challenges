/*

The flag of Tennessee is specified by chapter 498 of the Public Acts of 1905.

An oblong flag or banner in length one and two thirds times its width, the large or principal field of same to be of color red, but said flag or banner ending at its free or outer end in a perpendicular bar of blue, of uniform width, running from side to side; that is to say, from top to bottom of said flag or banner, and separated from the red field by a narrow margin or stripe of white of uniform width; the width of the white stripe to be one-fifth that of the blue bar; and the total width of the bar and stripe together to be equal to one-eighth of the width of the flag.

In the center of the red field shall be a smaller circular field of blue, separated from the surrounding red field by a circular margin or stripe of white of uniform width and of the same width as the straight margin or stripe first mentioned. The breadth or diameter of the circular blue field, exclusive of the white margin, shall be equal to one-half of the width of the flag. Inside the circular blue field shall be three five-pointed stars of white distributed at equal intervals around a point in the center of the blue field and shall be of such size and arrangement that one point of each star shall approach as closely as practicable without actually touching one point of each of the other two around the center point of the field; and the two outer points of each star shall approach as nearly as practicable without actually touching the periphery of the blue field. The arrangement of the three stars shall be such that the centers of no two stars shall be in a line parallel to either the side or end of the flag, but intermediate between same; and the highest star shall be the one nearest the upper confined corner of the flag.

Here is the flag, with annotations for its ratios:

https://i.sstatic.net/fd6bC.png

Your task is to draw this flag in a way that complies with the statute. However, because the statute is ambiguous, you have some wiggle room with what you output. Specifically:

You may use any colors reasonably recognizable as "red", "white", and "blue". (The sample image uses #cc0000, #002d65, and #ffffff.)
The "stars" may have any exterior or interior angles. But all the interior angles must be equal, all the exterior angles must be equal, all edges must be the same length, it must have ten edges and ten vertices, and it must be reasonably recognizable as a five-pointed star.
The stars must be as large as "practicable" so that their points do not touch each other in the center or the white band around the edge of the circle. Between the two points of each star closest to the edge and the edge, and between the points approaching the center of any two stars, there must be at least 1 pixel of space but not more than 1/48 of the length of the flag.
The centers of the three stars may form any equilateral triangle, so long as no side of the triangle is parallel to an edge of the flag, and the vertex closest to the top of the flag is closer to the top left corner than the top right corner.
Shortest code wins.

*/

void setup() {
    size(166, 100);
    flag();
}

void flag() {
    background(#cc0000);
    stroke(255);
    fill(#002d65);
    strokeWeight(2.1);
    circle(77, 50, 50);
    rect(154, -3, 13, 103);
    noStroke();
    fill(255);
    for (int i = 0; i < 3; i++) {
        pushMatrix();
        translate(77, 50);
        rotate(i * 2 * PI / 3);
        star(-5, 12, 4, 11);
        popMatrix();
    }
}

void star(float x, float y, float r1, float r2) {
    float t = TWO_PI / 5;
    beginShape();
    for (float a = 0; a < TWO_PI; a += t) {
        vertex(x + cos(a) * r2, y + sin(a) * r2);
        vertex(x + cos(a + t / 2.0) * r1, y + sin(a + t / 2.0) * r1);
    }
    endShape();
}
