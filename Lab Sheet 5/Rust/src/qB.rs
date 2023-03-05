use std::io;
use text_io::read;

fn position(mut head: i64,remaining: i64,step: i64,mut left: i64) -> i64 {

    if remaining == 1{
        return head;
    } 

    if left == 1 || (left == 0 && remaining%2 == 1){
        head += step;
    }

    if left > 0 {
        left = 0;
    } else {
        left = 1;
    }

    head = position(head, remaining/2, 2*step, left);
    return head;
    
}

fn main() {
    let mut count: i64 = 0;
    let stdin = io::stdin();
    let n: i64;

    n = read!();

    println!("{:?}", position(1,n,1,1));    
}