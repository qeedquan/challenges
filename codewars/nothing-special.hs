{-

The notorious Captain Schneider has given you a very straight forward mission. Any data that comes through the system make sure that only non-special characters see the light of day.

Create a function that given a string, retains only the letters A-Z (upper and lowercase), 0-9 digits, and whitespace characters. Also, returns "Not a string!" if the entry type is not a string.

-}

isletter :: Char -> Bool
isletter c = (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z') || ('0' <= c && c <= '9') || c == ' ' || c == '\t')

main :: IO()
main = print(filter (isletter) "!@#$%^&*()_+abcdefghi 24 jwf3 r3")
