{-

Mishka arranged to play football with his friends and was already about to leave home, but his mother stopped him.
She said that before he could go out to play, Mishka needed to help around the house.
His mother offered him a choice of one of three tasks: either wash the dishes, vacuum the apartment,
or play with his little sister Marinka while his mom goes to the store.
Mishka estimated how much time each task would take:

Washing the dishes will take t1 seconds

Vacuuming the apartment can be done in t2 seconds

Playing with Marinka will take t3 seconds

It is clear that Mishka will choose the task that takes the least time. Your program should determine and print this minimum time.

Input
Three integers t1, t2, t3 (1 <= t1, t2, t3 <= 1000)

Output
Print the minimum time Mishka needs to complete his mother's task.

Examples

Input #1
31 15 40

Answer #1
15

-}

solve :: Int -> Int -> Int -> (Int)
solve a b c = (min a (min b c))
