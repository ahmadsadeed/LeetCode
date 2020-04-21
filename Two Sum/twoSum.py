class Solution():
    def twoSum(self, nums, target):
        if len(nums) <= 1:
            return False
        map = {}
        for i in range(len(nums)):
            if nums[i] in map:
                return [map[nums[i]], i]
            else:
                complement = target - nums[i]
                map[complement] = i
