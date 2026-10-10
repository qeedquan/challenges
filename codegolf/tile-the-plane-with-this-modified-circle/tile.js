/*

Take a unit circle centered on the origin.
In any two neighboring quadrants, mirror the curve of the circle across the lines connecting the circle's x and y intercepts.

With the resulting shape, you can tile the plane:

https://i.sstatic.net/TmwIX.png

I made this image with the awesome 2D physics sandbox Algodoo!

Write a program that outputs an image similar to this one in some common lossless image file format. You may save the image as a file with the name of your choice or you may simply display it. No input should be taken.

Rules:

The entire image must be tessellated with the modified-circle tiles using any two visually distinct RGB colors: one for the vertically pointing tiles, one for the horizontally pointing tiles.

The radius of the circle tiles should be at least 32 pixels. (The radius in the image above is about 110 pixels.)

The image should be at least 4 tiles wide and 4 tiles tall. This, combined with the rule above, means that images can have a minimum size of 256×256 pixels. (The image above is 4 tiles by 4 tiles.)

The tessellation may be translated by any amount. For example, the top left corner of the image does not need to be the vertex where tiles meet. (The tessellation should not be rotated, however.)

You may use external graphics libraries that have commands for drawing circles and outputting images and the like.

The curves really should approximate circles, as can done with the midpoint circle algorithm, which most graphics libraries will do for you.

Anti-aliasing around the edges of the tiles is allowed but not required.

The shortest submission in bytes wins.

*/

// Ported from @edc65 solution
function render(radius) {
    let canvas = document.getElementById("canvas");
    canvas.width = 9 * radius;
    canvas.height = 9 * radius;
    
    let ctx = canvas.getContext('2d');
    ctx.fillStyle = '#c79360';
    ctx.fillRect(0, 0, canvas.width, canvas.height);

    let sign = 1;
    for (let i = 0; i < 45; i += (i & 7) ? 1 : 2) {
        let x = 2 * radius * ((i % 8) - 2);
        let y = 2 * radius * (i >> 3);
        let xr = radius;
        let yr = sign * radius;
        let ccw1 = sign < 0;
        let ccw2 = sign > 0;
        ctx.moveTo(x, y + yr);
        ctx.arc(x + xr, y + yr, radius, Math.PI, -sign * Math.PI / 2, ccw1);
        ctx.arc(x, y, radius, 0, Math.PI, ccw2);
        ctx.arc(x - xr, y + yr, radius, -sign * Math.PI / 2, 0, ccw1);
        sign = -sign;
    }
    ctx.fillStyle = '#7f5125';
    ctx.fill();
}

render(100);

