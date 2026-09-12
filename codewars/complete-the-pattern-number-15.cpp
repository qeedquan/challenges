/*

Task:
You have to write a function pattern which returns the following Pattern(See Examples) upto desired number of rows.

Note:Returning the pattern is not the same as Printing the pattern.
Parameters:
pattern(        n        ,        x        ,        y        );
                ^                 ^                 ^   
                |                 |                 |
         Term upto which   Number of times   Number of times
          Basic Pattern     Basic Pattern     Basic Pattern
            should be         should be         should be
             created          repeated           repeated
                            horizontally        vertically
Note: Basic Pattern means what we created in Complete The Pattern #12
Rules/Note:
The pattern should be created using only unit digits.
If n < 1 then it should return "" i.e. empty string.
If x <= 1 then the basic pattern should not be repeated horizontally.
If y <= 1 then the basic pattern should not be repeated vertically.
The length of each line is same, and is equal to the length of longest line in the pattern.
Range of Parameters (for the sake of CW Compiler) :
n ∈ (-∞,25]
x ∈ (-∞,10]
y ∈ (-∞,10]
If only two arguments are passed then the function pattern should run as if y <= 1.
If only one argument is passed then the function pattern should run as if x <= 1 & y <= 1.
The function pattern should work when extra arguments are passed, by ignoring the extra arguments.
Examples:
Having Three Arguments-
pattern(4,3,2):

 1     1     1     1
  2   2 2   2 2   2 
   3 3   3 3   3 3  
    4     4     4   
   3 3   3 3   3 3  
  2   2 2   2 2   2 
 1     1     1     1
  2   2 2   2 2   2 
   3 3   3 3   3 3  
    4     4     4   
   3 3   3 3   3 3  
  2   2 2   2 2   2 
 1     1     1     1
Having Two Arguments-

pattern(10,2):

1                 1                 1
 2               2 2               2 
  3             3   3             3  
   4           4     4           4   
    5         5       5         5    
     6       6         6       6     
      7     7           7     7      
       8   8             8   8       
        9 9               9 9        
         0                 0         
        9 9               9 9        
       8   8             8   8       
      7     7           7     7      
     6       6         6       6     
    5         5       5         5    
   4           4     4           4   
  3             3   3             3  
 2               2 2               2 
1                 1                 1
Having Only One Argument-

pattern(25):

1                                               1
 2                                             2 
  3                                           3  
   4                                         4   
    5                                       5    
     6                                     6     
      7                                   7      
       8                                 8       
        9                               9        
         0                             0         
          1                           1          
           2                         2           
            3                       3            
             4                     4             
              5                   5              
               6                 6               
                7               7                
                 8             8                 
                  9           9                  
                   0         0                   
                    1       1                    
                     2     2                     
                      3   3                      
                       4 4                       
                        5                        
                       4 4                       
                      3   3                      
                     2     2                     
                    1       1                    
                   0         0                   
                  9           9                  
                 8             8                 
                7               7                
               6                 6               
              5                   5              
             4                     4             
            3                       3            
           2                         2           
          1                           1          
         0                             0         
        9                               9        
       8                                 8       
      7                                   7      
     6                                     6     
    5                                       5    
   4                                         4   
  3                                           3  
 2                                             2 
1                                               1

*/

#include <print>

using namespace std;

void row(int s, int y, int v, int x0)
{
	for (auto x = x0; x < s; x++)
	{
		if (x == y || x == s - y - 1)
			print("{}", v);
		else
			print(" ");
	}
}

void cross(int n, int x, int y0)
{
	auto s = (2 * n) - 1;
	for (auto y = y0; y < s; y++)
	{
		auto v = y + 1;
		if (y >= n)
			v = s - y;
		v %= 10;

		row(s, y, v, 0);
		for (auto i = 0; i < x - 1; i++)
			row(s, y, v, 1);
		println();
	}
}

void pattern(int n, int x = 1, int y = 1)
{
	for (auto i = 0; i < y; i++)
		cross(n, x, i > 0);
	println();
}

int main()
{
	pattern(4, 3, 2);
	pattern(10, 2);
	pattern(25);

	return 0;
}
