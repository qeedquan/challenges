unshadow passwd shadow > unshadowed
john unshadowed --wordlist=wordlist.txt
john --show shadow

