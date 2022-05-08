class Solution:
       def singleNumber(self, nums) -> int:
            nums.sort()
            if len(nums) < 3:
                return nums[0]
            if nums[0] !=nums[1]:
                return nums[0]
            elif nums[-1] != nums[-2]:
                return nums[-1]
            for i in range(1,len(nums)-1):
                if nums[i] != nums[i+1] and nums[i-1] != nums[i]:
                    return nums[i]