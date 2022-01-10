// https://leetcode.com/problems/longest-substring-without-repeating-characters/

impl Solution {
    pub fn length_of_longest_substring(s: String) -> i32 {
        let mut seen = [0; 127];
        let mut start: i32 = 0;
        let mut max : i32 = 0;
        for (end, current_char) in s.char_indices().map(|(i, c)| (i as i32 + 1, c as usize)) {
            if seen[current_char] > start {
                start = seen[current_char];
            } else {
                max = std::cmp::max(max, end-start);
            }
            seen[current_char] = end;
        }
        max
    }
}
