{-

For today's challenge, you should calculate some simple statistical values based on a list of values. Given this data set, write functions that will calculate:

The mean value

The variance

The standard deviation

Obviously, many programming languages and environments have standard functions for these (this problem is one of the few that is really easy to solve in Excel!), but you are not allowed to use those! The point of this problem is to write the functions yourself.

Thanks to Cosmologicon for suggesting this problem at r/dailyprogrammer_ideas!

-}

mean     xs = (sum xs) / (fromIntegral $ length xs)
variance xs = mean . map (^2) $ fmap ((-) $ mean xs) xs
stdDev      = sqrt . variance

