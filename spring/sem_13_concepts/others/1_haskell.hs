
class Printable a where
    printIt :: a -> String

instance Printable Int where
    printIt x = "This is an integer: " ++ show x

instance Printable Bool where
    printIt True = "This is a boolean: True"
    printIt False = "This is a boolean: False"

data Person = Person { name :: String, age :: Int }

instance Printable Person where
    printIt p = name p ++ " is " ++ show (age p) ++ " years old"

printAnything :: Printable a => a -> IO ()
printAnything x = putStrLn (printIt x)

main :: IO ()
main = do
    printAnything (42 :: Int)
    printAnything True
    printAnything (Person "Alice" 30)

-- runghc 1_haskell.rs
