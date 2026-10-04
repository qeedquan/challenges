"

In today's challenge we will be touching the topics:

Strong Pseudoprime

Fermat Pseudoprime

Carmichael Number (for bonus)

Fermat’s primality test consists of choosing many numbers and checking if they are witnesses to the compositeness of the number being tested.

There are some composite numbers which pass Fermat’s primality test for all possible witnesses; they are called Carmichael numbers

Because there exist numbers that fool Fermat’s primality test for all bases, a strong pseudo-primality test is often used

Your tasks are

to write two functions that test if a number is a Fermat pseudo-prime or a strong pseudo-prime to a given base

two functions that test primality using the Fermat and strong pseudo-prime tests.

Bonus:

Write two functions that test if a number is a Carmichael number, and to identify all the Carmichael numbers less than a given input number by the user.

taken from programmingpraxis.com

Request: Please take your time in browsing r/dailyprogrammer_ideas and helping in the correcting and giving suggestions to the problems given by other users. It will really help us in giving quality challenges!

Thank you!

The next challenge will be given on 2nd july, i.e monday :)

"

; ported from @wicked-canid solution

(defun expt-mod (a b m)
  "Compute (MOD (EXPT A B) M) by fast exponentiation."
  (setq a (mod a m))
  (cond ((zerop b) 1)
        ((oddp b)
         (mod (* (expt-mod a (1- b) m)
                 a)
              m))
        ((evenp b)
         (let ((x (expt-mod a (/ b 2) m)))
           (mod (* x x) m)))))

(defun fermat-prime-p (n a)
  (= 1 (expt-mod a (1- n) n)))

(defun strong-prime-p (n a)
  (and (oddp n)
       "Write N-1 = D*2^S with D odd.
       Test whether A^X = N-1 (mod N) for X = D*2^R (0 <= R < S),
       or whether A^D = 1 (mod N)."
       (do ((x (/ (1- n) 2) (/ x 2)))
           ((oddp x) (let ((exp (expt-mod a x n)))
                       (or (= 1 exp) (= -1 exp))))
         (when (= (1- n) (expt-mod a x n))
           (return t)))))

(defun probable-prime-p (n test &key (rounds 5))
  "Test the probable primality of an integer N by repeating ROUNDS times the
   primality test TEST. TEST is a function of N and a base A.
   If N is found to be composite, return NIL and a witness, otherwise return T."
  (do ((rounds rounds (1- rounds))
       (a (random n) (random n)))
      ((zerop rounds) t)
    (when (not (funcall test n a))
      (return (values nil a)))))

(defun carmichaelp (n)
  "Test whether N is a a Carmichael number."
  (and (oddp n)
       (not (primep n))
       (loop for a from 2 below n
          always (or (/= 1 (gcd a n))
                     (fermat-prime-p n a)))))

(defun primep (n)
  "Deterministically determine if N is prime."
  (and (oddp n)
       (loop for d from 3 to (sqrt n) by 2
          never (zerop (mod n d)))))

(defun carmichaels-upto (n)
  (loop for m upto n
     when (carmichaelp m) collect m))

(princ (carmichaels-upto (expt 10 5)))
