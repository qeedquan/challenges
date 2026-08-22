; Reverse Polish notation (RPN) is a mathematical notation in which every operator follows all of its operands. This notation is also known as postfix notation and does not require any parentheses as long as each operator has a fixed number of operands.
;
; For example:
;
; The expression 2+4 in RPN is written as 2 4+
;
; The expression 2∗4+8 in RPN is written as 2 4∗8+
;
; The expression 2∗(4+8) in RPN is written as 2 4 8+∗
;
; Evaluate the value of an arithmetic expression written in Reverse Polish Notation. The valid operators are +, −, ∗, / only. The division operator / performs integer division (14 / 3=4). Each operand may be either an integer or another expression.
;
; Input
; One line contains the expression written in Reverse Polish notation. The length of the expression does not exceed 100 characters.
;
; Output
; Print the value of the expression given in Reverse Polish notation.
;
; Examples
;
; Input #1
; 2 4 * 8 +
;
; Answer #1
; 16
;
; Input #2
; 2 4 8 + *
;
; Answer #2
; 24
;
; Input #3
; 3 2 * 11 -
;
; Answer #3
; -5

(defun evaluate-rpn (tokens)
  (let ((stack '()))
    (dolist (token tokens (car stack))
      (cond
        ((member token '(+ - * /))
         (let* ((b (pop stack))
                (a (pop stack)))
           (push (funcall token a b) stack)))
        ((numberp token)
         (push token stack))
        (t (error "Unknown token: ~A" token))))))

(print (evaluate-rpn '(2 4 * 8 +)))
(print (evaluate-rpn '(2 4 8 + * )))
(print (evaluate-rpn '(3 2 * 11 -)))
