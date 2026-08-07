fn main() {
    mandelbrot(
        &[' ', '#', '$', '&', '/', '|', '[', ']', '+', ';', ':', '-', '.', ' '],
        -1.2,
        1.2,
        0.1,
        -2.0,
        1.0,
        0.05,
    );

    mandelbrot(
        &[' ', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'A', 'B', ' '],
        -1.2,
        -0.8,
        0.02,
        -0.5,
        0.5,
        0.02,
    );
}

fn mandelbrot(chars: &[char; 14], y0: f64, y1: f64, dy: f64, x0: f64, x1: f64, dx: f64) {
    let mut y = y0;
    while y <= y1 {
        let mut x = x0;
        while x <= x1 {
            let mut za = 0.0;
            let mut zb = 0.0;
            let ca = x;
            let cb = y;
            let mut i = 0;
            for _ in 0..12 {
                let ta = (za * za) - (zb * zb);
                let tb = 2.0 * za * zb;
                za = ta + ca;
                zb = tb + cb;
                if (za * za) + (zb * zb) > 4.0 {
                    break;
                }
                i += 1;
            }
            print!("{}", chars[i + 1]);
            x += dx;
        }
        y += dy;
        println!();
    }
    println!();
}
