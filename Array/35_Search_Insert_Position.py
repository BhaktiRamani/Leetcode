# 35. Search Insert Position
# Easy
# Topics
# Companies
# Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

# You must write an algorithm with O(log n) runtime complexity.

 

# Example 1:

# Input: nums = [1,3,5,6], target = 5
# Output: 2
# Example 2:

# Input: nums = [1,3,5,6], target = 2
# Output: 1
# Example 3:

# Input: nums = [1,3,5,6], target = 7
# Output: 4

nums = [1, 3, 5, 6]
target = 2

result = 0
min = nums[0]
max = nums[0]

for i in range(len(nums)):
 

    if i + 1 < len(nums):
       
        if nums[i] <= target and nums[i+1] >= target:
            result = i + 1
            break
        result = i + 2
        
print(result)
        
    