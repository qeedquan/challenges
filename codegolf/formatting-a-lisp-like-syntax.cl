; Background
; (Based on a true, heart-wrenching story)
;
; In my time, I've played around with Lisp and similar languages often. I've written with them, ran them, interpreted them, designed them, and made machines write with them for me... And if there is one thing that bothers me, it's seeing Lisp that does not comply with my specific formatting style.
;
; Unfortunately, some text editors (cough XCode cough) tend to strip my beautiful tabs and spaces whenever code is copied and pasted... Take this beautifully spaced Lisp-like syntax:
;
; (A
;     (B
;         (C)
;         (D))
;     (E))
; (Where ABCDE are arbitrary functions)
;
; SOME text editors butcher this lovely code to the following end:
;
; (A
; (B
; (C)
; (D))
; (E))
; What a mess! That's not readable!
;
; Help me out, here?
;
; The Challenge
; Your goal in this challenge is to take a series of functions separated by newlines in a format described below and return a more beautiful arrangement that highlights readability and elegance.
;
; The Input
; We define a function F of arity N arguments as a construct similar to the following:
;
; (F (G1 ...) (G2 ...) (G3 ...) ... (GN ...))
; where G1, G2, ..., GN are all functions in and of themselves. An arity 0 function A is simply (A), while an arity 2 function B is of the form (B (...) (...))
;
; Your code should take input as a series of functions with a single newline before every function's leading parenthesis (except for the first function). The example above is valid input.
;
; You may assume:
;
; The parentheses are balanced.
; A function will never have to be indented more than 250 times.
; EVERY function is surrounded by parentheses: ()
; A function's name will only contain printable ASCII characters.
; A function's name will never contain parentheses or spaces.
; There is an optional trailing newline on input.
; The Output
; Your code should output the same set of functions, where the only changes made are the additions of spaces or tabs before the leading parentheses of functions. Output should comply with the following rules:
;
; The first function (and later top-level functions) given should have no preceding spaces
; An argument to a function's horizontal location is exactly one tab to the right of that function's horizontal location.
; A tab is implementation-defined, but must be at least 3 spaces.
; You may optionally print a maximum of two spaces after each line.
; Rules
; This is code-golf: the shortest code wins!
; Standard Loopholes are disallowed.
; Examples
; Input:
;
; (A
; (B
; (C)
; (D))
; (E))
; Output:
;
; (A
;     (B
;         (C)
;         (D))
;     (E))
; Input:
;
; (!@#$%^&*
; (asdfghjklm
; (this_string_is_particularly_long
; (...))
; (123456789)))
; (THIS_IS_TOP_LEVEL_AGAIN
; (HERE'S_AN_ARGUMENT))
; Output:
;
; (!@#$%^&*
;     (asdfghjklm
;         (this_string_is_particularly_long
;             (...))
;         (123456789)))
; (THIS_IS_TOP_LEVEL_AGAIN
;     (HERE'S_AN_ARGUMENT))
; Input:
;
; (-:0
; (*:0
; (%:0
; (Arg:6)
; (Write:0
; (Read:0
; (Arg:30))
; (Write:0
; (Const:-6)
; (Arg:10))))
; (%:0
; (Const:9)
; (/:0
; (Const:-13)
; (%:0
; (Arg:14)
; (Arg:0)))))
; (WriteArg:22
; (-:0
; (Const:45)
; (?:0
; (Arg:3)
; (Arg:22)
; (Arg:0)))))
; Output:
;
; (-:0
;     (*:0
;         (%:0
;             (Arg:6)
;             (Write:0
;                 (Read:0
;                     (Arg:30))
;                 (Write:0
;                     (Const:-6)
;                     (Arg:10))))
;         (%:0
;             (Const:9)
;             (/:0
;                 (Const:-13)
;                 (%:0
;                     (Arg:14)
;                     (Arg:0)))))
;     (WriteArg:22
;         (-:0
;             (Const:45)
;             (?:0
;                 (Arg:3)
;                 (Arg:22)
;                 (Arg:0)))))

; Ported from @coredump solution
; Approach
; Instead of doing like everybody else and count parentheses by hand, let's invoke the Lisp reader and do it The Right Way :-)
;
; Read from input stream and write to a temporary output stream.
; While doing so, aggregate characters different from (, ) or whitespace as strings.
; The intermediate output is used to build a string, which contains syntactically well-formed Common-Lisp forms: nested lists of strings.
; Using that string as an input stream, call the standard read function to build actual lists.
; Call p on each of those lists, which recursively write them to the standard output with the requested format. In particular, strings are printed unquoted.
; As a consequence of this approach:
;
; There are less restrictions on the input format: you can read arbitrarly formatted inputs, not just "one function per line" (ugh).
; Also, if the input is not well-formed, an error will be signaled.
; Finally, the pretty-printing function is well decoupled from parsing: you can easily switch to another way of pretty-printing S-expressions (and you should, if you value your vertical space).
(labels ((p (x d)
           (or
            (when (listp x)
              (princ #\()
              (p (car x) d)
              (incf d)
              (dolist (a (cdr x)) (format t "~%~v{  ~}" d '(t)) (p a d))
              (princ #\)))
            (princ x))))
  (let ((i
         (make-string-input-stream
          (with-output-to-string (o)
            (ignore-errors
             (do (b
                  c)
                 (nil)
               (if (member (setq c (read-char)) '(#\( #\) #\  #\tab #\newline)
                           :test 'char=)
                   (progn
                    (when b (prin1 (coerce (reverse b) 'string) o))
                    (princ c o)
                    (setq b nil))
                   (push c b))))))))
    (ignore-errors (do () (nil) (p (read i) 0) (terpri)))))
