; Write a program that will print the english name of a value. for example, "1211" would become "one-thousand, two hundred, eleven".
; for extra credit, allow it to read the english value of a number and output the integer.
; input: one-hundred, four output: 104

(defun spellout (n)
  (format t "~R~%" n))

(spellout 1211)
(spellout 9999)
(spellout 104)
(spellout 565)

