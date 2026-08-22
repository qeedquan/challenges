%{

A dynamic system is most commonly described in one of three ways:

By a set of state-space equations and the corresponding matrices
By a transfer function using the symbolic s variable or numerator and denominator polynomials
By a list of poles and zeros and the associated gain

We can convert from one representation to another

%}

pkg load control;
pkg load signal;

% Create a transfer function symbolically
s = tf('s');
G = (2*s+1)/(4*s^2+3*s+2)

% Create a transfer function out of zeros and poles coefficient
num = [2 1];
den = [4 3 2];
G = tf(num, den)

% Get the state space model given a transfer function
[A, B, C, D] = ssdata(G)

% Recover the zero/poles given a A, B, C, D matrix
% should be match the above though reduced to lowest common denominator
[num, den] = ss2tf(A,B,C,D)

% convert a zeros and poles coefficient to an ABCD matrix
[A,B,C,D] = tf2ss(num,den)

% Construct a state space model from a A, B, C, D matrix
H = ss(A, B, C, D)

% Get the zero-pole-gain model from the system
% The z/p parameters are the zero roots and the pole roots
[z, p, k] = zpkdata(H, 'v')
% This should match the z/p above
roots(num)
roots(den)

% Construct a transfer function given a zero/pole/gain 
K = zpk(z, p, k)

%{

We say that a system has zeros at infinity if the limit as s->infinity or the value of the transfer function is equal to zero; this happens whenever you have more poles than zeros. You will see this in the root locus plot as asymptotes which go to infinity (the number of asymptotes is equal to the number of zeros at infinity). MATLAB sometimes computes these zeros at infinity as being large finite numbers.When this happens, some of the coefficients in the numerator that are supposed to be zero end up being very small numbers. It may not seem like a big deal, but it can cause errors when trying to use the transfer function later on. You should always check your transfer function, and if numbers that are 0.0000 show up that are supposed to be zero, rewrite the numerator into MATLAB to compensate.

%}

A = [0    1    0      0
     0 -0.1818 2.6727 0
     0    0    0      1
     0 -4.5454 31.1818 0];

B = [0
     1.8182
     0
     4.5455];

C = [1 0 0 0
    0 0 1 0];

D = [0
     0];

[num, den]=ss2tf(A,B,C,D)

% Pole/Zero to State-Space and Pole/Zero to Transfer Function
[A, B, C, D] = zp2ss(z, p, k)
[num, den] = zp2tf(z, p, k)
