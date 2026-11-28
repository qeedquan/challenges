; Your task is to draw the mandelbrot set in ascii. It should look something like
;
; https://i.sstatic.net/GPzpD.png
;
; The complex number c lies in the mandelbrot set, when the sequence z(n+1) = z(n)^2 + c, z(0) = 0 remains bounded. For the purpose of this challenge you can consider the sequence bounded for c if |z(32)| < 2.
;
; Plot the mandelbrot set on the complex plane from (-2 - i) to (1 + i), and a minimum resolution of 40x30, using ascii characters in your favourite language, using as few characters as possible.

; Ported from @stackman solution
(loop for y from -1 to 1 by 1/15 do
  (loop for x from -2 to 1 by .04 do
    (let*((c 126) (z (complex x y)) (a z))
      (loop while (< (abs (setq z (+ (* z z) a))) 2)
            while (> (decf c) 32))
      (princ (code-char c))))
  (terpri))
