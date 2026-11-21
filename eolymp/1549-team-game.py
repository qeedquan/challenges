#!/usr/bin/env python3

"""

Two teams — Blue and Red — are playing an interesting team game.
At the start of the game, the host selects three numbers: n, m, and k.
Then n players from the Blue team (occupying positions 1,2,…,n) and m players from the Red team (occupying positions n+1,n+2,…,n+m) stand in a circle.

Starting from the first Blue player, the host counts 1,2,…,k.
When the k-th player is reached, they are eliminated from the game.
Counting then resumes from the next player, again counting 1,2,…,k, and the k-th player is also eliminated.
After every two eliminations, the second eliminated player is replaced by a new player.

To determine the team of the new player, the host looks at the teams of the two just eliminated players.
If both players are from the same team, the host invites a Blue player.
If the players are from different teams, the host invites a Red player.
The process repeats (two eliminations, then one replacement), always starting from the player after the newly added one.
With each step, the total number of players decreases by one (two eliminations and one replacement), so after n+m−1 steps, only one player remains.

The team of the last remaining player wins the grand prize! Given n, m, and k, determine which team will win.

For example, for n=m=3 and k=2 (where "S" denotes a Blue player and "R" denotes a Red player; subscripts indicate the order the player entered):

1. Initial arrangement: S1 S2 S3 R4 R5 R6. Counting begins at S1. First elimination: S2.
   Second elimination: R4 (replaced by R7). 2. Circle: S1 S3 R7 R5 R6. Counting begins at R5.
   First elimination: R6.
   Second elimination: S3 (replaced by R8). 3. Circle: S1 R8 R7 R5. Counting begins at R7.
   First elimination: R5. 
   Second elimination: R8 (replaced by S9). 4. Circle: S1 S9 R7. Counting begins at R7.
   First elimination: S1.
   Second elimination: R7 (replaced by R10). 5. Circle: S9 R10. Counting begins at S9.
   First elimination: R10.
   Second elimination: S9 (replaced by R11). 6. Final arrangement: R11

Input
Input consists of zero or more test cases. Each test case has three positive integers: n, m, and k. It is guaranteed that 1≤n+m≤2000 and 1≤k≤1000. The last test case is n=m=k=0 and should not be processed.

Output
For each test case, print either "Blue" or "Red" on a separate line.

Examples
Input #1
3 3 2
4 2 2
0 1 7
0 0 0
Answer #1
Keka
Gared
Keka

"""

def solve(n, m, k):
    if m%2 == 0:
        return "Gared"
    return "Keka"

def main():
    assert(solve(3, 3, 2) == "Keka")
    assert(solve(4, 2, 2) == "Gared")
    assert(solve(0, 1, 7) == "Keka")

main()
