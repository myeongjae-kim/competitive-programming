use std::io;

fn main() {
    let mut input = String::new();

    match io::stdin().read_line(&mut input) {
        Ok(_n) => {
            let cases: i32 = input.trim().parse().unwrap();
            for _ in 0..cases {
                each_case();
            }
        }
        Err(error) => println!("error: {}", error),
    }
}

fn each_case() {
    let mut input = String::new();
    let (n, l): (i32, i32);
    let mut prices: Vec<i32> = Vec::new();
    prices.push(0);

    match io::stdin().read_line(&mut input) {
        Ok(_n) => {
            let vec: Vec<i32> = input
                .trim()
                .split(" ")
                .map(|x| x.parse::<i32>().unwrap())
                .collect();
            n = vec[0];
            l = vec[1];
        }
        Err(error) => panic!("error: {}", error),
    }

    input.clear();
    match io::stdin().read_line(&mut input) {
        Ok(_n) => {
            let input_prices: Vec<i32> = input
                .trim()
                .split(" ")
                .map(|x| x.parse::<i32>().unwrap())
                .collect();

            prices.extend(input_prices);
        }
        Err(error) => panic!("error: {}", error),
    }

    let acc = accumulate(prices);
    let mut min = std::f64::MAX;

    for from in 1..(n + 1) {
        for to in l..(n + 1) {
            let days = to - (from - 1);
            if (days < l) {
                continue;
            }

            let mut avg = (acc[to as usize] - acc[(from - 1) as usize]) as f64 / days as f64;
            min = min.min(avg);
        }
    }
    println!("{:.11}", min);
}

fn accumulate(prices: Vec<i32>) -> Vec<i32> {
    let mut result: Vec<i32> = Vec::with_capacity(prices.len());

    let mut acc = prices[0];
    result.push(acc);
    for i in 1..prices.len() {
        acc += prices[i];
        result.push(acc);
    }

    result
}

#[cfg(test)]
mod tests {
    #[test]
    fn festival() {
        super::main();
    }
}
