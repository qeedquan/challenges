#!/usr/bin/env python3

"""

Write a program that draws a square spiral. You can print out this spiral in ASCII text, but using a graphics library would produce a more pleasant output.

Bonus: Now draw a normal spiral. Some samples of spirals can be found here.

"""

# ported from @prophile solution
class Spiral:
    dirs = {
        (0, 0): False,
        (0, 1): True,
        (1, 0): True,
        (1, 1): True,
    }

    def __init__(self, w, h):
        assert (w - 2) % 4 == 0
        assert (h - 2) % 4 == 0
        assert w == h
        self.w = w
        self.h = h
        if w > 2 and h > 2:
            self.inner = Spiral(w - 4, h - 4)
        else:
            self.inner = None

    def black_at(self, x, y):
        if self.w == 2 and self.h == 2:
            return self.dirs[(x, y)]
        
        if y == self.h - 1:
            return True
        if x == self.w - 1:
            return True
        if y == 0:
            return x > 0
        if x == 0:
            return False
        if y == self.h - 2:
            return False
        if x == self.w - 2:
            return False
        if y == 1:
            return x == 1
        if x == 1:
            return True
        return self.inner.black_at(x - 2, y - 2)

    def draw(self):
        for y in range(self.h):
            for x in range(self.w):
                if self.black_at(x, self.h - y - 1):
                    print('#', end='')
                else:
                    print(' ', end='')
            print('')

def main():
    size = 34
    spiral = Spiral(size, size)
    spiral.draw()

main()

