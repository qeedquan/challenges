; Welcome to cipher day!
;
; Create a program that can take a piece of text and encrypt it with an alphabetical substitution cipher. This can ignore white space, numbers, and symbols.
;
; for extra credit, make it encrypt whitespace, numbers, and symbols!
;
; for extra extra credit, decode someone elses cipher!

(defun rot(x n)
  (map 'list
	   #'(lambda (c)
		   (let ((nc (char-code c)))
			 (cond 
			   ((and (>= nc 65) (<= nc 90))
				(if (>= nc (- 90 n))
				  (- nc (- n 1))
				  (+ nc n)))
			   ((and (>= nc 97) (<= nc 122))
				(if (>= nc (- 122 n))
				  (- nc (- n 1))
				  (+ nc n)))
			   (t nc))))
	   x))

(defun encode(x n)
  (map 'string #'(lambda (c) (code-char c)) (rot x n)))

(print (encode "hello" 13))
(print (encode "abc" 1))
