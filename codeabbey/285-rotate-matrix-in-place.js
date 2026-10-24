/*

Similar to previous task, but now we want to rotate matrix, i.e. two-dimensional array with equal number of rows and columns. This time "rotation" means just it - turn it 90 degrees clockwise, e.g.:

original:       rotated:

1 2 3 4         d 9 5 1
5 6 7 8         e a 6 2
9 a b c         f b 7 3
d e f g         g c 8 4
really I stuck upon this when preparing Polyomino Generation task

Again this should be written in BASIC, and here is a template code to help in your work:

INPUT n : DIM a(n, n)
FOR i = 0 TO n-1 : FOR j = 0 TO n-1 : INPUT a(i, j) : NEXT j : NEXT i

GOSUB rotate

FOR i = 0 TO n-1
FOR j = 0 TO n-1 : PRINT a(i, j); " "; : NEXT j
PRINT
NEXT i
END

rotate:
REM your wonderful code should be added here
RETURN

*/

function rot90cw(m) {
    let n = m.length;
    for (let i = 0; i < Math.floor(n / 2); i++) {
        for (let j = i; j < n - i - 1; j++) {
            let t = m[i][j];
            m[i][j] = m[n - 1 - j][i];
            m[n - 1 - j][i] = m[n - 1 - i][n - 1 - j];
            m[n - 1 - i][n - 1 - j] = m[j][n - 1 - i];
            m[j][n - 1 - i] = t;
        }
    }
    return m;
}

console.log(rot90cw([['1', '2', '3', '4'], ['5', '6', '7', '8'], ['9', 'a', 'b', 'c'], ['d', 'e', 'f', 'g']]));
