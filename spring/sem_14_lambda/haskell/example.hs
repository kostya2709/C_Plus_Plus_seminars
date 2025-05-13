
main :: IO ()
main = do
    print $ (*) 3 2
    let mul2 = (*) 2
    print $ mul2 2

    let foo = \x -> 2 * x
    print $ foo 21

    let apply = \f arg -> f arg
    print $ apply foo 27

-- runghc example.hs
