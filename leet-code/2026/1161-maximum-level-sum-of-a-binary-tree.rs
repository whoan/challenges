// https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/
// Medium

use std::cell::RefCell;
use std::collections::VecDeque;
use std::rc::Rc;

impl Solution {
    pub fn max_level_sum(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        let mut queue: VecDeque<Option<Rc<RefCell<TreeNode>>>> = VecDeque::new();
        let mut max = if root.is_some() {
            root.as_ref().unwrap().borrow().val
        } else {
            return 0;
        };
        let mut level = 1;
        let mut cur_level = 0;
        queue.push_back(Some(Rc::clone(&root.unwrap())));
        while !queue.is_empty() {
            let mut new_queue = VecDeque::new();
            let mut current: i32 = 0;
            cur_level += 1;
            while !queue.is_empty() {
                if let Some(node) = queue.pop_front().unwrap() {
                    current += node.borrow().val;
                    if let Some(left) = &node.borrow_mut().left {
                        new_queue.push_back(Some(Rc::clone(&left)));
                    }
                    if let Some(right) = &node.borrow_mut().right {
                        new_queue.push_back(Some(Rc::clone(&right)));
                    }
                }
            }
            if current > max {
                max = current;
                level = cur_level;
            }
            queue = new_queue;
        }
        level
    }
}

// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
//
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
