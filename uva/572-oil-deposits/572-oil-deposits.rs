type Map = Vec<Vec<char>>;

fn main() {
    assert_eq!(solve(&mut vec![vec!['*']]), 0);
    assert_eq!(
        solve(&mut vec![
            vec!['*', '@', '*', '@', '*'],
            vec!['*', '*', '@', '*', '*'],
            vec!['*', '@', '*', '@', '*'],
        ]),
        1
    );

    assert_eq!(
        solve(&mut vec![vec!['@', '@', '*', '*', '*', '*', '@', '*']]),
        2
    );

    assert_eq!(
        solve(&mut vec![
            vec!['*', '*', '*', '*', '@'],
            vec!['*', '@', '@', '*', '@'],
            vec!['*', '@', '*', '*', '@'],
            vec!['@', '@', '@', '*', '@'],
            vec!['@', '@', '*', '*', '@'],
        ]),
        2
    );
}

fn solve(map: &mut Map) -> usize {
    if map.len() == 0 || map[0].len() == 0 {
        return 0;
    }

    let h = map.len();
    let w = map[0].len();
    let mut c = 0;
    for y in 0..h {
        for x in 0..w {
            if mark(map, x, y, w, h) {
                c += 1;
            }
        }
    }
    c
}

fn mark(map: &mut Map, x: usize, y: usize, w: usize, h: usize) -> bool {
    if map[y][x] == '*' {
        return false;
    }
    map[y][x] = '*';

    for dx in -1..=1 {
        for dy in -1..=1 {
            let nx = (x as isize) + dx;
            let ny = (y as isize) + dy;
            if nx < 0 || ny < 0 {
                continue;
            }

            let nx = nx as usize;
            let ny = ny as usize;
            if nx >= w || ny >= h {
                continue;
            }

            mark(map, nx, ny, w, h);
        }
    }
    return true;
}
