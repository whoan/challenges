// https://leetcode.com/problems/reverse-integer/

// 0ms solution

impl Solution {
    pub fn reverse(x: i32) -> i32 {
        let mut result = 0;
        let mut x = x;

        // max allowed is == max_most_significant + max_remaining -> (-2^31 == -2147483648) or (2^31-1 == 2147483647)
        const max_most_significant: i32 = 0x7FFFFFFF / 10; // 214748364
        let max_remaining = 0x7FFFFFFF % 10; // == 7 == 0b01111111 0b11111111 0b11111111 0b11111111 % 10

        // reverse the x.len()-1 most significants digits
        while x / 10 != 0 {
            result *= 10;
            result += i32::abs(x % 10);
            x /= 10;
        }

        // check for overflow
        if result > max_most_significant ||
           (result == max_most_significant && x.abs() > max_remaining)
        {
            return 0;
        }

        // add the remaining to the result (no-overflow guaranteed)
        if x < 0 {
            result *= -1;
        }
        result *= 10;
        result + x
    }
}

/*
Test data:
-900000
1534236469
-2147483412
-2147483648
1563847412
*/
