
#[derive(Debug, PartialEq, Clone)]
struct Person {
    name: String,
    age: u32,
}

fn main() {
    let alice = Person { name: "Alice".to_string(), age: 30 };
    let alice_clone = alice.clone();

    println!("{:?}", alice);
    println!("Are they equal? {}", alice == alice_clone);
}

// rustc rust.rs
