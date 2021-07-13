impl Solution {
    pub fn is_isomorphic(s: String, t: String) -> bool {
        let mut map = [0 as char; 128];
        let mut known = [false; 128];

        let mut t: Vec<char> = t.chars().collect();
        for (index, c) in s.chars().enumerate() {
            let ct: char = t[index];
            if map[ct as usize] == 0 as char {
                if known[c as usize] {
                    return false;
                }
                known[c as usize] = true;
                map[ct as usize] = c;
            }
            t[index] = map[ct as usize];
        }
        //println!("{:?}", t);
        s.chars().collect::<Vec<char>>() == t
        //s.chars().cpm(t.iter()) == std::cmp::Ordering::Equal;
    }
}
