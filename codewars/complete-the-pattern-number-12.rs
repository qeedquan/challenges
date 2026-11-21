/*

Task:
You have to write a function pattern which returns the following Pattern(See Examples) upto (2n-1) rows, where n is parameter.

Note:Returning the pattern is not the same as Printing the pattern.
Parameters:
pattern(        n        );
                ^                     
                |                     
         Term upto which   
       Basic Pattern(this)     
            should be         
             created            
                              
                            
Rules/Note:
If n < 1 then it should return "" i.e. empty string.
The length of each line is same, and is equal to the length of longest line in the pattern i.e (2n-1).
Range of Parameters (for the sake of CW Compiler) :
n ∈ (-∞,100]
Examples:
pattern(5):

  1       1
   2     2 
    3   3  
     4 4   
      5    
     4 4   
    3   3  
   2     2 
  1       1
 
  
pattern(10):

  1                 1
   2               2 
    3             3  
     4           4   
      5         5    
       6       6     
        7     7      
         8   8       
          9 9        
           0         
          9 9        
         8   8       
        7     7      
       6       6     
      5         5    
     4           4   
    3             3  
   2               2 
  1                 1
pattern(15):

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

*/

fn main() {
    pattern(5);
    pattern(10);
    pattern(15);
}

fn pattern(n: isize) {
    println!("n={n}");
    let (mut i, s) = (1, (2 * n) - 1);
    for y in 0..s {
        for x in 0..s {
            if x == y {
                print!("{}", i % 10);
                if y < n - 1 {
                    i += 1;
                } else {
                    i -= 1;
                }
            } else if x == s - y - 1 {
                if y < n {
                    print!("{}", (i - 1) % 10);
                } else {
                    print!("{}", i % 10);
                }
            } else {
                print!(" ");
            }
        }
        println!();
    }
    println!();
}

