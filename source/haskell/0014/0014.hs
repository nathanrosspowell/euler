-- The following iterative seqChainuence is defined for the set of positive integers
--
--      n -> n/2 (n is even
--      n -> 3n+1 (n is odd)
--
-- Which starting number, under one million, produces the longes chain?
main = print $ test 1 0 0
seqChain num chain
    | num <= 1         = chain
    | num `mod` 2 == 0 = seqChain halfNum chain1
    | otherwise        = seqChain tripNum chain1
    where
        halfNum = num `div` 2
        tripNum = 3 * num + 1 
        chain1 = chain + 1
test num bestChain bestValue
    | num >= 1000000    = bestValue
    | chain > bestChain = test num2 chain num 
    | otherwise         = test num2 bestChain bestValue
    where
        chain = seqChain num 0
        num2 = num + 1
