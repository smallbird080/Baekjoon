use std::io::{self, BufRead};

fn main() {
    let scanner = io::stdin().lock().lines().next().unwrap().unwrap();
    let mut ns = scanner.split_ascii_whitespace().map(|x| x.parse::<i32>().expect("Failed parse"));
    let a = ns.next().unwrap_or_else(|| -1);
    let scanner = io::stdin().lock().lines().next().unwrap().unwrap();
    let mut ns = scanner.split_ascii_whitespace().map(|x| x.parse::<i32>().expect("Failed parse"));
    let b = ns.next().unwrap_or_else(|| -1);
    let mut c = &a + &b;
    println!("{}", c);
}
