// https://leetcode.com/problems/add-two-numbers

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
        Self::add_two_numbers_with_remaining(l1, l2, 0)
    }

    fn add_two_numbers_with_remaining(
        l1: Option<Box<ListNode>>,
        l2: Option<Box<ListNode>>,
        remaining: i32
    ) -> Option<Box<ListNode>> {
        let mut sum = remaining;
        match (l1, l2) {
            // both lists are None
            (None, None) => {
                if remaining > 0 {
                    return Some(Box::new(ListNode::new(remaining)));
                }
                None
            }
            // only 1 list is None
            (None, Some(mut list)) | (Some(mut list), None) => {
                sum += list.val;
                list.val = sum % 10;
                list.next = Self::add_two_numbers_with_remaining(list.next, None, sum/10);
                Some(list)
            },
            // none is None
            (Some(mut list), Some(l2)) => {
                sum += list.val + l2.val;
                list.val = sum % 10;
                list.next = Self::add_two_numbers_with_remaining(list.next, l2.next, sum/10);
                Some(list)
            },
        }
    }
}
