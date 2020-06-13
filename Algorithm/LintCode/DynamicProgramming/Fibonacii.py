class Solution:

    def Fib_recrsion(self, n):
        if n == 0:
            return 0
        if n == 1:
            return 1

        return self.Fib_recrsion(n - 1) + self.Fib_recrsion(n - 2)

    def Fib_DP_FullSpace(self, n):
        if n == 0:
            return 0
        if n == 1:
            return 1

        ans = [0] * (n+1)
        ans[0] = 0
        ans[1] = 1

        for i in range(2, n + 1):
            ans[i] = ans[i-1] + ans[i-2]     
        return ans[n]

    def Fib_DP_best(self, n):
        if n == 0:
            return 0
        if n == 1:
            return 1

        ans = [0] * 3
        ans[0] = 0
        ans[1] = 1

        for i in range(2, n + 1):
            ans[i%3] = ans[i%3-1] + ans[i%3-2]     
        return ans[n%3]

test = Solution()
n = 9
print(test.Fib_recrsion(n))
print(test.Fib_DP_FullSpace(n))
print(test.Fib_DP_best(n))