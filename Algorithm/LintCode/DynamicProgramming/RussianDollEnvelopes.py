"""
602. Russian Doll Envelopes
https://www.lintcode.com/problem/russian-doll-envelopes/
Give a number of envelopes with widths and heights given as a pair of integers (w, h). One envelope can fit into another if and only if both the width and height of one envelope is greater than the width and height of the other envelope.
Find the maximum number of nested layers of envelopes.

Example 1:
Input：[[5,4],[6,4],[6,7],[2,3]]
Output：3
Explanation：the maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).

Example 2:
Input：[[4,5],[4,6],[6,7],[2,3],[1,1]]
Output：4
Explanation：the maximum number of envelopes you can Russian doll is 4 ([1,1] => [2,3] => [4,5] / [4,6] => [6,7]).

思路：
也类似接龙型动态规划
想要套娃，那就先根据信封尺寸排位 -> 第一维小到大，第二维大到小

"""
import bisect
class Solution:
    """
    @param: envelopes: a number of envelopes with widths and heights
    @return: the maximum number of envelopes
    """
    def maxEnvelopes(self, envelopes):
        envelopes.sort(key = lambda x: (x[0], -(x[1] - x[0])))
        lut = []

        for ev in envelopes:
            height = ev[1]
            if len(lut) == 0 or height > lut[-1]:
                lut.append(height)
            else:
                index = bisect.bisect_left(lut, height)
                lut[index] = height

        return len(lut)
test = Solution()
envelop = [[4,5],[4,6],[6,7],[2,3],[1,1]]
test.maxEnvelopes(envelop)    