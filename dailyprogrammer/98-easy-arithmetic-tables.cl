; Write a program that reads two arguments from the command line:
;
; a symbol, +, -, *, or /
;
; a natural number n (≥ 0)
;
; And uses them to output a nice table for the operation from 0 to n, like this (for "+ 4"):
;
; +  |  0  1  2  3  4
; -------------------
; 0  |  0  1  2  3  4 
; 1  |  1  2  3  4  5
; 2  |  2  3  4  5  6
; 3  |  3  4  5  6  7
; 4  |  4  5  6  7  8
; If you want, you can format your output using the reddit table syntax:
;
; |+|0|1
; |:|:|:
; |**0**|0|1
; |**1**|1|2
; Becomes this:
;
; |+|0|1 |:|:|: |0|0|1 |1|1|2

(defun table (op size)
  (format t "|~s" op)
  (dotimes (x (+ 1 size)) (format t "|~d" x))
  (terpri)
  (dotimes (x (+ 2 size)) (princ "|:"))
  (terpri)
  (dotimes (y (1+ size))
    (format t "|**~d**" y)
    (dotimes (x (1+ size)) (format t "|~s" (funcall op x y)))
    (terpri))
  (terpri))

(table '+ 1)
(table '* 4)
