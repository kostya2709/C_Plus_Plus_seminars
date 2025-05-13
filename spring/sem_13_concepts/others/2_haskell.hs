
data Color = Red | Green | Blue
deriving (Show, Eq)

main :: IO ()
main = do
    print Red
    print (Red == Green)

-- runghc 2_haskell.rs
