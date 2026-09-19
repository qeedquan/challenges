--{
-- A good resolution for 2015 is to live more sustainably. We'll start by recycling. Recycling code, that is!
-- Your task is to print the number 2015 to STDOUT, with or without trailing newline (and only that). However, you have to do so by recycling some old code from PPCG. Here is how that works:
-- Pick any answer posted on CodeGolf.SE before 2014-12-16 00:00:00Z (the day I posted this in the sandbox). Exception: You may not use any answers from last year's New Year's challenge.
-- Choose one code block from that answer (not an inline code snippet, it has to be a on its own paragraph). This block must be advertised as actual code, e.g. you cannot use test cases or example output which happen to use monospace formatting.
-- Rearrange the characters in that code block to form your submission for this challenge. You may only change the order, not add or remove any characters. This includes newlines.
-- You must be able to show that the original source block is syntactically valid in your language.
-- In the best case you can do this by showing that it runs without compile-time or run-time errors.
-- So while the original code may have been Java, you could use it for a Whitespace answer (as every file is valid in Whitespace), but probably can't use it for a Python answer (as the original won't be valid Python syntax).
-- Note that your answer must ignore all input and external state (including the actual current date). It may read from STDIN, say, as long as it doesn't crash if it's empty, and produces the same output for all possible contents of the stream.
--
-- Your resulting code has to be a full program (not a function, nor a snippet which assumes a REPL environment).
--
-- This is code golf, so the shortest answer (in bytes) wins.
--
--}

with Ada.Text_IO;
use Ada.Text_IO;

procedure Main is
begin
   Put_Line("2015");
end Main;
