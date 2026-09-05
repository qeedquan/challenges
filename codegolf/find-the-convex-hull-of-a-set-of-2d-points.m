%{

When you hammer a set of nails into a wooden board and wrap a rubber band around them, you get a Convex Hull.

https://i.sstatic.net/USMJf.png

Your mission, should you decide to accept it, is to find the Convex Hull of a given set of 2D points.

Some rules:

Write it as a function, the point's list coordinates (in any format you want) is the argument
The output must be the list of points in the convex hull listed clockwise or anticlockwise, starting at any of them
The output list can be in any reasonable format where each point's coordinates are clearly distinguishable. (For example NOT a one dim list { 0.1, 1.3, 4, ...})
If three or more points in a segment of the convex hull are aligned, only the two extremes should be kept on the output
Sample data:

Sample 0
Input:

{{1, 1}, {2, 2}, {3, 3}, {1, 3}}
Output:

{{3, 3}, {1, 3}, {1, 1}}

https://i.sstatic.net/t9toX.png

Sample 1
Input:

{{4.4, 14}, {6.7, 15.25}, {6.9, 12.8}, {2.1, 11.1}, {9.5, 14.9},
 {13.2, 11.9}, {10.3, 12.3}, {6.8, 9.5}, {3.3, 7.7}, {0.6, 5.1}, {5.3, 2.4},
 {8.45, 4.7}, {11.5, 9.6}, {13.8, 7.3}, {12.9, 3.1}, {11, 1.1}}
Output:

{{13.8, 7.3}, {13.2, 11.9}, {9.5, 14.9}, {6.7, 15.25}, {4.4, 14},
 {2.1, 11.1}, {0.6, 5.1}, {5.3, 2.4}, {11, 1.1}, {12.9, 3.1}}

https://i.sstatic.net/tqyTq.png

Sample 2
Input:

{{1, 0}, {1, 1}, {1, -1}, {0.68957, 0.283647}, {0.909487, 0.644276},
 {0.0361877, 0.803816}, {0.583004, 0.91555}, {-0.748169, 0.210483},
 {-0.553528, -0.967036}, {0.316709, -0.153861}, {-0.79267, 0.585945},
 {-0.700164, -0.750994}, {0.452273, -0.604434}, {-0.79134, -0.249902},
 {-0.594918, -0.397574}, {-0.547371, -0.434041}, {0.958132, -0.499614},
 {0.039941, 0.0990732}, {-0.891471, -0.464943}, {0.513187, -0.457062},
 {-0.930053, 0.60341}, {0.656995, 0.854205}}
Output:

{{1, -1}, {1, 1}, {0.583004, 0.91555}, {0.0361877, 0.803816},
 {-0.930053, 0.60341}, {-0.891471, -0.464943}, {-0.700164, -0.750994},
 {-0.553528, -0.967036}}

https://i.sstatic.net/whQXS.png

Standard code-golf rules apply. No ad-hoc geometry libraries. Shorter code wins.

Edit 1

We are looking for an algorithmic answer here, not a convex hull finder pre-programmed routine like this one in MatLab or this one in Mathematica

Edit 2

Answering comments and additional info:

You can assume the input list contains the minimum number of points that suits you. But you must ensure proper treatment of aligned (sub)sets.
You may find repeated points in the input list
The maximum number of points should be limited only by the available memory
Re "floating point": You need to be able to process input lists with decimal coordinates as those given in the samples. You could do that by using a floating point representation

%}

function h = convex_hull(p)
	h = [];
	i = convhull(p);
	for n = 1:length(i)
		h = [h; p(i(n),:)];
	end
end

convex_hull([1 1; 2 2; 3 3; 1 3])
convex_hull([4.4, 14; 6.7, 15.25; 6.9, 12.8; 2.1, 11.1; 9.5, 14.9; 13.2, 11.9; 10.3, 12.3; 6.8, 9.5; 3.3, 7.7; 0.6, 5.1; 5.3, 2.4; 8.45, 4.7; 11.5, 9.6; 13.8, 7.3; 12.9, 3.1; 11, 1.1])
convex_hull([
	1, 0; 1, 1; 1, -1; 0.68957, 0.283647; 0.909487, 0.644276;
	0.0361877, 0.803816; 0.583004, 0.91555; -0.748169, 0.210483;
	-0.553528, -0.967036; 0.316709, -0.153861; -0.79267, 0.585945;
	-0.700164, -0.750994; 0.452273, -0.604434; -0.79134, -0.249902;
	-0.594918, -0.397574; -0.547371, -0.434041; 0.958132, -0.499614;
	0.039941, 0.0990732; -0.891471, -0.464943; 0.513187, -0.457062;
	-0.930053, 0.60341; 0.656995, 0.854205
])
