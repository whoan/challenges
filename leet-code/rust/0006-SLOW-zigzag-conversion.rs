/*
You can think of the zig zag as a two part movement:
- zig: starts going down and then up
- zag: starts going up and then down
*/

// (16ms) faster than 16.3% of submissions. Won the slooowww badge
impl SlowSolution {
    pub fn convert(s: String, num_rows: i32) -> String {
        if num_rows == 1 || num_rows >= s.len() {
            return s;
        }

        let mut result = String::with_capacity(s.len());
        let num_rows = num_rows as usize;
        let zig_zag_len = num_rows + num_rows - 2;
        let mut step = 0;

        for row in 0..num_rows {
            let mut it = s.chars().skip(row);
            let mut zig = true;
            let mut skip = 0usize;

            while let Some(c) = it.by_ref().skip(skip).next() {
                result.push(c);
                skip = match zig {
                    true => zig_zag_len - step,
                    false => step,
                } - 1; // -1 because next() already forwards the iterator by 1

                if step % zig_zag_len != 0 {
                    zig = !zig;
                }
            }
            step = (step + 2) % zig_zag_len;
        }
        result
    }
}

/*
Test data:
"PAYPALISHIRING"
4
"A"
1
"AB"
1
*/
