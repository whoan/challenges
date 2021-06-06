use std::collections::HashMap;

struct Solution;

impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut seen = HashMap::new();
        for (index, value) in nums.iter().enumerate() {
            match seen.get(&(target-value)) {
                Some(i) => return vec![index as i32, *i as i32],
                None => { seen.insert(value, index); }
            }
        }
        panic!("Not possible");
    }

    pub fn two_sum_alterative(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut seen = HashMap::new();
        for (index, value) in nums.iter().enumerate() {
            seen.insert(value, index);
        }
        for (index, value) in nums.iter().enumerate() {
            if let Some(i) = seen.get(&(target-value)) {
                if *i != index {
                    return vec![index as i32, *i as i32]
                }
            }
        }
        panic!("Not possible");
    }
}

fn main() {
    println!("{:?}", Solution::two_sum(vec![6, 2, 5, 7], 8));
}
