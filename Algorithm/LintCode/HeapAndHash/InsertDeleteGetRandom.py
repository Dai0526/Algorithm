"""
657. Insert Delete GetRandom O(1)
https://www.lintcode.com/problem/insert-delete-getrandom-o1
Design a data structure that supports all following operations in average O(1) time.

insert(val): Inserts an item val to the set if not already present.
remove(val): Removes an item val from the set if present.
getRandom: Returns a random element from current set of elements. Each element must have the same probability of being returned.

Example
// Init an empty set.
RandomizedSet randomSet = new RandomizedSet();

// Inserts 1 to the set. Returns true as 1 was inserted successfully.
randomSet.insert(1);

// Returns false as 2 does not exist in the set.
randomSet.remove(2);

// Inserts 2 to the set, returns true. Set now contains [1,2].
randomSet.insert(2);

// getRandom should return either 1 or 2 randomly.
randomSet.getRandom();

// Removes 1 from the set, returns true. Set now contains [2].
randomSet.remove(1);

// 2 was already in the set, so return false.
randomSet.insert(2);

// Since 2 is the only number in the set, getRandom always return 2.
randomSet.getRandom();
"""

"""
All in O(1)
1. Inseart: hashmap can deal with it
2. Remove: all built in delete is in O(n), since you need to find in O(n), then delete in O(1),
    the idea is to use stack/queue like such that you can pop or dequeue it at either end in O(1)

C++ like  list node remove won't work since you have to find it first. 

How:
    1. With the help of map<number, idx>, so you know where it is saved in the list
    2. swap it to the end, then you can remove end by pop, all intermediate operations are all in O(1)

"""
import random
class RandomizedSet:
    
    def __init__(self):
        # do intialization if necessary
        self.index_map = {}
        self.num_list = []

    """
    @param: val: a value to the set
    @return: true if the set did not already contain the specified element or false
    """
    def insert(self, val):
        
        # find if it is in the map
        if val in self.index_map:
            return False

        list_size = len(self.num_list) # it is also the index of this val

        self.num_list.append(val)
        self.index_map[val] = list_size

        return True

    """
    @param: val: a value from the set
    @return: true if the set contained the specified element or false
    """
    def remove(self, val):
        
        # find its index
        if val not in self.index_map:
            return False
        
        idx = self.index_map[val]

        # swap it with the last element -> not a full swap, only need to copy value & index info to it, then pop last
        val_current_last = self.num_list[-1]

        self.num_list[idx] = val_current_last
        self.index_map[val_current_last] = idx

        # wanted info is copied, val's has been removed, and now only need to remove its container

        self.num_list.pop()
        del self.index_map[val]

        return True



    """
    @return: Get a random element from the set
    """
    def getRandom(self):
        # get random index
        idx = random.randint(0, len(self.num_list))
        return self.num_list[idx]