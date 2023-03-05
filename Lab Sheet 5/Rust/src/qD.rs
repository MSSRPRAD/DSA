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
    let mut t: usize;
    n = read!();
    k = read!();
    t = read!();

    let mut arr = read_vec::<usize>();

    let mut count: usize;
    let mut sum: usize;    

    sum = 0;
    count = 0;

    //// First window
    for i in 0..k {
        sum += arr[i];
    }

    if sum/k >= t {
        count += 1;
    }

    //// Other windows
    for i in 1..n-k+1 {
        sum += arr[i+k-1];
        sum -= arr[i-1];
        if sum/k >= t {
            count += 1;
        }
    }

    println!("{:?}", count);
}