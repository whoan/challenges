https://leetcode.com/problems/roman-to-integer/

impl Solution {
    pub fn roman_to_int(s: String) -> i32 {
        let mut result: i32 = 0;
        let mut previous: i32 = 0;
        for c in s.chars() {
            let current = match c {
                'I' => 1,
                'V' => 5,
                'X' => 10,
                'L' => 50,
                'C' => 100,
                'D' => 500,
                'M' => 1000,
                _ => panic!("can't be possible"),
            };
            if previous < current {
                result += current - 2 * previous;
            } else {
                result += current;
            }
            previous = current;
        }
        result
    }
}
