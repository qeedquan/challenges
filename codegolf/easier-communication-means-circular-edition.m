%{

Based on this, but I was asked[1],[2] to do a graphical edition.

https://codegolf.stackexchange.com/questions/119361/easier-communication-means-faster-coding-means-fewer-coders-means/119406

https://i.stack.imgur.com/pEzT8.png

Task
Generate a circular display of the text EASIER COMMUNICATION MEANS FASTER CODING MEANS FEWER CODERS MEANS . Any uppercase font goes. The letter tops must face out of the circle. Either the space before FEWER must be at the bottom (6 o'clock) or (for brownie points) your text must rotate.

%}

% ported from @Stewie Griffin solution
function message(s)
	n = nnz(s);
	for i=1:n
		text(sin(i/n*2*pi), cos(i/n*2*pi), s(i), 'rotation', -i/n*360);
		axis([-2, 2, -2, 2]);
	end
end

message('CATION MEANS FASTER CODING MEANS FEWER CODERS MEANS EASIER COMMUNI');
pause;
