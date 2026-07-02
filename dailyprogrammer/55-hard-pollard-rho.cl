;
; Write a program to implement the Pollard's rho algorithm using both, Floyd’s cycle-finding algorithm and Brent’s cycle-finding algorithm ..
;
; Bonus: also compare the timings for the implementation of both the algorithms and come up stating whichever is the fastest.

; ported from @wicked-canid solution
(defun make-random (mod &optional (random-constant 1))
  (lambda (x)
    (mod (+ random-constant
            (* x x))
         mod)))

(defun pollard-floyd (n &optional (random-constant 1))
  (let ((next-random (make-random n random-constant)))
    (do* ((x 2 (funcall next-random x))
          (y 2 (funcall next-random (funcall next-random y)))
          (d 1 (gcd (- x y) n)))
        ((/= d 1) (if (= d n) nil d)))))

(defun pollard-brent (n &optional (random-constant 1))
  (let ((next-random (make-random n random-constant)))
    (do ((x 2 (if (= power lambda) y x))
         (y (funcall next-random 2) (funcall next-random y))
         (lambda 1 (if (= power lambda) 1 (1+ lambda)))
         (power 1 (if (= power lambda) (* 2 power) power))
         (d 1 (gcd (- x y) n)))
        ((/= d 1) (if (= d n) nil d)))))

(defun test (pollard start end)
  (loop for n from start below end
        for factor = (funcall pollard n)
        if (null factor)
          count 1 into fails
        else
          do (assert (zerop (mod n factor)))
        end
        finally (format t "The algorithm failed in ~f% of cases."
                        (* 100 (/ fails (- end start))))))

(time (test #'pollard-floyd 100000 200000))
(time (test #'pollard-brent 100000 200000))
