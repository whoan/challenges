// https://leetcode.com/problems/add-two-numbers/

// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
//
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }

impl Solution {
    pub fn add_two_numbers(l1: Option<Box<ListNode>>, l2: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        Solution::add_two(l1, l2, 0)
    }

    fn add_two(l1: Option<Box<ListNode>>, l2: Option<Box<ListNode>>, remaining: i32) -> Option<Box<ListNode>> {
        let mut result = Box::new(ListNode::new(remaining));

        let mut l1Next: Option<Box<ListNode>> = None;
        if let Some(node) = l1 {
            result.val += node.val;
            l1Next = node.next;
        } else if let None = l2 {
            if remaining == 0 {
                return None;
            }
            return Some(result);
        }

        let mut l2Next: Option<Box<ListNode>> = None;
        if let Some(node) = l2 {
            result.val += node.val;
            l2Next = node.next;
        }

        result.next = Solution::add_two(l1Next, l2Next, result.val/10);
        result.val %= 10;
        Some(result)
    }
}
