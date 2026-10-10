; Flavius Josephus was a roman historian of Jewish origin. During the Jewish-Roman wars of the first century AD, he was in a cave with fellow soldiers, 41 men in all, surrounded by enemy Roman troops. They decided to commit suicide by standing in a ring and counting off each third man. Each man so designated was to commit suicide. (When the count came back around the ring, soldiers who had already committed suicide were skipped in the counting.) Josephus, not wanting to die, placed himself in position #31, which was the last position to be chosen.
;
; In the general version of the problem, there are n soldiers numbered from 1 to n and each k-th soldier will be eliminated. The count starts from the first soldier. Write a function to find, given n and k, the number of the last survivor. For example, josephus(41, 3) = 31. Find josephus(123456789101112, 13).
;
; Thanks to user zebuilin for suggesting this problem in r/dailyprogrammer_ideas!

; Ported from @skeeto solution
(defun josephus (n k &optional (a 0) (b 1))
  (let ((q (min (max (floor (- (+ b k) a 2) (1- k)) 1) (- n b))))
    (if (>= b n)
        (1+ a)
        (josephus n k (mod (+ a (* k q)) (+ b q)) (+ b q)))))

(print (josephus 41 3))
(print (josephus 123456789101112 13))
