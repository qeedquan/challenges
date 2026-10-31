/*

Consider an expression 2^2^...^2 with n operators ^. Operator ^ means exponentiation ("to the power of"). Assume that it has no default assosiativity, so the expression needs to be fully parenthesized to become unambiguous. The number of ways to parenthesize the expression are given by Catalan numbers C_n=(2n)!/(n+1)!/n!.

Sometimes different parenthesizations give the same numeric outcome, for example (2^2)^(2^2)=((2^2)^2)^2, so the number of different possible numeric outcomes for a given n is less than C_n for all n>1. The sequence starts as 1, 1, 2, 4, 8, ... as opposed to Catalan numbers 1, 2, 5, 14, 42, ...

The problem is to write the fastest program (or function) that accepts n as an input and returns the number of different possible numeric outcomes of the expression 2^2^...^2 with n operators ^. The performance should not significantly deteriorate as n grows, so direct calculation of high power towers is probably a bad idea.

*/

use std::collections::{HashMap, HashSet};
use std::hash::{Hash, Hasher};

// Ported from @138 Aspen solution

// Custom struct to represent a frozen set
#[derive(Clone, Eq)]
struct FrozenSet {
    set: HashSet<FrozenSet>,
}

impl FrozenSet {
    fn new() -> Self {
        FrozenSet {
            set: HashSet::new(),
        }
    }

    fn insert(&mut self, value: FrozenSet) {
        self.set.insert(value);
    }

    fn remove(&mut self, value: &FrozenSet) {
        self.set.remove(value);
    }

    fn contains(&self, value: &FrozenSet) -> bool {
        self.set.contains(value)
    }
}

impl PartialEq for FrozenSet {
    fn eq(&self, other: &Self) -> bool {
        self.set == other.set
    }
}

impl Hash for FrozenSet {
    fn hash<H: Hasher>(&self, state: &mut H) {
        let mut elements: Vec<_> = self.set.iter().collect();
        elements.sort_by(|a, b| a.set.len().cmp(&b.set.len()));
        for elem in elements {
            elem.hash(state);
        }
    }
}

// Memoization struct
struct Memoize {
    get_results_cache: HashMap<usize, HashSet<FrozenSet>>,
    successor_cache: HashMap<FrozenSet, FrozenSet>,
}

impl Memoize {
    fn new() -> Self {
        Memoize {
            get_results_cache: HashMap::new(),
            successor_cache: HashMap::new(),
        }
    }

    fn get_results(&mut self, num_exponentiations: usize) -> HashSet<FrozenSet> {
        if let Some(cached) = self.get_results_cache.get(&num_exponentiations) {
            return cached.clone();
        }
        let result = if num_exponentiations == 0 {
            let mut set = HashSet::new();
            set.insert(FrozenSet::new());
            set
        } else {
            let mut results = HashSet::new();
            let split_points = 0..num_exponentiations;
            let splits = split_points
                .clone()
                .zip((0..num_exponentiations).rev())
                .filter(|(left_part, right_part)| left_part <= right_part);
            for (left_part, right_part) in splits {
                let left_results = self.get_results(left_part);
                let right_results = self.get_results(right_part);
                for left in &left_results {
                    for right in &right_results {
                        results.insert(self.exponentiate(left.clone(), right.clone()));
                        results.insert(self.exponentiate(right.clone(), left.clone()));
                    }
                }
            }
            results
        };
        self.get_results_cache
            .insert(num_exponentiations, result.clone());
        result
    }

    fn exponentiate(&mut self, mut base: FrozenSet, mut exponent: FrozenSet) -> FrozenSet {
        while base.contains(&exponent) {
            base.remove(&exponent);
            exponent = self.successor(exponent.clone());
        }
        base.insert(exponent.clone());
        base
    }

    fn successor(&mut self, value: FrozenSet) -> FrozenSet {
        if let Some(cached) = self.successor_cache.get(&value) {
            return cached.clone();
        }
        let result = self.exponentiate(value.clone(), FrozenSet::new());
        self.successor_cache.insert(value, result.clone());
        result
    }
}

// https://oeis.org/A002845
fn count_results(num_exponentiations: usize) -> usize {
    let mut memoize = Memoize::new();
    memoize.get_results(num_exponentiations).len()
}

fn main() {
    let start_time = std::time::Instant::now();
    for i in 0..=20 {
        println!("Execution time: {:?}", start_time.elapsed());
        println!("{:2}..{:>9}", i, count_results(i));
    }
}
