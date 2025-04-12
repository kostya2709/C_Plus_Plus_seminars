
all_even :: [Int] -> Bool
all_even [] = True
all_even (x:xs) = even x && all_even xs

main :: IO ()
main = do
    print $ all_even [2, 4, 6]
    print $ all_even [1, 4, 6]
    print $ all_even []

-- runghc list.hs
