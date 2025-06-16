#!/usr/bin/env python3

"""

8-bit XOR encryption takes a single byte and XORs every byte in the file by that byte. Here is a reference program in C++:

/*xorcipher.cpp
 *Encrypts a file using 8-bit xor encrytpion
 */

#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

int main(int argc, char** argv){
   ifstream* in = NULL;
   ofstream* out = NULL;

   if(argc < 3){
      cerr << "Usage: xor <key> <filename...>" << endl;
      exit(1);
   }

   int key = atoi(argv[1]);

   for(int x = 2; x < argc; x++){
      in = new ifstream(argv[x], ios::binary);
      if(!in->good()){
         cerr << "Error reading from " << argv[x] << endl;
         exit(1);
      }

      //Get file size
      in->seekg(0, ios::end);
      int size = in->tellg();
      in->seekg(0, ios::beg);

      //Allocate memory
      int* data = new int[size];

      int c = 0;
      for(int y = 0; (c = in->get()) != EOF; y++)
         data[y] = c ^ key;

      in->close();
      delete in;
      in = NULL;

      out = new ofstream(argv[x], ios::binary);
      if(!out->good()){
         cerr << "Error writing to " << argv[x] << endl;
         exit(1);
      }

      for(int y = 0; y < size; y++)
         out->put(data[y]);

      out->flush();
      out->close();
      delete out;
      out = NULL;

      delete[] data;
      data = NULL;
   }
   cout << "Operation complete" << endl;

   return 0;
}
The shortest answer (whitespace doesn't count) that produces the same end result will be selected. It does not have to store everything in memory at once or open and close every file multiple times. It can do anything as long as a file encrypted with the reference program can be decrypted with the answer, and vice versa.

Edit: The above program is not a specification. The only requirement is that answers should be able to decrypt a file encrypted with the above program, and the above program should be able to decrypt a file encrypted with the answer. I'm sorry if that was unclear.
The above program can be compiled with:

g++ xorcipher.cpp -o ~/bin/xor
It can be run like this:

xor <key> <filename...>
For example, if the key is 42 and the file is alpha.txt, you would use:

xor 42 alpha.txt

"""

import sys

def main():
    xorb = 0
    if len(sys.argv) >= 2:
        xorb = int(sys.argv[1], 0)

    inp = sys.stdin.buffer.read()
    buf = []
    for val in inp:
        buf.append(val ^ xorb)

    sys.stdout.buffer.write(bytearray(buf))

main()
