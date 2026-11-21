%{

Strassen's algorithm was the first method of matrix multiplication in subcubic time complexity, namely O(n**log2(7)) for a pair of n*n matrices (assuming the numbers therein are large enough that their O(n*log2(n)) exact multiplication has become the constraint on your performance, and any nested structures and function calls are negligible in comparison).

For a 2*2 matrix, it is defined as

lambda a,b: (lambda a,b,c,d,e,f,g: (a+d-e+g,c+e,b+d,a-b+c+f))((a[0]+a[3])*(b[0]+b[3]),(a[2]+a[3])*b[0],a[0]*(b[1]-b[3]),a[3]*(b[2]-b[0]),(a[0]+a[1])*b[3],(a[2]-a[0])*(b[0]+b[1]),(a[1]-a[3])*(b[2]+b[3]))
And for larger square ones, as splitting them into quarters and then calling this but with numbers' addition, negation and multiplication methods substituted for matrices' (notably using itself for the latter, its seven self-calls per doubling of the width and height being the reason for the exponent).

For simplicity (so you won't need to deal with implementing standard matrix multiplication and subdividing into Strassen-able ones), your inputs will be two 2**n*2**n matrices of integers, represented as length-2**(2*n) tuples (or lists or your language's equivalent), encoded with elements in reading order, and you will return another such tuple. For instance, when inputted with these two

(5,2,0,0,
 4,0,5,2,
 3,4,5,0,
 3,1,4,2)

(7,4,5,3,
 4,0,2,7,
 1,4,1,1,
 0,5,3,5)
, it should return

(43,20,29,29,
 33,46,31,27,
 42,32,28,42,
 29,38,27,30)

%}

% https://rosettacode.org/wiki/Strassen%27s_algorithm
function C = strassen(A, B)
    n = size(A, 1);
    if n == 1
        C = A * B;
        return
    end
    
    A11 = A(1:n/2, 1:n/2);
    A12 = A(1:n/2, n/2+1:n);
    A21 = A(n/2+1:n, 1:n/2);
    A22 = A(n/2+1:n, n/2+1:n);
    B11 = B(1:n/2, 1:n/2);
    B12 = B(1:n/2, n/2+1:n);
    B21 = B(n/2+1:n, 1:n/2);
    B22 = B(n/2+1:n, n/2+1:n);

    P1 = strassen(A12 - A22, B21 + B22);
    P2 = strassen(A11 + A22, B11 + B22);
    P3 = strassen(A11 - A21, B11 + B12);
    P4 = strassen(A11 + A12, B22);
    P5 = strassen(A11, B12 - B22);
    P6 = strassen(A22, B21 - B11);
    P7 = strassen(A21 + A22, B11);

    C11 = P1 + P2 - P4 + P6;
    C12 = P4 + P5;
    C21 = P6 + P7;
    C22 = P2 - P3 + P5 - P7;

    C = [C11 C12; C21 C22];
end

A = [5, 2, 0, 0;
     4, 0, 5, 2;
     3, 4, 5, 0;
     3, 1, 4, 2]

B = [7, 4, 5, 3;
     4, 0, 2, 7;
     1, 4, 1, 1;
     0, 5, 3, 5]

C = strassen(A, B)

