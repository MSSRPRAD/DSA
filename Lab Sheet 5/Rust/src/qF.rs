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
    let mut A = read_vec::<usize>();
    println!();
    let mut m: usize = read!();
    let mut B = read_vec::<usize>();
    
    match n%2 {
        0 => {
            match m%2 {
                //// When A is even and B is even
                0 => {
                    println!("0");
                },
                //// When A is even and B is odd
                1 => {
                    let mut xor: usize = 0;
                    for i in 0..m {
                        xor = xor^B[i];
                    }
                    println!("{:?}", xor);
                },
                _ => {

                }
                
            }
        },
        1=> {
            match n%2 {
                //// When A is odd and B is even
                0 => {
                    let mut xor: usize = 0;
                    for i in 0..n {
                        xor = xor^A[i];
                    }   
                    println!("{:?}", xor);                 
                },
                //// When A is odd and B is odd
                1 => {
                    let mut xor: usize = 0;
                    for i in 0..n {
                        xor = xor^A[i];
                    }   
                    for i in 0..m {
                        xor = xor^B[i];
                    }   
                    println!("{:?}", xor); 
                },

                _ => {

                },
            }

        },

        _ => {

        }
    }
}