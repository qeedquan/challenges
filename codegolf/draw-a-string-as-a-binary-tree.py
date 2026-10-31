#!/usr/bin/env python3

r"""

The string abcdefghijklmno, with length 24-1, can be formatted as such:

       h
      / \
     /   \
    /     \
   d       l
  / \     / \
 b   f   j   n
a c e g i k m o
Each letter should be kept in the same column, but raised up by the right amount to form the above tree structure. Then, slashes (and backslashes) should be added to link each node to the two below. No slashes should be added between the bottom two rows.

Your challenge is to, given a string of lowercase letters of length 2k-1, format it as such. This is code-golf, shortest wins!

Testcases
Input	Output
a	
a
bcd	
 c
b d
hellowo	
   l   
  / \    
 e   w 
h l o o
abcdefghijklmno	
       h       
      / \      
     /   \     
    /     \    
   d       l   
  / \     / \  
 b   f   j   n 
a c e g i k m o
thistestcasehasalengththirtyone	
               a               
              / \              
             /   \             
            /     \            
           /       \           
          /         \          
         /           \         
        /             \        
       t               h       
      / \             / \      
     /   \           /   \     
    /     \         /     \    
   s       e       g       y   
  / \     / \     / \     / \  
 h   e   a   a   e   h   r   n 
t i t s c s h s l n t t i t o e

"""

def render(text):
    midpoint = len(text) // 2
    width = 2*midpoint + 1
    if midpoint == 0:
        return [text]

    root = text[midpoint]
    branches = []
    for spacing in range(1, midpoint, 2):
        branches.append(f"/{' ' * spacing}\\")

    left_tree = render(text[:midpoint])
    right_tree = render(text[midpoint + 1:])

    combined_subtrees = []
    for left_and_right in zip(left_tree, right_tree):
        combined_subtrees.append(" ".join(left_and_right))

    result = []
    for line in [root, *branches]:
        result.append(line.center(width))
    result += combined_subtrees

    return result

# Ported from @squareroot12621 solution
def tree(text):
    return '\n'.join(render(text))

def main():
    print(tree("a"))
    print(tree("bcd"))
    print(tree("hellowo"))
    print(tree("abcdefghijklmno"))
    print(tree("thistestcasehasalengththirtyone"))

main()
