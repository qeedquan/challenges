/*

We have a few questions related to pokemon types, but the only one that has you print the type chart requires you to take a parameter for dual typings which adds a ton of complexity, switches the axes around from a standard type chart, and shuffled the type order. Thus, we should standardize it using the minimalist type chart taken from this reddit post.

Print the Pokemon type chart! The chart is minimalistic, so your source code should be short as well.

       Def N F W E G I F P G F P B R G D D S F
Atk        o i a l r c i o r l s u o h r a t a
Normal                             - X     -  
Fire         - -   + +           + -   -   +  
Water        + -   -       +       +   -      
Electric       + - -       X +         -      
Grass        - +   -     - + -   - +   -   -  
Ice          - -   + -     + +         +   -  
Fighting   +         +   -   - - - + X   + + -
Poison             +     - -       - -     X +
Ground       +   + -     +   X   - +       +  
Flying           - +   +         + -       -  
Psychic                + +     -         X -  
Bug          -     +   - -   - +     -   + - -
Rock         +       + -   - +   +         -  
Ghost      X                   +     +   -    
Dragon                                 +   - X
Dark                   -       +     +   -   -
Steel        - - -   +             +       - +
Fairy        -         + -             + + -  
You may use any pairwise distinct characters for X- +, but any numbers used must correspond to the damage multiplier (i.e. 0123 is not allowed because there is no 3x damage) Take no input, trailing newline and/or consistent trailing whitespace on each line is fine, if a line ends in whitespace you may optionally include that. For example, water attacking can end at dragon or extend to fairy.

*/

#include <print>

using namespace std;

const string CHART = R"(
       Def N F W E G I F P G F P B R G D D S F
Atk        o i a l r c i o r l s u o h r a t a
Normal                             - X     -
Fire         - -   + +           + -   -   +
Water        + -   -       +       +   -
Electric       + - -       X +         -
Grass        - +   -     - + -   - +   -   -
Ice          - -   + -     + +         +   -
Fighting   +         +   -   - - - + X   + + -
Poison             +     - -       - -     X +
Ground       +   + -     +   X   - +       +
Flying           - +   +         + -       -
Psychic                + +     -         X -
Bug          -     +   - -   - +     -   + - -
Rock         +       + -   - +   +         -
Ghost      X                   +     +   -
Dragon                                 +   - X
Dark                   -       +     +   -   -
Steel        - - -   +             +       - +
Fairy        -         + -             + + -
)";

int main()
{
	print("{}\n", CHART);
	return 0;
}
