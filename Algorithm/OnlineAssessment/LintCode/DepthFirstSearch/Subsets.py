

class Subset:

    """
        list.sort() and sorted(list)
    """

    def subsets(self, nums):
        # DFS decision tree
        if nums is None:
            return []
        
        sorted_num = sorted(nums)
        results = []
        self.dfs(sorted_num, 0, [], results)
        return results
    
    """
    IDEA 决策树 -> 更推荐的算法
               /--> [1,2] -> [1,2,3] 
       /-> [1] -> [1,3] 
    []  -> [2] -> [2,3]
      \\
        -> [3]
    1， 12， 123， 2，23， 3，
    """

    def dfs(self, nums, idx, combination, results):
        results.append(list(combination))
        #print("comb: {}".format(combination))
        #print("results: {}".format(results))
        for i in range(idx, len(nums)):
            combination.append(nums[i])
            self.dfs(nums, i + 1, combination, results)
            combination.pop()
    

    """
        More intuitive way to solve it

        Append the one you need, do a search
        Remove it, search with it

        过程和上一个方法一样，代码更容易理解
            1， 12， 123， 2，23， 3，
    """
    def search(self, nums, index, combination, results):
        if index == len(nums):
            results.append(list(combination))
            return
        
        combination.append(nums[index])
        self.search(nums, index + 1, combination, results)
        combination.pop()
        self.search(nums, index + 1, combination, results)