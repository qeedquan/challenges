#!/usr/bin/env python3

"""

Given consecutive side lengths s1, s2, s3... s_n of an n-gon inscribed in a circle, find its area. You may assume that the polygon exists. In addition, the polygon will be convex and not self-intersecting, which is enough to guarantee uniqueness. Built-ins that specifically solve this challenge, as well as built-in functions that calculate the circumradius or circumcenter, are banned (this is different from a previous version of this challenge).

Input: The side lengths of the cyclic polygon; may be taken as parameters to a function, stdin, etc.

Output: The area of the polygon.

The answer should be accurate to 6 decimal places and must run within 20 seconds on a reasonable laptop.

This is code golf so shortest code wins!

Specific test cases:

[3, 4, 5] --> 6
[3, 4, 6] --> 5.332682251925386
[3, 4, 6, 7] --> 22.44994432064365
[5, 5, 5, 5] --> 25
[6, 6, 6, 6, 6] --> 61.93718642120281
[6.974973020933265, 2.2393294197257387, 5.158285083300981, 1.4845682771595603, 3.5957940796134173] --> 21.958390804292847
[7.353566082457831, 12.271766915518073, 8.453884922273897, 9.879017670784675, 9.493366404245332, 1.2050010402321778] --> 162.27641678140589

Test case generator:

function randPolygon(n) {
  var left = 2 * Math.PI;
  var angles = [];
  for (var i = 0; i < n - 1; ++i) {
    var r = Math.random() * left;
    angles.push(r);
    left -= r;
  }
  angles.push(left);
  var area = 0;
  var radius = 1 + Math.random() * 9;
  for (var i = 0; i < angles.length; ++i) area += radius * radius * Math.sin(angles[i]) / 2;
  var sideLens = angles.map(function(a) {
    return Math.sin(a / 2) * radius * 2;
  });

  document.querySelector("#radius").innerHTML = radius;
  document.querySelector("#angles").innerHTML = "[" + angles.join(", ") + "]";
  document.querySelector("#inp").innerHTML = "[" + sideLens.join(", ") + "]";
  document.querySelector("#out").innerHTML = area;

  draw(angles);
}

function draw(angles) {
  var canv = document.querySelector("#diagram"),
    ctx = canv.getContext("2d");
  var size = canv.width
  ctx.clearRect(0, 0, size, size);
  ctx.beginPath();
  ctx.arc(size / 2, size / 2, size / 2, 0, 2 * Math.PI, true);
  ctx.stroke();
  ctx.beginPath();
  ctx.moveTo(size, size / 2);
  var runningTotal = 0;
  for (var i = 0; i < angles.length; ++i) {
    runningTotal += angles[i];
    var x = Math.cos(runningTotal) * size / 2 + size / 2;
    var y = Math.sin(runningTotal) * size / 2 + size / 2;
    ctx.lineTo(x, y);
  }
  ctx.stroke();
}
document.querySelector("#gen").onclick = function() {
  randPolygon(parseInt(document.querySelector("#sideLens").value, 10));
}
<div id="hints">
  <p><strong>These are to help you; they are not part of the input or output.</strong>
  </p>
  Circumradius:
  <pre id="radius"></pre>
  Angles, in radians, of each sector (this are NOT the angles of the polygon):
  <pre id="angles"></pre>
</div>
<hr>
<div id="output">
  Input:
  <pre id="inp"></pre>
  Output:
  <pre id="out"></pre>
</div>
<hr>
<div id="draw">
  Diagram:
  <br />
  <canvas id="diagram" width="200" height="200" style="border:1px solid black"></canvas>
</div>

Number of side lengths:
<input type="number" id="sideLens" step="1" min="3" value="3" />
<br />
<button id="gen">Generate test case</button>

"""

from math import *

def segment_angles(line_segments, invd):
    return [2*asin(c*invd) for c in line_segments]

# ported from @orlp solution
def cyclic_ngon_area(line_segments):
    line_segments = list(sorted(line_segments))
    lo, hi = 0, 1/max(line_segments)
    while hi - lo > 2e-16:
        mid = (lo + hi) / 2
        angles = segment_angles(line_segments[:-1], mid)
        angles.append(2*pi - sum(angles))
        if sin(angles[-1]/2) / mid > line_segments[-1]:
            lo = mid
        else:
            hi = mid
    return sum([sin(a)/(lo*lo*8) for a in angles])

def test(line_segments, expected, eps=1e-9):
    area = cyclic_ngon_area(line_segments)
    print(area)
    assert(abs(area - expected) < eps)

def main():
    test([3, 4, 5], 6)
    test([3, 4, 6], 5.332682251925386)
    test([3, 4, 6, 7], 22.44994432064365)
    test([5, 5, 5, 5], 25)
    test([6, 6, 6, 6, 6], 61.93718642120281)
    test([6.974973020933265, 2.2393294197257387, 5.158285083300981, 1.4845682771595603, 3.5957940796134173], 21.958390804292847)
    test([7.353566082457831, 12.271766915518073, 8.453884922273897, 9.879017670784675, 9.493366404245332, 1.2050010402321778], 162.27641678140589) 
    test([0.25, 0.25, 0.499999], 0.000125)
    test([1000000, 1000000, 1999999], 1999999*sqrt(3999999)/4, eps=230)

main()
