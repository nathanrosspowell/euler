-- 2^15 = 32768 and the sum of the digits is 3+2+7+6+8=26
-- What is the sum of the digits of the number 2^1000
import Data.Char
main = print $ foldr (+) 0 $ map digitToInt $ show $ 2^1000 
