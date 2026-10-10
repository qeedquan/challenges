%{

Is the number even?
If the numbers is even return true. If it's odd, return false.

Oh yeah... the following symbols/commands have been disabled!

use of %
use of .even? in Ruby
use of mod in Python

%}

function r = iseven(x)
	r = !bitand(x, 1);
end

for i = 0:20
	if iseven(i)
		display(i);
	end
end
