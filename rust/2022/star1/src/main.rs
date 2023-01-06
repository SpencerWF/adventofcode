use std::fs;

#[allow(unused_variables)]
#[allow(unused_assignments)]
#[allow(dead_code)]
fn main() {
    // Read in the file as a string
    let data = fs::read_to_string("../../../input/2022/input2.txt").expect("Unable to read file");
    // println!("{}", data.len());

    let use_array = ['X', 'Y', 'Z'];
    let opp_array = ['A', 'B', 'C'];
    let compare_array = [['X', 'Y', 'Z'], ['Y', 'Z', 'X'], ['Z', 'X', 'Y']];
    let points_array = [3, 6, 0];

    // Create an iterator to go through each line of the data from the input file
    let lines:Vec<&str> = data.split('\n').collect();

    let mut total_points = 0;

    // Go through the iterator
    for n in lines {
        // println!("{}", n)
        let mut line_points = 0;
        let mut state_array = ['A', 'B', 'C'];

        for (i,c) in n.chars().enumerate() {
            if i == 0 {
                let opp = opp_array.iter().position(|&x| x == c).unwrap();
                // println!("{} {}", c, opp);
                state_array = compare_array[opp].clone();
            } else if i == 2 {
                // println!("State Array {:?}", state_array);
                // println!("Index {} with Character {}", i, c);
                let throw = use_array.iter().position(|&x| x == c).unwrap();
                line_points += throw + 1;
                let compare = state_array.iter().position(|&x| x == c).unwrap();
                line_points += points_array[compare];
                total_points += line_points;
            }
        }
    }

    println!("Final points: {}", total_points);


}
