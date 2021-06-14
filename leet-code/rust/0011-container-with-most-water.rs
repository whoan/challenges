// https://leetcode.com/problems/container-with-most-water/

impl Solution {
    pub fn max_area(heights: Vec<i32>) -> i32 {
        let (mut start, mut end) = (0usize, heights.len() -1);
        let mut max_area: i32 = 0;

        while start < end {
            let min_height = std::cmp::min(heights[start], heights[end]);
            max_area = std::cmp::max(max_area, min_height * (end-start) as i32);
            match heights[start] < heights[end] {
                true  => start += 1,
                false => end -= 1
            }
        }
        max_area
    }
}

impl OptimizedSolution {
    pub fn max_area(heights: Vec<i32>) -> i32 {
        let (mut start, mut end) = (0usize, heights.len() -1);
        let mut max_area: i32 = 0;

        while start < end {
            let min_height = std::cmp::min(heights[start], heights[end]);
            max_area = std::cmp::max(max_area, min_height*(end-start) as i32);
            match heights[start] < heights[end] {
                true  => {
                    // optimization. does not make any difference in LC results though
                    while start + 1 < end && heights[start] >= heights[start+1] {
                        start += 1;
                    }
                    start += 1;
                },
                false => {
                    // optimization. does not make any difference in LC results though
                    while start + 1 < end && heights[end] >= heights[end-1] {
                        end -= 1;
                    }
                    end -= 1;
                }
            }
        }
        max_area
    }
}
