//* 23. Merge k Sorted Lists [HARD]

/**
 * How it works?
 * 
 * 1. Divide and Conquer approach is used to merge k sorted linked lists.
 * 2. The lists are recursively divided into two halves until each half contains a single list.
 * 3. The two halves are then merged together using the mergeTwoSortedList function.
 * 4. This process continues until all lists are merged into a single sorted linked list.
 * 5. The mergeTwoSortedList function merges two sorted linked lists by comparing their nodes and linking them in sorted order.
 * 6. A dummy node is used to simplify the merging process, and the merged list is returned starting from the node next to the dummy.
 * 7. The overall time complexity is O(N log k), where N is the total number of nodes across all lists and k is the number of lists.
 */
class ListNode {
  val: number;
  next: ListNode | null;
  constructor(val?: number, next?: ListNode | null) {
    this.val = val === undefined ? 0 : val;
    this.next = next === undefined ? null : next;
  }
}

function mergeKLists(lists: Array<ListNode | null>): ListNode | null {
  if (lists.length === 0) return null;

  function mergeLists(
    lists: Array<ListNode | null>,
    start: number,
    end: number
  ): ListNode | null {
    //Base case
    if (start === end) {
      return lists[start];
    }
    const mid = Math.floor((start + end) / 2);
    const left = mergeLists(lists, start, mid - 1);
    const right = mergeLists(lists, mid + 1, end);
    return mergeTwoSortedList(left, right);
  }
  function mergeTwoSortedList(
    list1: ListNode | null,
    list2: ListNode | null
  ): ListNode | null {
    //Base Case
    const dummy = new ListNode(0);
    let current = dummy;

    while (list1 !== null && list2 !== null) {
      console.log(list1.val, list2.val);
      if (list1.val < list2.val) {
        current.next = list1;
        list1 = list1.next;
      } else {
        current.next = list2;
        list2 = list2.next;
      }
      current = current.next;
    }
    if (list1 !== null) {
      current.next = list1;
    }
    if (list2 !== null) {
      current.next = list2;
    }
    return dummy.next;
  }
  return mergeLists(lists, 0, lists.length - 1);
}

//Test
const list1 = new ListNode(1, new ListNode(4, new ListNode(5)));
const list2 = new ListNode(1, new ListNode(3, new ListNode(4)));
const list3 = new ListNode(2, new ListNode(6));
const lists = [list1, list2, list3];
console.log(mergeKLists(lists));

//Output: [1,1,2,3,4,4,5,6]
