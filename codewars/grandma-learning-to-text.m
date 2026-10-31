%{

Write a function that replaces 'two', 'too' and 'to' with the number '2'. Even if the sound is found mid word (like in octopus) or not in lowercase grandma still thinks that should be replaced with a 2. Bless her.

'I love to text' becomes 'I love 2 text'
'see you tomorrow' becomes 'see you 2morrow'
'look at that octopus' becomes 'look at that oc2pus'

Note that 'too' should become '2', not '2o'

%}

function r = textin(s)
	r = strrep(s, "two", "2");
	r = strrep(r, "too", "2");
	r = strrep(r, "to", "2");
end

textin("I love to text")
textin("see you tomorrow")
textin("look at that octopus")
textin("too")
