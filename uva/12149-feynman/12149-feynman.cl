(defun squares (n)
  (floor (* n (+ n 1) (+ (* 2 n) 1)) 6))

(assert (= (squares 2) 5))
(assert (= (squares 1) 1))
(assert (= (squares 8) 204))
