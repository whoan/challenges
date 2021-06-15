// https://leetcode.com/problems/palindrome-number/

// based on https://leetcode.com/problems/palindrome-number/discuss/5127/9-line-accepted-Java-code-without-the-need-of-handling-overflow
impl Solution {
    pub fn is_palindrome(x: i32) -> bool {
        if x < 0  || (x != 0 && x % 10 == 0) {
            return false;
        }

        // eg: 12321 -> x will have 12, reversed will have 123 (0 -> 1 -> 12 > 123)
        let (mut x, mut reversed) = (x, 0);
        while x > reversed {
            reversed *= 10;
            reversed += x % 10;
            x /= 10;
        }
        x == reversed || x == reversed/10
    }
}

// somehow, it seems to run faster than the solution above in LeetCode
impl IntricateSolution {
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
