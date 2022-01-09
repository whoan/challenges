// https://leetcode.com/problems/isomorphic-strings/

/*
Add this for safety but not needed due to constraints:

    if s.len() != t.len() {
        return false;
    }
    assert!(s.is_ascii());
    assert!(t.is_ascii());

*/

/*
Runtime: 0 ms, faster than 100.00% of Rust online submissions for Isomorphic Strings.
Memory Usage: 2.1 MB, less than 100.00% of Rust online submissions for Isomorphic Strings.
*/
impl Solution {
    pub fn is_isomorphic(s: String, t: String) -> bool {
        let mut map = [0 as char; 128];
        let mut known = [false; 128];

        for (x, y) in s.chars().zip(t.chars().map(|y| y as usize)) {
            if map[y] == 0 as char {
                if known[x as usize] {
                    return false;
                }
                known[x as usize] = true;
                map[y] = x;
            }
            if map[y] != x {
                return false;
            }
        }
        true
    }
}

impl Solution {
    pub fn is_isomorphic(s: String, t: String) -> bool {
        let mut map = [0 as char; 128];
        let mut known = [false; 128];
        s.chars()
            .zip(t.chars())
            .all(|(x, y)| {
                let y = y as usize;
                if map[y] == 0 as char {
                    if known[x as usize] {
                        return false;
                    }
                    known[x as usize] = true;
                    map[y] = x;
                }
                map[y] == x
            })
    }
}

impl Solution {
    pub fn is_isomorphic(s: String, t: String) -> bool {
        let mut map = [0u8; 128];
        let mut known = [false; 128];
        s.bytes()
            .zip(t.bytes().map(|y| y as usize))
            .all(|(x, y)| {
                if map[y] == 0u8 {
                    if known[x as usize] {
                        return false;
                    }
                    known[x as usize] = true;
                    map[y] = x;
                }
                map[y] == x
            })
    }
}
