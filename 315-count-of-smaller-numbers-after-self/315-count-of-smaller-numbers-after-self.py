class Solution:
    def countSmaller(self, nums: List[int]) -> List[int]:
        sorted_values, ans = [], []
        for x in nums[::-1]:
            idx = bisect.bisect_left(sorted_values, x)
            sorted_values.insert(idx, x)
            ans.append(idx)
        return ans[::-1]