// https://leetcode.com/problems/longest-substring-without-repeating-characters

impl Solution {
    pub fn length_of_longest_substring(s: String) -> i32 {
        let mut seen: [Option<usize>; 128] = [None; 128]; // assume ascii
        let mut start: usize = 0;
        let mut max: i32 = 0;

        for (end, c) in s.chars().enumerate() {
            match seen[c as usize] {
                Some(index) if index >= start => {
                    max = std::cmp::max(max, (end-start) as i32);
                    start = index+1;
                },
                _ => {}
            }
            seen[c as usize] = Some(end);
        }

        std::cmp::max(max, (s.len()-start) as i32)
    }
}

impl AlternativeSyntaxSolution {
    pub fn length_of_longest_substring(s: String) -> i32 {
        let mut seen: [Option<usize>; 128] = [None; 128]; // assume ascii
        let mut start: usize = 0;
        let mut max: i32 = 0;

        for (end, c) in s.chars().enumerate() {
            if let Some(index) = seen[c as usize] {
                if index >= start {
                    max = std::cmp::max(max, (end-start) as i32);
                    start = index+1;
                }
            }
            seen[c as usize] = Some(end);
        }

        std::cmp::max(max, (s.len()-start) as i32)
    }
}

impl SSSSlooowwwSolution {
    pub fn length_of_longest_substring(s: String) -> i32 {
        let mut seen = [false; 128];
        let mut start: usize = 0;
        let mut max: i32 = 0;

        for (end, c) in s.chars().enumerate() {
            if seen[c as usize] {
                max = std::cmp::max(max, (end-start) as i32);
                // clean seen (cache friendly, but still not fast)
                for a in s.chars().skip(start).take(end) {
                    seen[a as usize] = false;
                    start += 1;
                    if a == c {
                        break;
                    }
                }
            }
            seen[c as usize] = true;
        }
        std::cmp::max(max, (s.len()-start) as i32)
    }
}

/*
Test data:
"bbbbb"
"abcabcbb"
"pwwkew"
""
" "
"au"
"dvdf"
"abba"
*/
