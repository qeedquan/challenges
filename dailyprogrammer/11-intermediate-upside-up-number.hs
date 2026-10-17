{-

An “upside up” number is a number that reads the same when it is rotated 180°. For instance, 689 and 1961 are upside up numbers.

Your task is to find the next upside up number greater than 1961, and to count the number of upside up numbers less than ten thousand.

edit: since there is a confusion about 2 and 5, please consider them as "upside up" numbers for this problem. If you have already done without it, its ok. Sorry for the late reply.

source: programmingpraxis.com

-}

isUpsideUp :: Int -> Bool
isUpsideUp x = all canRot x' && x'' == x
  where x' = show x
        x'' = read $ reverse $ rotate x'
        canRot = (`elem` "1256890")
        rotate = map rot
        rot '1' = '1'
        rot '2' = '5'
        rot '5' = '2'
        rot '6' = '9'
        rot '8' = '8'
        rot '9' = '6'
        rot '0' = '0'
        rot _ = undefined

main = do
  let xs = filter isUpsideUp [1..9999]
  print $ head $ dropWhile (<= 1961) xs
  print $ length xs

