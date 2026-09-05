/*

Welcome to Canvas Fun ;-) In this series, we'll be learning how to draw the image on a canvas.

Task
Given some points, your task is to draw lines between two adjacent points.

points is given by a 2D integer array. Each subarray has two elements, means the x-coordinate, y-coordinate of each point.

The basic canvas(width 100 x height 100), background color(white) and pen's color(red) are already defined in the initial code(please don't delete or modify them).

You just need to draw the lines, using the following two methods:

moveTo(x,y)
Set the current coordinate to (x, y).

lineTo(x, y)
Draw a line from current coordinate to the target coordinate (x,y).

Note: After lineTo operation, the current coordinate became to (x,y). You don't need use moveTo(x,y) to reset the current coordinate.

Example
For points = [[0,0],[99,99]], the output image should be:

data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAGQAAABkCAYAAABw4pVUAAAABmJLR0QA/wD/AP+gvaeTAAACQUlEQVR4nO3RuVEFQQwA0WZjIALSwCMICpfw8KCwSeAHQSqLAxTHP/aYQzPTbUmyVPWu5uvrmacnuLvD6jfx/Az39/D6WvsXAyZub+HlBR4fRQnQBCBKnKbvSZQQTb82Uao3/buIUrX/ICBKxY6DgCiVOg0ColToPAiIUrjLICBKwZaBgCiFWg4CohRoHQiIkrn1ICBKxraBgCiZ2g4ComRoHwiIkrj9ICBKwtKAgCiJSgcCoiQoLQiIsrP0ICDKjvKAgCgbywcComwoLwiIsrL8ICDKisqAgCgLKwcCoiyoLAiIcqHyICDKmeqAgCgnqgcCohypLgiI8qf6ICDKj2KAgCifxQEBUYgGAsOjxAOBoVFigsCwKHFBYEiU2CAwHEp8EBgKpQ0QGAalHRAYAqUtEOgepT0Q6BqlTRDoFqVdEOgSpW0Q6A6lfRDoCqUPEOgGpR8Q6AKlLxBoHqU/EGgapU8QaBalXxBoEqVvEGgOpX8QaAplDBBoBmUcEGgCZSwQCI8yHgiERhkTBMKijAsCIVHGBoFwKIJAKBRBvgqCIsjPAqAI8rfKKIIcqyKKIKeqhCLIuSqgCHKpwiiCLKkgiiBLK4QiyJoKoAiytswogmwpI4ogW8uEIsieMqAIsrfEKIKkKCGKIKlKhCJIyhKgCJK6nSiC5GgHiiC52ogiSM42oAiSu5UogpRoBYogpVqIIkjJFqAIUroLKILU6AyKILU6gSJIzY6gXM3zPFd+y97e4OEBDgdBwvT+Djc3fAAwbZX5JkK08AAAAABJRU5ErkJggg==

You just need draw a line from (0,0) to (99,99)

For points = [[20,20],[80,20],[80,80],[20,80],[20,20]], the output image should be:

data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAGQAAABkCAYAAABw4pVUAAAABmJLR0QA/wD/AP+gvaeTAAABQ0lEQVR4nO3dMWrEMBBA0dmQg/loPppu5i1SpZ+QB/sfuBUSH6Fu/Hqe55kwvv57A/mtIJiCYAqCKQimIJiCYAqCKQimIJiCYAqCKQimIJiCYAqCKQimIJjv9RXve31J2nX9fEt2b8h9z5yzuiTtnPXz7t+Q6/qcW/IH5+wNwRQEUxBMQTAFwRQEUxBMQTAFwRQEUxBMQTAFwRQEUxBMQTAFwRQEUxBMQTAFwRQEUxBMQTAFwRQEUxBMQTAFwRQEUxBMQTAFwRQEUxBMQTAFwRQEUxBMQTAFwRQEUxBMQTAFwRQEUxBMQTAFwRQEUxBMQTAFwRQEUxBMQTAFwexPtj7ncyZbn7M6931mO8jy5njLg/hnZl794N7SG4IpCKYgmIJgCoIpCKYgmIJgCoIpCKYgmIJgCoIpCKYgmIJgCoIpCOYNCHkYxxmeBQcAAAAASUVORK5CYII=


You need draw four lines for each two adjacent points:

from (20,20) to (80,20)
from (80,20) to (80,80)
from (80,80) to (20,80)
from (20,80) to (20,20)

For points = [[50,10],[20,80],[80,80],[50,10]], the output image should be:

data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAGQAAABkCAYAAABw4pVUAAAABmJLR0QA/wD/AP+gvaeTAAAEH0lEQVR4nO2du04qURSGf8ixp9JWo43iS1hoI50Re0sTnkahECx8AMFoqfEFwEYjlbfGC1Y0aiIFp9iZnGNknYizL/+as7+EAjDDNt+s2Z/GibnhcDhEhIZ86AVEPhOFkBGFkBGFkBGFkBGFkBGFkBGFkJENIa+v5pEBcpn4SX1pCcjlgLOz0CtJjf4JubgA7u+B21vg8jL0alKjf0I2N4HFRWA4BLpdYG8v9IpSoVvIywuwsABcX5vnc3NGyuRk2HWlQPclq9EAymWgUDCP9fU4IcEYDICZGeDkBJifN691u8DKCnB3B0xMhF3fD9E7Ia2WuVwlMoA/zw8Pw60rJXqFbG8DlcrX1ysV855SdArpdICnJ2B19et7pRLw8ACcn/tflwV0CqnVgK0tID9i+fm8ea9W878uC+jb1Hs9oFg0qVsojP6afl9tAuubkL9TVyJJ4EbD37osoWtCRqWuhNIE1jUho1JXQmkC6xIipa6EwgTWI+RfqSuRJHCn425dltEjpFqVU1dCYQLr2NS/k7oSyhJYx4R8J3UllCUw/4SMk7oSihKYf0LGSV0JRQnML2Tc1JVQksDcQn6SuhJKEphbyE9SV0JJAvNu6mlSV0JBAvNOSJrUlVCQwJwTYiN1JcgTmHNCms30qSuRHLfVsn9sC3AKsZW6EsQJzCek0wGen+2krkSpBDw+UiYwnxCbqStBnMBcm7qL1JVIEvjqCpiacvtZY8A1IS5SV4L0b4F5JsRl6koQJjDPhLhMXQnCBOYR4jp1JcgSmEOIj9SVIEtgDiE+UleCLIHDb+o+U1eCKIHDT0i97i91JYh+Cxx2QgYDYHoaOD31W1ejIEngsBPSbJrLVWgZAE0ChxUSKnUlCBI4nJB2O1zqShAkcDghIVNXIkngajXYEsJs6gypKxE4gcOcngypKxE4gf1PCFPqSgRMYP8TwpS6EgET2L8QttSVCJTAfoUwpq5EoAT2K4QxdSUCJbC/Tb3XM9fmmxvOuhpFvw/MzppN3lMC+ztV63VgY0OPDMCstVz2msB+JkRD6kp4TmA/E3JwwJ+6EkkCN5tePs6PEC2pK+Exgd0LabfNhq4hdSVKJXNrnYcEdi9EU+pKeExgt5u6xtSV8JTAbk9bjakr4SmB3U2I5tSV8JDA7iZEc+pKeEhgd0K0p66E4wR2IyQLqSuRJHC77eTwboTs7OhPXQnHCWx/U89S6ko4TGD7p/DubnZSVyJJ4Hrd+qHtTsjHh7ktLUupK9HtAsvL5t8tWUzgX9aOBABHR8D7O7C/b/WwtLy9me95bc3aIe1OyPGxOXP+J4pFU16WCH/DTuQTGexS3UQhZEQhZEQhZEQhZEQhZEQhZEQhZEQhZEQhZEQhZEQhZEQhZEQhZEQhZEQhZEQhZEQhZPwGc4f97TcHo7oAAAAASUVORK5CYII=

*/

const { createCanvas } = require('canvas');

function drawLines(points) {
	var canvas = createCanvas(100, 100);
	var ctx = canvas.getContext('2d');
	ctx.fillStyle = '#ffffff';
	ctx.fillRect(0, 0, 100, 100);
	ctx.strokeStyle = '#ff0000';
	ctx.beginPath();
	
	points.forEach((p, i) => (i ? ctx.lineTo(p[0], p[1]) : ctx.moveTo(p[0], p[1])));
	
	ctx.stroke();
	return canvas.toDataURL();
}

console.log(drawLines([[50, 10], [20, 80], [80, 80], [50, 10]]));

