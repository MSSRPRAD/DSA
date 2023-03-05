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

    let mut arr = read_vec::<String>();
    let mut input: String = String::from(&arr[0]);

    let mut count: usize;
    let mut sum: usize;    

    sum = 0;
    count = 0;
    let strt: usize = 'a' as usize;
    let end: usize = strt + k-1;

    println!("{:?}\n{:?}\n\n", strt, end);

    let mut check = true;

    for i in strt..end+1 {
        let mut c = false;
        for j in input.chars(){
            if j as usize == i {
                c = true;
            }
        }
        if !c {
            check = false;
            break;
        }
    }

    if !check {
        print!("0");
        return
    }

    let mut left = 0;
    let mut right = 0;
    let mut count = 0;
    let mut check = true;
    let mut freq = Vec::<usize>::new();

    
    for i in 0..k {
        freq.push(0);
    }
    let mut distinct = 0;

    while(right<=n-1){

        let char_right = input.chars().nth(right).unwrap();

        if freq[char_right as usize - 'a' as usize]==0 {
            freq[char_right as usize - 'a' as usize] += 1;
            distinct += 1;
        } else {
            freq[char_right as usize - 'a' as usize] += 1;
        }
        // If all the characters are present, count++
        if distinct == k {
            while distinct == k {
                count += n-right;
                let char_left = input.chars().nth(left).unwrap();
                freq[char_left as usize - 'a' as usize] -= 1;
                if freq[char_left as usize - 'a' as usize] == 0 {
                    distinct -= 1;
                }
                left +=1;
            }
            right += 1;
        } else {
            right += 1;
        }
    }
    println!("Count: {:?}", count);

}