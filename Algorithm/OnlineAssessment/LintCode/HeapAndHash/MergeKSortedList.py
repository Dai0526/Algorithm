"""
104. Merge K Sorted Lists
https://www.lintcode.com/problem/merge-k-sorted-lists
Merge k sorted linked lists and return it as one sorted list.

Analyze and describe its complexity.

Example 1:
	Input:   [2->4->null,null,-1->null]
	Output:  -1->2->4->null

Example 2:
	Input: [2->6->null,5->null,7->null]
	Output:  2->5->6->7->null

 Two ways to do it:
 Idea 1: min heap, push everything in, then keep remove and add to lists
 Idea 2: merge 2 sorted list by using two pointers, keep do it until only one list left

for heap, the complexity will be:
    O(n) = heap_add + heap_remove = n + nlogn

"""


class ListNode(object):

    def __init__(self, val, next=None):
        self.val = val
        self.next = next

import heapq


# overwrite the compare function 
# so that we can directly put ListNode into heapq
ListNode.__lt__ = lambda x, y: (x.val < y.val)

class Solution:
    """
    @param lists: a list of ListNode
    @return: The head of one sorted list.
    """
    def mergeKLists(self, lists):
        # write your code here
        
        heap = []
        if not lists:
            return None
            
        for li in lists:
            node = li
            while node is not None:
                heapq.heappush(heap, node)
                node = node.next
                
        node = ListNode(0)
        tail = node
        while heap:
            head = heapq.heappop(heap)
            tail.next = head
            tail = head
        
        return node.next