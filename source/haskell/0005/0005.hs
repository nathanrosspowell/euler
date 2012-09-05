-- 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
-- What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
main = print $ test 1 
divide x y
    | n > 0 = False
    | y < 20 =  divide x (y + 1 )
    | otherwise = True
    where
        n = x `mod` y  
test x = if n then x else test (x + 1) 
    where
        n = divide x 2 
