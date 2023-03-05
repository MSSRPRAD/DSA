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
    n = read!();
    k = read!();

    let mut arr = read_vec::<usize>();

    let mut sum = 0;

    let mut prefix = Vec::<usize>::new();
    for i in 0..n {
        sum += arr[i];
        prefix.push(sum);
    }
    for i in 0..n {
        prefix[i] = prefix[i]%k;
    }

    let mut freq = Vec::<usize>::new();
    for i in 0..k {
        freq.push(0)
    }
    freq[0]=1;
    for i in 0..n {
        freq[prefix[i]] += 1;
    }

    for i in 0..k {
        if freq[i]>1 {
            count += (freq[i]*(freq[i]-1))/2
        }
    }

    println!("{:?}", count);
}