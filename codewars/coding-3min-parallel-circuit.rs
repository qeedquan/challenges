/*

Task:

In theory, A parallel circuit can have a lot of branch circuit, the total resistance of the parallel circuit is related to the resistance value of the branch circuit:

the reciprocal of the total resistance of a parallel circuit is equal to the sum of the reciprocal of the branch resistances.

Given parameter:

2D array arr they are each branch circuit of parallel circuits. thay contains some resistance value of electric appliances in the branch circuit.

Please calculate and return the total resistance of the parallel circuit.

Formula:

                R : total resistance, 
    r1,r2,r3...rn : resistance value of the branch circuit
    
       ∵  1/R=1/r1+1/r2+1/r3...+1/rn
       ∴  R=1/(1/r1+1/r2+1/r3...+1/rn)

Examples:

example1:
arr=[[1],[1]]
R = 1/(1/1+1/1)= 0.5
So, resistance([[1],[1]])=0.5

example2:
arr=[[1],[2]]
R = 1/(1/1+1/2)= 0.67
So, resistance([[1],[2]])=0.67

example3:
arr=[[1],[2,3]]
R = 1/(1/1+1/5)= 0.83
So, resistance([[1],[2,3]])=0.83

*/

fn main() {
    println!("{}", parallel(&vec![&vec![1.0], &vec![1.0]]));
    println!("{}", parallel(&vec![&vec![1.0], &vec![2.0]]));
    println!("{}", parallel(&vec![&vec![1.0], &vec![2.0, 3.0]]));
    println!(
        "{}",
        parallel(&vec![
            &vec![13.0, 8.0],
            &vec![17.0, 17.0, 3.0],
            &vec![4.0, 7.0, 12.0, 12.0, 8.0]
        ])
    );
    println!(
        "{}",
        parallel(&vec![
            &vec![16.0, 20.0, 20.0],
            &vec![13.0, 12.0],
            &vec![20.0, 12.0, 3.0, 20.0]
        ])
    );
    println!(
        "{}",
        parallel(&vec![
            &vec![18.0, 20.0, 11.0],
            &vec![20.0, 4.0],
            &vec![18.0],
            &vec![7.0, 18.0, 18.0, 19.0],
            &vec![12.0, 1.0]
        ])
    );
}

fn parallel(branches: &Vec<&Vec<f64>>) -> f64 {
    let mut total = 0.0;
    for &branch in branches {
        let mut sum = 0.0;
        for value in branch {
            sum += value;
        }
        total += 1.0 / sum;
    }
    1.0 / total
}
