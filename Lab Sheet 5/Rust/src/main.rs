//// Problem G
/// 
/// Not Done Yet

use text_io::read;
use std::io::BufRead;
fn read_vec<T>() -> Vec<T>
where
    T: std::str::FromStr,
    <T as std::str::FromStr>::Err: std::fmt::Debug,
{
    std::io::stdin()
        .lock()
        .lines()
        .next()
        .unwrap()
        .unwrap()
        .trim()
        .split_whitespace()
        .map(|s| s.parse::<T>().unwrap())
        .collect::<Vec<T>>()
}



fn main() {
    let mut count: usize = 0;
    let mut n: usize;
    let mut k: usize;
    let mut n: usize = read!();
    let mut k: usize = read!();
    let mut arr = read_vec::<usize>();
    
    println!("{:?}", arr);
    println!("{:?}", n);
    println!("{:?}", k);
}