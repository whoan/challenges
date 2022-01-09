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

impl MessySolution {
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

type OptionalNode = Option<Box<ListNode>>;

impl Solution {
    pub fn add_two_numbers(l1: OptionalNode, l2: OptionalNode) -> OptionalNode {
        Self::add_two(l1, l2, 0)
    }

    fn add_two(l1: OptionalNode, l2: OptionalNode, remaining: i32) -> OptionalNode {
        // base case
        if l1.is_none() && l2.is_none() && remaining == 0 {
            return None;
        }

        if let (Some(mut some), option) = Self::reorder(l1, l2) {
            some.val += option.as_ref().map_or(0, |n| n.val) + remaining;
            some.next = Self::add_two(some.next, option.map_or(None, |n| n.next), some.val/10);
            some.val %= 10;
            return Some(some)
        }
        return Some(Box::new(ListNode::new(remaining)));
    }

    fn reorder(l1: OptionalNode, l2: OptionalNode) -> (OptionalNode, OptionalNode) {
        if l1.is_some() {
            return (l1, l2)
        }
        return (l2, l1)
    }
}
