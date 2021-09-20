class Solution:
    """
    @param triangle: a list of lists of integers
    @return: An integer, minimum path sum
    """
    def minimumTotal(self, triangle):
        # write your code here
        return self.TopToBottom_FullTriangle(triangle)
        
    """
        思路：
        初始化一个三角形的look up table
        由上往下走，下一层的每一个值都去觉得上左和上右，即：
            # dp[i][j] = min(dp[i + 1][j], dp[i + 1][j + 1]) + triangle[i][j]
        
        *特殊情况是顶点和两边，他们只有一个或者没有，所以可以直接把值传递
        于是初始化时先做两边：
            lut[0][0] = triangle[0][0]
            # initialize: 三角形的左边和右边要初始化
            # 因为他们分别没有左上角和右上角的点
            for i in range(1, tri_size):
                lut[i][0] = lut[i - 1][0] + triangle[i][0]
                lut[i][i] = lut[i - 1][i - 1] + triangle[i][i]
        
        剩下的就是遍历三角形内部，从第三层开始
        1
        23
        456  --》 从数字5开始， 即从row = 2 开始，外边以处理，所以col从1开始，每层遍历的数量是 i - 1
            for i in range(2, tri_size):
                for j in range(1, i):


        优化思路： 优化空间复杂度从O(n*n) -> O(2n)
        lut = [[0]*n, [0]*2]   n * 2 的数组
        通过%取余来生成一个滚动数组，节省空间
        拿斐波那契举例：
        f[n] = f[n-1] + f[n - 2] 实际记录只需三个数，所以
        f[n % 3] = f[n % 3-1] + f[n % 3 - 2]
            
    """
    def TopToBottom(self, triangle):
        # dp[i][j] = min(dp[i + 1][j], dp[i + 1][j + 1]) + triangle[i][j]
        tri_size = len(triangle)
        lut = [[0] * (j + 1) for j in range(tri_size)]
        
        #top value
        lut[0][0] = triangle[0][0]
        # initialize: 三角形的左边和右边要初始化
        # 因为他们分别没有左上角和右上角的点
        for i in range(1, tri_size):
            lut[i][0] = lut[i - 1][0] + triangle[i][0]
            lut[i][i] = lut[i - 1][i - 1] + triangle[i][i]

        for i in range(2, tri_size):
            for j in range(1, i):
                lut[i][j] = min(lut[i - 1][j], lut[i - 1][j - 1]) + triangle[i][j]

        return min(lut[tri_size - 1])
    

    """
    Full triangle
       0 1 2 3
    0  1
    1  2 3
    2  4 5 6 
    3  7 8 9 10

    left side is lut[1][0] lut[2][0] lut[3][0] ---> lut[i][0]
    right side is lut[1][1] lut[2][2] lut[3][3] ---> lut[i][i]

    """
    def TopToBottom_FullTriangle(self, triangle):
        tri_size = len(triangle)
        lut = [[0 for i in range(tri_size)] for j in range(tri_size)]

        lut[0][0] = triangle[0][0]  #init top value


        for i in range(1, tri_size):
            # get two side, since it only do a simple sum value down
            lut[i][0] = lut[(i - 1)][0] + triangle[i][0]
            lut[i][i] = lut[(i-1)][i-1] + triangle[i][i]
            for j in range(1, i):
                lut[i][j] = min(lut[i-1][j], lut[i-1][j-1]) + triangle[i][j]
        self.print_lut(lut)
        return min(lut[(tri_size - 1)])

    def minimumTotal_nSpace(self, triangle):
        n = len(triangle)
        
        # state: dp[i][j] 代表从 0, 0 走到 i, j 的最短路径值
        dp = [[0] * n, [0] * n]
        
        # initialize: 初始化起点
        dp[0][0] = triangle[0][0]
        
        # function: dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j]
        # i, j 这个位置是从位置 i - 1, j 或者 i - 1, j - 1 走过来的
        for i in range(1, n):
            dp[i % 2][0] = dp[(i - 1) % 2][0] + triangle[i][0]
            dp[i % 2][i] = dp[(i - 1) % 2][i - 1] + triangle[i][i]
            for j in range(1, i):
                dp[i % 2][j] = min(dp[(i - 1) % 2][j], dp[(i - 1) % 2][j - 1]) + triangle[i][j]
               
        # answer: 最后一层的任意位置都可以是路径的终点
        return min(dp[(n - 1) % 2])


    def print_lut(self, lut):

        for i in lut:
            s = ""
            for j in i:
                s += str(j) + " "
            print(s)


test = Solution()
inData = [[1],[2,3],[4,5,6],[7,8,9,10]]
out = test.minimumTotal(inData)
print(out)