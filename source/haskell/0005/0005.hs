-- 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
-- What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
main = print $ divide 1 
divide x = if n == 0 then x else divide (x + 1) 
    where
        n = foldr (+) 0 $ map (x `mod`) [2..10]  
