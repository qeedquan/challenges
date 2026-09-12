#!/usr/bin/env python3

"""

Description
ElsieFour (LC4) is a low-tech authenticated encryption algorithm that can be computed by hand. Rather than operating on octets, the cipher operates on this 36-character alphabet:

#_23456789abcdefghijklmnopqrstuvwxyz
Each of these characters is assigned an integer 0–35. The cipher uses a 6x6 tile substitution-box (s-box) where each tile is one of these characters. A key is any random permutation of the alphabet arranged in this 6x6 s-box. Additionally a marker is initially placed on the tile in the upper-left corner. The s-box is permuted and the marked moves during encryption and decryption.

See the illustrations from the paper (album).

Each tile has a positive "vector" derived from its value: (N % 6, N / 6), referring to horizontal and vertical movement respectively. All vector movement wraps around, modulo-style.

To encrypt a single character, locate its tile in the s-box, then starting from that tile, move along the vector of the tile under the marker. This will be the ciphertext character (the output).

Next, the s-box is permuted. Right-rotate the row containing the plaintext character. Then down-rotate the column containing the ciphertext character. If the tile on which the marker is sitting gets rotated, marker goes with it.

Finally, move the marker according to the vector on the ciphertext tile.

Repeat this process for each character in the message.

Decryption is the same, but it (obviously) starts from the ciphertext character, and the plaintext is computed by moving along the negated vector (left and up) of the tile under the marker. Rotation and marker movement remains the same (right-rotate on plaintext tile, down-rotate on ciphertext tile).

If that doesn't make sense, have a look at the paper itself. It has pseudo-code and a detailed step-by-step example.

Input Description
Your program will be fed two lines. The first line is the encryption key. The second line is a message to be decrypted.

Output Description
Print the decrypted message.

Sample Inputs
s2ferw_nx346ty5odiupq#lmz8ajhgcvk79b
tk5j23tq94_gw9c#lhzs

#o2zqijbkcw8hudm94g5fnprxla7t6_yse3v
b66rfjmlpmfh9vtzu53nwf5e7ixjnp
Sample Outputs
aaaaaaaaaaaaaaaaaaaa

be_sure_to_drink_your_ovaltine
Challenge Input
9mlpg_to2yxuzh4387dsajknf56bi#ecwrqv
grrhkajlmd3c6xkw65m3dnwl65n9op6k_o59qeq
Bonus
Also add support for encryption. If the second line begins with % (not in the cipher alphabet), then it should be encrypted instead.

7dju4s_in6vkecxorlzftgq358mhy29pw#ba
%the_swallow_flies_at_midnight

hemmykrc2gx_i3p9vwwitl2kvljiz
If you want to get really fancy, also add support for nonces and signature authentication as discussed in the paper. The interface for these is up to you.

Credit
This challenge was suggested by user u/skeeto, many thanks! If you have any challenge ideas, please share them in r/dailyprogrammer_ideas and there's a good chance we'll use them.

"""

import numpy as np

"""

@zatoichi49

Convert the key string into a 6x6 array, and create a dictionary of the vectors for each tile.
For each character in the input text, find the row/col position and subtract (for decryption) or add (for encryption)
the vectors of the marker to find the row/col position of the decrypted/encrypted character.
Add the character to the results string. Rotate the relevant row and column, and move the marker to its new position.
Repeat for the remaining characters, and return the final results string. (EDIT: Added comments)

"""

def elsie_four(key, text, decryption=True):
    # marker = m, with position (i, j)
    # text character = a, with position (r, c)
    # decrypted/encrypted char = b, with position (x, y)
    if text.startswith('%'):
        decryption = False
        text = text[1:]

    alphabet = '#_23456789abcdefghijklmnopqrstuvwxyz'
    # create dictionary of vectors
    vectors = {i:[n%6, n//6] for n, i in enumerate(alphabet)}

    # check for valid input
    if len(key) != 36:
        return '--Error: Please provide a 36-char key--'
    if len(set(alphabet + key + text)) > 36:
        return '--Error: Invalid characters in key/text--'
    
    # initialize grid
    grid = np.array(list(key)).reshape(6, 6)
    # set marker position
    m, i, j = key[0], 0, 0

    res = ''
    for a in text:
        r, c = np.ravel(np.where(grid == a))
        
        if decryption:
            # subtract vectors for decryption
            x, y = np.subtract([r, c], vectors[m][::-1]) % 6
            # decrypted character
            b = grid[x][y]
            row, col, tile = x, c, a
        else:
            # add vectors for encryption
            x, y = np.add([r, c], vectors[m][::-1]) % 6
            # encrypted character
            b = grid[x][y]
            row, col, tile = r, y, b 
        res += b

        # rotate row
        grid[row] = np.roll(grid[row], 1)
        col = np.where(grid == tile)[1]
        # rotate column
        grid[:, col] = np.roll(grid[:, col], 1)

        # find marker
        i, j = np.ravel(np.where(grid == m))
        # set new position
        i, j = np.add([i, j], vectors[tile][::-1]) % 6
        # set new marker character
        m = grid[i][j]

    return res 

def main():
    print(elsie_four('s2ferw_nx346ty5odiupq#lmz8ajhgcvk79b', 'tk5j23tq94_gw9c#lhzs'))
    print(elsie_four('#o2zqijbkcw8hudm94g5fnprxla7t6_yse3v', 'b66rfjmlpmfh9vtzu53nwf5e7ixjnp'))
    print(elsie_four('9mlpg_to2yxuzh4387dsajknf56bi#ecwrqv', 'grrhkajlmd3c6xkw65m3dnwl65n9op6k_o59qeq'))

main()
