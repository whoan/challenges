// https://leetcode.com/problems/palindrome-number/

impl Solution {
    pub fn is_palindrome(x: i32) -> bool {
        if x < 0 {
            return false;
        }

        let mut x = x;
        let mut power = Self::get_number_of_numbers(x) - 1;
        let mut power_remaining = 1;
        while x/i32::pow(10, power_remaining) != 0 && (x % 10) == ((x / i32::pow(10, power)) % 10) {
            x /= 10;
            power -= 2;
            power_remaining += 1;
        }
        x / i32::pow(10, power_remaining) == 0
    }

    fn get_number_of_numbers(mut x: i32) -> u32 {
        // I don't know how to use log in Rust :(
        let mut n = 1;
        x /= 10;
        while x != 0 {
            n += 1;
            x /= 10;
        }
        n
    }
}

/*
Test cases:
121
-121
10
-101
12321
123431
1000021
*/
