use std::io;
use text_io::read;

fn generateBrackets(count: &mut i64, no: i64 , open: i64, closed: i64, s: String, result: &mut Vec::<String> ) {
    
    if open == no && closed == no {
        *count+=1;
        result.push(s);
        return
    }

    if open<no {
        generateBrackets(count, no, open+1, closed, s.clone() + "(", result);
    }
    
    if closed < open {
        generateBrackets(count, no, open, closed+1, s.clone()+")", result);
    }
}

fn main() {
    let mut count: i64 = 0;
    let stdin = io::stdin();
    let n: i64;
    // read until a whitespace and try to convert what was read into an i32
    n = read!(); 
    let mut result: Vec::<String> = Vec::<String>::new();
    generateBrackets(&mut count, n/2, 0, 0,String::new() , &mut result);
    println!("{:?}", count);
    for i in result.iter() {
        println!("{:?}", i);
    }
     
}
