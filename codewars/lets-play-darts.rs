/*

Create your own mechanical dartboard that gives back your score based on the coordinates of your
dart.

## Task

Use the [scoring rules](https://en.wikipedia.org/wiki/Darts#Scoring) for a standard dartboard:
![](https://upload.wikimedia.org/wikipedia/commons/4/42/Dartboard.svg)

Finish method:

```
public String getScore(double x, double y);
```

The coordinates are `(x, y)` are always relative to the center of the board (0, 0). The unit is
millimeters. If you throw your dart 5 centimeters to the left and 3 centimeters below, it is written
as:

```
String score = dartboard.getScore(-50, -30);
```

Possible scores are:

- Outside the board: `"X"`
- Bull's eye: `"DB"`
- Bull: `"SB"`
- A single number, example: `"10"`
- A triple number: `"T10"`
- A double number: `"D10"`

A throw that ends exactly on the border of two sections results in a bounce out. You can ignore this
because all the given coordinates of the tests are within the sections.

The diameters of the circles on the dartboard are:

- Bull's eye: `12.70 mm`
- Bull: `31.8 mm`
- Triple ring inner circle: `198 mm`
- Triple ring outer circle: `214 mm`
- Double ring inner circle: `324 mm`
- Double ring outer circle: `340 mm`

*/

use std::f64::consts::PI;

fn main() {
    assert_eq!(getscore(-133.69, -147.38), "X");
    assert_eq!(getscore(4.06, 0.71), "DB");
    assert_eq!(getscore(2.38, -6.06), "SB");
    assert_eq!(getscore(-14.568070690087325, -58.22411710478049), "19");
    assert_eq!(getscore(-5.43, 117.95), "20");
    assert_eq!(getscore(-73.905, -95.94), "7");
    assert_eq!(getscore(55.53, -87.95), "T2");
    assert_eq!(getscore(-145.19, 86.53), "D9");
}

fn getscore(x: f64, y: f64) -> String {
    let tab = vec![
        6, 13, 4, 18, 1, 20, 5, 12, 9, 14, 11, 8, 16, 7, 19, 3, 17, 2, 15, 10,
    ];

    let i = ((6.44026 + f64::atan2(y, x)) % (2.0 * PI)) * PI;
    let p = tab[i as usize];
    let r = f64::hypot(x, y);
    let s: String;
    if r < 6.35 {
        s = format!("DB");
    } else if r < 15.9 {
        s = format!("SB");
    } else if r > 170.0 {
        s = format!("X");
    } else if r > 162.0 {
        s = format!("D{p}");
    } else if r > 99.0 && r < 107.0 {
        s = format!("T{p}");
    } else {
        s = format!("{p}");
    }
    s
}
