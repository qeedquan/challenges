fn main() {
    poly([-1, 1, 0, -333, 22, 1, 0, 0, 0]);
    poly([0, 5, -55, 0, 0, 0, 0, 0, 0]);
}

fn poly(mut p: [isize; 9]) {
    let mut f = true;
    for i in (0..p.len()).rev() {
        if p[i] != 0 {
            if f {
                f = false;
            } else {
                if p[i] > 0 {
                    print!(" + ");
                } else {
                    print!(" - ");
                    p[i] = -p[i];
                }
            }

            if i > 0 && p[i] == -1 {
                print!("-");
            } else if i == 0 || p[i] != 1 {
                print!("{}", p[i]);
            }

            if i != 0 {
                print!("x");
                if i > 1 {
                    print!("^{}", i);
                }
            }
        } else if f && i == 0 {
            print!("0");
        }
    }
    println!();
}
