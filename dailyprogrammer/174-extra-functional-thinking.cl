; I'm trying a new bonus challenge today with any theme I can think of, such as rewriting an existing solution using a different paradigm or with a limitation on how you can write it.
; I'm going to see how this is received and may or may not make this a recurring thing.
; I will be writing these to primarily be a learning exercise - both for me and for you, the readers of r/DailyProgrammer -
; so if you are interested in learning about new languages, new ways of writing solutions or modern programming in general then this may be of interest for you.
; For today, though, you are to rewrite a solution (that you've wrote) to any previous challenge (and as many as you want to), in a functional programming language.
;
; If you're new to functional programming languages, like I am, it's a paradigm of programming that treats a program as an evaluation of functions only, avoiding variables.
; Everything is treated as a function, and programs written in such a language are designed and look substantially different to one written in an imperative language such as Python, Java or Ruby.
; There are a boat load of languages you can choose from. One of the popular ones on r/DailyProgrammer is Haskell.
; There is the Lisp family (including Common Lisp, Scheme. R is also debatably a functional language, or at least can be used as one.
; There are others too. Pick one you like and rewrite one of your existing solutions in it. Do you use Haskell or something already? Rewrite it in a new functional language! They're all different in some way or another.
;
; I'm trying to learn Clojure at the moment myself so I'll be submitting some of my own solutions.
;
; Post Format
; When you post your solution, please give the name (and the link) to the challenge which the solution is for.

; @lukz
; Interpreter of a brainfuck interpreter

(defparameter *bf-prg* (format () "~a~a"
  "++++++++[>++++[>++>+++>+++>+<<<<-]>+>+>->>+[<]<-]"
  ">>.>---.+++++++..+++.>>.<-.<.+++.------.--------.>>+.>++."))

(defparameter *bf-in*
  "")

(defparameter *prg* '(
  "(loop"
  "  (if (= c \\>) (PInc))"
  "  (if (= c \\<) (PDec))"
  "  (if (= c \\+) (Inc))"
  "  (if (= c \\-) (Dec))"
  "  (if (= c \\.) (Out))"
  "  (if (= c \\,) (In))"
  "  (if (= c \\[) (Test))"
  "  (if (= c \\]) (End)))"))

(defun main (&aux (p 0) (ip 0) (input -1) is-loop c
                  (d (make-array 30000 :initial-element 0))
                  (jump (make-array (length *bf-prg*))) s)
  (dotimes (i (length *bf-prg*))
    (if (eql #\[ (elt *bf-prg* i)) (push i s)
      (when (eql #\] (elt *bf-prg* i))
        (setf (elt jump (car s)) i (elt jump i) (car s)) (pop s))))
  (loop
    (dolist (i *prg*)
      (if (search "loop" i) (setf is-loop 1))
      (if (>= ip (length *bf-prg*)) (return-from main))
      (setf c (elt *bf-prg* ip))
      (cond
        ((and (find c i) (search "PInc" i))
          (incf p) (incf ip))
        ((and (find c i) (search "PDec" i))
          (decf p) (incf ip))
        ((and (find c i) (search "Inc" i))
          (incf (elt d p)) (incf ip))
        ((and (find c i) (search "Dec" i))
          (decf (elt d p)) (incf ip))
        ((and (find c i) (search "Out" i))
          (princ (code-char (elt d p))) (incf ip))
        ((and (find c i) (search "In" i))
          (setf (elt d p) (elt *bf-in* (incf input))) (incf ip))
        ((and (find c i) (search "Test" i))
          (if (= 0 (elt d p)) 
              (setf ip (elt jump ip))
            (incf ip)))
        ((and (find c i) (search "End" i))
          (if (< 0 (elt d p))
              (setf ip (elt jump ip))
            (incf ip))) ))
    (if (not is-loop) (return))))

(main)
