(defun pizza (n)
  (+ (floor (* n (+ n 1)) 2) 1))

(assert (= (pizza 5) 16))
(assert (= (pizza 10) 56))
