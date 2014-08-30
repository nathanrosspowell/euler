fn main() {
    let mut sum = 0i;
    for i in range(1i,1000i) {
        if i % 3 == 0 || i % 5 ==0 {
            sum += i;
        }
    }
    println!("{}", sum);
}
