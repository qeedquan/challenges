%{

Today's challenge is simple: Without taking any input, output any valid sudoku board.

In case you are unfamiliar with sudoku, Wikipedia describes what a valid board should look like:

The objective is to fill a 9×9 grid with digits so that each column, each row, and each of the nine 3×3 subgrids that compose the grid (also called "boxes", "blocks", or "regions") contains all of the digits from 1 to 9.

Now here's the thing... There are 6,670,903,752,021,072,936,960 different valid sudoku boards. Some of them may be very difficult to compress and output in fewer bytes. Others of them may be easier. Part of this challenge is to figure out which boards will be most compressible and could be outputted in the fewest bytes.

Your submission does not necessarily have to output the same board every time. But if multiple outputs are possible, you'll have to prove that every possible output is a valid board.

You can use this script (thanks to Magic Octopus Urn) or any of these answers to verify if a particular grid is a valid solution. It will output a [1] for a valid board, and anything else for an invalid board.

I'm not too picky about what format you output your answer in, as long as it's clearly 2-dimensional. For example, you could output a 9x9 matrix, nine 3x3 matrices, a string, an array of strings, an array of 9-digit integers, or nine 9-digit numbers with a separator. Outputting 81 digits in 1 dimension would not be permitted. If you would like to know about a particular output format, feel free to ask me in the comments.

As usual, this is code-golf, so write the shortest answer you can come up with in the language(s) of your choosing!

%}

% Ported from @Poptimist solution
% Uses broadcast summing to spread 1:9 over 9 rows, spread by values determined by the char string.
function sudoku
	mod((1:9) + ['furRaghAt']', 9) + 1
end

sudoku
