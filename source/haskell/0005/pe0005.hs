-- 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
-- What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
main = print $ test 1 
increase x y z
    | n == 0    = z 
    | otherwise = increase x y (z + 1)
    where 
        n = (x * z) `mod` y
divide x y
    | n > 0     = increase x y 2
    | y < 20    = divide x (y + 1)
    | otherwise = 0 
    where
        n = x `mod` y  
test x = if inc == 0 then x else test (x * inc) 
    where
        inc = divide x 2 
