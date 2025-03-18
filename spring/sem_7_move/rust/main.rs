
fn main() {
    let hello = String::from("Hello, world!");
    let hello2 = hello; // we move hello to hello2 here
    println!("{}", hello2);
    
    // println!("{}", hello);
}
